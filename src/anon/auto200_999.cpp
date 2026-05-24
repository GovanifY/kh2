#include "../common/types.h"

u32 func_0013e940(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_00149350(u32, u32, u32, u32);
void func_0014b150(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_00135ff0(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_00177dc8(...);
u32 func_00182f28(...);
u32 func_00185ed8(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_001b3b70(u32, u32, u32, u32, u32, u32, u32, u32);
void func_00192f78(void *);
void func_001a9970(void *, u32);
u32 func_001aae68(u32);
void func_001b0188(u32);
void func_00102670(u32, u32);
u32 func_00102788(u32, u32, u32, u32);
void func_001c0248(u32);
void func_001d5718(u32);
void func_002361a0(...);
u32 func_00239700(...);
void func_00239870(u32);
void func_002579e0(void);
void func_0028abe0(u32);
void func_0028be18(u32);
u32 func_0028acc8(u32);
u32 func_0028be58(u32);
u32 func_002cf268(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_002cff50(u32, u32, u32, u32, u32, u32, u32, u32);
void func_0016a358(u32);
void func_0019f9a8(u32);
void func_002fd160(void) __attribute__((noreturn));
u32 func_00290738(...);
void func_0031e7f8(u32);
void func_0014c8e0();
typedef void (*Fn_00322908)(u32, u32);
extern u8 D_0014c7f0;
extern u8 D_0032f234;
extern u8 D_01c61af4;
extern u8 D_01c61af5;
extern u32 D_01c6cba0;
extern u8 D_0032da20;
extern u32 D_0032b91c;
extern u8 D_0032df30;
extern u8 D_0032fae4;
extern u8 D_0032fb68;
extern u32 D_00347f80;
extern u8 D_00347d18;
extern u32 D_00347e08;
extern u8 D_003486f0;
extern u8 D_00347e60;
extern u8 D_00347f98;
extern u32 D_00352bd0;
extern u32 D_0034e8b8;
extern u32 D_0034ee08;
extern u32 D_003503e0;
extern u8 D_00350000;
extern u32 D_00350e48;
extern u32 D_00350e60;
extern u8 D_00351100;
extern u32 D_0035f490;
extern u32 D_0035f01c;
extern u32 D_0035f04c;
extern u32 D_0035de5c;
extern u8 D_0035de54;
extern u16 D_0035ef70;
extern u32 D_0035f23c;
extern u32 D_0035f240;
extern u32 D_0035f30c;
extern u32 D_0035f310;
extern u32 D_0035ec94;
extern u8 D_0035ef78;
extern u8 D_00360000;
extern u8 D_003616f8;
extern u8 D_00361fc8;
extern u8 D_00362060;
extern f32 D_003760a0;
extern f32 D_003760a4;
extern u8 D_004f36a8;
extern u8 D_004f3700;
extern u32 D_004f41c0;

static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
static inline u32 addr_D_0034e8b8() { return (u32)&D_0034e8b8; }
static inline u32 addr_D_0034ee08() { return (u32)&D_0034ee08; }
static inline u32 addr_D_003503e0() { return (u32)&D_003503e0; }
static inline u32 addr_D_00350e48() { return (u32)&D_00350e48; }
static inline u32 addr_D_00350e60() { return (u32)&D_00350e60; }

u32 func_00135e10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                  u32 a7) {
    u32 r16 = a0;
    *(volatile u32 *)a0 = (u32)&D_00347d18;
    u32 r2 = ((u32 (*)(u32, u32, u32, u32, u32, u32, u32, u32))func_00135ff0)(
        a0, a1, a2, a3, a4, a5, a6, a7);
    u32 base = 0x00340000u;
    u32 old = *(volatile u32 *)(base + 32008);
    *(volatile u32 *)(r16 + 8) = old;
    *(volatile u32 *)(base + 32008) = r16;
    return r2;
}

u32 func_0013e900(u32 a0) {
    u32 s0 = a0;
    ((u32 (*)(u32))func_0014b150)(a0);
    *(u32 *)(s0 + 272) = 0;
    *(u32 *)(s0 + 276) = 0;
    *(u32 *)s0 = (u32)&D_003486f0;
    *(u32 *)(s0 + 280) = 0;
    return ((u32 (*)(u32))func_0013e940)(s0);
}

void func_0015cb18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7) {
    u8 *p = (u8 *)&D_004f36a8;
    *(u8 *)a0 = p[0];
    *(u8 *)a1 = p[1];
    *(u8 *)a2 = p[2];
    *(u8 *)a3 = p[3];
}

void dk_MapColor_getOnColorTable(u32, u32) asm(
    "_ZN2dk8MapColor15getOnColorTableEPhi");
void dk_MapColor_getOnColorTable(u32 a0, u32 a1) {
    u8 *p = (u8 *)((u32)&D_004f3700 + (a1 << 2));
    *(u8 *)a0 = p[4];
    a0 += 1;
    *(u8 *)a0 = p[5];
    a0 += 1;
    *(u8 *)a0 = p[6];
    *(u8 *)(a0 + 1) = p[7];
}

u32 func_001570a0(u8 *a0) {
    u32 t4 = *(u32 *)(a0 + 15600);
    u32 v0 = 0;
    if (t4 != 4) {
        u32 p15 = *(u32 *)(a0 + 52);
        u32 p14 = *(u32 *)(p15 + 1164);
        if (*(u8 *)(p14 + 431) == 4) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}

void func_0011c210(u32 a0) {
    u64 v = *(u64 *)(a0 + 16);
    u64 mask = 1ull << 53;
    *(u64 *)(a0 + 16) = v | mask;
}

void func_0010dee8(u32 a0, u32 *a1, u32 *a2) {
    a2[0] = a1[0];
    a2[1] = a1[1];
    a2[2] = a1[2];
    a2[3] = a1[3];
    a2[4] = a1[4];
}

u8 *func_00100430(u8 *a0, u64 *a1) {
    u8 *p = a0;
    u32 shift = 0;
    s64 out = 0;
    s32 cont;

    do {
        u32 b = *p++;
        out |= (s32)((b & 0x7f) << shift);
        cont = b & -128;
        shift += 7;
    } while (cont != 0);

    *a1 = out;
    return p;
}

void func_0010ef28(u32 a0, u32 a1) {
    u32 p = a0 + 8;
    *(u32 *)(p + 3156) = *(u32 *)(p + 3152);
    p = a0 + 4;
    *(u32 *)(p + 3156) = *(u32 *)(p + 3152);
    *(u32 *)(a0 + 3156) = a1;
}

u64 func_0011c230(u32 a0) {
    u64 v = *(u64 *)(a0 + 16);
    return (v >> 53) & 1;
}

u32 func_0014c908() {
    func_0014c8e0();
    u32 a0 = D_0032b91c;
    return func_00102788(a0, 0, 1, (u32)&D_0014c7f0);
}

void dk_RectParamBase_setColor(u32, u32, u32, u32,
                               u32) asm("_ZN2dk13RectParamBase8setColorEhhhh");
void dk_RectParamBase_setColor(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    a1 &= 0xff;
    a2 &= 0xff;
    a3 &= 0xff;
    *(u8 *)(a0 + 16) = a1;
    t0 &= 0xff;
    *(u8 *)(a0 + 17) = a2;
    *(u8 *)(a0 + 19) = t0;
    *(u8 *)(a0 + 18) = a3;
}

void func_0014bb00(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    a1 = (s16)a1;
    a2 = (s16)a2;
    a3 &= 0xffff;
    asm volatile("" : "+r"(a3));
    *(volatile u16 *)(a0 + 320) = a1;
    t0 &= 0xffff;
    *(volatile u16 *)(a0 + 322) = a2;
    *(volatile u16 *)(a0 + 326) = t0;
    *(volatile u16 *)(a0 + 324) = a3;
}

u32 func_001493b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (*(s8 *)a0 == 0) {
        return func_00149350(a0, a0, a2, a3);
    }
}

u32 func_00165ef0(u32 a0) {
    u32 head = D_004f41c0;
    u32 v;

    for (;;) {
        if (a0 != 0) {
            v = *(u32 *)(a0 + 12);
        } else {
            v = head;
        }
        if (v == 0) {
            return 0;
        }
        a0 = v;
        if ((*(u32 *)(v + 8) & 2) == 0) {
            return v;
        }
    }
}

u32 func_0018cae0(u32 a0) {
    u32 p = *(u32 *)(a0 + 32);
    u32 v = *(u8 *)(p + 18);
    v >>= 5;
    v &= 1;
    u8 ret = (u8)v;
    return ret;
}

u32 func_0018f010(u32 a0) {
    u32 p = *(u32 *)(a0 + 40);
    u32 v = *(u8 *)(p + 4);
    v -= 2;
    v = v < 2;
    u8 ret = (u8)v;
    return ret;
}

void func_00190128(u32 a0) {
    u32 neg = 0xffffffffu;
    *(u32 *)(a0 + 4) = 0;
    *(u32 *)(a0 + 12) = neg;
    *(u32 *)(a0 + 8) = 0;
    *(u32 *)a0 = 0;
}

void func_00194668(u32 a0) {
    u32 v0 = *(u32 *)(a0 + 268);
    u32 v1 = *(u32 *)(a0 + 1896);
    v0 &= 0xffffffbf;
    *(u32 *)(a0 + 1936) = 0;
    v1 &= 0xffffefff;
    *(u32 *)(a0 + 268) = v0;
    *(u32 *)(a0 + 1896) = v1;
}

u32 YS_OBJ_get_draw_color(u32) asm("_ZN2YS3OBJ14get_draw_colorEv");
u32 YS_OBJ_get_draw_color(u32 a0) {
    u32 flag = *(u32 *)(a0 + 1416);
    u32 alt = a0 + 1880;
    flag &= 0x20000000;
    a0 += 2236;
    if (flag == 0) {
        a0 = alt;
    }
    return a0;
}

u32 func_001949d0() {
    u32 ret = 0;
    if (D_01c61af4 != 0) {
        ret = D_01c61af5 < 1;
    }
    return ret;
}

void func_001963c8(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032da20 + (idx << 2));
    a0 &= 31;
    u32 val = *p;
    u32 mask = 1u << a0;
    *p = val | mask;
}

void func_00198e70(u32 a0, u32 a1) {
    s32 idx = *(s16 *)(a0 + 46);
    a1 &= 0x1fff;
    a1 <<= 2;
    s32 off = idx;
    idx += 1;
    off <<= 1;
    *(u16 *)(a0 + 46) = idx;
    a0 += off;
    u32 v = *(u16 *)(a0 + 32);
    v &= 0x8000;
    v |= a1;
    *(u16 *)(a0 + 32) = v;
}

void func_00198ea8(u32 a0, u32 a1) {
    s32 idx = *(s16 *)(a0 + 46);
    a1 &= 0x1fff;
    a1 <<= 2;
    s32 off = idx;
    idx += 1;
    off <<= 1;
    *(u16 *)(a0 + 46) = idx;
    a0 += off;
    u32 v = *(u16 *)(a0 + 32);
    v &= 0xfffc;
    v |= 1;
    v &= 0x8001;
    v |= a1;
    *(u16 *)(a0 + 32) = v;
}

void func_0019f490(u32 a0, u32 a1) {
    u32 idx = a1 >> 5;
    u32 mask = 1;
    idx <<= 2;
    a1 &= 31;
    a0 += idx;
    mask <<= a1;
    u32 val = *(u32 *)a0;
    *(u32 *)a0 = val | mask;
}

void func_001a1c70(u32 a0) {
    u8 v = *(u8 *)(a0 + 434);
    *(u8 *)(a0 + 432) = 100;
    *(u8 *)(a0 + 433) = v;
    *(u32 *)(a0 + 436) = 0;
    *(u32 *)(a0 + 440) = 0;
}

void func_001a1d40(u32 a0, f32 f12) {
    *(u32 *)(a0 + 384) = 0;
    *(f32 *)(a0 + 448) = f12;
    *(f32 *)(a0 + 444) = f12;
}

u32 func_001a3888(s32 a0) {
    if (a0 < 5) {
        goto L_zero;
    }
    if (a0 < 8) {
        goto L_one;
    }
    if (a0 != 131) {
        goto L_zero;
    }
L_one:
    return 1;
L_zero:
    return 0;
}

u32 func_001a84f0() {
    u32 *p = &D_01c6cba0;
    u32 v = p[1] ^ p[0];
    return v < 1;
}

void func_001a8ff8(u32 a0, u32 a1, u32 a2) {
    u8 *p1 = (u8 *)(a0 + a1);
    u8 *p2 = (u8 *)(a0 + a2);
    u8 v1 = *p1;
    u8 v2 = *p2;
    *p1 = v2;
    *p2 = v1;
}

void func_00226f78(u32 a0) {
    D_0035de5c = a0;
    D_0035de54 = 1;
}

u32 func_00258068(u32 a0) {
    s32 v = D_0035ef70;
    v >>= a0;
    v &= 1;
    u8 ret = (u8)v;
    return ret;
}

void func_0027dc20(u32 *a0, u32 *a1) {
    *a0 = D_0035f240;
    *a1 = D_0035f23c;
}

u32 func_00282228(u32 a0, u32 a1, u32 a2) {
    u32 mask = 1;
    mask <<= a1;
    a2 &= mask;
    a2 = (u32)(0 < a2);
    return a2;
}

void func_00287d08() {
    D_0035f30c = 0;
    D_0035f310 = 0xffffffff;
}

void func_002c5628(u32 a0) {
    u32 v1 = *(u32 *)(a0 + 264);
    u32 v2 = *(u32 *)(a0 + 268);
    v1 &= 0xfffffffdu;
    v1 &= 0xffffffbfu;
    v2 &= 0xfffffeffu;
    *(u32 *)(a0 + 264) = v1;
    *(u32 *)(a0 + 268) = v2;
}

void func_003191d0(u32 a0, u32 a1, u64 a2) {
    a1 <<= 2;
    a1 += a0;
    u32 p = *(u32 *)a1;
    *(u64 *)p = a2;
}

void func_001c6c60(u32 a0) {
    s32 t7 = 0x001c0000;
    *(volatile u8 *)(a0 + 21) = 0;
    asm volatile("" : "+r"(t7)::"memory");
    t7 += 27176;
    *(u32 *)(a0 + 84) = t7;
}

void func_001e0dc8(u32 a0) {
    u32 idx = *(u32 *)(a0 + 32);
    u32 base = D_00352bd0;
    idx <<= 6;
    u32 p = *(u32 *)(base + 3524);
    p += idx;
    *(u32 *)(p + 60) = 0;
}

void func_002e9a00(u32 a0, u32 a1) {
    u32 p = 0x00370000;
    asm volatile("" : "+r"(p));
    *(u32 *)a0 = a1;
    p += 24736;
    asm volatile("" : "+r"(p));
    *(volatile u32 *)(a0 + 4) = 0;
    f32 f0 = *(f32 *)p;
    *(volatile u32 *)(a0 + 8) = 0;
    p = 0x00370000;
    asm volatile("" : "+r"(p));
    *(f32 *)(a0 + 20) = f0;
    p += 24740;
    asm volatile("" : "+r"(p));
    *(volatile u32 *)(a0 + 12) = 0;
    register f32 f1 asm("$f1") = *(f32 *)p;
    *(volatile u32 *)(a0 + 16) = 0;
    *(f32 *)(a0 + 24) = f1;
}

u32 func_00239cf0(u32 a0) {
    s32 idx = *(s32 *)(a0 + 276);
    s32 stride = 36;
    u32 base = *(u32 *)(a0 + 180);
    idx = idx * stride;
    u32 p = idx + base;
    u32 v = *(u16 *)(p + 2);
    return v < 1;
}

namespace dk {
class Pause {
  public:
    static void disable(s32);
};
class Ft4Base {
  public:
    void setGsUV(u64, u64, u64, u64);
};
class ObjCamera {
  public:
    void returnMode();
};
class RectBase {
  public:
    void setGsUV(u64, u64);
};

void Pause::disable(s32 a0) {
    u32 mask = 1u << a0;
    D_00347e08 |= mask;
}

void Ft4Base::setGsUV(u64 a0, u64 a1, u64 a2, u64 a3) {
    *(volatile u64 *)((u8 *)this + 208) = a0;
    *(volatile u64 *)((u8 *)this + 256) = a3;
    *(volatile u64 *)((u8 *)this + 224) = a1;
    *(volatile u64 *)((u8 *)this + 240) = a2;
}

void ObjCamera::returnMode() {
    if (*(u8 *)((u8 *)this + 59) != 0) {
        *(u32 *)((u8 *)this + 64) = 2;
        return;
    }
    *(u32 *)((u8 *)this + 64) = 0;
}

void RectBase::setGsUV(u64 a0, u64 a1) {
    *(volatile u64 *)((u8 *)this + 208) = a0;
    *(volatile u64 *)((u8 *)this + 224) = a1;
}
} // namespace dk

void func_0019f4b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7) {
    u32 idx = a1 >> 5;
    a0 += 4;
    idx <<= 2;
    a1 &= 31;
    a0 += idx;
    u32 val = *(u32 *)a0;
    u32 mask = 1u << a1;
    val |= mask;
    *(u32 *)a0 = val;
}

void func_001a98e8(u32 *a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    a0[0] = 0;
    a0[1] = func_001aae68(a1);
    a0[2] = a2;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    func_00192f78(a0 + 9);

    a0[22] = a4;
    a0[19] = 0;
    a0[20] = 0;
    a0[21] = 0;
    a0[23] = 0;
    func_001a9970(a0, a3);
}

void func_001d3328(u32 *a0) {
    s32 t7 = 2;
    do {
        *a0 = 0;
        t7 -= 1;
        a0 += 1;
    } while (t7 >= 0);
}

u32 func_001b3bb8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                  u32 a7) {
    u32 s0 = a0;
    u32 r = ((u32 (*)(u32, u32, u32, u32, u32, u32, u32, u32))func_00185ed8)(
        a0, a1, a2, a3, a4, a5, a6, a7);
    u32 mask = *(u32 *)(s0 + 1420);
    u32 vtbl = (u32)&D_00351100;
    *(u32 *)(s0 + 2788) = 0;
    mask |= 2;
    *(u32 *)s0 = vtbl;
    *(u32 *)(s0 + 2796) = 0;
    *(u32 *)(s0 + 1420) = mask;
    return r;
}

