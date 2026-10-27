typedef unsigned int u32;
typedef int s32;

extern "C" s32 func_001a4550(u32 a0, u32 a1);

extern "C" void func_0018f858(u32 a0);
void func_0018f858(u32 a0) {
    u32 *s0 = (u32 *)a0;
    __asm__ __volatile__("" : "+r"(s0));
    u32 a1 = s0[1];
    s32 r = func_001a4550(*(u32 *)a0, a1);
    s0[0] = (u32)r;
}
