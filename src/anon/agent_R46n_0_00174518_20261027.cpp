typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern "C" s32 func_00184780(u32 a0, f32 f12, f32 f13, f32 f14);

extern "C" void func_00174518(u32 a0);
void func_00174518(u32 a0) {
    u32 *s0 = (u32 *)a0;
    __asm__ __volatile__("" : "+r"(s0));
    register u32 a1 asm("$5") = *(u32 *)(a0 + 4);
    __asm__ __volatile__("" : "+r"(a1));
    register u32 t7 asm("$15") = *(u32 *)(a0 + 0);
    __asm__ __volatile__("" : "+r"(t7));
    register f32 f13 asm("$f13") = *(f32 *)(a0 + 8);
    __asm__ __volatile__("" : "+f"(f13));
    register f32 f14 asm("$f14") = *(f32 *)((u32)s0 + 12);
    __asm__ __volatile__("" : "+f"(f14));
    u32 ar = *(u32 *)(t7 + 4);
    __asm__ __volatile__("" : "+r"(ar));
    s32 r = func_00184780(ar, *(f32 *)(a1 + 12), f13, f14);
    s0[0] = (u32)r;
}
