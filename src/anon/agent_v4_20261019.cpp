#include "../common/types.h"

extern u8 D_00350000[];
extern u8 D_01d50000[];
extern u8 D_01d60000[];

// FUN_001ca448 (76 bytes; this object is built with -falign-functions=1 because the size is
//       not a multiple of 8, see the Makefile).
// Code: v = word at arg0 + 340. Returns 0 when v == 44 or v == 16, returns 1 for other
//       values below 45. For values above 45 it returns 1 unless v == 161. For 161 it
//       returns 1 when the word at arg0 + 1416 has bit 0x80 clear, else 0.
// Guess: a state test on an object type field (+340), with a flag bit (+1416) checked for
//       one type.
// Note: pinned registers (t6 value, t7 constant, t5 compare result) and the ret1/ret0 labels
//       keep the original branch layout: beq to the ret0 block with a nop slot, and the
//       ret1 block as jr + li in the delay slot.
u32 func_001ca448(u8* a0) {
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register s32 t5 asm("$13");

    t6 = *(u32*)(a0 + 340);
    t7 = 44;
    if (t6 == t7) {
        goto ret0;
    }
    t5 = ((s32)t6 < 45);
    if (t5 == 0) {
        goto check_161;
    }
    t7 = 16;
    if (t6 == t7) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
check_161:
    t7 = 161;
    if (t6 != t7) {
        goto ret1;
    }
    t7 = *(u32*)(a0 + 1416);
    t7 = t7 & 0x80;
    return t7 < 1;
}

// FUN_001cd520 (40 bytes).
// Code: copies 10 bytes from D_01d60000 - 22160 (an 8-byte block with an unaligned ldl/ldr
//       pair, then a halfword at +8) to arg0, and returns arg0.
// Guess: copies a fixed 10-byte header or record template into an object.
// Note: the load/store pairs and the lui/addiu of the source are one asm block with
//       %hi/%lo relocations for D_01d60000-22160, so the linker resolves the address.
void* func_001cd520(void* a0) {
    __asm__ volatile(
        "lui $15, %%hi(D_01d60000-22160)\n\t"
        "addiu $14, $15, %%lo(D_01d60000-22160)\n\t"
        "ldl $11, 7($14)\n\t"
        "ldr $11, 0($14)\n\t"
        "lh $12, 8($14)\n\t"
        "sdl $11, 7(%0)\n\t"
        "sdr $11, 0(%0)\n\t"
        "sh $12, 8(%0)\n\t"
        :
        : "r"(a0)
        : "$11", "$12", "$14", "$15", "memory");
    return a0;
}
