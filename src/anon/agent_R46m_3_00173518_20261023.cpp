#include "../common/types.h"

// FUN_00173518 (64 bytes). Calls func_00102c18(1, 14002, &func_001734b0) and fills the record it
// returns: word +4 = 0, float +8 = the float at +0 of arg0.
// Matching: the prologue and call are C. The tail is one noreorder asm block (sw in C, then
// ld ra / lwc1 / ld s0 / swc1 / jr / addiu in the original order). Pinned: arg0 to $16 (s0) and
// the returned record to $2 (v0). gcc appends a dead epilogue after the asm; it lies past the
// 64-byte boundary, so only the function bytes are compared.
extern "C" u32 func_00102c18(u32, u32, u32);
extern "C" void func_001734b0(void);

void func_00173518(u32 *s) {
    register u32 *sv asm("$16") = s;
    u32 *r = (u32 *)func_00102c18(1, 14002, (u32)&func_001734b0);
    r[1] = 0;
    register u32 *rv asm("$2") = r;
    asm volatile(
        ".set noreorder\n\t"
        "ld $31,8($29)\n\t"
        "lwc1 $f0,0(%0)\n\t"
        "ld $16,0($29)\n\t"
        "swc1 $f0,8(%1)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder\n\t"
        : : "r"(sv), "r"(rv) : "memory", "$f0");
}
