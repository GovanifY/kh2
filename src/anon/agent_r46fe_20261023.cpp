#include "../common/types.h"

// Retry R46f_e (2026-10-23): FUN_00105af8 (96 bytes) and FUN_00105de0 (104 bytes).
// Whole-body noreorder asm bodies, copied from the original disassembly with local labels.
// Literal lui/offset addresses match the original encodings exactly.

extern "C" u32 func_00103b38(void);      // FUN_00103b38 (MENU::isRunning), callee of FUN_00105de0
extern "C" void func_00102080(u32);      // FUN_00102080, tail-call target of FUN_00105de0

// FUN_00105af8 (96 bytes). Stores a0 at 0x33CAFC, table[a0-1] at 0x33CAF0, and then
// 0x33CAEC gets table[1] for a0 == 3, table[0] for a0 == 8, else the 0x33CAF0 value.
// table = 0x33CB00. Leaf, no frame.
void func_00105af8(u32 a0) __attribute__((noreturn));
void func_00105af8(u32 a0) {
    asm volatile(
        ".set\tnoreorder\n\t"
        "lui\t$11,0x34\n\t"
        "sll\t$15,$4,2\n\t"
        "addiu\t$12,$11,-13568\n\t"
        "lui\t$14,0x34\n\t"
        "addu\t$15,$15,$12\n\t"
        "sw\t$4,-13572($14)\n\t"
        "lw\t$13,-4($15)\n\t"
        "addiu\t$14,$0,3\n\t"
        "lui\t$15,0x34\n\t"
        "beq\t$4,$14,2f\n\t"
        "sw\t$13,-13584($15)\n\t"
        "addiu\t$15,$0,8\n\t"
        "beq\t$4,$15,3f\n\t"
        "lw\t$14,-13568($11)\n\t"
        "lui\t$15,0x34\n\t"
        "lui\t$14,0x34\n\t"
        "lw\t$13,-13584($15)\n\t"
        "jr\t$31\n\t"
        "sw\t$13,-13580($14)\n\t"
        "3:\n\t"
        "lui\t$15,0x34\n\t"
        "jr\t$31\n\t"
        "sw\t$14,-13580($15)\n\t"
        "2:\n\t"
        "b\t3b\n\t"
        "lw\t$14,4($12)\n\t"
        ".set\treorder\n\t"
        : : : "memory");
}

// FUN_00105de0 (104 bytes). r = FUN_00103b38(a0); if r != 0 return r (restoring s0).
// If word 0x32B984 != 2 and r == 0: store s0 at 0x33CBAC, byte 0x33CBB0 = 1, tail-call
// FUN_00102080(0x33CB80). Otherwise return 0 (through the shared epilogue).
void func_00105de0(u32 a0) __attribute__((noreturn));
void func_00105de0(u32 a0) {
    asm volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "jal\tfunc_00103b38\n\t"
        "move\t$16,$4\n\t"
        "bnezl\t$2,2f\n\t"
        "ld\t$16,0($29)\n\t"
        "lui\t$14,0x33\n\t"
        "lw\t$15,-18044($14)\n\t"
        "xori\t$15,$15,0x2\n\t"
        "beqzl\t$15,2f\n\t"
        "ld\t$16,0($29)\n\t"
        "lui\t$14,0x34\n\t"
        "ld\t$31,8($29)\n\t"
        "sw\t$16,-13396($14)\n\t"
        "addiu\t$13,$0,1\n\t"
        "lui\t$15,0x34\n\t"
        "lui\t$4,0x34\n\t"
        "sb\t$13,-13392($15)\n\t"
        "addiu\t$4,$4,-13440\n\t"
        "ld\t$16,0($29)\n\t"
        "j\tfunc_00102080\n\t"
        "addiu\t$29,$29,16\n\t"
        "2:\n\t"
        "ld\t$31,8($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "memory");
}
