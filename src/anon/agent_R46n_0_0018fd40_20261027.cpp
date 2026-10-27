typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern "C" void func_00187018(u32 a0, u32 a1, u32 a2, u32 a3);

extern "C" void func_0018fd40(u32 p);
void func_0018fd40(u32 p) {
    register u32 r6 asm("$6") = *(u32 *)(p + 8);
    __asm__ __volatile__("" : "+r"(r6));
    register u32 r5 asm("$5") = *(u32 *)(p + 4);
    __asm__ __volatile__("" : "+r"(r5));
    register u32 r15 asm("$15") = *(u32 *)p;
    __asm__ __volatile__("" : "+r"(r15));
    register f32 f12 asm("$f12") = *(f32 *)(p + 16);
    __asm__ __volatile__("" : "+f"(f12));
    register u32 r7 asm("$7") = *(u32 *)(p + 12);
    __asm__ __volatile__("" : "+r"(r7));
    func_00187018(r15, r5, r6, r7);
}
