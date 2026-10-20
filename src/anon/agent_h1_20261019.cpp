#include "../common/types.h"

extern u8 D_00340000;

// FUN_0010abc8 (36 bytes)
// Code: the word at 0x340ea8 is a cursor. Rounds arg0 up to a multiple of 4, adds it to the
//       cursor, and returns the cursor's old value.
// Guess: a 4-byte aligned bump allocator over a fixed region.
// Note: the global is reached as &D_00340000 + 3752, which gives lui/lw/sw with %hi/%lo
//       relocations. The register pin on the old value (t7) matches the original order.
u32 func_0010abc8(u32 size) {
    register u32 p asm("$15");
    u32* cur = (u32*)((u32)&D_00340000 + 3752u);
    p = *cur;
    *cur = p + ((size + 3) & ~3u);
    return p;
}

// FUN_0010f6f8 (76 bytes)
// Code: returns 0 if (a0->+2040 & 4). Otherwise p = a0->+1164; returns 0 if p is NULL.
//       Else returns (p->+384 < (int)((float)p->+388 * a1)). The +388 field is read as an
//       int and converted to float, and the product is truncated back to int.
// Guess: a range or threshold test on an object's state, with the float scaled by a1.
// Note: the final compare and select must stay as a branch (slt, bnez with li v0,1 in its
//       delay slot). GCC folds every plain C return form into slt, so this block is written
//       as a noreorder asm with c pinned to $14 and the result to $2 (v0).
s32 func_0010f6f8(u8* a0, f32 a1) {
    register s32 r asm("$2");
    register s32 c asm("$14");
    if (*(u32*)(a0 + 2040) & 4)
        return 0;
    u8* p = *(u8**)(a0 + 1164);
    if (!p)
        return 0;
    s32 scaled = (s32)((f32)*(s32*)(p + 388) * a1);
    c = *(s32*)(p + 384) < scaled;
    __asm__ volatile(
        ".set noreorder\n\t"
        "bnez %1,1f\n\t"
        "li %0,1\n\t"
        "move %0,$0\n"
        "1:\n\t"
        ".set reorder"
        : "=r"(r)
        : "r"(c));
    return r;
}

// FUN_0011eea8 (76 bytes)
// Code: a0 = list. Head pointer at +8, next pointer at +4 of each node. If the head is a1,
//       sets the head to a1->next. Otherwise walks from the head until it reaches a1 or NULL,
//       then sets prev->next = a1->next.
// Guess: unlink a node from a singly linked list.
// Note: prev is pinned to t5, cur to t6, and the loaded next pointer to t7. The loop loads the
//       next pointer before it moves prev, which gives the original's bnel/beqz delay slots.
void func_0011eea8(u8* a0, u8* a1) {
    register u8* head asm("$15");
    register u8* prev asm("$13");
    register u8* cur asm("$14");
    register u8* nxt asm("$15");
    head = *(u8**)(a0 + 8);
    if (head == a1) {
        *(u8**)(a0 + 8) = *(u8**)(a1 + 4);
        return;
    }
    prev = head;
    cur = *(u8**)(head + 4);
    if (cur && cur != a1) {
        for (;;) {
            nxt = *(u8**)(cur + 4);
            prev = cur;
            if (!nxt)
                break;
            cur = nxt;
            if (nxt == a1)
                break;
        }
    }
    *(u8**)(prev + 4) = *(u8**)(a1 + 4);
}