namespace YS {
struct SAVEFLAG {
    static u32 Check(u32);
};
struct WORLDFLAG {
    static u32 Check(s32);
};

u32 SAVEFLAG::Check(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032df30 + (idx << 2));
    u32 bit = a0 & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}

u32 WORLDFLAG::Check(s32 a0) {
    u32 v = (u32)a0;
    u32 idx = v >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032fb68 + (idx << 2));
    u32 bit = v & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}
} // namespace YS

u32 func_001c09c0(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032f234 + (idx << 2));
    u32 bit = a0 & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}

u32 func_001d5668(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032fae4 + (idx << 2));
    u32 bit = a0 & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}

void func_001b6038() {
    u32 t6 = *(u32 *)((u8 *)&D_00350000 + 4480u);
    if (t6 == 0) {
        return;
    }
    func_00102670(*(u32 *)((u8 *)&D_00350000 + 4628u), t6);
}

u32 func_001e6d08(u32 a0, u32 a1, u32 a2, u32 a3) {
    return (*(f32 *)(a0 + 164u) > 0.0f) ? 1u : 0u;
}

void func_001e7650(u32 a0, u32 a1, u32 a2) {
    u32 t0 = a2;
    a2 = (u32)(a1 + t0);
    *(u32 *)((u32)a0 + (s32)(4)) = a1;
    a2 = (u32)((s32)a2 + (-16));
    *(u32 *)((u32)a0 + (s32)(0)) = 0u;
    *(u32 *)((u32)a0 + (s32)(8)) = a2;

    *(u32 *)((u32)a1 + (s32)(4)) = 0u;
    u32 t7 = *(u32 *)((u32)a0 + (s32)(8));
    *(u32 *)((u32)a1 + (s32)(8)) = 0u;
    *(u32 *)((u32)a1 + (s32)(0)) = t7;

    u32 t6 = *(u32 *)((u32)a0 + (s32)(8));
    u32 t7b = 1u;
    u32 t5 = *(u32 *)((u32)a0 + (s32)(4));
    *(u32 *)((u32)t6 + (s32)(8)) = t7b;
    *(u32 *)((u32)t6 + (s32)(4)) = t5;
    *(u32 *)((u32)t6 + (s32)(0)) = 0u;
    *(u32 *)((u32)a0 + (s32)(12)) = 0u;
}

