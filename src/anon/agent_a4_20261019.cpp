#include "../common/types.h"

// FUN_00168b88 (96 bytes)
// Searches the 16-byte records that follow a 16-byte header in a0 (record count at +4).
// A record matches when its u16 key (at +16 of the record slot) equals a1 (a1 == -1 matches
// any key) and its u32 at +4 within that slot equals a2. Returns the slot+16 pointer of the
// (a3+1)-th match, or NULL. Written as one inline-asm block: a C version of the loop (goto
// and for-loop shapes, pinned registers, barriers) never produced the original's delay-slot
// layout (the shared address computation and the out-of-line key-match branch target).
// Registers: a0..a3 = $4..$7, count $11, index $12, byte offset $13, key/value $14, slot $15,
// constant -1 in $10, return value $2.
void* func_00168b88(u8* a0, s32 a1, s32 a2, s32 a3) {
    register u8* r4 asm("$4") = a0;
    register s32 r5 asm("$5") = a1;
    register s32 r6 asm("$6") = a2;
    register s32 r7 asm("$7") = a3;
    register void* ret asm("$2");
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "lw $11,4($4)\n\t"
        "blez $11,9f\n\t"
        "move $12,$0\n\t"
        "li $10,-1\n\t"
        "1:\n\t"
        "beq $5,$10,2f\n\t"
        "sll $13,$12,4\n\t"
        "addu $15,$13,$4\n\t"
        "lhu $14,16($15)\n\t"
        "bnel $14,$5,3f\n\t"
        "addiu $12,$12,1\n\t"
        "2:\n\t"
        "addu $15,$13,$4\n\t"
        "lw $14,20($15)\n\t"
        "bne $14,$6,4f\n\t"
        "addiu $2,$15,16\n\t"
        "addiu $7,$7,-1\n\t"
        "beq $7,$10,8f\n\t"
        "nop\n\t"
        "4:\n\t"
        "addiu $12,$12,1\n\t"
        "3:\n\t"
        "slt $15,$12,$11\n\t"
        "bnez $15,1b\n\t"
        "nop\n\t"
        "9:\n\t"
        "move $2,$0\n\t"
        "8:\n\t"
        ".set pop\n\t"
        : "=r"(ret)
        : "r"(r4), "r"(r5), "r"(r6), "r"(r7)
        : "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    return ret;
}

extern f32 D_0036c4cc;

// FUN_00178570 (72 bytes)
// Zeroes the 16-byte vector at a0+16 (VU0: vf1 = vf0 - vf0, then sqc2). Then, when the float
// at +2620 of the sub-object at a0+2884 is positive and the float at +2612 is negative, copies
// the float constant D_0036c4cc into a0+20. The empty asm barrier on the constant's address
// keeps GCC from folding the low half into the lwc1 offset (the original uses lui + addiu).
void func_00178570(u8* a0) {
    __asm__ volatile(
        "vsub.wxyz $vf1,$vf0,$vf0\n\t"
        "sqc2 $vf1,0(%0)\n\t"
        :
        : "r"(a0 + 16)
        : "memory");
    u8* t = *(u8**)(a0 + 2884);
    if (0.0f < *(f32*)(t + 2620) && *(f32*)(t + 2612) < 0.0f) {
        f32* g = &D_0036c4cc;
        __asm__("" : "+r"(g));
        *(f32*)(a0 + 20) = *g;
    }
}

// FUN_00182838 (40 bytes)
// Fills a 3-word header: word 0 = a1, word 1 = 1 (or 3 when the low byte of a3 is non-zero),
// word 2 = a2.
void func_00182838(s32* a0, s32 a1, s32 a2, s32 a3) {
    a0[0] = a1;
    a0[1] = 1;
    a0[2] = a2;
    if ((u8)a3)
        a0[1] = 3;
}
