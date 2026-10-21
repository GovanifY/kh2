#include "../common/types.h"

// Callee: the function at 0x001391c8 (dk::Obj2D::create). Declared plainly, as the
// sibling files do.
extern "C" void func_001391c8(u32, u32, u32);

// FUN_00137c50 (56 bytes)
// Code: stores six words into the object at a0 (offsets 10696, 10688, 32, 48, 52,
// 10692) and then tail-calls func_001391c8(a0, 11100, 0).
// Layout (matched): the stores are in source order; a1 is set to 11100 and a2 to 0 at
// the same points the original sets them, through pinned registers $5/$6 and asm
// blocks, so the li/move and the ld ra land in the original slots. The volatile
// pointer keeps the stores in order. The memory barriers stop gcc from moving the
// stack reload of ra above the stores.
void func_00137c50(u32 a0) {
    volatile u32* p = (volatile u32*)a0;
    register u32 n asm("$5");
    register u32 z asm("$6");
    p[2674] = 0;
    asm volatile("" ::: "memory");
    p[2672] = 1;
    asm volatile("addiu $5,$0,11100" : "=r"(n) : : "memory");
    p[8] = 1;
    asm volatile("move $6,$0" : "=r"(z) : : "memory");
    p[12] = 0;
    asm volatile("" ::: "memory");
    p[13] = 0;
    asm volatile("" ::: "memory");
    p[2673] = 0;
    asm volatile("" ::: "memory");
    func_001391c8(a0, n, z);
}

// FUN_0013b9e0 (108 bytes)
// Code: calls func_0013ba50(a0). If that returns non-zero, the result is 0. Otherwise,
// if a1 == 0 the result is (word at +236 of a0 == 6). If a1 == 6 the result is
// (word at +236 == 0). Any other a1 gives 0.
// Layout: the C part saves s0 = a1 and s1 = a0 in $16/$17 around the call, which
// gcc turns into sd saves. The branch tail is one noreorder asm block in the
// original order, with the result in $13 (t5) so the epilogue loads interleave the
// same way. Pure C always produced xori/sltiu or branch-likely forms.
extern "C" u32 func_0013ba50(u32 a0);

u32 func_0013b9e0(u32 a0, u32 a1) {
    register u32 s0 asm("$16");
    register u32 s1 asm("$17");
    register u32 f asm("$2");
    register u32 t5 asm("$13");
    s0 = a1;
    f = func_0013ba50(a0);
    s1 = a0;
    asm volatile(
        ".set noreorder\n"
        "bnez $2, 1f\n"
        " move $13, $0\n"
        "bnez $16, 2f\n"
        " li $15, 6\n"
        "lw $14, 236($17)\n"
        "beq $14, $15, 1f\n"
        " li $13, 1\n"
        "li $15, 6\n"
        "2:\n"
        "bne $16, $15, 1f\n"
        " move $13, $0\n"
        "lw $15, 236($17)\n"
        "beqz $15, 1f\n"
        " li $13, 1\n"
        "move $13, $0\n"
        "1:\n"
        ".set reorder\n"
        : "+r"(t5) : "r"(s1), "r"(f), "r"(s0) : "$14", "$15", "memory");
    return t5;
}

// FUN_001375f0 (64 bytes)
// Code: f12 = the float at 0x0036ac9c. Calls func_001374c8(a0, 79, a1, a2, f12) and
// then stores zero at offset 1304 of a0. Frame of 16 bytes (ra, s0).
// Layout: the body is one noreorder asm block in the original order. The original
// interleaves the prologue saves with the argument moves and the lui/addiu pair,
// which gcc does not reproduce from C. The unused 16-byte local (u128t) and the
// trailing "=m" asm make gcc allocate that frame and emit the epilogue, so the
// asm block only has to do the saves, the body and the reloads. $16 and $31 are
// not listed as clobbers, so gcc does not add its own saves.
extern "C" void func_001374c8(u32 a0, u32 a1, u32 a2, u32 a3, f32 f12);

void func_001375f0(u32 a0, u32 a1, u32 a2) {
    typedef int u128t __attribute__((mode(TI)));
    u128t tmp;
    asm volatile(
        ".set noreorder\n"
        "lui $15, 0x37\n"
        "sd $16, 0($29)\n"
        "move $7, $6\n"
        "addiu $15, $15, -21348\n"
        "sd $31, 8($29)\n"
        "move $6, $5\n"
        "lwc1 $f12, 0($15)\n"
        "move $16, $4\n"
        "jal func_001374c8\n"
        " li $5, 79\n"
        "sw $0, 1304($16)\n"
        "ld $31, 8($29)\n"
        "ld $16, 0($29)\n"
        ".set reorder\n"
        : : : "$4","$5","$6","$7","$8","$9","$10","$11","$12","$13","$14","$15","$f12","memory");
    asm volatile("" : "=m"(tmp));
}