void func_00257000() {
    s32 c = 0;
    s32 d = 0;
    do {
        u16 *p = (u16 *)((u8 *)&D_0035ef78 + d);
        s32 e = 37;
        do {
            *p = 0u;
            e -= 1;
            p += 1;
        } while (e >= 0);
        c += 1;
        d += 76;
    } while (c < 2);
}

void func_002bcf58(u32 *a0) {
    u32 thirty = 30;
    u32 neg1 = 0xFFFFFFFF;
    a0[82] = thirty;
    s32 i = 13;
    a0 = (u32 *)((u8 *)a0 + 132);
    u32 *base = (u32 *)&D_003616f8;
    u32 *src = (u32 *)((u8 *)base + 44);
    do {
        u32 v = src[0];
        i -= 1;
        a0[0] = v;
        src = (u32 *)((u8 *)src + 4);
        a0[1] = neg1;
        a0[2] = 0;
        a0 = (u32 *)((u8 *)a0 + 12);
    } while (i >= 0);
}

void func_0031e2c8(u32 a0, u32 a1) {
    u32 t7 = *(u32 *)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32 *)(a1 + 40);
        t5 = 0;
        *(u32 *)a0 = t7n;
    } else {
        u32 t6 = *(u32 *)(t7 + 40);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32 *)(t6 + 40);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32 *)(a1 + 40);
        *(u32 *)(t5 + 40) = t7n;
    }

    u32 t7c = *(u32 *)(a0 + 4);
    if (a1 == t7c) {
        *(u32 *)(a0 + 4) = t5;
    }
    *(u32 *)(a1 + 40) = 0;
}

