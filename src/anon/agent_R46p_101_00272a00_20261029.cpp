#include "../common/types.h"

// Agent R46p_101 (2026-10-29): FUN_00272a00 (108 bytes, SLPM_666.75).
// Whole-body asm (form a). Loop over six (or three) 436-byte records at GetListBuffer()+24740: each pass calls
// GetFontColorSeqNum(0), setNum(rec, v0), 0x273180(3, i), then 0x192048(lhu(v0)) stored at rec+408.
// Callees 0x257770, 0x257140, 0x138c10, 0x273180 and 0x192048 are reached by numeric jal (no func_ row for 0x273180).
void func_00272a00(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "sd $16,0($29)\n"
        "sd $17,8($29)\n"
        "sd $31,16($29)\n"
        "jal 0x257770\n"
        "daddu $17,$0,$0\n"
        "addiu $16,$2,24740\n"
        "1:\n"
        "jal 0x257140\n"
        "daddu $4,$0,$0\n"
        "daddu $5,$2,$0\n"
        "jal 0x138c10\n"
        "daddu $4,$16,$0\n"
        "daddu $5,$17,$0\n"
        "jal 0x273180\n"
        "addiu $4,$0,3\n"
        "addiu $17,$17,1\n"
        "jal 0x192048\n"
        "lhu $4,0($2)\n"
        "sw $2,408($16)\n"
        "slti $15,$17,6\n"
        "bnez $15,1b\n"
        "addiu $16,$16,436\n"
        "ld $16,0($29)\n"
        "ld $17,8($29)\n"
        "ld $31,16($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set pop\n"
        :
        :
        : "memory");
}
