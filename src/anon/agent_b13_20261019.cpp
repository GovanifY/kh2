typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

// FUN_00237578 (52 bytes): v0 = rec[+12] - rec[+4], where rec = a0[+8] + 20 * (u16 table[a1*4 + a0[+12]] + a2).
// Register pins match the original: t7 = $15, t6 = $14 (constant 20), t5 = $13 (record), v0 = $2.
// Keep-alive asm inputs make gcc write the add into t5 and the sub into v0 (no extra move).
// The memory clobber keeps the original load order (t6 first, then v0).
u32 func_00237578(u32* a0, u32 a1, u32 a2) {
    register u32 t7 asm("$15");
    register u32 t6 asm("$14");
    register u32 t5 asm("$13");
    register u32 v0 asm("$2");
    t7 = *(u32*)((u8*)a0 + 12);
    a1 = a1 << 2;
    t6 = 20;
    t5 = *(u32*)((u8*)a0 + 8);
    a1 = a1 + t7;
    t7 = *(u16*)(a1 + 0);
    t7 = t7 + a2;
    t7 = t7 * t6;
    t5 = t5 + t7;
    asm volatile("" :: "r"(t7));
    asm volatile("" : "+r"(t5));
    t6 = *(u32*)(t5 + 4);
    asm volatile("" ::: "memory");
    v0 = *(u32*)(t5 + 12);
    v0 = v0 - t6;
    asm volatile("" :: "r"(t6));
    return v0;
}

// FUN_002375b0 (52 bytes): rec[+12] = rec[+4] + a3, same record addressing.
// Original reuses t7 for a0[12] first, then for the constant 20 after the u16 load (t6).
// The keep-alive on t7 stops the mult writing t7, and the keep-alive on t6 keeps the add in t5.
void func_002375b0(u32* a0, u32 a1, u32 a2, u32 a3) {
    register u32 t7 asm("$15");
    register u32 t6 asm("$14");
    register u32 t5 asm("$13");
    t7 = *(u32*)((u8*)a0 + 12);
    a1 = a1 << 2;
    t5 = *(u32*)((u8*)a0 + 8);
    a1 = a1 + t7;
    t6 = *(u16*)(a1 + 0);
    t7 = 20;
    t6 = t6 + a2;
    t6 = t6 * t7;
    asm volatile("" :: "r"(t7));
    t5 = t5 + t6;
    asm volatile("" :: "r"(t6));
    asm volatile("" : "+r"(t5));
    t7 = *(u32*)(t5 + 4);
    t7 = t7 + a3;
    *(u32*)(t5 + 12) = t7;
}

// FUN_00237640 (64 bytes): rec[+8] = rec[+0] + a3, rec[+12] = rec[+4] + a4.
// Same addressing as FUN_00237578; the keep-alive on t5 pins the record pointer.
void func_00237640(u32* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    register u32 t7 asm("$15");
    register u32 t6 asm("$14");
    register u32 t5 asm("$13");
    t7 = *(u32*)((u8*)a0 + 12);
    a1 = a1 << 2;
    t6 = 20;
    t5 = *(u32*)((u8*)a0 + 8);
    a1 = a1 + t7;
    t7 = *(u16*)(a1 + 0);
    t7 = t7 + a2;
    t7 = t7 * t6;
    t5 = t5 + t7;
    asm volatile("" :: "r"(t7));
    asm volatile("" : "+r"(t5));
    t6 = *(u32*)(t5 + 0);
    t7 = *(u32*)(t5 + 4);
    t6 = t6 + a3;
    t7 = t7 + a4;
    *(u32*)(t5 + 8) = t6;
    *(u32*)(t5 + 12) = t7;
}
