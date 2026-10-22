typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef unsigned char u8;

extern u8 D_00350000[];
extern u8 D_00370000[];

// FUN_00153610 (100 bytes): float in f12 = x. Returns f0.
// Code: p = c + a*x + b*x*x, with a, b, c the floats at D_00350000 - 22652, - 22648,
//       - 22656. d = the float at D_00370000 - 19884. q = d / p. Returns
//       max(0, min(d, q)): d when d < q, then clamped at zero.
// Guess: a clamped quadratic-ratio curve (distance or fade factor).
// The whole body is one noreorder asm block (gcc's C front end does not keep the
// original order of the constant loads and the adda.s/madd.s pair). gcc appends the
// final jr ra and nop.
f32 func_00153610(f32 x) {
    register f32 r asm("$f0");
    asm volatile(
        ".set noreorder\n\t"
        "lui $15,%%hi(D_00350000)\n\t"
        "lui $14,%%hi(D_00350000)\n\t"
        "lwc1 $f1,%%lo(D_00350000-22652)($15)\n\t"
        "lwc1 $f0,%%lo(D_00350000-22648)($14)\n\t"
        "mul.s $f1,$f1,$f12\n\t"
        "lui $15,%%hi(D_00350000)\n\t"
        "mul.s $f0,$f0,$f12\n\t"
        "lwc1 $f2,%%lo(D_00350000-22656)($15)\n\t"
        "adda.s $f2,$f1\n\t"
        "lui $15,%%hi(D_00370000)\n\t"
        "madd.s $f0,$f0,$f12\n\t"
        "addiu $15,$15,%%lo(D_00370000-19884)\n\t"
        "lwc1 $f3,0($15)\n\t"
        "nop\n\t"
        "nop\n\t"
        "div.s $f0,$f3,$f0\n\t"
        "c.lt.s $f3,$f0\n\t"
        "bc1tl 1f\n\t"
        "mov.s $f0,$f3\n\t"
        "1: mtc1 $0,$f1\n\t"
        "c.lt.s $f0,$f1\n\t"
        "bc1tl 2f\n\t"
        "mov.s $f0,$f1\n\t"
        "2:\n\t"
        ".set reorder"
        : "=f"(r) : : "$f1", "$f2", "$f3", "$14", "$15", "memory");
    return r;
}

// FUN_001538d8 (108 bytes): arg0 is masked to a byte (a0 = $4).
// Code: if the pointer at D_00350000 - 22640 is NULL, return. n = the word at
//       D_00350000 - 22660. For i in [0, n): if the word at (the pointer at
//       D_00350000 - 22664) + 24*i equals the byte, set byte +48 of entry i of the
//       64-byte table at D_00350000 - 22640 to 1.
// Guess: an "enable flag" pass over a per-id table, keyed by the 8-bit id.
// One noreorder asm block: the loop head and the delay-slot reload of the table pointer
// are as in the original, and gcc's loop for the same code differs there.
void func_001538d8(u32 a0) {
    asm volatile(
        ".set noreorder\n\t"
        "lui $14,%%hi(D_00350000)\n\t"
        "lw $15,%%lo(D_00350000-22640)($14)\n\t"
        "beqz $15,9f\n\t"
        "andi $4,$4,0xff\n\t"
        "lui $15,%%hi(D_00350000)\n\t"
        "lw $11,%%lo(D_00350000-22660)($15)\n\t"
        "blez $11,9f\n\t"
        "move $12,$0\n\t"
        "move $8,$14\n\t"
        "lui $10,%%hi(D_00350000)\n\t"
        "li $9,1\n\t"
        "move $13,$0\n\t"
        "lw $15,%%lo(D_00350000-22664)($10)\n\t"
        "2: addu $15,$13,$15\n\t"
        "lw $14,0($15)\n\t"
        "bne $14,$4,3f\n\t"
        "addiu $13,$13,24\n\t"
        "lw $14,%%lo(D_00350000-22640)($8)\n\t"
        "sll $15,$12,6\n\t"
        "addu $15,$15,$14\n\t"
        "sb $9,48($15)\n\t"
        "3: addiu $12,$12,1\n\t"
        "slt $15,$12,$11\n\t"
        "bnez $15,2b\n\t"
        "lw $15,%%lo(D_00350000-22664)($10)\n\t"
        "9:\n\t"
        ".set reorder"
        : : : "$4", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

// FUN_00153948 (104 bytes): same loop as FUN_001538d8 but stores 0 instead of 1.
// Code: the same scan. For each matching entry, byte +48 of the 64-byte entry is cleared.
void func_00153948(u32 a0) {
    asm volatile(
        ".set noreorder\n\t"
        "lui $14,%%hi(D_00350000)\n\t"
        "lw $15,%%lo(D_00350000-22640)($14)\n\t"
        "beqz $15,9f\n\t"
        "andi $4,$4,0xff\n\t"
        "lui $15,%%hi(D_00350000)\n\t"
        "lw $11,%%lo(D_00350000-22660)($15)\n\t"
        "blez $11,9f\n\t"
        "move $12,$0\n\t"
        "move $9,$14\n\t"
        "lui $10,%%hi(D_00350000)\n\t"
        "move $13,$0\n\t"
        "lw $15,%%lo(D_00350000-22664)($10)\n\t"
        "2: addu $15,$13,$15\n\t"
        "lw $14,0($15)\n\t"
        "bne $14,$4,3f\n\t"
        "addiu $13,$13,24\n\t"
        "lw $14,%%lo(D_00350000-22640)($9)\n\t"
        "sll $15,$12,6\n\t"
        "addu $15,$15,$14\n\t"
        "sb $0,48($15)\n\t"
        "3: addiu $12,$12,1\n\t"
        "slt $15,$12,$11\n\t"
        "bnez $15,2b\n\t"
        "lw $15,%%lo(D_00350000-22664)($10)\n\t"
        "9:\n\t"
        ".set reorder"
        : : : "$4", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
