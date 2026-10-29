// Agent R46p_1 (2026-10-29): FUN_00176c68 (100 bytes). Plain C with pinned registers ($4 pointer, $f1/$f0 floats,
// $14 flags) and one sub.s asm so the result stays in $f1 (gcc otherwise writes $f0 and adds a mov.s).
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
extern u8 D_00350000[];
extern "C" void func_001dc840(void);
void func_00176c68(u8* a0) {
    u8* s = a0;
    __asm__ __volatile__("" : "+r"(s));
    register void* p asm("$4") = *(void**)(a0 + 2788);
    __asm__ __volatile__("" : "+r"(p));
    if (p == 0) {
        return;
    }
    register f32 x asm("$f1") = *(f32*)(s + 2792);
    register f32 y asm("$f0") = *(f32*)&D_00350000[-25072];
    __asm__ __volatile__("" : "+f"(x), "+f"(y));
    register u32 w asm("$14") = *(u32*)(s + 352);
    __asm__ __volatile__("" : "+r"(w));
    __asm__ __volatile__("sub.s %0,%0,%1" : "+f"(x) : "f"(y));
    *(f32*)(s + 2792) = x;
    if ((w & 0x4000) == 0 && !(x <= 0.0f)) {
        return;
    }
    func_001dc840();
    *(void**)(s + 2788) = 0;
}
