#include "types.h"

extern u32 D_0032b9dc;
extern u32 D_00340ed4;
extern u32 D_00341780;
extern u32 D_00347d30;
extern u32 D_00347fb0;
extern u32 D_0035eee0;
extern u32 D_0035f068;
extern u32 D_0035f6d0;

u32 func_00102fa0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; s32 v=*(s8*)&D_0032b9dc; return (v!=0); }

u32 func_0010abb8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 old=D_00340ed4; D_00340ed4=a0; return old; }

u32 func_001124e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 old=D_00341780; D_00341780=a0; return old; }

void func_0011ee98(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v=*(u32*)((u32)a0+(8)); *(u32*)((u32)a1+(4))=v; *(u32*)((u32)a0+(8))=a1; }

u32 func_00136b90(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p=(u32)&D_00347d30 + ((u32)a0 << 4); return *(u32*)((u32)p + (8)); }

u32 func_002537c8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p=(u32)&D_0035eee0 + ((u32)a0 << 4); return *(u32*)((u32)p + (12)); }

u32 func_002b50e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; s32 v=*(s8*)&D_0035f6d0; return (v!=0); }
