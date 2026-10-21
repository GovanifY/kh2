#include "../common/types.h"

// Symbols used by these functions.
// D_0033cc18 is the vtable for the object built by FUN_001060b8 / FUN_001060e0. Taking its
// address (instead of a literal 0x33cc18) makes gcc emit a lui/addiu pair with HI16/LO16
// relocations, which matches the original code's lui 0x34 + addiu -13288 after linking.
extern u8 D_0033cc18;

// FUN_001058e8 (registered as getSaveRam) takes no arguments and returns a pointer to save
// data. The original code never sets a0 before these calls, so the calls below take no
// arguments.
void* func_001058e8(void);
// FUN_00102c80 (getFieldMod) takes no arguments and returns an object with a vtable.
u32 func_00102c80(void);
// FUN_00106108 is the shared tail: it takes the object pointer and finishes its setup.
void func_00106108(u32* a0);

// FUN_00106048 (108 bytes): a void function with no arguments and a 16-byte stack buffer.
// It fills the buffer with 0xFFFF through a mix of halfword and byte stores, then calls
// save-data getter FUN_001058e8 three times. Each return value gets one byte written at
// offsets 12, 13, 14. The buffer bytes change between calls. Then it calls FUN_00102c80 and
// makes a virtual call through the returned object's vtable slot 0 (the vtable pointer is
// at +0, the function pointer at +0 of the vtable). Guess: a save-data initializer that
// marks a table of slots, then runs an object's init method.
// The buffer stores are volatile so gcc keeps them. The memory-clobber asm at the top stops
// the prologue ra save from moving below the first store.
void func_00106048(void) {
    volatile u8 buf[16];
    u16 v = 0xFFFF;
    __asm__ volatile("" ::: "memory");
    *(volatile u16*)(buf + 8) = v;
    buf[0] = (u8)v;
    buf[1] = (u8)v;
    buf[2] = (u8)v;
    *(volatile u16*)(buf + 4) = v;
    *(volatile u16*)(buf + 6) = v;

    u8* p = (u8*)func_001058e8();
    p[12] = 15;
    buf[0] = 15;
    p = (u8*)func_001058e8();
    p[13] = 0;
    buf[1] = 0;
    p = (u8*)func_001058e8();
    p[14] = 0;
    buf[2] = 0;

    u32 o = func_00102c80();
    u32 vt = *(u32*)o;
    u32 fn = *(u32*)vt;
    ((void (*)(u32))fn)(o);
}

// FUN_001060b8 (40 bytes): sets the vtable word at a0+0 to D_0033cc18, stores a1 at +4 and
// a2 at +8, and tail-jumps to FUN_00106108(a0). Guess: constructor for a 3-word object.
// The pinned value t = &D_0033cc18 comes before the stack-pointer adjustment in the
// prologue. The memory-clobber asm after the stores keeps the epilogue ra restore after them.
void func_001060b8(u32* a0, u32 a1, u32 a2) {
    u32 t = (u32)&D_0033cc18;
    __asm__ volatile("" : "+r"(t));
    volatile u32* p = a0;
    p[0] = t;
    p[2] = a2;
    p[1] = a1;
    __asm__ volatile("" ::: "memory");
    func_00106108(a0);
}

// FUN_001060e0 (40 bytes): identical body to FUN_001060b8 (same vtable, same stores, same
// tail call). The original binary has two copies of this shape at 0x1060b8 and 0x1060e0.
void func_001060e0(u32* a0, u32 a1, u32 a2) {
    u32 t = (u32)&D_0033cc18;
    __asm__ volatile("" : "+r"(t));
    volatile u32* p = a0;
    p[0] = t;
    p[2] = a2;
    p[1] = a1;
    __asm__ volatile("" ::: "memory");
    func_00106108(a0);
}
