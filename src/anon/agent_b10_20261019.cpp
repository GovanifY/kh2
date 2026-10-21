#include "../common/types.h"

extern u8 D_00360000[];

// FUN_00222978 (36 bytes)
// Code: stores its float argument at sp+4, loads the 16-byte frame into VU0 vf10, takes
//       vsqrt of the y lane into Q, waits, and copies Q's bit pattern into $f0 through v0.
// Guess: scalar float square root through VU0.
// Note: the frame is a volatile 4-float local (16 bytes, so the prologue and epilogue match).
//       The VU sequence is one asm block that addresses the frame through $29 directly.
f32 func_00222978(f32 f) {
    volatile f32 buf[4];
    register f32 r asm("$f0");
    buf[1] = f;
    __asm__ volatile(
        "lqc2 $vf10,0($29)\n\t"
        "vsqrt Q,$vf10y\n\t"
        "vwaitq\n\t"
        "cfc2.ni $2,$22\n\t"
        "mtc1 $2,%0\n\t"
        : "=f"(r)
        :
        : "$2", "memory");
    return r;
}

// FUN_0022e330 (56 bytes)
// Code: reads the table pointer at D_00360000 - 8972 and scans 96 records of 52 bytes. Returns the
//       first record whose word at +4 equals a0, or 0 if none match.
// Guess: lookup of an object by its ID in a fixed table of 96 entries.
// Note: plain C; the loop shape and the bnezl back-branch with a delay-slot load come out of gcc
//       directly once the first load is hoisted into p.
u32 func_0022e330(u32 a0) {
    u8* p = *(u8**)&D_00360000[-8972];
    s32 i;
    for (i = 0; i < 96; i++) {
        if (*(u32*)(p + 4) == a0)
            return (u32)p;
        p += 52;
    }
    return 0;
}

// FUN_00234188 (96 bytes)
// Code: a ring buffer of 64 slots, 32 bytes each, at D_01dadc00. The head index is the word at
//       D_00360000 - 7328 and the serial counter is the word at D_00360000 - 7320. Writes the six
//       arguments a0..a5 into the slot at the head (state word = 3, serial at +4), advances the
//       head mod 64 and the serial, and returns the old serial.
// Guess: an event or message ring. Each entry is a state tag, a serial, and six payload words.
// Note: every register is pinned with an empty asm operand (register variables are only
//       honoured at asm operands in this gcc). The base is built as lui 0x01db0000 with the
//       addiu -9216 split around the serial load, and the pointer is formed by an addu asm
//       so it lands in the pinned register. The stores are ordered by empty memory barriers.
u32 func_00234188(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    register u32 hb asm("$10") = 0x00360000;
    register u32 cb asm("$3") = 0x00360000;
    __asm__ volatile("" : "+r"(hb), "+r"(cb));
    register s32 h asm("$14");
    register s32 c asm("$11");
    register s32 nh asm("$13");
    register s32 nc asm("$12");
    register s32 po asm("$14");
    register u8* gb asm("$15");
    h = *(s32*)(hb - 7328);
    __asm__ volatile("" : "+r"(h));
    gb = (u8*)0x01db0000;
    __asm__ volatile("" : "+r"(gb));
    c = *(s32*)(cb - 7320);
    __asm__ volatile("" : "+r"(c));
    gb = gb + (-9216);
    __asm__ volatile("" : "+r"(gb));
    nh = h + 1;
    __asm__ volatile("" : "+r"(nh));
    po = h << 5;
    __asm__ volatile("" : "+r"(po));
    nh &= 0x3f;
    __asm__ volatile("" : "+r"(nh));
    __asm__ volatile("addu %0,%0,%1" : "+r"(po) : "r"(gb));
    nc = c + 1;
    __asm__ volatile("" : "+r"(nc));
    struct Slot3 {
        s32 state;
        s32 serial;
        u32 a0, a1, a2, a3, a4, a5;
    };
    Slot3* p = (Slot3*)po;
    p->a5 = a5;
    __asm__ volatile("" ::: "memory");
    register s32 st asm("$15") = 3;
    __asm__ volatile("" : "+r"(st));
    register u32 rv asm("$2") = (u32)c;
    __asm__ volatile("" : "+r"(rv));
    *(s32*)(hb - 7328) = nh;
    *(s32*)(cb - 7320) = nc;
    __asm__ volatile("" ::: "memory");
    p->state = st;
    __asm__ volatile("" ::: "memory");
    p->a0 = a0;
    p->a1 = a1;
    p->a2 = a2;
    p->a3 = a3;
    p->a4 = a4;
    __asm__ volatile("" ::: "memory");
    p->serial = c;
    return rv;
}
