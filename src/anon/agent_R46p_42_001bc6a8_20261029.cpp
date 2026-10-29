
// Agent R46p_42 (2026-10-29): FUN_001bc6a8 (84 bytes), SLPM_666.75.
// Code: copies a halfword from *a1 into a0+2, stores t0 at a0+4, then calls FUN_001bc2a8(a1, a2, a3)
// (the arguments shifted down), and stores a3 at +8, the result byte at +5 and clears the halfword at +0.
// Whole-body asm: the jal delay slot holds the move a2,a3, which plain C does not keep in that slot.
// Frame of 32 bytes; s0, s1 and ra are saved at 0, 8 and 16. The size is not a multiple of 8, so the
// object needs -falign-functions=1.

void func_001bc6a8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "daddu $17,$7,$0\n\t"
        "lhu $15,0($5)\n\t"
        "sh $15,2($4)\n\t"
        "sb $8,4($16)\n\t"
        "daddu $4,$5,$0\n\t"
        "daddu $5,$6,$0\n\t"
        "jal 0x1bc2a8\n\t"
        " daddu $6,$7,$0\n\t"
        "sw $17,8($16)\n\t"
        "sb $2,5($16)\n\t"
        "sh $0,0($16)\n\t"
        "ld $17,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
