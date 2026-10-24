#include "../common/types.h"

// Agent R46m_10 (2026-10-23): FUN_00265740 (60 bytes), SLPM_666.75.
// p = FUN_00257770(); FUN_00139d78(p); returns 1 when the word at p+388 equals 0x8d, else 0.
// Both calls are one asm block with explicit nop/move delay slots, so gcc keeps the s0 save in
// the prologue instead of moving it into a jal delay slot. p is kept in $16 (s0).
u32 r_FUN_00265740(void) asm("func_00265740");

u32 r_FUN_00265740(void) {
    register u8* p asm("$16");
    asm volatile(
        ".set noreorder\n\t"
        "jal func_00257770\n\t"
        " nop\n\t"
        "move $16,$2\n\t"
        "jal func_00139d78\n\t"
        " move $4,$2\n\t"
        ".set reorder"
        : "=r"(p)
        :
        : "$1", "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
          "$24", "$25", "$31", "memory");
    return *(u32*)(p + 388) == 0x8du;
}
