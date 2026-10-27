typedef unsigned int u32;
typedef int s32;

typedef void (*VFn2)(u32, u32);

extern "C" void func_0018f218(u32 a0);
void func_0018f218(u32 a0) {
    u32 t7 = *(u32 *)a0;
    u32 a1 = *(u32 *)(a0 + 4);
    u32 obj = *(u32 *)(t7 + 4);
    u32 t6 = *(u32 *)obj;
    VFn2 f = *(VFn2 *)(t6 + 104);
    f(obj, a1);
}
