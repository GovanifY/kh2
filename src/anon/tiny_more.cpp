#include "types.h"

extern u32 D_0032b9d8;
extern u32 D_0032bae0;
extern u32 D_00347d58;
extern u32 D_00347f80;
extern u32 D_003484a0;
extern u32 D_003485e8;
extern u32 D_003486a0;
extern u32 D_00348818;
extern u32 D_00349e00;
extern u32 D_0035037c;
extern u32 D_0035e298;
extern u32 D_0035e370;
extern u32 D_0035ec94;
extern u32 D_0035ecd8;
extern u32 D_0035f1fc;
extern u32 D_0035f5ac;
extern u32 D_00363c2c;

u32 func_00102f70(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v = D_0032b9d8; return v & 0x1u; }

f32 func_001070a8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(f32*)((u32)a0 + (108)); }

f32 func_0010f8a8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(f32*)((u32)a0 + (3284)); }

u32 func_0010f9e0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (3168)); v ^= a1; return (v < (u32)1); }

u32 func_00112730(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 old = *(u32*)((u32)a0 + (2940)); *(u32*)((u32)a0 + (2940)) = a1; return old; }

u32 func_00112760(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 old = *(u32*)((u32)a0 + (3316)); *(u32*)((u32)a0 + (3316)) = a1; return old; }

void func_00112c58(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (2940)); v |= (u32)0x40000000u; *(u32*)((u32)a0 + (2940)) = v; }

u32 func_00139538(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (12)); return v & 0x1u; }

extern "C" u32 func_0013a1d8(u32, u32, u32, u32) asm("_ZN2dk5Obj2D12GetAllocatorEv");

void func_0013b2b8(f32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_003484a0; *(f32*)((u32)p + (692)) = a0; }

void func_0013b2d8(f32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_003484a0; *(f32*)((u32)p + (688)) = a0; }

u32 func_00141970(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = *(u32*)((u32)a0 + (0)); return *(u32*)((u32)p + (12)); }

u32 func_00143318(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p = D_00348818; return *(u32*)((u32)p + (0)); }

u32 func_0016a090(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = *(u32*)((u32)a0 + (8)); return *(u8*)((u32)p + (74)); }

extern "C" u32 func_00177860(u32,u32,u32,u32) asm("_ZN2YS5PARTY11get_abilityEv");

u32 func_0017fd20(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (20))) + (-56)); return (v < (u32)18); }

u32 func_0019fdb0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (340)); return (u32)((s32)v + (1)); }

void func_001bc0d0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)4); *(u32*)((u32)a0 + (728)) = v; }

u32 func_001c5f78(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = *(u32*)((u32)a0 + (92)); u32 v = *(u32*)((u32)p + (4)); v ^= 0x5bdu; return (v < 1u); }

u32 func_001c90f0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a1 + (340))) + (-201)); return (v < (u32)4); }

u32 func_001ca498(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (340))) + (-31)); return (v < (u32)2); }

void func_001e0e40(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)1); *(u32*)((u32)a0 + (36)) = v; }

u32 func_001e0fd0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (36))) + (-1)); return (v < (u32)3); }

u32 func_001e2778(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (3520))) + (-4)); return (v < (u32)2); }

f32 func_001ed2d8(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }

f32 func_001ed488(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }

f32 func_001ee7a0(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }

f32 func_001ee980(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }

extern "C" u32 func_002283c8(u32,u32,u32,u32) asm("_ZN2sa5EVENT4isLKEv");

u32 func_002283e0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v = *(u8*)&D_0032bae0; v ^= 0x2u; return (v < 1u); }

u32 func_00240440(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)a0 + (1023)); v = v >> 10; return v; }

u32 func_00240bd0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p = D_0035ec94; return (u32)(s32)(*(s8*)((u32)p + (1))); }

u32 func_00242e48(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v = D_0035ecd8; return v & 0x1u; }

void func_00276578(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_0035f1fc; *(u8*)((u32)p + (0)) = (u8)a0; }

void func_0029e950(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_0035f5ac; *(u8*)((u32)p + (4)) = (u8)a0; }

u32 func_002cb920(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (4)) + *(u32*)((u32)a0 + (8)); return (u32)((s32)v + (-1)); }

u32 func_002e34c8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = *(u32*)((u32)a0 + (0)); return *(u32*)((u32)p + (8)); }

u32 func_002f1ab8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p = D_00363c2c; return *(u32*)((u32)p + (4)); }
