#include "../common/types.h"

// FUN_0014ba20 and FUN_0014ba90 (108 bytes each). Body is one noreorder asm block inside a C
// function. gcc supplies the 16-byte frame through an unused u64 local with an empty "=m"
// asm; the asm does the saves, the jal, the ld ra, the constant setup and stores, and the
// s0 restore, in the original order. Only $11..$15, $2..$10, $24, $25 are clobbered, so gcc
// does not add callee-saved saves.
extern "C" void func_0014ba20(u32 a0);
extern "C" void func_0014ba90(u32 a0);

#define BA_BODY(GOFF)                                              \
    u64 frame[2];                                                  \
    register u32 arg asm("$4") = a0;                               \
    __asm__ volatile("" : "=m"(frame));                            \
    __asm__ volatile(                                              \
        ".set push\n"                                              \
        ".set noreorder\n"                                         \
        "sd $16, 0($29)\n"                                         \
        "sd $31, 8($29)\n"                                         \
        "jal func_0014b290\n"                                      \
        "move $16, $4\n"                                           \
        "lui $15, 0x37\n"                                          \
        "ld $31, 8($29)\n"                                         \
        "ld $11, " GOFF "($15)\n"                                  \
        "li $14, 1\n"                                              \
        "dsll32 $14, $14, 0x1c\n"                                  \
        "li $13, 14\n"                                             \
        "lui $15, 0x35\n"                                          \
        "sd $13, 264($16)\n"                                       \
        "ori $14, $14, 0x8001\n"                                   \
        "sd $11, 272($16)\n"                                       \
        "li $12, 64\n"                                             \
        "sd $14, 256($16)\n"                                       \
        "addiu $15, $15, -25176\n"                                 \
        "sd $12, 280($16)\n"                                       \
        "sw $15, 0($16)\n"                                         \
        "sd $14, 288($16)\n"                                       \
        "sd $13, 296($16)\n"                                       \
        "sd $11, 304($16)\n"                                       \
        "sd $12, 312($16)\n"                                       \
        "ld $16, 0($29)\n"                                         \
        ".set pop\n"                                               \
        : "+r"(arg), "=m"(frame)                                   \
        :                                                          \
        : "$11", "$12", "$13", "$14", "$15", "$2", "$3", "$5", "$6", \
          "$7", "$8", "$9", "$10", "$24", "$25", "memory")

// Original: lw/ld of the global at 0x00370000 - 20264.
void func_0014ba20(u32 a0) {
    BA_BODY("-20264");
}

// Original: same body, global at 0x00370000 - 20256.
void func_0014ba90(u32 a0) {
    BA_BODY("-20256");
}