void func_0031e328(u32 a0, u32 a1) {
    u32 t7 = *(u32 *)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32 *)(a1 + 60);
        t5 = 0;
        *(u32 *)a0 = t7n;
    } else {
        u32 t6 = *(u32 *)(t7 + 60);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32 *)(t6 + 60);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32 *)(a1 + 60);
        *(u32 *)(t5 + 60) = t7n;
    }

    u32 t7c = *(u32 *)(a0 + 4);
    if (a1 == t7c) {
        *(u32 *)(a0 + 4) = t5;
    }
    *(u32 *)(a1 + 60) = 0;
}

#define UNLINK_BODY(link_offset)                                               \
    u32 t7 = *(u32 *)a0;                                                       \
    u32 t5;                                                                    \
    if (a1 == t7) {                                                            \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        t5 = 0;                                                                \
        *(u32 *)a0 = t7n;                                                      \
    } else {                                                                   \
        u32 t6 = *(u32 *)(t7 + (link_offset));                                 \
        if (t6 != a1) {                                                        \
            do {                                                               \
                u32 t7x = *(u32 *)(t6 + (link_offset));                        \
                t5 = t6;                                                       \
                if (t7x == a1) {                                               \
                    break;                                                     \
                }                                                              \
                t6 = t7x;                                                      \
            } while (1);                                                       \
        } else {                                                               \
            t5 = t7;                                                           \
        }                                                                      \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        *(u32 *)(t5 + (link_offset)) = t7n;                                    \
    }                                                                          \
    u32 t7c = *(u32 *)(a0 + 4);                                                \
    if (a1 == t7c) {                                                           \
        *(u32 *)(a0 + 4) = t5;                                                 \
    }                                                                          \
    *(u32 *)(a1 + (link_offset)) = 0;

