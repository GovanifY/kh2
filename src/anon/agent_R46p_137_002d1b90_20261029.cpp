#include "../common/types.h"

// Agent R46p_137 (2026-10-29): FUN_002d1b90 (104 bytes), SLPM_666.75.
// Builds two 4-float vectors on the stack from three float constants at 0x3759e4, 0x3759e8,
// 0x3759ec: A = {c0, c1, 0, 0} and B = {c0, c2, 0, 0}, then calls FUN_002d1bf8(a0, a1, B, A).
// The callee has no func_ row, so it is called by numeric jal.
extern "C" void call_002d1bf8(void*, void*, f32*, f32*) asm("0x2d1bf8");
extern u8 D_00370000;
#define BAR() __asm__ volatile("" ::: "memory")

void func_002d1b90(void* a0, void* a1) {
    f32 A[4];
    f32 B[4];
    register f32 z asm("$f2") = 0.0f;
    u32 pa;
    asm volatile("lui %0,%%hi(D_00370000+23012)" : "=r"(pa));
    asm volatile("addiu %0,%0,%%lo(D_00370000+23012)" : "+r"(pa));
    B[3] = z; BAR();
    register f32 ca asm("$f3");
    ca = *(f32*)pa;
    register f32* pB asm("$6") = B;
    asm volatile("" : "+r"(pB));
    A[2] = z; BAR();
    register f32* pA asm("$7") = A;
    asm volatile("" : "+r"(pA));
    u32 pb;
    asm volatile("lui %0,%%hi(D_00370000+23016)" : "=r"(pb));
    B[0] = ca; BAR();
    asm volatile("addiu %0,%0,%%lo(D_00370000+23016)" : "+r"(pb));
    A[0] = ca; BAR();
    register f32 cb asm("$f0");
    cb = *(f32*)pb;
    A[3] = z; BAR();
    u32 pc;
    asm volatile("lui %0,%%hi(D_00370000+23020)" : "=r"(pc));
    A[1] = cb; BAR();
    asm volatile("addiu %0,%0,%%lo(D_00370000+23020)" : "+r"(pc));
    B[2] = z; BAR();
    register f32 cc asm("$f1");
    cc = *(f32*)pc;
    B[1] = cc;
    call_002d1bf8(a0, a1, pB, pA);
}
