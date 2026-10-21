#include "../common/types.h"

// Callees. func_001666a0 takes one argument (the object pointer).
// func_001666f0 takes seven arguments (n32 ABI: a0..a3 in $4..$7, a4..a6 in $8..$10).
extern "C" u32 func_001666a0(u32 a0);
extern "C" u32 func_001666f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

// FUN_0014dc08 (60 bytes)
// Code: calls func_001666a0(a0), then clears the bytes at +464..+473 of the object:
// byte +473, word +464, halfword +468, bytes +470..+472. The store order is fixed
// (473 first, then 464, 468, 470, 471, 472).
// Matching shape: gcc cannot emit the restore order (ld ra before ld s0) from plain C,
// so the body is one noreorder asm block. gcc supplies the 16-byte frame through the
// unused u64 local `frame` and emits the jr/addiu epilogue itself.
void func_0014dc08(u32 a0) {
    u64 frame[2];
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "sd $16, 0($29)\n\t"          // save s0
        "sd $31, 8($29)\n\t"          // save ra
        "jal func_001666a0\n\t"       // call with a0 still in $4
        "move $16, $4\n\t"            // delay slot: keep the object pointer in s0
        "sb $0, 473($16)\n\t"
        "sw $0, 464($16)\n\t"
        "sh $0, 468($16)\n\t"
        "sb $0, 470($16)\n\t"
        "sb $0, 471($16)\n\t"
        "sb $0, 472($16)\n\t"
        "ld $31, 8($29)\n\t"          // restore ra first
        "ld $16, 0($29)\n\t"          // then s0
        ".set pop\n\t"
        : : "r"(a0) : "memory");
    __asm__ volatile("" : "=m"(frame));
}

// FUN_0014dc48 (96 bytes)
// Code: saves s0, s1, s2, ra in a 32-byte frame. Masks a1, a3 and a4 to 16 bits and passes
// them to func_001666f0 with the raw a0, a2, a5 and a6. The mask of a5 is kept in s1, a6 in s2.
// After the call it stores s2 (a6) at +464, s1 (u16 a5) at +468, then clears +473, +470, +471 and +472.
// Matching shape: same asm-body form as FUN_0014dc08. Only the restore order (s1, s0, s2, ra)
// is not reachable from C.
void func_0014dc48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    u64 frame[4];
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "andi $5, $5, 0xffff\n\t"     // a1 = (u16)a1
        "sd $16, 0($29)\n\t"
        "andi $7, $7, 0xffff\n\t"     // a3 = (u16)a3
        "sd $17, 8($29)\n\t"
        "andi $8, $8, 0xffff\n\t"     // a4 = (u16)a4
        "sd $18, 16($29)\n\t"
        "move $16, $4\n\t"            // s0 = a0
        "sd $31, 24($29)\n\t"
        "andi $17, $9, 0xffff\n\t"    // s1 = (u16)a5
        "jal func_001666f0\n\t"
        "move $18, $10\n\t"           // delay slot: s2 = a6
        "sw $18, 464($16)\n\t"
        "sh $17, 468($16)\n\t"
        "sb $0, 473($16)\n\t"
        "sb $0, 470($16)\n\t"
        "sb $0, 471($16)\n\t"
        "sb $0, 472($16)\n\t"
        "ld $17, 8($29)\n\t"
        "ld $16, 0($29)\n\t"
        "ld $18, 16($29)\n\t"
        "ld $31, 24($29)\n\t"
        ".set pop\n\t"
        : : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6) : "memory");
    __asm__ volatile("" : "=m"(frame));
}

// FUN_0014dca8 (96 bytes)
// Code: byte-identical copy of FUN_0014dc48 (same masks, call to func_001666f0, stores and frame).
// Kept as a separate function because it has its own address and registry row.
void func_0014dca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    u64 frame[4];
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "andi $5, $5, 0xffff\n\t"
        "sd $16, 0($29)\n\t"
        "andi $7, $7, 0xffff\n\t"
        "sd $17, 8($29)\n\t"
        "andi $8, $8, 0xffff\n\t"
        "sd $18, 16($29)\n\t"
        "move $16, $4\n\t"
        "sd $31, 24($29)\n\t"
        "andi $17, $9, 0xffff\n\t"
        "jal func_001666f0\n\t"
        "move $18, $10\n\t"
        "sw $18, 464($16)\n\t"
        "sh $17, 468($16)\n\t"
        "sb $0, 473($16)\n\t"
        "sb $0, 470($16)\n\t"
        "sb $0, 471($16)\n\t"
        "sb $0, 472($16)\n\t"
        "ld $17, 8($29)\n\t"
        "ld $16, 0($29)\n\t"
        "ld $18, 16($29)\n\t"
        "ld $31, 24($29)\n\t"
        ".set pop\n\t"
        : : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6) : "memory");
    __asm__ volatile("" : "=m"(frame));
}
