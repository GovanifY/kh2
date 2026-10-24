#include "../common/types.h"

// Agent R46m_10 (2026-10-23): FUN_0027d450 (56 bytes), SLPM_666.75.
// p = FUN_00257770(); FUN_00139d78(p); then tail-calls FUN_0028da70(p, 234).
extern "C" void func_0028da70(void*, u32) asm("func_0028da70");

void r_FUN_0027d450(void) asm("func_0027d450");

void r_FUN_0027d450(void) {
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
    func_0028da70((void*)p, 234u);
}
