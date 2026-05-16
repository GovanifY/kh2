#include "types.h"

extern u32 D_0032bad0;
extern u32 D_0033cbb8;
extern u32 D_00341698;
extern u32 D_00341708;
extern u32 D_00347f80;
extern u32 D_00347f84;
extern u32 D_00347fec;
extern u32 D_00347ff0;
extern u32 D_00347ff8;
extern u32 D_003484a0;
extern u32 D_0034e9f8;
extern u32 D_00354680;
extern u32 D_00354684;
extern u32 D_00354688;
extern u32 D_0035468c;
extern u32 D_0035dac4;
extern u32 D_0035de28;
extern u32 D_0035de40;
extern u32 D_0035eb48;
extern u32 D_0035eb4c;
extern u32 D_0035ec94;
extern u32 D_0035ecd8;
extern u32 D_0035eeb8;
extern u32 D_0035f028;
extern u32 D_0035f090;
extern u32 D_0035f094;
extern u32 D_0035f23c;
extern u32 D_0035f240;
extern u32 D_0035f2f0;
extern u32 D_0035f2f4;
extern u32 D_0035f304;
extern u32 D_0035f32c;
extern u32 D_0035f32e;
extern u32 D_0035f3fc;
extern u32 D_0035f520;
extern u32 D_0035f640;
extern u32 D_0035f644;
extern u32 D_00361fb0;
extern u32 D_00369ff8;
extern u32 D_0036c278;
extern u32 D_0036d4d8;
extern u32 D_00372368;
extern u32 D_00374190;
extern u32 D_01c60528;
extern u32 D_01d9eaac;
extern u32 D_01d9eab0;

u32 func_00104340(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u8*)((u32)&D_0032bad0 + (u32)a0 + (0)); }

u32 func_00105f80(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00369ff8 + ((u32)a0 << 2) + (0)); }

extern "C" void func_00107350(u32,f32,f32,f32) asm("_ZN2kn6Camera11setUpVectorEfff");

u32 func_0010aed8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00341698 + ((u32)a0 << 2) + (0)); }

void func_0013a1e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; D_00347f84 = D_00347f80; }

void func_0013a6b8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v=(u32)((s32)-1); D_00347fec=v; D_00347ff0=v; }

void func_0013c720(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p=D_003484a0; *(u8*)((u32)p + (254)) = (u8)((u32)((s32)1)); }

void func_00150660(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (1232)) = (u32)((s32)4); *(u32*)((u32)a0 + (1640)) = (u32)((s32)10); }

void func_00151bd8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (1232)) = (u32)((s32)4); *(u32*)((u32)a0 + (2864)) = (u32)((s32)10); }

void func_001656c0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (0)) = 0; *(u32*)((u32)a0 + (4)) = 0; *(u32*)((u32)a0 + (8)) = 0; }

u32 func_0016f448(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_0036c278 + ((u32)a0 << 2) + (0)); }

u32 func_0017aab8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_0034e9f8 + ((u32)a0 << 2) + (0)); }

u32 func_001a5af0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u8*)((u32)&D_0036d4d8 + (u32)a0 + (0)); }

u32 func_001bdfe0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return (*(u16*)((u32)a0 + (2628)) != 0); }

void func_001bf100(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v=*(u32*)((u32)a0 + (2736)); u32 bit=1u<<a1; v|=bit; *(u32*)((u32)a0 + (2736)) = v; }

void func_001d56f0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (0)) = 0; *(u32*)((u32)a0 + (4)) = 0; *(u32*)((u32)a0 + (8)) = 0; }

void func_001e2b50(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_01d9eaac = a0; D_01d9eab0 = a1; }

void func_001e7070(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_00354680 = a0; D_00354684 = a1; }

void func_001e7088(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_00354688 = a0; D_0035468c = a1; }

f32 func_001ed130(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 v=a0*a1; return v-a0; }

u32 func_001ed7d8(u32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 fv=(f32)(s32)a0; fv=fv*a1; return (u32)(s32)fv; }

u32 func_001ed978(u32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 fv=(f32)(s32)a0; fv=fv*a1; return (u32)(s32)fv; }

f32 func_001ee5c8(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 v=a0*a1; return v-a0; }

u32 func_0021e988(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; return 0x70001e00u; }

u32 func_0021e998(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; return 0x70002f00u; }

void func_002248f8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v=D_0035dac4; v=v+a0; D_0035dac4=v; }

void func_0022d3a8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; s32 v=*(s16*)((u32)a0 + (4)); D_0035de40=(u32)v; }

void func_0022d3b8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; s32 v=*(s16*)((u32)a0 + (4)); D_0035de28=(u32)v; }

void func_0023d2b0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v=(u32)((s32)-1); D_0035eb48=v; D_0035eb4c=v; }

void func_0023d2c8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_0035eb48 = a0; D_0035eb4c = a1; }

void func_0023eac0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 p=a1+a0; *(u8*)((u32)p + (2912))=(u8)a2; }

u32 func_002419e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p=D_0035ec94; s32 v=*(s8*)((u32)p + (4)); return (v != 0); }

void func_00241a70(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p=D_0035ec94; *(u8*)((u32)p + (5)) = (u8)((u32)((s32)1)); }

extern "C" u32 func_00242ee8(u32,u32,u32,u32) asm("_ZN2Tz6Config12isChapterAllEv");

u32 func_0024f2b8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00372368 + ((u32)a0 << 2) + (0)); }

u32 func_00253598(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v=D_0035eeb8; v ^= 0x1u; return (v < 1u); }

void func_00258d40(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; *(u16*)&D_0035f090=(u16)a0; *(u16*)&D_0035f094=(u16)a1; }

void func_0027dc08(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_0035f240 = a0; D_0035f23c = a1; }

u32 func_002811e0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return (u32)(s32)(*(s16*)((u32)a0 + ((u32)a1 * (20)) + (8))); }

u32 func_002812c8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00374190 + ((u32)a0 << 2) + (0)); }

u32 func_0028af78(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v=*(u32*)((u32)a0+(52)); v &= a1; return (v != 0); }

void func_002b4ac8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_0035f640 = a0; D_0035f644 = a1; }

u32 func_002cf308(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00361fb0 + ((u32)a0 << 2) + (0)); }

void func_002e93a0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (28)) = 0; *(u32*)((u32)a0 + (48)) = 0; *(u32*)((u32)a0 + (60)) = 0; }