void func_0031ee68(u32 a0, u32 a1) { UNLINK_BODY(192) }
void func_0031f298(u32 a0, u32 a1) { UNLINK_BODY(12) }
void func_0031fe00(u32 a0, u32 a1) { UNLINK_BODY(124) }
void func_003201e8(u32 a0, u32 a1) { UNLINK_BODY(24) }
void func_00320468(u32 a0, u32 a1) { UNLINK_BODY(2232) }
void func_003204c8(u32 a0, u32 a1) { UNLINK_BODY(20) }
void wtarget_00320828(u32 a0, u32 a1, u32 a2, u32 a3) { UNLINK_BODY(80) }
void func_003208a8(u32 a0, u32 a1) { UNLINK_BODY(36) }
void u_call4_003216c8(u32 a0, u32 a1, u32 a2, u32 a3) { UNLINK_BODY(48) }
void func_00321c50(u32 a0, u32 a1) { UNLINK_BODY(40) }
void func_00321ce8(u32 a0, u32 a1) { UNLINK_BODY(96) }

#undef UNLINK_BODY

void func_00271e80() {
    func_002579e0();
    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }
}

void func_0027a180() {
    func_002579e0();
    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }
}

void func_002723e0() {
    func_00271e80();
    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
}

void func_00290610(u32 self) {
    *(u32 *)(self + 12) = 0;
    *(u32 *)self = (u32)&D_00347e60;
    func_00239700(self + 24);
    *(u32 *)self = (u32)&D_0035f490;
    func_002361a0(self + 416);
    func_00290738(self, 30022);
}

