#include "../common/types.h"

// Batch R46h_c (2026-10-23): three candidates from lay36 lines 3400-3799.
// Guesses are unverified.

extern u8 D_00360000[];
extern u8 D_00370000[];

extern "C" int func_00287bc0(void*) asm("_ZN2Tz8MenuBase7GetModeEv");
void func_00276c50(void*, u32);
void func_002a5df0(void);
void func_002a65d0(void);
void func_0028be78(u32, u32);

// FUN_002a1f40 (64 bytes)
// Code: r = GetMode(arg0). Picks a global object pointer at 0x374b44 when r == 6,
// else the one at 0x374b48, then tail-calls DrawMessage(obj, 0).
// Guess: picks a message-box object by mode and draws a message.
void func_002a1f40(void* a0) {
    int r = func_00287bc0(a0);
    void* obj;
    if (r == 6) {
        obj = *(void**)(D_00370000 + 19268);
    } else {
        obj = *(void**)(D_00370000 + 19272);
    }
    func_00276c50(obj, 0);
}

// FUN_002a4990 (104 bytes)
// Code: when arg0 is negative, it is replaced by a value from the record at p
// (4228 + 4232/8). Then walks 15 byte-count records (stride 8, starting at p+4097),
// returning the index of the first record whose running sum exceeds arg0.
// Guess: maps a time or position to a segment index.
int func_002a4990(int a0) {
    u8* p1;
    if (a0 < 0) {
        p1 = *(u8**)((u8*)D_00360000 - 2588);
        s32 t = *(s32*)(p1 + 4232);
        a0 = *(s32*)(p1 + 4228) + (t / 8);
    }
    asm volatile("" ::: "memory");
    u8* p = *(u8**)((u8*)D_00360000 - 2588);
    u8* t6 = p + 4097;
    s32 sum = 0;
    s32 v0;
    for (v0 = 0; v0 < 15; v0++) {
        u8 c = *t6;
        t6 += 8;
        if (c != 0) {
            sum += c;
            if (a0 < sum) {
                return v0;
            }
        }
    }
    return v0;
}

// FUN_002a6308 (92 bytes)
// Code: dispatches on arg1: 37 calls 0x2a5df0 then tail-calls 0x2a65d0. 38 calls
// GetSelectTop on a global, then tail-calls 0x28be78 with a second global and the
// result. Otherwise returns.
// Written as one noreorder asm body: gcc 3.2 lays out the 38 block before the
// default return and the 37 block out of line, which plain C did not reproduce.
void func_002a6308(int a0, int a1) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "li $15,37\n\t"
        "sd $31,0($29)\n\t"
        "beq $5,$15,1f\n\t"
        "li $15,38\n\t"
        "beq $5,$15,2f\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        "2:\n\t"
        "lui $15,0x36\n\t"
        "jal _ZN2Tz6Select12GetSelectTopEv\n\t"
        "lw $4,-3584($15)\n\t"
        "lui $15,0x36\n\t"
        "ld $31,0($29)\n\t"
        "lw $4,-3564($15)\n\t"
        "move $5,$2\n\t"
        "j _Z13func_0028be78jj\n\t"
        "addiu $29,$29,16\n\t"
        "1:\n\t"
        "jal _Z13func_002a5df0v\n\t"
        "nop\n\t"
        "ld $31,0($29)\n\t"
        "j _Z13func_002a65d0v\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder\n\t"
        : : "r"(a0), "r"(a1) : "memory");
}
