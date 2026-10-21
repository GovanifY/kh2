// Matching functions for kh2 (agent N13). Each comment records what the code does.
typedef unsigned int u32;
typedef unsigned char u8;

// FUN_001055b8 (104 bytes): restores gp/sp/fp/ra/s0..s7 and f20..f31 from a0, returns 1.
// Whole body is one asm block; a0 is pinned to $4 so no load uses a register it just loaded.
// The block emits exactly the original 24 loads, then gcc's own jr ra with li v0,1 in the slot.
u32 func_001055b8(u32 a0) {
    register u32 p asm("$4") = a0;
    asm volatile(
        "lq $28,0(%0)\n\t"
        "lq $29,16(%0)\n\t"
        "lq $30,32(%0)\n\t"
        "lq $31,48(%0)\n\t"
        "lq $16,64(%0)\n\t"
        "lq $17,80(%0)\n\t"
        "lq $18,96(%0)\n\t"
        "lq $19,112(%0)\n\t"
        "lq $20,128(%0)\n\t"
        "lq $21,144(%0)\n\t"
        "lq $22,160(%0)\n\t"
        "lq $23,176(%0)\n\t"
        "lwc1 $f20,192(%0)\n\t"
        "lwc1 $f21,196(%0)\n\t"
        "lwc1 $f22,200(%0)\n\t"
        "lwc1 $f23,204(%0)\n\t"
        "lwc1 $f24,208(%0)\n\t"
        "lwc1 $f25,212(%0)\n\t"
        "lwc1 $f26,216(%0)\n\t"
        "lwc1 $f27,220(%0)\n\t"
        "lwc1 $f28,224(%0)\n\t"
        "lwc1 $f29,228(%0)\n\t"
        "lwc1 $f30,232(%0)\n\t"
        "lwc1 $f31,236(%0)\n\t"
        :: "r"(p));
    return 1;
}
