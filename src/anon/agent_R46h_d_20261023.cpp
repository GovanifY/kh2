#include "../common/types.h"

// FUN_002db808 and FUN_002db858 (76 bytes each, identical bodies): calls FUN_002cfeb0(a0, a1, 3, a2),
// stores -1 at +2836 and the vtable 0x00362908 at +0, then calls FUN_002e7308(a0 + 2976).
extern "C" void func_002cfeb0(u8* a0, u8* a1, s32 a2, s32 a3);
extern "C" void func_002e7308(u8* a0);
extern u8 D_00362908[];

void func_002db808(u8* a0, u8* a1, s32 a2) {
    func_002cfeb0(a0, a1, 3, a2);
    *(s32*)(a0 + 2836) = -1;
    *(u32*)a0 = (u32)D_00362908;
    func_002e7308(a0 + 2976);
    __asm__ volatile("" ::: "memory");
}

void func_002db858(u8* a0, u8* a1, s32 a2) {
    func_002cfeb0(a0, a1, 3, a2);
    *(s32*)(a0 + 2836) = -1;
    *(u32*)a0 = (u32)D_00362908;
    func_002e7308(a0 + 2976);
    __asm__ volatile("" ::: "memory");
}

// FUN_002dc140 (108 bytes): if a0+2912 != a0+2848, copy 64 bytes from +2848 to +2912. If a1 != a0+2848,
// copy 64 bytes from a1 to +2848. Then tail-jumps to FUN_002d0bd8 (a0, a1 unchanged).
// Whole-body noreorder asm inside a noreturn C function (the tail jump ends it).
void func_002dc140(u8* a0, u8* a1) __attribute__((noreturn));
void func_002dc140(u8* a0, u8* a1) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "addiu\t$14,$4,2848\n\t"
        "addiu\t$15,$4,2912\n\t"
        "beq\t$15,$14,1f\n\t"
        "move\t$13,$5\n\t"
        "lq\t$8,0($14)\n\t"
        "lq\t$9,16($14)\n\t"
        "lq\t$10,32($14)\n\t"
        "lq\t$11,48($14)\n\t"
        "sq\t$8,0($15)\n\t"
        "sq\t$9,16($15)\n\t"
        "sq\t$10,32($15)\n\t"
        "sq\t$11,48($15)\n\t"
        "1:\n\t"
        "beq\t$14,$13,2f\n\t"
        "ld\t$31,0($29)\n\t"
        "lq\t$8,0($13)\n\t"
        "lq\t$9,16($13)\n\t"
        "lq\t$10,32($13)\n\t"
        "lq\t$11,48($13)\n\t"
        "sq\t$8,0($14)\n\t"
        "sq\t$9,16($14)\n\t"
        "sq\t$10,32($14)\n\t"
        "sq\t$11,48($14)\n\t"
        "ld\t$31,0($29)\n\t"
        "2:\n\t"
        "j\t0x2d0bd8\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        : : : "memory");
}
