#include "../common/types.h"

// Batch R46h_b: three small functions from SLPM_666.75 (lay36 lines 3000-3399).

extern u8 D_00360000;

extern "C" u32 func_00257130(void);
extern "C" u32 func_00281198(u32, u32);
extern "C" void func_00282240(u32, u32, u32);
extern "C" u32 func_002827f0(u32, u32, u32);

// FUN_00261ce8 (92 bytes)
// Code: frame of 16 bytes. r = FUN_00281198(*(D_00360000 - 4080), arg0). s0 = r + 5.
// FUN_00257130(). FUN_00282240(v0, s0, 0). u = FUN_00257130(). Tail-calls FUN_002827f0(u, 0, 0).
// Matching: plain C puts the s0 save into the delay slot of the first call, so the whole body is
// one noreorder asm block with no C locals (same shape as the R46e_a asm bodies).
void r_FUN_00261ce8(void) asm("func_00261ce8");

void r_FUN_00261ce8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x36\n\t"
        "daddu $5,$4,$0\n\t"
        "sd $31,8($29)\n\t"
        "lw $4,-4080($15)\n\t"
        "sd $16,0($29)\n\t"
        "jal func_00281198\n\t"
        " nop\n\t"
        "jal func_00257130\n\t"
        " addiu $16,$2,5\n\t"
        "daddu $5,$16,$0\n\t"
        "daddu $4,$2,$0\n\t"
        "jal func_00282240\n\t"
        " daddu $6,$0,$0\n\t"
        "jal func_00257130\n\t"
        " nop\n\t"
        "ld $16,0($29)\n\t"
        "daddu $4,$2,$0\n\t"
        "ld $31,8($29)\n\t"
        "daddu $5,$0,$0\n\t"
        "daddu $6,$0,$0\n\t"
        "j func_002827f0\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

extern "C" u32 func_00256b68(u32);
extern "C" u32 func_00139d78(u32);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028be58(u32);

// FUN_00262290 (108 bytes)
// Code: r = FUN_00139d78(FUN_00256b68(1)). If r != 0, return r.
// If *(D_00360000 - 4068) != 0, r = (FUN_0028acc8(that) != 0). If r != 0, return r.
// If *(D_00360000 - 4020) != 0, r = (FUN_0028be58(that) != 0). Return r.
u32 func_00262290(void) {
    u32 r = func_00139d78(func_00256b68(1));
    if (r != 0) {
        return r;
    }
    u32 g1 = *(u32*)((u8*)&D_00360000 - 4068);
    if (g1 != 0) {
        r = (func_0028acc8(g1) != 0);
    }
    if (r != 0) {
        return r;
    }
    u32 g2 = *(u32*)((u8*)&D_00360000 - 4020);
    if (g2 != 0) {
        r = (func_0028be58(g2) != 0);
    }
    return r;
}

extern "C" u32 func_00257770(void);
extern "C" u32 func_0028da70(u32, u32);

// FUN_00262f58 (68 bytes)
// Code: frame of 16 bytes. p = FUN_00257770(). FUN_0028da70(p, 297).
// Tail-calls FUN_0028da70(p + 0xb350, 306).
// Matching: same as FUN_00261ce8, the s0 save has to stay ahead of the first call, so asm body.
void r_FUN_00262f58(void) asm("func_00262f58");

void r_FUN_00262f58(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,8($29)\n\t"
        "sd $16,0($29)\n\t"
        "jal func_00257770\n\t"
        " nop\n\t"
        "daddu $16,$2,$0\n\t"
        "daddu $4,$2,$0\n\t"
        "jal func_0028da70\n\t"
        " addiu $5,$0,297\n\t"
        "ori $15,$0,0xb350\n\t"
        "ld $31,8($29)\n\t"
        "addu $16,$16,$15\n\t"
        "addiu $5,$0,306\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $16,0($29)\n\t"
        "j func_0028da70\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
