// Retry candidates (agent R46d_b). Both bodies are whole-function inline asm; the object needs -falign-functions=1.

// FUN_00136ab8 (68 bytes): zeroes words at 0x347d30..0x347d4f, then tail-calls FUN_00136a98.
extern "C" void func_00136a98(void);
void func_00136ab8(void) {
    asm volatile(
        ".set noreorder\n"
        "lui $15, 0x34\n"
        "addiu $29, $29, -16\n"
        "sw $0, 32048($15)\n"
        "addiu $14, $15, 32048\n"
        "addiu $13, $14, 16\n"
        "sd $31, 0($29)\n"
        "lui $15, 0x34\n"
        "sw $0, 8($13)\n"
        "sw $0, 32064($15)\n"
        "sw $0, 4($14)\n"
        "sw $0, 28($14)\n"
        "sw $0, 12($14)\n"
        "sw $0, 8($14)\n"
        "sw $0, 4($13)\n"
        "ld $31, 0($29)\n"
        "j func_00136a98\n"
        "addiu $29, $29, 16\n"
        ".set reorder\n"
        ::: "memory", "$13", "$14", "$15");
}

// FUN_00104d30 (108 bytes): copies bytes 0..2 of a1 to a0, idx = a1[0]*384 + a1[1]*6, copies three
// u16 from table 0x0032bb30 + idx + 16..20 to a0+4..8, then tail-calls FUN_00104cf0(a0+4, a1+4).
extern "C" void func_00104cf0(void);
void func_00104d30(unsigned char* a0, unsigned char* a1) {
    asm volatile(
        ".set noreorder\n"
        "addiu $29, $29, -16\n"
        "addiu $15, $0, 384\n"
        "sd $31, 0($29)\n"
        "daddu $13, $4, $0\n"
        "lbu $10, 0($5)\n"
        "lbu $9, 1($5)\n"
        "mult $10, $15\n"
        "lbu $11, 2($5)\n"
        "sb $10, 0($4)\n"
        "sb $11, 2($4)\n"
        "addiu $5, $5, 4\n"
        "sb $9, 1($4)\n"
        "addiu $15, $0, 6\n"
        "ld $31, 0($29)\n"
        "madd $14, $9, $15\n"
        "addiu $4, $4, 4\n"
        "lui $15, 0x33\n"
        "addiu $15, $15, -17616\n"
        "addu $14, $14, $15\n"
        "lhu $11, 20($14)\n"
        "lhu $15, 16($14)\n"
        "lhu $12, 18($14)\n"
        "sh $15, 4($13)\n"
        "sh $12, 6($13)\n"
        "sh $11, 8($13)\n"
        "j func_00104cf0\n"
        "addiu $29, $29, 16\n"
        ".set reorder\n"
        ::: "memory", "$4", "$5", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "hi", "lo");
}