u32 func_002cff00(u32 a0) {
    u32 s0 = a0;
    ((u32 (*)(u32))func_001b3b70)(a0);
    *(u32 *)s0 = (u32)&D_00361fc8;
    ((u32 (*)(u32, u32))func_002cf268)(s0 + 2800, 0);
    *(u32 *)(s0 + 1416) |= 0x08000000u;
    return ((u32 (*)(u32))func_002cff50)(s0);
}

u32 func_002d0ef0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    ((u32 (*)(u32, u32, u32, u32, u32))func_00177dc8)(a0, a1, 11, a2, a3);
    *(u32 *)s0 = (u32)&D_00362060;
    *(u32 *)((u8 *)&D_00360000 + 8272) = s0;
    return ((u32 (*)(u32))func_00182f28)(s0);
}

void func_0031a2f0(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}

void func_0031ac18(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}

void func_0031ad00(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}

void func_0031ada0(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}

void func_0031bfc8(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}

void func_0031d700(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}

void func_0031d840(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}

void func_00319fb0(u32 self) {
    u32 s18 = self;
    *(u32 *)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);
        } while (1);
    }

    *(u32 *)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031e690(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32 *)(self + 2824) = c2824;
    *(u32 *)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32 *)(s18 + 0) = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32 *)(s18 + 0) = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

u32 func_003149e8(u32 a0) {
    a0 &= 0xFFu;
    u32 v0 = 0;
    if (a0 == 0xFFu) {
        return v0;
    }

    u32 t = a0 & 7u;
    v0 = 2;
    if (t == 2u) {
        return v0;
    }
    if ((s32)t < 3) {
        if (t != 0u) {
            v0 = 4;
            func_002fd160();
        }
        return 4;
    }

    if (t == 3u) {
        return 4;
    }
    if (t == 4u) {
        return 8;
    }
    func_002fd160();
}

u32 func_00316e20(u32 a0) {
    a0 &= 0xFFu;
    u32 v0 = 0;
    if (a0 == 0xFFu) {
        return v0;
    }

    u32 t = a0 & 7u;
    v0 = 2;
    if (t == 2u) {
        return v0;
    }
    if ((s32)t < 3) {
        if (t != 0u) {
            v0 = 4;
            func_002fd160();
        }
        return 4;
    }

    if (t == 3u) {
        return 4;
    }
    if (t == 4u) {
        return 8;
    }
    func_002fd160();
}
