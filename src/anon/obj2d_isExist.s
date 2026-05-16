.set push
.set at
.set noreorder
.set nomacro
.set mips0
.set hardfloat
.set fp=32
.set oddspreg
.text
.globl func_00139768
.globl _ZN2dk5Obj2D7isExistEPS0_
.type func_00139768, @function
.type _ZN2dk5Obj2D7isExistEPS0_, @function
.ent func_00139768
func_00139768:
_ZN2dk5Obj2D7isExistEPS0_:
    addiu $29, $29, -32
    sd $16, 0($29)
    sd $17, 8($29)
    sd $31, 16($29)
    move $16, $0
    lui $17, 0x34
L00139780:
    bnez $16, L001397d0
    lw $4, 32640($17)
    lw $4, 4($4)
L0013978c:
    bnez $4, L001397a8
    move $16, $4
    ld $16, 0($29)
    ld $17, 8($29)
    ld $31, 16($29)
    jr $31
    addiu $29, $29, 32
L001397a8:
    lw $15, 12($4)
    andi $15, $15, 0x1
    bnez $15, L00139780
    nop
    lw $14, 0($4)
    lw $15, 20($14)
    jalr $15
    nop
    b L00139780
    nop
L001397d0:
    b L0013978c
    lw $4, 4($16)
.end func_00139768
.set pop
