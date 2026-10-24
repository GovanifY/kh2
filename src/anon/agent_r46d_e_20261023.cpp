#include "../common/types.h"

// Callees. func_<addr> names come from the linker script (one symbol per function address).
extern "C" u32 func_001666a0(u32 a0);
extern "C" u32 func_001666d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

extern "C" u32 func_0014db78(u8* a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern "C" u32 func_0014dbc8(u8* a0);

// FUN_0014db78 (80 bytes).
// Frame and epilogue are emitted by gcc (u64 frame[4] local, empty "=m" output). The body is a
// noreorder asm block: saves s0/s1/s2/ra, masks a1/a3/a4 and a5, calls FUN_001666d0, stores a6 and
// (u16)a5 into the object, then restores in the original order s2, s0, s1, ra.
u32 func_0014db78(u8* a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u64 frame[4];
    register u32 p0 asm("$4") = (u32)a0;
    register u32 p1 asm("$5") = a1;
    register u32 p3 asm("$7") = a3;
    register u32 p4 asm("$8") = a4;
    register u32 p5 asm("$9") = a5;
    register u32 p6 asm("$10") = a6;
    register u32 ret asm("$2");
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "andi $5,$5,0xffff\n"
        "sd $16,0($29)\n"
        "andi $7,$7,0xffff\n"
        "sd $17,8($29)\n"
        "andi $8,$8,0xffff\n"
        "sd $18,16($29)\n"
        "move $16,$4\n"
        "sd $31,24($29)\n"
        "andi $17,$9,0xffff\n"
        "jal func_001666d0\n"
        "move $18,$10\n"
        "sw $18,464($16)\n"
        "sh $17,468($16)\n"
        "ld $18,16($29)\n"
        "ld $16,0($29)\n"
        "ld $17,8($29)\n"
        "ld $31,24($29)\n"
        ".set pop\n"
        : "=r"(ret), "=m"(frame), "+r"(p1), "+r"(p3), "+r"(p4)
        : "r"(p0), "r"(p5), "r"(p6)
        : "$2", "$3", "$6", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
    return ret;
}

// FUN_0014dbc8 (60 bytes).
// Same pattern: gcc emits the 16-byte frame; the asm saves s0/ra, calls FUN_001666a0, clears the
// fields, then restores ra before s0 (the original order).
u32 func_0014dbc8(u8* a0) {
    u64 frame[2];
    register u32 arg asm("$4") = (u32)a0;
    register u32 ret asm("$2");
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "sd $16,0($29)\n"
        "sd $31,8($29)\n"
        "jal func_001666a0\n"
        "move $16,$4\n"
        "sb $0,473($16)\n"
        "sw $0,464($16)\n"
        "sh $0,468($16)\n"
        "sb $0,470($16)\n"
        "sb $0,471($16)\n"
        "sb $0,472($16)\n"
        "ld $31,8($29)\n"
        "ld $16,0($29)\n"
        ".set pop\n"
        : "=r"(ret), "=m"(frame)
        : "r"(arg)
        : "$2", "$3", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
    return ret;
}
