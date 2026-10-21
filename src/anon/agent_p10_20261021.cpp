#include "../common/types.h"

// Callees. func_0016bd60 is the YS::OBJ::change_action entry point. func_00112720 is a
// one-argument predicate that the function at 0x0010fea0 calls before the table compare.
extern "C" void func_0016bd60(u32 a0, u32 a1);
extern "C" u32 func_00112720(void* a0);

// FUN_0010f960 (64 bytes, MATCHED): if the type word at ((a0+12)->+4) is 31, tail-calls
// func_0016bd60(a0, 32). Otherwise sets bit 0x4000 in the flag word at a0+0xb7c. The
// compiled output is instruction-for-instruction the original (the call target is a reloc).
void func_0010f960(u8* a0) {
    u32 t7 = *(u32*)(a0 + 12);
    if (*(u32*)(t7 + 4) == 31) {
        func_0016bd60((u32)a0, 32);
        return;
    }
    u32 w = *(u32*)(a0 + 0xb7c);
    w |= 0x4000;
    *(u32*)(a0 + 0xb7c) = w;
}

// FUN_0010fea0 (100 bytes, MATCHED with -falign-functions=1 for this object): returns 0 if
// func_00112720(a0) is non-zero. Otherwise it reads v0 = a0->+3156 and compares it with the
// words at +3160 and +3164 (two iterations, do-while form). It returns v0 if both match,
// else 0. The do-while puts v0 on the left of the compare so the bne operand order matches.
u32 func_0010fea0(u8* a0) {
    if (func_00112720(a0) != 0) return 0;
    u32 v0 = *(u32*)(a0 + 3156);
    u32* p = (u32*)(a0 + 3160);
    s32 t6 = 1;
    do {
        if (v0 != *p) return 0;
        p++;
        t6++;
    } while (t6 < 3);
    return v0;
}

// FUN_0010f9f0 (52 bytes): NOT MATCHED, not registered, not compiled (#if 0).
// Intent: if (a0+0xc00) != a1, copy 16 bytes from a1 to a0+0xc00 (lq/sq through t0). Then
// set bit 0x80 in a0->+0xb7c when (a2 & 0xff) != 0, else clear it. The best candidate has the
// same control flow and delay slots, but gcc puts the flag word in t6 and the -129 mask in
// t7 (the original uses t7 for the flag word and t6 for the mask). Pinning the registers
// (register ... asm("$15") / asm("$14")) moved the copy into t5 or hoisted the mask.
#if 0
typedef int u128 __attribute__((mode(TI)));
void func_0010f9f0(u8* a0, u8* a1, u32 a2) {
    u8* dst = a0 + 0xc00;
    asm volatile("" : "+r"(dst));
    if (dst != a1) {
        register u128 v asm("$8") = *(u128*)a1;
        *(u128*)dst = v;
    }
    u32 w = *(u32*)(a0 + 0xb7c);
    if ((a2 & 0xff) != 0) {
        w |= 0x80;
    } else {
        asm volatile("" ::: "memory");
        w &= 0xffffff7fu;
    }
    *(u32*)(a0 + 0xb7c) = w;
}
#endif
