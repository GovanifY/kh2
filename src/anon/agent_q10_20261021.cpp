#include "../common/types.h"

// Callees. func_00114738 is kn::AbilityInfo::item2index(int); it is reached only by its address.
extern "C" s32 func_00114738(s32 a0);

// Table of 7 s16 keys at 0x00345d30. Read by FUN_001145b0.
extern s16 D_00345d30[];

// FUN_001145b0 (76 bytes, MATCHED with -falign-functions=1 for this object): scans the seven s16
// entries at D_00345d30 for a0. Returns the index of the first match. If none matches, returns
// func_00114738(a0) + 7. The loop is written with the index as the return value so GCC keeps the
// original v0 = i move in the loop head, and the test is a bne/beq on the sign-extended s16.
s32 func_001145b0(s32 a0) {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (D_00345d30[i] == a0) return i;
    }
    return func_00114738(a0) + 7;
}

// ---------------------------------------------------------------------------------------------
// The two functions below are NOT matched and are not compiled (#if 0). They are not registered.
// ---------------------------------------------------------------------------------------------
#if 0
// FUN_00104d30 (108 bytes): NOT MATCHED. Shape: copies bytes 0..2 of a1 to a0, computes
// idx = a1[0]*384 + a1[1]*6 (mult/madd), copies three u16 from the table at 0x0032bb30+idx+16..20
// to a0+4..8, then tail-calls func_00104cf0(a0+4, a1+4). The frame, register picks (t5 = saved
// a0, t2/t1/t3 = a1[0..2]) and the mult/madd form all match when the function is written with
// pins. The remaining diff is instruction scheduling: GCC hoists the lbu loads above the
// prologue, and the original keeps "li t7,384" before "sd ra". Scheduling flags did not help.
// A whole-function asm body reproduces every instruction, but gcc appends "jr ra; nop" after the
// final j because the asm falls through, so it cannot be byte-exact.
extern u8 D_0032bb30[];
void func_00104cf0(u16* a0, u16* a1);
void func_00104d30(u8* a0, u8* a1) {
    register u8* t5 asm("$13") = a0;
    register u32 t2 asm("$10");
    register u32 t1 asm("$9");
    register u32 t3 asm("$11");
    t2 = a1[0];
    t1 = a1[1];
    t3 = a1[2];
    u32 idx = t2 * 384 + t1 * 6;
    t5[0] = (u8)t2;
    t5[2] = (u8)t3;
    a1 += 4;
    t5[1] = (u8)t1;
    u8* t = D_0032bb30 + idx;
    u16 v0 = *(u16*)(t + 16);
    u16 v1 = *(u16*)(t + 18);
    u16 v2 = *(u16*)(t + 20);
    *(u16*)(t5 + 4) = v0;
    *(u16*)(t5 + 6) = v1;
    *(u16*)(t5 + 8) = v2;
    a0 = t5 + 4;
    func_00104cf0((u16*)a0, (u16*)a1);
}

// FUN_001182d0 (88 bytes): NOT MATCHED. Shape: loop calling func_0010cce0 (s0 = result, exit when
// it is zero), then func_0019c410(s0) and s1 += 1 when it returns zero, implemented with movz. The
// body instructions match exactly. The remaining diff is layout: the original branches with
// bnez to the body and places the return block (with its epilogue) directly after the test. GCC
// emits beqz to a return block at the end instead. Tried: goto forms, early return, do/while,
// -fno-reorder-blocks, -O1/-O3, __builtin_expect; none changed the block order.
u32 func_001182d0(void) {
    u32 s0 = 0, s1 = 0;
    for (;;) {
        s0 = func_0010cce0(s0);
        if (s0 == 0) return s1;
        {
            u32 r = func_0019c410(s0);
            u32 t = s1 + 1;
            u32 s = s1;
            s = (r == 0) ? t : s;
            s1 = s;
        }
    }
}
#endif
