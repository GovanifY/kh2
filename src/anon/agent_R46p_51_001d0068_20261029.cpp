#include "../common/types.h"

// FUN_001d0068 (60 bytes).
// Code: sd ra then sd s0 before the first jal (plain C put the s0 store in the jal delay slot).
// p = YS::MEMBER::TABLE::Get() (mangled, 0x1d01e0). Calls YS::CACHE_BUFF::Clear(5000) (0x170320),
// then tail-calls wtarget_0016ed50(p, 5000, 7) at 0x16ed50 with a3 untouched.
void func_001d0068(void) __attribute__((noreturn));
void func_001d0068(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,8($29)\n\t"
        "sd $16,0($29)\n\t"
        "jal 0x1d01e0\n\t"
        "nop\n\t"
        "daddu $16,$2,$0\n\t"
        "jal 0x170320\n\t"
        "li $4,5000\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "li $5,5000\n\t"
        "li $6,7\n\t"
        "j 0x16ed50\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "memory");
}
