#include "types.h"
#include "auto80_199_queue_decls.hpp"

extern "C" u32 YS_STATUS_IsBattleMode(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
extern "C" u32 func_001dc9d0(u32) asm("_ZN3ryj6EFFECT8is_aliveEv");

extern "C" void RECOM_FLAG_clear_0019f578(u32) asm("_ZN2YS10RECOM_FLAG5clearEv");

namespace Tz { class Select { public: u32 isCursorMove(); u32 isSelectTopMove(); }; }

namespace dk {
class Ft4Base {
public:
    void setRot(f32);
    void setCenterXY(s32, s32);
};

class Sprite {
public:
    void setPos(s32, s32);
    void setOffsetPos(s32, s32);
};

class TREASURE_INFO {
public:
    static u32 openEventInfo(s32);
};

class CmTop {
public:
    static s32 GetSelectPos(s32);
};
}  // namespace dk

namespace Tz {
class CmTop {
public:
    static s32 GetSelectPos(s32);
};

class HelpGra {
public:
    u32 isExist();
};
}  // namespace Tz

u32 func_001003c8(u32 a0) {
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

void func_00100350(void) {
    if (func_00100690 != 0) {
        func_00100690(&D_00378ae8, (u32)&D_0037aa08);
    }

    if (*(u32*)&D_0037a4b0 != 0) {
        if (func_00000000 != 0) {
            func_00000000(&D_0037a4b0);
        }
    }
}

void func_001022e8(u8* a0) {
    Fn0 fn = (Fn0) * (u32*)(a0 + 48);
    if (fn != 0) {
        fn();
    }

    u32 arg = *(u32*)(a0 + 52);
    if (arg != 0) {
        u32 obj = *(u32*)(a0 + 36);
        u32 vt = *(u32*)obj;
        Fn2 m = (Fn2) * (u32*)(vt + 4);
        m(obj, arg);
    }

    u32 obj = *(u32*)(a0 + 36);
    u32 vt = *(u32*)obj;
    Fn2 m = (Fn2) * (u32*)(vt + 4);
    m(obj, (u32)a0);
}

void func_00103bb0(s32 a0) {
    u32 v20 = func_00102c80();
    u32 v19 = func_00103070();
    u32 v18 = func_00104190();
    u32 v17 = func_001045f0();

    u32 out;
    func_00102180((void*)&out);

    if (a0 != -1) {
        D_0032ba24 = (u32)a0;
        return;
    }

    u32 v = out;
    if (v == v20) {
        D_0032ba24 = 1;
        return;
    }
    if (v == v19) {
        D_0032ba24 = 4;
        return;
    }
    if (v == v18) {
        D_0032ba24 = 2;
        return;
    }
    if (v == v17) {
        D_0032ba24 = 3;
        return;
    }
}

void func_00104018(void) {
    func_003058a0(2u);
    func_01f18014(1u, (u32)&D_0032ba48);
    func_00106420(D_0032ba78);

    u32 v = D_0032ba74;
    D_0032ba78 = 0;
    func_00170c00(v);
    func_00170320(0u);
    D_0032ba74 = 0;
}

void func_00104e98(S00104e98* self) {
    s32 t = self->counter;
    if (t > 0) {
        t -= 1;
        self->counter = t;
        if (t > 0) {
            return;
        }
        func_0013f050(self->ptrC);
    }

    if (func_00103b38() != 0) {
        return;
    }
    if (func_002ee530() != 0) {
        return;
    }

    if (self->ptr10 != 0) {
        func_001ada38(self->ptr10);
    }

    func_00104e18();

    if (self->flag8 != 0) {
        func_001cd388();
        D_0032bb10 = -1;
    }

    func_00104da0((void*)((s32)&D_0032bb10 - 32));
    func_001050b8();
    func_001024a8(self);
}

void* func_00105140(const u8* src, void* dst) {
    const u8* s1 = src;
    if (dst == 0) {
        dst = (void*)((s32)&D_003a0000 + 31512);
    }
    void* s0 = dst;
    u32 t = func_00105ee8(s1[0]);
    u32 a0 = (u32)s0;
    u32 a2 = t + (a0 & 0u);
    u32 r = func_002fee78(a0, (u32)((s32)&D_00370000 - 25008), a2, s1[1]);
    (void)r;
    return s0;
}

u32 func_00105310(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = 0;

    if (func_001d50b8(s0, s1) != 0) {
        goto set_one;
    }
    if (func_001d5a58(s0, s1) == 0) {
        goto out;
    }
set_one:
    s2 = 1;
out:
    return s2;
}

u32 func_00105870() {
    s32 v = func_00105c30();
    s32 c;
    switch (v) {
    case 2:
        c = 85;
        break;
    case 1:
    case 8:
        c = 74;
        break;
    default:
        c = 69;
        break;
    }
    return ((u32)c << 24) | 0x0032484b;
}

u32 func_00106178(u32 a0, u32 a1) {
    u32 s0 = (a0 + 15u) & ~15u;
    u32 a2 = a0 + a1;
    u32 arg0 = s0;
    u32 t = (s0 + 80u);
    u32 ok = (t < a2);
    u32 v0 = 0;
    u32 arg1 = s0 + 48u;

    if (ok) {
        func_001060e0(arg0, arg1, a2);
        v0 = s0;
    }

    return v0;
}

u32 func_00106358(u32 a0, u32 a1) {
    u32 s2 = D_0033cc08;
    u32 s1 = a0;
    u32 s0 = a1;

    if (s2 != 0) {
        u32 vtbl = *(u32*)s2;
        (*(void (**)(u32))(vtbl + 24))(s2);
    }

    u32 v0 = func_00106178(s1, s0);
    D_0033cc08 = v0;
    return v0;
}

u32 func_001085a8(u32 a0, const u8* a1) {
    const u8* s0 = a1;
    u32 v0 = func_00133bb8(a0, 1, 0x01000101, 0x6c010001);

    *(u32*)(v0 + 0) = s0[0];
    *(u32*)(v0 + 4) = s0[1];
    *(u32*)(v0 + 8) = s0[2];
    *(u32*)(v0 + 12) = s0[3];
    return v0;
}

void func_00108998(u8* a0) {
    u8* s1 = a0;
    u8* s0 = (u8*)((s32)&D_003b0000 - 29264);

    func_001342c8((u32)s0, 14, 0x13000000);

    *(u64*)(s1 + 0) = *(u64*)(s0 + 32);
    *(u64*)(s1 + 8) = *(u64*)(s0 + 48);
    *(u64*)(s1 + 16) = *(u64*)(s0 + 144);
    *(u64*)(s1 + 24) = *(u64*)(s0 + 160);
    *(u64*)(s1 + 32) = *(u64*)(s0 + 192);
    *(u64*)(s1 + 40) = *(u64*)(s0 + 208);
    s1[48] = 0;
}

void func_00108a10(u8* a0) {
    u8* s1 = a0;
    u8* s0 = (u8*)((s32)&D_003b0000 - 29488);

    func_001342c8((u32)s0, 14, 0x13000000);

    *(u64*)(s1 + 0) = *(u64*)(s0 + 32);
    *(u64*)(s1 + 8) = *(u64*)(s0 + 48);
    *(u64*)(s1 + 16) = *(u64*)(s0 + 144);
    *(u64*)(s1 + 24) = *(u64*)(s0 + 160);
    *(u64*)(s1 + 32) = *(u64*)(s0 + 192);
    *(u64*)(s1 + 40) = *(u64*)(s0 + 208);
    s1[48] = 0;
}

u64 func_00108d68(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 0);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 0) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(76, s1);
    }

    return s2;
}

u64 func_00108dd8(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 8);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 8) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(78, s1);
    }

    return s2;
}

u64 func_00108e48(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 16);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 16) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(71, s1);
    }

    return s2;
}

u64 func_00108eb8(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 24);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 24) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(66, s1);
    }

    return s2;
}

u64 func_00108f28(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 32);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 32) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(61, s1);
    }

    return s2;
}

u64 func_00108f98(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 40);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 40) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(1, s1);
    }

    return s2;
}

void func_00109280(void* a0) {
    void* s0 = a0;
    func_00133d18(s0);

    u32 v = D_0033cc64;
    if (v != 0) {
        u32 vtbl = *(u32*)s0;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(void*, u32))fn)(s0, v);
        D_0033cc64 = 0;
    }

    v = D_0033cc6c;
    if (v != 0) {
        u32 vtbl = *(u32*)s0;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(void*, u32))fn)(s0, v);
        D_0033cc6c = 0;
    }

    v = D_0033cc70;
    if (v != 0) {
        u32 vtbl = *(u32*)s0;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(void*, u32))fn)(s0, v);
        D_0033cc70 = 0;
    }

    D_0033cc68 = 0;
    D_00340ea8 = 0;
}

u32 func_001093c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    u32 s3 = a1;
    u32 s0 = a3;
    u32 s1 = a4;
    u32 s2 = a5;

    u32 n = a2 + 1;
    u32 cmd = (n << 16) | 0x6c004009;
    u32 v0 = func_00133bb8(a0, n, 0x01000101, cmd);

    *(u32*)(v0 + 0) = s3;
    *(u32*)(v0 + 4) = s0;
    *(u32*)(v0 + 8) = s1;
    *(u32*)(v0 + 12) = s2;
    return v0 + 16;
}

void func_0010a580(u32 a0) {
    u32 s1 = a0 & 0xff;
    u8* s0 = *(u8**)&D_0033cc84;

    while (s0 != 0) {
        u32 fn = *(u32*)(s0 + 80);
        if (fn != 0) {
            ((void (*)(u8*, u32))fn)(s0, s1);
        }

        fn = *(u32*)(s0 + 84);
        if (fn != 0) {
            ((void (*)(u8*, u32))fn)(s0, s1);
        }

        func_00134490();
        s0 = *(u8**)(s0 + 16);
    }
}

void func_0010c850(u8* a0) {
    u8* s0 = a0;

    u32 p = *(u32*)(s0 + 2904);
    if (p != 0) {
        u32 vtbl = *(u32*)p;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(u32))fn)(p);
        *(u32*)(s0 + 2904) = 0;
    }

    p = *(u32*)(s0 + 2908);
    if (p != 0) {
        u32 vtbl = *(u32*)p;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(u32))fn)(p);
        *(u32*)(s0 + 2908) = 0;
    }

    p = *(u32*)(s0 + 2912);
    if (p != 0) {
        u32 vtbl = *(u32*)p;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(u32))fn)(p);
        *(u32*)(s0 + 2912) = 0;
    }

    func_0017dc08(s0);
}

void func_0010cb50(u8* a0, s32 a1, u32 a2) {
    u8* s0 = a0;
    u8* p = s0 + 2548;
    u32 v;
    u32 eq;

    if (a2 == 0) {
        return;
    }
    *(s16*)(s0 + 3122) = (s16)a1;
    *(u32*)(s0 + 2936) = 0;
    *(u8*)(s0 + 3125) = 0;
    *(s16*)(s0 + 3120) = 2;

    v = *(u32*)(p + 0);
    eq = (v == a2);
    if (!eq) {
        func_00190878(p, a2, 0);
        v = *(u32*)(p + 0);
    }

    u32 e = *(volatile u32*)(s0 + 2552);
    u32 d = *(volatile u32*)(s0 + 2556);
    u32 c = *(volatile u32*)(s0 + 2560);
    u32 f = *(volatile u32*)(s0 + 2564);
    volatile u32* dst = (volatile u32*)s0;
    dst[782] = v;   // +3128
    dst[786] = f;   // +3144
    dst[783] = e;   // +3132
    dst[784] = d;   // +3136
    dst[785] = c;   // +3140
}

u32 func_0010cc80(u8* a0) {
    u8* s0 = a0 + 2548;
    u32 s1 = 0;

    if ((*(u32*)(a0 + 2940) & 0x40) == 0) {
        if (func_00112d90(s0) != 0) {
            u32 v0 = func_001901c0(s0);
            s1 = (v0 != 0);
        }
    }

    return s1;
}

void func_0010fa68(u8* a0) {
    u8* s0 = a0;
    u32 s1;

    u32 g = D_00341708;
    if (g != 0) {
        if (func_001a2478(*(u32*)(g + 1164)) != 0) {
            g = D_00341708;
            *(u32*)(s0 + 3300) = g;
            return;
        }
    }

    if (func_00112720(s0) != 0) {
        *(u32*)(s0 + 3300) = 0;
        return;
    }

    if (func_001a2478(*(u32*)(s0 + 1164)) != 0) {
        *(u32*)(s0 + 3300) = (u32)s0;
        return;
    }

    s1 = func_00111e20(s0);
    if (s1 == 0) {
        goto set_zero;
    }
    if (func_001a2478(*(u32*)(s1 + 1164)) == 0) {
        goto set_zero;
    }
    *(u32*)(s0 + 3300) = s1;
    return;

set_zero:
    *(u32*)(s0 + 3300) = 0;
}

void func_00110630(u8* a0) {
    u8* s0 = a0;
    u32 t6 = *(u32*)(s0 + 2940);

    if ((t6 & 0x1000) == 0) {
        if (func_0010cc80(s0) != 0) {
            func_00110618(s0);
            return;
        }
        t6 = *(u32*)(s0 + 2940);
    }

    if ((t6 & 0x20000) != 0) {
        return;
    }

    func_00110500(s0);
}

void func_00110960(u8* a0, u32 a1, u32 a2, u32 a3) {
    u8* s0 = a0;
    u32 s3 = a1;
    u32 s1 = a2;
    u32 s2 = a3;

    u32 p = *(u32*)(s0 + 2912);
    u32 vtbl = *(u32*)p;
    u32 fn = *(u32*)(vtbl + 16);
    ((void (*)(u32))fn)(p);

    func_00177760(s0, s3, s1, s2);
}

u32 func_00112cc8(s32* a0) {
    s32* s1 = a0;
    u32 s0 = 0;
    u32 t6 = 0;

    if (func_00190140() != 0) {
        s0 = (u32)(*s1 != 0);
    }
    if ((s0 & 0xff) != 0) {
        t6 = func_00112c80((u32)*s1);
    }
    return t6;
}

void func_001132d8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1 = a0;
    u32 s2 = a2;
    u8 tmp[16];

    u32 vtbl = *(u32*)s0;
    u32 fn = *(u32*)(vtbl + 8);
    ((void (*)(void*))fn)(tmp);
    func_001130b0(tmp, s1, s0, s2);
}

u8 func_00113990(u32 param_1, u32 param_2, u32 param_3, u32* param_4, u8 param_5) {
    (void)param_2;
    (void)param_3;

    if (param_5 != 0) {
        *param_4 = 0;
        if (func_0010f8c0(*(u32*)(param_1 + 4)) != 0) {
            if (func_0010f8e0(*(u32*)(param_1 + 4)) != 0) {
                return 0;
            }
            if (func_0010f8a8(*(u32*)(param_1 + 4)) <= 0.0f) {
                return 0;
            }
        }
        return (u8)(func_0010ef48(*(u32*)(param_1 + 4)) ^ 1);
    }

    if (func_0010f8c0(*(u32*)(param_1 + 4)) == 0) {
        u32 obj = *(u32*)(param_1 + 8);
        f32 f12 = *(f32*)(obj + 0x78);
        f32 f13 = *(f32*)(obj + 0x7c);
        func_0010f880(f12, f13, *(u32*)(param_1 + 4));
    }
    func_00110630(*(u32*)(param_1 + 4));
    return 1;
}

void func_00115128(u32 param_1, u32 param_2) {
    u32 s1 = param_1;
    if (param_2 != 0) {
        u32 a1 = *(u32*)(param_2 + 0x20);
        if (a1 != 0) {
            if (((u16)*(u16*)(a1 + 2) - 0x2dcu) < 2u) {
                u32 s0 = (u32)&D_0036a698;
                u32 a0 = *(u32*)(param_1 + 4);
                if (func_001883d8(a0 + 0x300, s0) != 0) {
                    func_00188170(*(u32*)(s1 + 4) + 0x300, s0);
                    return;
                }
            }
        }
    }
}

void func_00116938(u32 param_1, f32* param_2, f32* param_3) {
    (void)param_1;
    s32 iVar1 = (s32)func_0010f648(6);
    Pair00116938* p = &D_00347688[iVar1];
    *param_2 = p->x;
    *param_3 = p->y;
}

void func_00116990(u32 param_1, f32* param_2, f32* param_3) {
    (void)param_1;
    s32 iVar1 = (s32)func_0010f648(6);
    Pair00116990* p = &D_003476b8[iVar1];
    *param_2 = p->x;
    *param_3 = p->y;
}

u32 func_0011a7f0(u8* a0, u8* a1, u32* a2, u32* a3, u32 a4) {
    if ((a4 & 0xff) != 0) {
        *a3 = 0;
        u8* t5 = *(u8**)(a0 + 4);
        a2[0] = *(u32*)(t5 + 0x9f4);
        a2[1] = *(u32*)(t5 + 0x9f8);
        a2[2] = *(u32*)(t5 + 0x9fc);
        a2[3] = *(u32*)(t5 + 0xa00);
        a2[4] = *(u32*)(t5 + 0xa04);
        return 1;
    }

    u32 p = *(u32*)(a0 + 4);
    func_00188170(p + 0x300, *(u32*)(a1 + 0x20));
    return 1;
}

u32 func_0011b7b0(u32 a0, f32* a1) {
    f32 zero = 0.0f;

    f32 v = a1[0];
    if (v != zero) {
        v = func_0011c050(v);
        ((u32(*)(u32, u32, f32))func_002f4148)(a0, a0, v);
    }

    v = a1[1];
    if (v != zero) {
        v = func_0011c050(v);
        ((u32(*)(u32, u32, f32))func_002f41f0)(a0, a0, v);
    }

    v = a1[2];
    if (v != zero) {
        v = func_0011c050(v);
        ((u32(*)(u32, u32, f32))func_002f40a0)(a0, a0, v);
    }

    return a0;
}

u32 func_0011b868(u32 a0, f32* a1) {
    f32 v[3];
    v[0] = func_0011c050(a1[0]);
    v[1] = func_0011c050(a1[1]);
    v[2] = func_0011c050(a1[2]);
    func_002f4298(a0, a0, v);
    return a0;
}

f32 func_0011bdc0(f32* a0, u32 a1, u32 a2) {
    f32 m[9];
    s32 t3 = 0;
    s32 t2 = 0;

    while (t3 < 4) {
        if ((u32)t3 != a1) {
            s32 t4 = 0;
            u32 t7 = ((u32)t3 << 4);
            f32* t6 = (f32*)(t7 + (u32)a0);
            f32* t5 = (f32*)(t2 + (u32)m);
            while (t4 < 4) {
                if ((u32)t4 != a2) {
                    *t5 = *t6;
                    t5 = t5 + 1;
                }
                t4 = t4 + 1;
                t6 = t6 + 1;
            }
            t2 = t2 + 12;
        }
        t3 = t3 + 1;
    }

    if (((a1 + a2) & 1) != 0) {
        return -func_0011bd70(m);
    }
    return func_0011bd70(m);
}

void func_0011c2d0(u8* a0) {
    *(u32*)(a0 + 0x10) = 0;
    *(u32*)(a0 + 0x14) = 0;
    *(u32*)(a0 + 0x18) = 0;
    *(u32*)(a0 + 0x1c) = 0;
    *(u32*)(a0 + 0x20) = 0;
    *(u32*)(a0 + 0x24) = 0;
    *(u32*)(a0 + 0x28) = 0;
    *(u32*)(a0 + 0x2c) = 0;
    *(u32*)(a0 + 0x30) = 0;
    *(u32*)(a0 + 0x34) = 0;
    *(u32*)(a0 + 0x38) = 0;
    *(u32*)(a0 + 0x100) = 0;
    *(u32*)(a0 + 0x104) = 0;
    *(u32*)(a0 + 4) = 0;
    *(u32*)(a0 + 0x124) = 0;

    u32 next = D_00347930;
    *(u32*)(a0 + 0) = next;
    D_00347930 = (u32)a0;

    *(u32*)(a0 + 0x108) = 0;
    *(u32*)(a0 + 0x10c) = 0;
}

void func_0011c438(u8* a0) {
    u8* s0 = a0;
    func_0011eea8(*(u32*)(a0 + 0x14), (u32)s0);

    u8* t7 = (u8*)D_00347930;
    u8* t5 = 0;

    if (t7 != 0 && t7 != s0) {
        do {
            t5 = t7;
            t7 = *(u8**)t7;
            if (t7 == 0) {
                break;
            }
        } while (t7 != s0);
    }

    if (t5 != 0) {
        *(u32*)t5 = *(u32*)s0;
    } else {
        D_00347930 = *(u32*)s0;
    }
}

void func_0011ea98(u32 a0, u32 a1) {
    u32 s0 = *(u32*)(a0 + 0x38);
    u32 s1 = a1;

    while (s0 != 0) {
        u32 t7 = *(u32*)s0;
        u32 v0 = ((Fn4)(*(u32*)(t7 + 0xc)))(s0, 1, 0xffff, s1);
        if (v0 != 0) {
            func_00132e28(s0, s1);
        }
        v0 = func_00132350(s0);
        if (v0 != 0) {
            s0 = v0;
            continue;
        }
        break;
    }
}

void func_0011eb08(u32 a0, u32 a1) {
    u32 s0 = *(u32*)(a0 + 0x38);
    u32 s1 = a1;

    while (s0 != 0) {
        u32 t7 = *(u32*)s0;
        u32 v0 = ((Fn4)(*(u32*)(t7 + 0xc)))(s0, 1, 0xffff, s1);
        if (v0 != 0) {
            func_00132ec0(s0, s1);
        }
        v0 = func_00132350(s0);
        if (v0 != 0) {
            s0 = v0;
            continue;
        }
        break;
    }
}

void func_0011eb78(u32 a0, u32 a1) {
    u32 s0 = *(u32*)(a0 + 0x38);
    u32 s1 = a1;

    while (s0 != 0) {
        u32 t7 = *(u32*)s0;
        u32 v0 = ((Fn4)(*(u32*)(t7 + 0xc)))(s0, 1, 0xffff, s1);
        if (v0 != 0) {
            func_00132f38(s0);
        }
        v0 = func_00132350(s0);
        if (v0 != 0) {
            s0 = v0;
            continue;
        }
        break;
    }
}

void func_0011ec28(u8* a0, u32 a1, u32 a2, u32 a3) {
    u32 s1 = a3;
    u8* s2 = a0;
    u32 s3 = a1;

    func_0011ecc8();
    u32 s4 = a2;

    u32 obj = *(u32*)(s2 + 0x10);
    u32 t7 = *(u32*)obj;
    u32 v0 = ((FnAlloc)(*(u32*)(t7 + 0x0)))(obj, s1 + 0x10, 0);

    *(u32*)(v0 + 0x0) = s3;
    *(u32*)(v0 + 0x4) = s1;
    *(u32*)(v0 + 0x8) = 0;
    *(u32*)(v0 + 0xc) = 0;
    func_002fdd68(v0 + 0x10, s4, s1);

    *(u32*)(v0 + 0x8) = 0;
    *(u32*)(v0 + 0xc) = *(u32*)(s2 + 0x124);
    *(u32*)(s2 + 0x124) = v0;
}

u32 func_00124140(u8* a0) {
    s32 s1 = 0;
    u32 s2 = 0;

    s32 t7 = *(s32*)(a0 + 0x10);
    if (t7 > 0) {
        do {
            VObj* obj = func_00124748((u32)a0, (u32)s1);
            VCall48 fn = (VCall48)obj->vtbl[12];
            u32 v = fn(obj);
            s1 = s1 + 1;
            t7 = *(s32*)(a0 + 0x10);
            s2 = s2 + v;
        } while (s1 < t7);
    }

    return s2;
}

void func_00127c70(u32 a0, Obj* a1, u32 a2) {
    Obj* s0 = a1;
    u32 s1 = a2;

    u32 t7 = *(u32*)(s1 + 12);
    if (t7 != 0) {
        ((VCall4)s0->vtbl[1])(s0, t7);
    }

    t7 = *(u32*)(s1 + 16);
    if (t7 != 0) {
        ((VCall4)s0->vtbl[1])(s0, t7);
    }

    func_00124840(s1);
    ((VCall4)s0->vtbl[1])(s0, s1);
    (void)a0;
}

u32 func_00129008(u32 a0, u32 a1, u8* a2, u32 a3, u32 a4, u32 a5) {
    u32 t3 = a3;
    u32 t5 = a4;
    u32 t4 = a5;

    u32 out_a3 = -1;
    u32 out_a4 = t3;
    u32 out_a5 = t5;
    u32 out_a6 = t4;

    if (*(u8*)(a2 + 0) == 5) {
        out_a3 = *(u16*)(a2 + 6);
        a2 = (u8*)(u32)(*(u16*)(a2 + 4));
        return func_00128e98(a0, a1, (u32)a2, out_a3, out_a4, out_a5, out_a6);
    }

    a2 = (u8*)(u32)(*(u16*)(a2 + 4));
    return func_00128e98(a0, a1, (u32)a2, out_a3, out_a4, out_a5, out_a6);
}

u32 func_00132208(u32 a0) {
    u32 t5 = 0;
    u32 v0;
    u32 t7;
    u32 t6;

    if (a0 == 0) {
        goto L0013224c;
    }

    v0 = func_001320b0(a0);
    t7 = 0x41584554;
    t5 = 1;
    if (v0 == t7) {
        goto L0013224c;
    }

    t6 = (t7 < v0);
    if (t6 != 0) {
        goto L0013225c;
    }

    t7 = 0x354e4b5f;

L00132244:
    if (v0 != t7) {
        t5 = 0;
    }

L0013224c:
    return t5;

L0013225c:
    t7 = 0x43535655;
    if (v0 == t7) {
        goto L0013224c;
    }

    t7 = 0x594d445f;
    goto L00132244;
}

void func_00133598(u32 a0, u32 a1, u32 a2) {
    u32 t6 = a1 + 15;
    *(u8*)(a0 + 0) = 0;
    t6 = t6 & 0xFFFFFFF0;

    u32 a1n = a1 + a2;
    a1n = a1n - t6;
    a1n = a1n >> 1;

    u32 t7 = t6 + a1n;
    (*(u32*)(a0 + 8) = t6, *(u32*)(a0 + 12) = t7, *(u32*)(a0 + 4) = t6);
    *(u32*)(a0 + 16) = a1n;

    u32 v0 = func_001336f8(a0);
    *(u32*)(a0 + 24) = v0;

    *(u32*)(a0 + 20) = 0;
    *(u32*)(a0 + 28) = 0;

    func_00133be8(a0, 0, 0, 0);
    func_00133690(a0);
    func_00133be8(a0, 0, 0, 0);
    func_00133690(a0);
}

void func_00133de8(void) {
    func_002f25a0(0, 0);
    func_00133d18();

    u32 v0 = func_00133d38();
    D_00347cac = v0;

    func_002f3918(v0, (u32)&D_0032a780);
    func_00134030();

    D_00347cb4 = 0;
    D_00347cb0 = 0xFFFFFFFF;
}

void func_00133e50(void) {
    u32 s0 = (u32)&D_00347c88;

    func_00133c60(s0, (u32)&D_0032a870, 0, 0, 0);
    func_00133be8(s0, 0, 0, 0);
    func_00133768(s0);
}

void func_00133ea8(void) {
    u32 s0 = (u32)&D_00347c88;

    func_00133c60(s0, (u32)&D_0032a870, 0, 0, 0);
    func_00133be8(s0, 0, 0, 0);
    func_00133690(s0);
    func_00133c60(s0, (u32)&D_0032a850, 0, 0, 0);
}

void func_00135818(u32 a0, u32 a1) {
    u32 s1 = a1;
    u32 s2 = a0;
    u32 s0 = D_00347cf0;

    if (s0 != 0) {
        u32 a4 = s0;
L00135844:
        func_00135cc8(a4, s2, s1);
        s0 = *(u32*)(s0 + 8);
        if (s0 != 0) {
            a4 = s0;
            goto L00135844;
        }
    }
}

void func_001364b8(u32 a0, u32 a1, u32 a2) {
    u32 s2 = a0;
    u32 s3 = a2;
    u32 flag;

    u32 s0 = func_002ba0b0(a1);
    u32 s1 = func_00136790(s0, (u32)&flag);

    if (flag != 0) {
        func_001367e0(s2, s0, s1);
        func_002ba3b8(s3, s1, flag, 0, 0, 0, 0);
        func_002ba7c8(s2);
    }

    func_001367c8(s1);
}

void func_001372d8(void) {
    D_00347d50 = 1;

    if (D_00347d30 != 0) {
        func_002ba2b0(960, 0);
    }

    if (D_00347d40 != 0) {
        func_002ba220(1, 0, 12288, 240, 0, 240);
        return;
    }
}

void func_00137340(void) {
    D_00347d50 = 0;

    if (D_00347d40 != 0) {
        func_002ba2b0(720, 1);
    }

    if (D_00347d30 != 0) {
        func_002ba220(0, 0, 12288, 480, 1, 240);
        return;
    }
}

void func_001373d8(void) {
    D_00347d54 = D_00347d56;
    D_00347d50 = 0;
    D_00347d55 = 0;

    if (D_00347d30 != 0) {
        func_002ba220(0, 12288, 12288, 0, 0, 0);
        func_00136b78(0, 12288);
        func_00136b78(1, 0);
    }

    func_00136a50();
    func_00136878();
}

void func_00138d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    func_001386e0(a0, a1, a2, a3, a4, a6);

    *(u32*)(a0 + 408) = a5;
    *(u32*)(a0 + 412) = 0;
    *(u32*)(a0 + 420) = 0x80E5E5E5;
    *(u32*)(a0 + 416) = 0;
    *(u32*)(a0 + 432) = 0;

    s32 v0 = func_0023aa58(a0 + 24);
    *(u32*)(a0 + 428) = 0;

    u32 v1 = 15;
    if (0 < v0) {
        v1 = (u32)v0;
    }

    *(u32*)(a0 + 424) = v1;
    func_001395e8(a0);
    func_00139610(a0);
    func_00139638(a0);
}

void func_001390f0(u32 a0) {
    if ((*(u32*)(a0 + 12) & 0x100) != 0) {
        return;
    }

    u32 v0 = func_0013a178(a0 + 416, D_00347f80 + 32);
    *(u32*)(a0 + 368) = *(u32*)(v0 + 0);
    *(u32*)(a0 + 372) = *(u32*)(v0 + 4);
    *(u32*)(a0 + 432) = *(u32*)(v0 + 8);

    ((void (*)(u32))(*(u32*)(*(u32*)a0 + 24)))(a0);
    func_00138840(a0);
}

void func_00139200(u32 a0) {
    u32 s0 = *(u32*)(a0 + 8);
    u32 s1 = *(u32*)(a0 + 4);

    *(u32*)(s1 + 96) = s0;
    if ((*(u32*)(s0 + 12) & 0x20) == 0) {
        ((void (*)(u32))(*(u32*)(*(u32*)s0 + 4)))(s0);
    }

    *(u32*)(s1 + 96) = 0;
    u32 p = s1 + 12;
    u32 n = *(u32*)(p + 4);

    if (n == 0) {
        *(u32*)(p + 4) = s0;
        *(u32*)(s1 + 12) = s0;
        *(u32*)(s0 + 8) = 0;
        return;
    }

    *(u32*)(n + 8) = s0;
    *(u32*)(s0 + 8) = 0;
    *(u32*)(p + 4) = s0;
}

void func_00139280(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 v0 = func_00102788(*(u32*)D_00347f80, 0, a1, (u32)func_00139200);
    u32 t = D_00347f80;

    *(u32*)(v0 + 8) = s1;
    *(u32*)(v0 + 4) = t;
    *(u32*)(s1 + 20) = v0;

    u32 head = D_00347f80;
    u32 p = head + 4;
    u32 n = *(u32*)(p + 4);

    if (n == 0) {
        *(u32*)(p + 4) = s1;
        *(u32*)(head + 4) = s1;
        *(u32*)(s1 + 4) = 0;
        return;
    }

    *(u32*)(n + 4) = s1;
    *(u32*)(s1 + 4) = 0;
    *(u32*)(p + 4) = s1;
}

void func_0013a8f8(void) {
    u32 a0;
    u8* p = &D_0032bae0;
    if (func_001948c0((u32)p[1], (u32)p[0]) != 0) {
        D_00347ff8 = 1;
        a0 = 1;
    } else {
        D_00347ff8 = 0;
        a0 = 0;
    }

    func_001dd208(a0);
    D_00347ffc = 1;
}

void func_0013b128(u32 a0) {
    s32 t15 = -1;
    s32 t11 = 0;
    *(u32*)(a0 + 248) = (u32)t15;
    s32 t10 = -1;
    u32 t12 = a0;

L0013b13c:
    {
        u32 t15 = (u32)t11 << 3;
        *(u32*)(t12 + 220) = (u32)t10;
        u32 t14 = t15 + (u32)t11;
        *(u32*)(t12 + 204) = (u32)t10;
        u32 t9 = t15 + a0;
        t14 = (t14 << 2);
        t15 = t9 + (u32)t11;
        t14 = t14 + a0;
        t15 = t15 + 168;
        t14 = t14 + 24;

        s32 t13 = 8;
L0013b168:
        *(u32*)t14 = 0;
        t13 = t13 - 1;
        *(u8*)t15 = 0;
        t14 = t14 + 4;
        if (t13 >= 0) {
            t15 = t15 + 1;
            goto L0013b168;
        }
    }

    t11 = t11 + 1;
    if (t11 < 4) {
        t12 = t12 + 4;
        goto L0013b13c;
    }
}

void func_0013b348(u32 a0) {
    u32 s1 = a0;
    u32 v0 = D_003484a0;
    if (v0 != 0) {
        func_0013b258(v0, s1);
        return;
    }

    func_0013b570();
    func_0013ad20();

    u32 mgr = D_00347f80;
    u32 obj = *(u32*)(mgr + 20);
    u32 s0 = ((u32(*)(u32, u32, u32))(*(u32*)(*(u32*)obj + 0)))(obj, 696, 0);
    func_0013b088(s0);
    D_003484a0 = s0;
    func_0013b260(s0, s1);
    func_0013b508();
    func_0013b5a8();
}

void func_0013b3f8(void) {
    u32 v0 = D_003484a0;
    if (v0 == 0) {
        return;
    }

    func_0013b570();
    func_0013b1d0(D_003484a0);
    func_0013d2d0(D_003484a0);
    func_0013b1a0(D_003484a0);
    func_0013b4b0();
    func_0013b5a8();
}

void func_0013b458(void) {
    func_0013b538();
    func_0013b570();
    func_0013aed8();

    u32 p = D_003484a0;
    if (p != 0) {
        ((void (*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        D_003484a0 = 0;
    }

    func_0013b5a8();
}

void func_0013b838(u32 a0) {
    s32 s2 = 0;
    u32* s3 = &D_004573c0;
    u32 s4 = a0;

L0013b864:
    {
        s32 s1 = (s32)*s3;
        if (s1 < 9) {
            u32 off = (s2 << 3) + s2;
            off = off + s1;
            off = off << 2;
            u32 s0 = off + s4;

L0013b884:
            {
                u32 p = *(u32*)(s0 + 24);
                if (p != 0) {
                    ((void (*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
                    *(u32*)(s0 + 24) = 0;
                }
                s1 = s1 + 1;
                if (s1 < 9) {
                    s0 = s0 + 4;
                    goto L0013b884;
                }
            }
        }
    }

    s2 = s2 + 1;
    if (s2 < 4) {
        s3 = (u32*)((u8*)s3 + 4);
        goto L0013b864;
    }
}

void func_0013b8e8(u32 a0, s32 a1, s32 a2) {
    s32 s2 = a1;
    s32 s3 = a2;
    u32 s4 = a0;

    if (s2 >= s3) {
        return;
    }

L0013b91c:
    {
        s32 s1 = 8;
        u32 off = ((u32)s2 << 3) + (u32)s2;
        off = off << 2;
        u32 s0 = off + s4;

L0013b92c:
        {
            u32 p = *(u32*)(s0 + 24);
            if (p != 0) {
                ((void (*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
                *(u32*)(s0 + 24) = 0;
            }
            s1 = s1 - 1;
            if (s1 >= 0) {
                s0 = s0 + 4;
                goto L0013b92c;
            }
        }

        s2 = s2 + 1;
        if (s2 < s3) {
            goto L0013b91c;
        }
    }
}

u32 func_0013b988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    u32 i = a2 & 0xFF;
    u32 b4 = a4 & 0xFF;
    u32 b5 = a5 & 0xFF;

    if (b5 == 1) {
        return *(u32*)((u32)&D_003484a8 + (i << 2));
    }
    if (b4 == 1) {
        return *(u32*)((u32)&D_003484f8 + (i << 2));
    }
    return *(u32*)((u32)&D_003484d0 + (i << 2));
}

u32 func_0013d390(u32 a0) {
    u32 s0 = a0 + 260;
    u32 v0;

    if (*(u8*)(s0 + 404) != 0) {
        goto Lret1;
    }

    if (func_0013c7d0() == 0) {
        goto Lret0;
    }

    v0 = func_0013cb90();
    v0 = (v0 << 3);
    v0 = v0 + (u32)&D_00348578;
    func_00138c10(s0, *(u32*)(v0 + 4));

Lret1:
    return 1;
Lret0:
    return 0;
}

void func_0013d4c8(void) {
    u32* p = &D_004573c0;
    s32 i = 3;

L0013d4e0:
    *p = 0;
    i = i - 1;
    if (i >= 0) {
        p = (u32*)((u8*)p + 4);
        goto L0013d4e0;
    }

    func_0013b838(D_003484a0);
    *(u8*)(D_003484a0 + 253) = 0;
    *(u8*)(D_003484a0 + 252) = 0;
    *(u8*)(D_003484a0 + 681) = 0;
    *(u32*)(D_003484a0 + 240) = 0;
    *(u32*)(D_003484a0 + 244) = 0xFFFFFFFFu;
    *(u8*)(D_003484a0 + 255) = 0;
    func_0013d7d0();
}

void func_0013daf8(void) {
    if (D_003485fc == 0) {
        return;
    }

    func_00139858(3);
    func_00139ba0(3);
    func_00139858(4);
    func_00139ba0(4);
    func_00139858(5);
    func_00139ba0(5);
    func_00139858(6);
    func_00139ba0(6);
}

void func_0013dfb8(u32 a0) {
    func_001391c8(a0);
    u32 s0 = a0 + 32;
    func_0013ee38(s0, 4);
    ((dk::Ft4Base*)s0)->setRot(0.0f);
    func_0013ee18(s0, 0x00032001u);
    func_0014b208(s0, 50, 120);
    ((dk::Ft4Base*)s0)->setCenterXY(-25, -60);
}

void func_0013e520(u32 a0, u32 a1) {
    u32 s0 = a0 + 448;
    u32 s1 = a1 & 0xFF;

    if (func_00139d78(s0) == 0) {
        return;
    }

    if (s1 == 1) {
        func_001395a8(s0);
        func_00139718(s0);
    } else {
        func_00139598(s0);
        func_00139708(s0);
    }
}

void func_0013e808(void) {
    u32 p = D_003486a0;
    if (p != 0) {
        ((void (*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        D_003486a0 = 0;
    }

    u32 s1 = D_003486a4;
    if (s1 != 0) {
        u32 s0 = s1 + 8064;
L0013e84c:
        if (s1 != s0) {
            s0 = s0 - 896;
            ((void (*)(u32))(*(u32*)(*(u32*)s0 + 12)))(s0);
            goto L0013e84c;
        }

        func_00106420(s1);
        D_003486a4 = 0;
    }
}

u32 func_0013ef90(u32 a0) {
    func_0014df88(a0);
    if ((D_00348704 & 0x40000000) == 0) {
        func_0014e0d8(216);
    } else {
        func_0014e098();
    }
    return func_001024a8(a0);
}

u32 func_0013f230(void) {
    func_0013efe8();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f198;
    func_00102788(a0, 0, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa58(v0, 15, 0);
}

u32 func_0013f288(void) {
    func_0013f030();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f1e8;
    func_00102788(a0, 1, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa80(v0, 15, 0);
}

u32 func_0013f378(void) {
    func_0013efe8();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f2e0;
    func_00102788(a0, 0, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa58(v0, 15, 1);
}

u32 func_0013f3d0(void) {
    func_0013f030();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f330;
    func_00102788(a0, 1, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa80(v0, 15, 1);
}

void func_00140d38(u32 a0, u32 a1) {
    u8* s0 = D_00348710;
    *(u32*)(s0 + 68) = a0;

    if (func_00140dc0() == 7) {
        return;
    }

    *(u32*)(s0 + 60) = a1;
    *(u32*)(s0 + 64) = 0;
    func_00140ef8((u32)s0);

    if (func_001069e8() == 1) {
        return;
    }

    func_001069b8(0);
}

void func_00143060(u32 a0) {
    u32 s0 = a0 & 0xFF;

    func_00145c28(D_00348800, s0);

    if (D_00348814 != 0) {
        func_001418e8(D_00348814, s0);
    }
    if (D_00348804 != 0) {
        func_001418e8(D_00348804, s0);
    }
    if (D_00348810 != 0) {
        func_001418e8(D_00348810, s0);
    }
    if (D_0034880c != 0) {
        func_001418e8(D_0034880c, s0);
    }
    if (D_00348808 != 0) {
        func_001418e8(D_00348808, s0);
    }
}

void func_00143110(u32 a0) {
    u32 s0 = a0 & 0xFF;

    func_00145c68(D_00348800, s0);

    if (D_00348814 != 0) {
        func_00141928(D_00348814, s0);
    }
    if (D_00348804 != 0) {
        func_00141928(D_00348804, s0);
    }
    if (D_00348810 != 0) {
        func_00141928(D_00348810, s0);
    }
    if (D_0034880c != 0) {
        func_00141928(D_0034880c, s0);
    }
    if (D_00348808 != 0) {
        func_00141928(D_00348808, s0);
    }
}

void func_001433e8(void) {
    func_00146d68(D_00348800);
    u32 s0 = D_00348818;
    func_0011c4b0(*(u32*)s0);

    if (*(u8*)(s0 + 140) != 0) {
        return;
    }

    func_0011ea40(*(u32*)s0, D_00349e10);
}

u32 func_00143e50(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a1 & 0xFFFF;
    u32 t7 = a2 & 0xFF;
    u32 a2v = t5;
    u32 s0 = a0;

    if (t7 != 0) {
        u32 t6 = D_00348808;
        if (t6 != 0) {
            func_001422a0(s0, t6, a2v);
            return s0;
        }
    }

    func_001422a0(s0, D_00348804, a2v);
    return s0;
}

u32 func_00144d10(f32* a0, f32* a1) {
    if (a0[3] < a1[0]) {
        return 0;
    }
    f32 f1 = a0[0];
    f32 f0 = a1[3];
    if (f0 < f1) {
        return 0;
    }
    if (a0[4] < a1[1]) {
        return 0;
    }
    f1 = a0[1];
    f0 = a1[4];
    if (f0 < f1) {
        return 0;
    }
    if (a0[5] < a1[2]) {
        return 0;
    }
    f1 = a0[2];
    f0 = a1[5];
    if (f0 < f1) {
        return 0;
    }
    return 1;
}

u32 func_00144d90(f32* a0, f32* a1) {
    f32 f1 = a0[0];
    f32 f0 = a1[0];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[3];
    f0 = a1[3];
    if (f1 < f0) {
        return 0;
    }

    f1 = a0[1];
    f0 = a1[1];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[4];
    f0 = a1[4];
    if (f1 < f0) {
        return 0;
    }

    f1 = a0[2];
    f0 = a1[2];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[5];
    f0 = a1[5];
    if (f1 < f0) {
        return 0;
    }

    return 1;
}

void func_001461f0(u32 a0, u8* a1) {
    u32 s0 = *(u32*)(a1 + 44);
    u32 s1 = a0;
    if (s0 == 0) {
        return;
    }

    do {
        u32 t7 = *(u32*)(s0 + 248);
        if ((t7 & 0x800) == 0) {
            func_001471d8(s1, s0);
        } else {
            func_001471d8(s1, s0);
        }
        s0 = *(u32*)(s0 + 272);
    } while (s0 != 0);
}

void func_00148ac0(u8* a0) {
    s32 s0 = 0;
    u32* s2 = D_003a99f0;
    s32 s1 = *(s32*)(a0 + 21372);

    while (s0 < 256) {
        if (s1 <= 0) {
            return;
        }

        u32 t7 = *s2;
        s2 += 1;
        if (t7 != 0) {
            func_00147f08((u32)a0, t7);
            s1 -= 1;
        }

        s0 += 1;
    }
}

void func_00148bc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 cur = *(u32*)(a1 + 44);
    if (*(u32*)a2 == cur) {
        return;
    }
    if (cur == 0) {
        return;
    }

    while (cur != 0) {
        if (func_00144d10(cur + 208, a3) == 1) {
            if ((*(u32*)(cur + 248) & 2) != 0) {
                func_00148b40(a0, cur);
            }
        }
        cur = *(u32*)(cur + 272);
    }
}

void func_001491d8(u32 a0) {
    *(u32*)(a0 + 32) = 0;
    *(u32*)(a0 + 36) = 0;
    *(u32*)(a0 + 40) = 0;
    *(u32*)(a0 + 44) = 0;
    *(u32*)(a0 + 48) = 0;
    *(u32*)(a0 + 52) = 0;
    *(u32*)(a0 + 56) = 0;
    *(u32*)(a0 + 60) = 0;
    *(u32*)(a0 + 64) = 0;
    *(u32*)(a0 + 68) = 0;
    *(u32*)(a0 + 72) = 0;
    *(u32*)(a0 + 76) = 0;
    *(u32*)(a0 + 80) = 0;
    *(u32*)(a0 + 100) = 0;
    *(u32*)(a0 + 104) = 0;
    *(u32*)(a0 + 108) = 0;
    *(u32*)(a0 + 112) = 0;
    *(u32*)(a0 + 116) = 0;
    *(u32*)(a0 + 1272) = 0;
    *(u8*)a0 = 0;

    s32 p = (s32)a0;
    s32 end = (s32)(a0 + 1152);
    *(u32*)(p + 120) = 0;
    while (1) {
        *(u32*)(p + 124) = 0;
        *(u32*)(p + 128) = 0;
        p += 12;
        if (p < end) {
            *(u32*)(p + 120) = 0;
        } else {
            break;
        }
    }

    p = (s32)(a0 + 84);
    s32 i = 3;
    do {
        *(u32*)p = 0;
        i -= 1;
        p += 4;
    } while (i >= 0);
}

void func_0014ddb0(u32 a0) {
    u32 s0 = a0;
    func_0014d8d0(a0 + 16);
    u32 p = s0 + 144;
    if (*(u8*)(s0 + 473) != 1) {
        return;
    }

    u8 b2 = *(u8*)(s0 + 472);
    u8 b0 = *(u8*)(s0 + 470);
    u8 b1 = *(u8*)(s0 + 471);
    u64 v = ((u64)b0) | (1ULL << 32);
    u64 t = (((u64)b2) << 16) | (1ULL << 31);
    v |= t;
    v |= ((u64)b1) << 8;
    *(u64*)(s0 + 184) = v;
    func_0014d8d0(p);
}

u32 func_0014f788(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 b34 = 0x00340000;
    u32 s1 = a4;
    u32 s2 = a1;
    u32 s3 = a2;
    u32 s4 = a3;
    u32 s5 = a0;

    u32 t = *(u32*)(b34 + 32640);
    u32 obj = *(u32*)(t + 20);
    u32 fn = *(u32*)(*(u32*)obj + 0);
    u32 s0 = ((u32 (*)(u32, u32, u32))fn)(obj, 6576, 0);
    func_0031bd98(s0);
    func_00150de0(s0, s5, s2, s3, s4, s1);
    return s0;
}

void func_00150260(u32 a0, u32 a1, s32 a2, u32 a3) {
    char buf[16];
    u32 s1 = a0;
    s32 s2 = a2;
    u32 s0 = a3;

    func_002fee78((u32)buf, (u32)D_0036b228, a1);

    if (s2 > 0) {
        s32 n = s2;
        char* p = &buf[8];

        do {
            s32 d = (s32)(*p) - 48;
            n--;
            p--;
            u32 idx = ((u32)d) << 2;
            idx = idx + s1;
            *(u32*)s0 = *(u32*)idx;
            s0 += 4;
        } while (n != 0);
    }
}

void func_001505b0(u32 a0) {
    u32 s1 = a0 + 840;
    func_00138c10(s1, 4);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 1248;
    func_00138c10(s0, 10);
    *(s32*)(s0 + 392) = s2;
}

void func_00150678(u32 a0) {
    *(u32*)(a0 + 6176) = 1;

    u32 s1 = a0 + 840;
    func_00138c10(s1, 5);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 1248;
    func_00138c10(s0, 11);
    *(s32*)(s0 + 392) = s2;
}

void func_00151528(u32 a0) {
    *(u32*)(a0 + 6568) = 1;

    u32 s1 = a0 + 496;
    func_00138c10(s1, 5);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 904;
    func_00138c10(s0, 11);
    *(s32*)(s0 + 392) = s2;
}

void func_00151b78(u32 a0) {
    u32 s1 = a0 + 840;
    func_00138c10(s1, 4);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 2472;
    func_00138c10(s0, 10);
    *(s32*)(s0 + 392) = s2;
}

void func_00151bf0(u32 a0) {
    *(u32*)(a0 + 2896) = 1;

    u32 s0 = a0;
    u32 s1 = a0 + 840;

    func_00138c10(s1, 5);
    s0 = s0 + 2472;
    func_00138c10(s0, 11);

    s32 v = -1;
    *(s32*)(s1 + 392) = v;
    *(s32*)(s0 + 392) = v;
}

void func_00152718(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8 buf[96];
    u32 s1 = a0 + 24;
    u32 s2 = a1;
    u32 s3 = a2;
    u32 s4 = a3;

    u32 n = *(u32*)(a0 + 440);
    if (n == 0) {
        return;
    }

    volatile u32* vp = (volatile u32*)a0;
    u32 a1v = vp[107];
    u32 a3v = vp[106];
    func_001a98e8(buf, a1v, n, a3v, 0);

    u32 s0 = s2 + func_0023aa18(s1);
    u32 v = func_0023aa38(s1);
    func_001a9ae8(buf, s0, s3 + v + 17, s4);
}

void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8 buf[96];
    u32 s2 = a3;
    u32 s0 = a1;
    u32 s1 = a2;

    func_001a98e8(buf, 1, *(u32*)(a0 + 436), *(u32*)(a0 + 424), 1);
    func_001a9ae8(buf, s0, s1, s2);
}

void func_00152910(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);

    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    func_00152688(s0, v2, v3, v4);
    func_00152718(s0, v0, v1, v4);
}

void func_00152a30(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);
    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    if (*(u32*)(s0 + 448) != 0) {
        func_00152688(s0, v2, v3, v4);
    }
    func_00152718(s0, v0, v1, v4);
}

void func_00152ae8(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);
    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    func_00152688(s0, v2, v3, v4);
}

void func_00153cc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u8 ctx[32];
    u32 s0 = a0;
    u32 s2 = a2;
    u32 s3 = a3;
    u32 s4 = a4;

    *(u32*)(s0 + 160) = a1;

    func_0023f800(ctx);
    func_0023fa08(ctx, *(u32*)(s0 + 160));

    u32 s1 = func_0023f948(ctx, 0);
    u32 v = func_0023f908(ctx, 0);

    func_0023eea0(s0, s2, s1, v, s3, s4);
    func_0023f848(ctx);
}

void func_00153ea0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s0 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a4;

    u32 v = func_001708f8(a1, 0xFFFFFFFFu);
    func_00153cc8(s0, v, s1, s2, s3);
}

u32 func_001541d8(u32 a0, u32 a1, u32 a2) {
    *(u8*)(a0 + 836) = 0;

    u32 s1 = a0;
    u32 p = a1;
    u32 kind = a2;

    u32 tmp0;
    u32 tmp1;
    u32 tmp2;

    if (kind != 0) {
        u32 s2 = func_0016c060(kind, (u32)&tmp0, p);
        u32 p1 = (u32)&tmp1;
        u32 p2 = (u32)&tmp2;
        if (s2 == 1) {
            u32 s0 = s1 + 416;
            func_00154100(s1, p1, p2);
            func_002362b0(s0, tmp0);
            func_00236410(s0, tmp1);
            func_00236428(s0, tmp2);
            func_002367c8(s0);
            *(u8*)(s1 + 836) = (u8)s2;
            return 1;
        }
    }

    return 0;
}

void func_001543a0(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a2;

    if (*(u8*)(a0 + 836) != 0) {
        if (a1 == 1) {
            func_00138c10(a0, a1);
            *(u32*)(s0 + 392) = func_00154288(s0, s1);
            return;
        }
        func_00138c10(a0, a1);
    }
}

u32 func_00154450(u32 a0, u32 a1, u32 a2) {
    *(u32*)(a0 + 15556) = a2;

    u32 s0 = a0;
    *(u32*)(s0 + 15552) = a1;
    u32 s1 = a1;
    *(u32*)(s0 + 15560) = a1;
    *(u32*)(s0 + 15564) = a1;

    func_00154af0(s0);
    func_00154b98(s0, s1);

    u32 vtbl = *(u32*)s0;
    u32 fn = *(u32*)(vtbl + 4);
    ((void (*)(u32))fn)(s0);

    return s0;
}

void func_00154a88(u32 a0) {
    u32 s0 = a0;

    if (*(u8*)(a0 + 15584) != 0) {
        if ((*(u32*)(a0 + 12) & 0x100) == 0) {
            func_0014fcd8(a0);
            ((dk::Sprite*)(u32)(s0 + 48))->setPos(*(u32*)(s0 + 32), *(u32*)(s0 + 36));
            func_00154950(s0);
        }
    }
}

void func_00155300(u32 a0) {
    u32 s0 = a0;
    u32 s1 = func_0013dda0(*(u32*)(s0 + 48) + 1);
    u32 p;
    *(u32*)(s0 + 52) = s1;

    if (*(u8*)(s0 + 5538) != 0) {
        goto L_call_55528;
    }
    *(u8*)(s0 + 5538) = 1;
L_after_flag:
    func_001542c8(s0 + 64, s1, *(u32*)(s0 + 24));
    *(u8*)(s0 + 5536) = 1;

    p = *(u32*)(s0 + 52);
    if (p != 0) {
        u32 v = *(u32*)(*(u32*)(p + 1164));
        *(u32*)(s0 + 40) = v;
        *(u32*)(s0 + 36) = v;
    }
    return;

L_call_55528:
    func_00155528(s0);
    goto L_after_flag;
}

void func_00155390(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = s0 + 916;
    u32 s2 = a1;

    *(u32*)(s0 + 36) = *(u32*)(a0 + 40);
    *(u32*)(s0 + 40) = *(u32*)(*(u32*)(*(u32*)(s0 + 52) + 1164));

    func_00138c10(a0 + 1328, 64);
    func_00138c10(s1, s2);
    *(u32*)(s1 + 392) = func_00154ee8(s0);
    func_001543a0(s0 + 64, 1, *(u32*)(s0 + 24));
}

void func_001554c0(u32 a0) {
    u32 s0 = a0;
    if (*(u8*)(s0 + 32) != 0) {
        return;
    }

    if (func_0013c7d0() != 0) {
        func_00138c10(s0 + 916, func_00154ee8(s0));
        *(u8*)(s0 + 32) = 1;
        return;
    }

    if (*(u8*)(s0 + 1320) != 0) {
        *(u8*)(s0 + 32) = 1;
    }
}

void func_001556f0(u32 a0) {
    u32 s0 = a0;
    func_00158300(s0);
    if (*(u32*)(s0 + 52) == 0) {
        return;
    }
    if ((*(u32*)(s0 + 12) & 0x100) != 0) {
        return;
    }
    func_001554c0(s0);
    func_00155568(s0);
    func_00155658(s0);
    return func_001556c0(s0);
}

u32 func_00155d80(u32 a0) {
    u32 s0 = a0;
    u32 sp0;
    u32 sp4;
    u32 v0;
    u32 p;
    u32 cur;
    u32 old;
    if (func_00156058(s0) != 0) {
        sp0 = 0;
        goto L_common;
    }
    if (func_00156080(s0) == 0) {
        goto L_path2;
    }
    sp0 = 0;

L_common:
    sp4 = 0;
    v0 = func_001560a8(s0, (u32)&sp0, (u32)&sp4);
    old = (u32)*(u8*)(s0 + 15605);
    if (old != v0) {
        if (old < v0) {
            *(u8*)(s0 + 15608) = 1;
        }
        *(u8*)(s0 + 15605) = (u8)v0;
        *(u8*)(s0 + 15607) = 1;
    }
    goto L_end;

L_path2:
    p = *(u32*)(s0 + 52);
    if (p == 0) {
        v0 = 0;
        goto L_end;
    }
    v0 = (u32)*(u8*)(*(u32*)(p + 1164) + 433);
    cur = (u32)*(u8*)(s0 + 15604);
    if (cur != v0) {
        if (cur < v0) {
            *(u8*)(s0 + 15608) = 1;
        }
        *(u8*)(s0 + 15604) = (u8)v0;
        *(u8*)(s0 + 15606) = 1;
    }

L_end:
    return v0;
}

void func_00156408(u32 a0) {
    u32 s0 = a0;
    s32 s1;

    if (func_00156010(s0) != 0) {
        s1 = 12;
        s0 = s0 + 11648;
        do {
            func_00139598(s0);
            s1 = s1 + 1;
            if (s1 < 15) {
                s0 = s0 + 412;
            } else {
                break;
            }
        } while (1);
        return;
    }

    if (func_00156030(s0) == 0) {
        goto L_after_56030;
    }
    s0 = s0 + 12060;
    {
        s1 = 13;
        do {
            func_00139598(s0);
            s1 = s1 + 1;
            if (s1 < 15) {
                s0 = s0 + 412;
            } else {
                break;
            }
        } while (1);
        return;
    }

L_after_56030:
    s0 = s0 + 12060;
    s1 = 1;
    do {
        func_001395a8(s0);
        s1 = s1 - 1;
        if (s1 >= 0) {
            s0 = s0 + 412;
        } else {
            break;
        }
    } while (1);
}

u32 func_001564b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a0 + 1324;
    u32 s17 = a0;

    func_001386e0(s16, 7005, a1, a2, 27, a3);
    *(u32*)(s16 + 396) = s17 + 6704;
    func_001396b0(s16);

    if (*(u32*)(s16 + 396) != 0) {
        *(u32*)(s16 + 400) = 0;
        func_001396b0(s16);
        if (*(u32*)(s16 + 400) != 0) {
            func_0031a260(s16, 0);
        }
    }

    return func_001565a8(s17);
}

u32 func_00156540(u32 a0) {
    u32 s0 = a0;
    u32 s1;
    func_001565a8(s0);
    s1 = s0 + 1324;
    func_00138c10(s1, 27);
    u32 v0 = func_00155ee8(s0);
    if (v0 == 21) {
        return func_001395a8(s1);
    }
    return v0;
}

void func_00157758(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 52);
    if (p == 0) {
        return;
    }

    if (func_002ba358() == 0) {
        if (func_00166cc8(*(u32*)(s0 + 52)) == 0) {
            return;
        }
        return func_001576e8(s0);
    }

    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        return;
    }
    return func_001576e8(s0);
}

void func_001577c8(u32 a0) {
    u32 s0 = a0;
    u32 p;
    if (func_001396c0(s0) != 0) {
        goto L_800;
    }

    p = *(u32*)(s0 + 52);
    if (p == 0) {
        return;
    }
    if (func_00166cf0(p) == 0) {
        goto L_828;
    }

L_800:
    if (func_002ba358() == 0) {
        return;
    }
    return func_002ba390();

L_828:
    if (func_002ba358() != 0) {
        goto L_854;
    }
    if (func_00166cc8(*(u32*)(s0 + 52)) == 0) {
        return;
    }
    return func_002ba368();

L_854:
    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        return;
    }
    func_002ba390();
    return func_001576e8(s0);
}

void func_00157880(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(a0 + 52) == 0) {
        return;
    }
    if (func_002ba358() == 0) {
        return;
    }
    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        return;
    }
    return func_002ba390();
}

void func_00157a00(u32 a0) {
    u32 s0 = a0;
    u32 s1;
    u32 s2;
    u32 p;

    func_00157990(s0);
    p = *(u32*)(*(u32*)(s0 + 52) + 1164);
    s1 = *(u32*)(p + 4);
    s2 = *(u32*)(p + 0);

    func_001558b8(s0, s1, 1);
    func_001559e8(s0, s1, 4);
    func_001558b8(s0, *(u32*)(s0 + 36), 2);
    func_001559e8(s0, *(u32*)(s0 + 36), 5);
    func_001558b8(s0, s2, 3);
    return func_001559e8(s0, s2, 6);
}

void func_00158088() {
    u32 s[4];
    u32 p = (u32)s;

    s[2] = 0;
    s[1] = 0;
    func_001b7e68(p, (s[0] = 0, 16));
    func_001b8010(p, 1, 71, 0x00070000, 0xffff);
    func_001b80d8(p);
    func_001b7f30(p);
}

void func_001580e0(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(a0 + 408) != 0) {
        func_00158088();
        u32 p = s0 + 24;
        u32 m = 0xfffffffd;
        u32 x = *(u32*)(p + 16);
        *(u32*)(p + 16) = x & m;
        func_00237ad8(p, *(u32*)(s0 + 408));
    }
    return func_00138988(s0);
}

u32 func_00158138(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    u32 v;

    *(u32*)(a0 + 44) = a3;
    *(u32*)(a0 + 48) = a2;
    *(u32*)(a0 + 52) = a1;
    *(u32*)(a0 + 28) = 0;
    *(u32*)(a0 + 24) = 0;
    *(u8*)(a0 + 32) = 0;
    *(u8*)(a0 + 33) = 0;

    if (a1 != 0) {
        u32 t6 = *(u32*)(*(u32*)(a1 + 1164));
        *(volatile u32*)(a0 + 36) = t6;
        *(volatile u32*)(a0 + 40) = t6;
    } else {
        *(u32*)(a0 + 40) = 0;
        *(u32*)(a0 + 36) = 0;
    }

    v = func_00158290(s0);
    return func_001391c8(s0, 7000, v);
}

void func_001581f8(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 52);
    *(u32*)(s0 + 28) = *(u32*)(s0 + 24);
    if (func_00166cf0(p) != 0) {
        *(u32*)(s0 + 24) = 2;
        return;
    }
    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        *(u32*)(s0 + 24) = 1;
        return;
    }
    *(u32*)(s0 + 24) = 0;
}

void func_001582a8(u32 a0) {
    u32 s0 = a0;
    u32 v = func_00158290(s0);
    if (*(u32*)(s0 + 52) == 0) {
        return func_001399c0(v);
    }
    if (v != 3) {
        return func_00139948(v);
    }
}

void func_00158658(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 68);
    u32 fn = *(u32*)(*(u32*)(p + 0) + 64);
    if (((u32(*)(u32))fn)(p) != 0) {
        func_001585e8(s0);
    }
    func_0013f828(s0);
    func_0013f888(s0, s0 + 128, 0);
    return func_0013fca8(s0);
}

void func_0015a708() {
    u32 s0;
    u32 v0;

    s0 = func_00140df0();
    *(u8*)(s0 + 59) = 0;
    v0 = func_00140dc0();
    if (v0 == 6) {
        return;
    }
    if (v0 == 8) {
        return;
    }
    if (v0 != 2) {
        return;
    }
    return func_00140dd0(s0);
}

void func_0015ad28(u32 a0) {
    u32 s0 = a0;
    if (func_00139538(s0) != 0) {
        return;
    }
    func_001aa728(2, *(u32*)(s0 + 24), 256, 192, 0x80ffffff, 0, 4);
}

void func_0015ad80(u32 a0, u32 a1, f32 a2) {
    u32 s1 = a0;
    u32 s2 = a1;
    f32 f20 = a2;
    u32 s0;
    u32 v0;

    s0 = func_0013a7e8(1);
    v0 = func_0013d7e0();
    *(f32*)(s1 + 436) = f20;
    func_00138d60(s1, 10000, s0, v0, 47, s2, 0);
    *(u32*)(s1 + 428) = 1;
}

void func_0015b578(u32 a0) {
    u32 s1 = 0;
    u32 s2 = a0;
    u32 s0;
    s32 n;

    n = *(s32*)(a0 + 436);
    if (n > 0) {
        s0 = a0 + 440;
        do {
            func_0023acd8(s0);
            s1 += 1;
            n = *(s32*)(s2 + 436);
            if ((s32)s1 < n) {
                s0 += 344;
                continue;
            }
            break;
        } while (1);
    }
    func_001390f0(s2);
}

void func_0015b5d8(u32 a0) {
    u32 s1 = a0;
    s32 n;
    u32 s3;
    u32 s2;
    u32 s0;
    u32 v;
    u32 t0;
    u32 t1;

    n = *(s32*)(a0 + 432);
    if (n <= 0) {
        return;
    }
    if (n > 0x003d0900) {
        return;
    }

    func_00139170();
    s3 = 0;
    if (*(s32*)(s1 + 436) <= 0) {
        return;
    }
    s2 = s1 + 2848;
    s0 = s1 + 440;

    do {
        v = *(u32*)(s2 + 0);
        t0 = *(u32*)(s1 + 368);
        t1 = *(u32*)(s1 + 372);
        s3 += 1;
        s2 += 4;
        *(u32*)(s0 + 328) = t0 + v;
        *(u32*)(s0 + 332) = t1;
        func_0023ade0(s0);
        if ((s32)s3 < *(s32*)(s1 + 436)) {
            s0 += 344;
            continue;
        }
        break;
    } while (1);
}

void func_0015ee90(u32 a0) {
    u64 t7 = 1ULL;
    u64 t6 = D_0034c710;
    t7 <<= a0;
    t7 |= t6;
    D_0034c710 = t7;
    func_00143110(a0);
    func_00153948(a0 & 0xff);
    func_0015c450(a0);
    if (D_0034c70c != 1) {
        return;
    }
    return func_001de228(D_0034c6f0, a0, 1, 2, 0, 0);
}

void func_0015f738(u32 a0, u32 a1) {
    const u32 s = 0xffff;
    if (a1 == s) {
        if (a0 == 1u) {
            func_001ddd10(D_0034c6f0);
        }
    }

    if (a1 != s) {
        return;
    }
    if (a0 != 0u) {
        return;
    }
    return func_001ddd88(D_0034c6f0);
}

void func_00160960(u8* a0) {
    if ((*(u32*)(a0 + 384) & 2u) != 0u) {
        func_001606e0(a0);
        u32 t = *(u32*)(a0 + 696) & 1u;
        if (t != 0u) {
            func_001608c0(a0);
        }
        return func_00143398(a0 + 448);
    }

    u32 t = *(u32*)(a0 + 696) & 1u;
    if (t != 0u) {
        func_001608c0(a0);
    }
    return func_00143328(a0 + 448);
}

void func_00161668(u8* a0, f32 a1) {
    if (*(u32*)(a0 + 72) == 0) {
        return;
    }

    f32 f0 = *(f32*)(a0 + 76) + a1;
    *(f32*)(a0 + 76) = f0;
    func_001616f0((u32)a0, f0);

    f32 f2 = *(f32*)(a0 + 80);
    f32 f1 = *(f32*)(a0 + 76);
    if (f2 < f1) {
        *(f32*)(a0 + 76) = f1 - f2;
        return func_001616f0((u32)a0, f2);
    }
}

u32 func_00168f18() {
    func_00168808(0xFFFFFFFFu);
    func_001675b0();
    func_001b13d8();
    func_0016e8f8();
    func_00180f28();
    func_00194a30();
    func_00196170();
    func_00196300();
    func_00199688();
    func_001aeb80();
    func_001d53e8();
    func_001aaa08();
    func_0019f790();
    func_00192320();
    func_001d9d00();
    return func_001b13f0();
}

void func_00168fd8(u32 a0) {
    func_00195738();
    func_001afa50();
    func_001ba138();

    s32 t5 = 13;
    if ((s32)a0 == t5) {
        func_00170a50();
        return;
    }
    if ((s32)D_004f6280 == t5) {
        func_00170a50();
    }
}

void func_00169f98(u8* a0) {
    if ((*(u32*)(a0 + 1416) & 0x20u) == 0) {
        u32 t2 = func_00168b38(*(u32*)(a0 + 1964), 3, 0);
        D_004f6284 = t2;
        if (t2 != 0) {
            u32 t5 = *(u32*)(t2 + 8);
            if (t5 != 0) {
                func_0016a158((u32)a0, t5);
            }
        }
    }

    kn::FVector* t6 = (kn::FVector*)(a0 + 2192);
    kn::FVector* t7 = (kn::FVector*)(a0 + 1344);
    if (t6 != t7) {
        *t6 = *t7;
    }

    u32 t7v = *(u32*)(a0 + 2040);
    f32 f0 = *(f32*)(a0 + 1372);
    *(f32*)(a0 + 2204) = f0;
    *(u32*)(a0 + 2040) = t7v | 0x80u;
}

u32 func_0016ad68(u32 a0, u32 a1, f32 f12) {
    f32 f20 = f12;
    f32 f0 = func_0016afe0(a1);
    f0 = f0 + f20;
    ((void(*)(u32, f32))func_0016aeb8)(a0, f0);
    return func_0016ad38(a0, func_0016c028(a1));
}

f32 func_0016ae58(u8* a0, f32 f12) {
    kn::FVector sp0;
    kn::FVector* s0 = (kn::FVector*)(a0 + 1360);
    u8* s1 = a0;
    f32 f20 = f12;

    func_0019c400((u32)s1);
    func_0017d0e8(&sp0, f20);
    if (s0 != &sp0) {
        *s0 = sp0;
    }

    return *(f32*)(s1 + 1372);
}

u32 func_0016aef0(u32 a0, u32 a1) {
    if (func_0019c400(a0) != 0) {
        return func_0016b070(a0, a1);
    }

    f32 f0 = func_002f8ad0(*(f32*)(a1 + 0), *(f32*)(a1 + 8));
    return ((u32(*)(u32, f32))func_0016aeb8)(a0, f0);
}

f32 func_0016b558(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s1 = a0;
    u8* s0 = func_0016bc20(a0, 15, 0xFFFFFFFFu);
    func_0016b0e0(s1, *(u16*)(s0 + 6), s2);
    return (f32)*(s16*)(s0 + 8);
}

void func_0016b5b8(u8* a0) {
    u32 t6 = *(u32*)(a0 + 264);
    if ((t6 & 0x10000000u) == 0) {
        u32 t7 = *(u32*)(a0 + 1156);
        if (t7 != 0) {
            func_00188738(a0 + 768);
            func_0016ce90(*(u32*)(a0 + 1156));
        }

        func_00180ce0(a0 + 320);

        u32 t6p = *(u32*)(a0 + 8);
        u32 t7v = *(u8*)(t6p + 84);
        func_001826c8((f32)(-(s32)t7v));
        t6 = *(u32*)(a0 + 264);
    }

    *(u32*)(a0 + 264) = t6 | 0x10000000u;
}

u32 func_0016bba8(u8* a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u8* s1 = a0;
    u32 s2 = a1;
    u32 v0;

    if (*(u32*)(s1 + 2264) == 0) {
        return 0;
    }

loop:
    s0 = func_0018a100(*(u32*)(s1 + 2264), s2, s0);
    if (s0 == 0) {
        goto done;
    }

    v0 = func_0019bd08((u32)s1, *(u8*)s0);
    if (v0 == 0) {
        goto loop;
    }
done:
    return s0;
}

u32 func_0016bc98(u8* a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u8* s1 = a0;
    u32 s2 = a1;
    u32 v0;

    if (*(u32*)(s1 + 2264) == 0) {
        return 0;
    }

loop:
    s0 = func_0018a1b8(*(u32*)(s1 + 2264), s2, s0);
    if (s0 != 0) {
        v0 = func_0019bd08((u32)s1, *(u8*)s0);
        if (v0 == 0) {
            goto loop;
        }
    }
    return s0;
}

u32 func_0016bda8(u32 a0, u32 a1) {
    u8 sp0[32];
    func_00190128(sp0);
    func_00190878(sp0, a1, 0);
    func_00190388(a0, sp0);
    return a0;
}

u32 func_0016cce8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s0 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a4;

    u32 v0 = func_0016cb88(s0);
    return func_0016cc18(s0, v0, s1, s2, s3);
}

u32 func_0016cf00(u8* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s1 = (u32)a0;
    u32 s2 = a2;
    u32 s3 = a3;
    u32 s4 = a1;
    u32 s5 = a4;

    u32 s0 = func_0016c7a0(64);
    func_0016c8f8(s0, *(u32*)(s1 + 0), *(u32*)(s1 + 52), *(u32*)(s1 + 56));

    u32 t7 = *(u32*)(s0 + 28);
    *(u32*)(s0 + 32) = s4;
    *(u32*)(s0 + 28) = t7 | 1;

    func_001da458(s0, s2, s3, s5);
    return s0;
}

void func_0016cff0(u8* a0, u32 a1, u32 a2) {
    u32 s2 = a2;
    u32 s3 = a1;
    u8* s4 = a0;
    u32 s0 = *(u32*)(a0 + 44);

    while (s0 != 0) {
        u32 s1 = *(u32*)(s0 + 40);
        if ((*(u32*)(s0 + 32) & s3) == s2) {
            func_0031e2c8((u32)(s4 + 44), s0);
            if (s0 != 0) {
                func_0016cab8(s0);
                func_0016c7d8(s0);
            }
        }
        s0 = s1;
    }
}

u32 func_0016d080(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s2 = a1;
    u32 s1 = func_0016c7a0(64);
    func_0016c8f8(s1, s0, 0, s2);
    return s1;
}

void func_0016d698(u8* a0) {
    u8* s0 = a0;
    u8* s1 = (u8*)*(u32*)(a0 + 0);
    u8* t7 = (u8*)*(u32*)(a0 + 4);

    f32 f20 = func_002f8ad0(*(f32*)(t7 + 0), *(f32*)(t7 + 8));
    f20 = f20 - func_002f8ad0(*(f32*)(s1 + 0), *(f32*)(s1 + 8));
    *(f32*)(s0 + 0) = func_0017ce10(f20);
}

void func_0016db20(u8* a0) {
    u32 s0 = *(u32*)(a0 + 0);
    if (s0 != 0) {
        func_0016cff0(D_0034d8a0, s0, s0);
    }

    u32 v0 = func_0016cfa0(
        D_0034d8a0,
        *(u32*)(a0 + 0),
        *(u32*)(a0 + 4),
        (u32)(a0 + 12),
        (u32)(*(u32*)(a0 + 12) != 0));

    u32 t7 = *(u32*)(a0 + 8);
    if (t7 != 0) {
        *(u32*)(v0 + 36) = t7;
    }
    *(u32*)(a0 + 0) = v0;
}

void func_0016ef58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s0 = a2;
    u32 s1 = a0;
    u32 s2 = a1;
    u32 s3 = a3;

    func_0016eb48(s0, s3, a4, -1);
    if (func_0016f6f8(s0) != 0) {
        return;
    }

    u32 v0 = func_00185920(s1, s2, 0);
    if (v0 != 0) {
        func_00170518(v0, s3, 0);
    }
}

void func_0016fb30(u8* a0, u32 a1, u32 a2, u32 a3) {
    u8* s0 = a0;
    u32 s1 = a2;
    u32 s2 = a1;

    *(u32*)(s0 + 44) = a3;
    *(u32*)(s0 + 40) = s1;
    *(u8*)(s0 + 0) = 0;
    *(u8*)(s0 + 1) = 0;
    *(u16*)(s0 + 2) = 0;
    *(u32*)(s0 + 36) = 0;
    *(u32*)(s0 + 48) = 0;
    *(u32*)(s0 + 52) = 0;

    func_002ff3fc(s2);
    *(u32*)(s0 + 56) = s1;

    func_002ff2e8(s0 + 4, s2);
}

void func_0016fba0(u8* a0, u32 a1, u32 a2, u32 a3) {
    u8* s0 = a0;
    u32 s1 = a2;
    u32 s2 = a1;

    *(u32*)(s0 + 44) = a3;
    *(u32*)(s0 + 40) = s1;
    *(u8*)(s0 + 0) = 0;
    *(u8*)(s0 + 1) = 0;
    *(u16*)(s0 + 2) = 0;
    *(u32*)(s0 + 36) = 0;
    *(u32*)(s0 + 48) = 0;
    *(u32*)(s0 + 52) = 0;

    func_002ff3fc(s2);
    *(u32*)(s0 + 56) = s1;

    func_002ff2e8(s0 + 4, s2);
}

void func_00170888(u32 a0) {
    u32 s0 = a0;

    if (a0 != 0) {
        func_00170dd0(a0);
    }

    func_00170c50();
    if (func_00170e18() != 0) {
        return;
    }

    func_00170670();
    D_0034dcac = 1;

    if (s0 != 0) {
        func_00170dd0(s0);
    }
}

u32 func_00170978(u32 a0) {
    u8* v0 = (u8*)func_00170240(a0, (u32)-1);
    u32 t6 = 0;

    if (v0 != 0) {
        u32 t7 = (u32)(*(s32*)(v0 + 40) < 10000);
        t7 ^= 1;
        if (t7 == 0) {
            u32 t5 = *(u8*)(v0 + 1);
            if (t5 != 3) {
                return 1;
            }

            u16 t7h = *(u16*)(v0 + 2);
            t6 = 2;
            if (t7h != 0) {
                t6 = t5;
            }
        }
    }

    return t6;
}

void func_001709d0(s32 a0) {
    s32 s0 = a0;
    u32 a0v = D_0034dca0;

    if (a0v == 0) {
        return;
    }

loop:
    u32 s1 = *(u32*)(a0v + 60);

    if (s0 >= 0) {
        if (*(s32*)(a0v + 40) < s0) {
            goto next;
        }
    } else {
        if (s0 < *(s32*)(a0v + 40)) {
            goto next;
        }
    }

    func_001700e8(a0v, 1);

next:
    if (s1 != 0) {
        a0v = s1;
        goto loop;
    }
}

void func_00171740(u32* a0) {
    u32* s0 = a0;
    u32 t6 = *(u32*)a0;
    t6 = *(u32*)(t6 + 4);

    u32 t7 = *(u32*)(t6 + 1416);
    if ((t7 & 2) != 0) {
        t6 = *(u32*)(t6 + 4);
        t7 = *(u32*)t6;
        u32 fn = *(u32*)(t7 + 96);
        u32 v0 = ((u32(*)(u32))fn)(t6);
        *s0 = v0;
    } else {
        *(u32*)a0 = 0;
    }
}

void func_00171998(u32 a0) {
    u8 local[32];
    u32 s0 = a0;

    u32 t7a = *(u32*)(a0 + 12);
    u32 s1 = *(u32*)(t7a + 4);

    func_00190128(local);
    func_00190878(local, s1, 0);

    u32 t6 = *(u32*)(s0 + 4);
    u32 t7 = *(u32*)(s0 + 0);
    u32 a2 = *(u32*)(s0 + 8);
    u32 a1 = *(u32*)(t6 + 4);
    u32 a0v = *(u32*)(t7 + 4);

    func_0016bae8(a0v, a1, a2, local);
}

void func_00171ac8(u32* a0) {
    u8 local[32];
    u8* s1 = local + 16;
    u32* s0 = a0;

    u32 t7 = *(u32*)(a0 + 1);
    func_0016bda8(local, *(u32*)(t7 + 4));

    t7 = *(u32*)(s0 + 0);
    func_0016bda8(s1, *(u32*)(t7 + 4));

    *s0 = func_001a75d8((u32)s1, (u32)local, 4);
}

void func_001731e0(u32* a0) {
    u32* s1 = a0;
    u32 s3 = *(u32*)(a0 + 0);
    u32 s2 = *(u32*)(s1 + 1);

    u32 s0 = func_001050d8(2924);
    func_001ad0f8(s0, s3, s2);

    u32 v0 = func_001050d8(28);
    func_001ac7c8(v0, s0);

    *s1 = s0;
}

u32 func_00173450(u32 a0) {
    u32 s0 = a0;
    u32 a2 = (u32)func_001733f8;
    u32 a1 = 14002;
    u32 v0 = func_00102c18(1, a1, a2);

    *(u32*)(v0 + 4) = 1;

    volatile u32* vp = (volatile u32*)s0;
    f32 f0;

    {
        u32 t6 = vp[0];
        f0 = *(f32*)(t6 + 0);
        *(volatile f32*)(v0 + 8) = f0;
    }

    {
        u32 t7 = vp[0];
        f0 = *(f32*)(t7 + 4);
        *(volatile f32*)(v0 + 12) = f0;
    }

    {
        u32 t7 = vp[0];
        f0 = *(f32*)(t7 + 8);
        *(volatile f32*)(v0 + 16) = f0;
    }

    return v0;
}

u32 func_001734b0(u32 a0) {
    u32 s0 = a0;
    s32 t7 = *(s32*)(a0 + 4);
    s32 t6 = t7;
    t7 = t7 - 1;
    *(s32*)(a0 + 4) = t7;

    if (t6 > 0) {
        return;
    }

    u32 v0 = func_0015ef38();
    func_0011e9a8(v0, 2, 0, 0, *(f32*)(s0 + 8));
    return func_001024a8(s0);
}

void func_00173c70(u32 a0) {
    u32 s1 = a0;
    u32 t7 = *(u32*)(a0 + 0);
    u32 s0 = *(u32*)(a0 + 4);
    u32 s2 = *(u32*)(t7 + 4);

    if (s0 != 0) {
        func_0016cff0(*(u32*)(s2 + 1156), s0, s0);
    }

    u32 v0 = func_0016cfa0(*(u32*)(s2 + 1156), s0, *(u32*)(s1 + 8), s1 + 16, 1);
    *(u32*)(v0 + 36) = *(u32*)(s1 + 12);
    *(u32*)(s1 + 0) = v0;
}

void func_00174388(u32 a0) {
    u8 local[32];
    u32 s0 = a0;

    func_00190128(local);

    u32 t7 = *(u32*)(s0 + 16);
    func_00190878(local, *(u32*)(t7 + 4), 0);

    u32 t6 = D_0034e948;
    func_001bd4e8(*(u32*)(t6 + 2884), s0, (u32)local);
}

u32 func_001758b0(u32 a0) {
    u32 s0 = a0;
    if (func_001bb9b0(a0) != 0) {
        func_00180800(s0 + 320, 0);
        func_00177540(s0);
    }

    u32 t6 = *(u32*)(s0 + 0);
    u32 fn = *(u32*)(t6 + 140);
    ((void(*)(u32))fn)(s0);

    u32 v0 = func_0016a020(s0);
    if (v0 == 1279) {
        func_0016bd60(s0, 10);
    }

    return func_00198450(s0);
}

u32 func_00175af8(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 0x00100000;

    u32 t7 = *(u32*)(a0 + 264);
    if ((t7 & s1) == 0) {
        if (YS_STATUS_IsBattleMode() != 0) {
            t7 = *(u32*)(s0 + 264);
            t7 |= s1;
            *(u32*)(s0 + 264) = t7;
        }
    }

    func_00176a68(s0);
    func_00176c68(s0);
    func_00176f00(s0);
    return func_00187750(s0);
}

u32 func_00176760(u32 a0) {
    u32 s0 = a0 + 320;
    f32 f20 = 0.0f;

    ((u32(*)(u32, u32, f32, f32))func_0017f488)(s0, 151, f20, f20);
    return ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(s0, 0, 0, f20, f20);
}

u32 func_00176fb0(u32 a0) {
    u32 t6 = 0;
    u32 s0 = a0;
    u32 t7 = *(u32*)(a0 + 2800);

    if (t7 == 0) {
        return t6;
    }

    a0 = t7;
    s32 v0 = func_001d7f40(a0);
    if (v0 < 0) {
        return t6;
    }

    u32 t7b = *(u32*)(s0 + 2800);
    a0 = (u32)(v0 * 68);
    t7b += a0;
    t6 = t7b + 4;
    return t6;
}

u32 func_001774e0(u32 a0) {
    u32 s0 = a0;
    u32 a0v = *(u32*)(a0 + 2796);
    if (a0v == 0) {
        return 0;
    }

    u32 t7 = *(u32*)(s0 + 352);
    if ((t7 & 0x00040000u) != 0) {
        return 1;
    }

    if (func_0016cd48(a0v, 0) == 1) {
        func_00177498(s0);
    }

    return 1;
}

u32 func_001778c0(u32 a0, u32 a1) {
    u32 s17 = a0;
    u32 s18 = a1;

    if (func_00177870(s17) != 0) {
        return 0;
    }

    if ((*(u32*)(s17 + 360) & 0x20) != 0) {
        return 1;
    }

    if (func_0019c090(s17) != 0) {
        u32 s16 = *(u8*)(s17 + 2820);
        u32 v0 = func_00177860(s17);
        s16 += s18;
        s8 t7 = *(s8*)(v0 + 45);
        return (u32)(((s32)s16 < (s32)t7) ^ 1);
    }

    u32 s16 = *(u8*)(s17 + 2820);
    u32 v0 = func_00177860(s17);
    s16 += s18;
    s8 t7 = *(s8*)(v0 + 44);
    return (u32)(((s32)s16 < (s32)t7) ^ 1);
}

u32 func_001779d0() {
    u32 s0 = 0;

    if (func_001b9c90() != 0) {
        if (func_001ad938() == 0) {
            u32 t13 = D_0034f240;
            t13 &= 0x00100000;
            s0 = (u32)(t13 < 1);
        }
    }

    return s0;
}

u32 func_00177d30(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 v0 = func_00177860(s0);
    u32 t6;
    s32 t7 = *(s32*)(v0 + 12);

    if (t7 < 0) {
        u32 t14 = *(u32*)(s0 + 1164);
        t7 = *(u32*)(t14 + 8);
        if (t7 == 0) {
            t7 = *(u32*)(t14 + 0);
            t7 = (u32)((s32)t7 < 2);
            if (t7 == 0) {
                t6 = 1;
                goto done;
            }
        }
    }

    t7 = *(u32*)(v0 + 16);
    t7 = t7 & 1;
    t7 = (u8)t7;
    if (t7 != 0) {
        if (func_00186ce8(s0) != 0) {
            t6 = 1;
            goto done;
        }
    }

    t6 = func_00186ec0(s0, s1);

done:
    return t6;
}

void func_001782c8(u32 a0) {
    u32 t6 = *(u32*)(a0 + 12);
    u32 t7 = *(u32*)(t6 + 8);

    if ((t7 & 8) != 0) {
        return func_001785b8(a0);
    }

    t6 = *(u32*)(t6 + 4);
    if ((t6 ^ 0x2) == 0) {
        return func_00178570(a0);
    }

    u32 t5 = t6 ^ 0x18;
    if (t5 == 0) {
        return func_001786e0(a0);
    }

    if ((t6 ^ 0x35) == 0) {
        return func_001786e0(a0);
    }

    return func_001784a8(a0);
}

u32 func_00179c08(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s0 = a1;
    u32 s2 = 0;

    if (func_001b90f0(s0, s1) != 0) {
        u32 a2v = 0;
        if (func_0019c218(s1, s0) != 0) {
            s32 v0 = func_001bc2a8(s0, s1, a2v);
            s2 = (u32)(v0 < 4);
        }
    }

    return s2;
}

u32 func_00179e48() {
    if (D_0034e94c == 0) {
        func_0019ba60(D_0034e948);
    }

    func_00179ea0(D_0034e948);

    u32 t7 = D_0034e948;
    D_0034e948 = 0;
    D_0034e94c = t7;
    return t7;
}

u32 func_00179eb8() {
    if (D_0034e948 == 0) {
        func_0019ba60(D_0034e94c);
    }

    u32 t7 = D_0034e94c;
    D_0034e94c = 0;
    D_0034e948 = t7;

    func_00179f58(t7);

    return D_0034e948;
}

void func_0017a3b0(u32 a0) {
    u32 s0 = a0;

    if (*(u8*)(a0 + 2916) != 0) {
        return;
    }

    u32 t7 = *(u32*)(a0 + 0);
    u32 fn = *(u32*)(t7 + 64);

    if (((u32(*)(u32))fn)(a0) != 0 || func_001ad938() != 0) {
        return func_0017a418(s0, 1);
    }
}

void func_0017a480(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 s3 = a3 & 0xff;

    u32 t5 = *(u32*)(a0 + 1164);
    if (t5 != 0) {
        u8 t6 = *(u8*)(t5 + 431);
        if (t6 == 1) {
            if ((s32)s1 < 0) {
                u32 t7 = (u32)(-(s32)s1);
                s32 i0 = *(s32*)(t5 + 4);
                f32 f0 = (f32)i0;
                f32 f20 = (f32)(s32)t7;
                f20 = f20 / f0;

                u32 v0 = func_00177860(s0);
                f0 = *(f32*)(v0 + 84);
                f20 = f20 * f0;
                func_00179a68(s0, f20);
            }
        }
    }

    return func_00177c50(s0, s1, s2, s3);
}

void func_0017a590(u32 a0, u32 a1) {
    u32 v0 = 0;
    u32 s0 = a0;
    u32 s1 = a1;

    if (*(u32*)(a0 + 2896) != 7) {
        v0 = func_001778c0(a0, 0);
    }

    v0 = func_001a6178(s0, s1, v0);
    *(u32*)(s0 + 2856) = v0;
    *(u32*)(s0 + 268) |= 0x00040000;
}

void func_0017bf40(u32 a0) {
    *(u16*)(a0 + 0) = 0;

    u32 s0 = a0;
    func_00190128(a0 + 8);

    u32 t7 = *(u32*)(s0 + 4);
    u32 t6 = (u32)-2;
    u32 t5 = (u32)-3;
    t7 &= t6;
    t7 &= t5;
    t6 = (u32)-5;
    t7 &= t6;
    t5 = (u32)-9;
    t7 &= t5;
    t6 = (u32)-17;
    t7 &= t6;
    *(u32*)(s0 + 4) = t7;
}

void func_0017bfa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u16*)(a0 + 0) = (u16)a1;

    u32 s0 = a0;
    u32 v0 = a3;
    u32 s1 = a2;

    if (a3 == 0) {
        v0 = func_001b8e88(a1);
    }

    u32 t7 = *(u16*)(v0 + 4);
    *(u16*)(s0 + 2) = (u16)t7;

    if (s1 == 0) {
        func_00190128(s0 + 8);
        return;
    }

    struct Copy {
        u32 a, b, c, d, e;
    };
    *(Copy*)(s0 + 8) = *(Copy*)s1;
}

u32 func_0017dee8(u32 a0) {
    u32 s0 = a0 + 320;
    f32 f20 = 0.0f;

    ((u32(*)(u32, u32, f32, f32))func_0017f488)(s0, 151, f20, f20);
    return ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(s0, 0, 0, f20, f20);
}

u32 func_0017df70(u32 a0) {
    u32 s0 = a0;

    u32 v0 = func_001a8bd0((u32)-1);
    v0 = func_001a8bf8(v0, s0);

    u32 t6 = v0;
    u32 out = 0;
    if (t6 != 18) {
        return func_001a8b38(v0);
    }

    return out;
}

void func_0017e030(u32 a0, u32 a1) {
    u32 s2 = a0;
    u32 s1 = a1;

    u32 s0 = func_001a2478(*(u32*)(a0 + 1164));
    func_001762f8(s2, s1);

    if (s0 == 0) {
        u32 v0 = func_001a2478(*(u32*)(s2 + 1164));
        if (v0 != 0) {
            u32 t7 = *(u32*)(s2 + 0);
            u32 fn = *(u32*)(t7 + 84);
            ((void(*)(u32, u32, u32))fn)(s2, 9, 0);
        }
    }
}

void func_0017e0b0(u32 a0) {
    u32 s1 = a0;

    u32 v0 = func_00177860(a0);
    u32 t7 = *(u32*)(v0 + 16);
    t7 &= 0x4;
    if (t7 != 0) {
        if (func_001b6070() != 0) {
            if (func_0017e358(s1) != 0) {
                func_001b5ef0(s1);
            }
        }
    }

    func_00176ec8(s1);

    u32 s0 = *(u32*)(s1 + 300);
    v0 = func_00177860(s1);

    f32 f0 = *(f32*)(s0 + 24);
    f32 f1 = *(f32*)(v0 + 92);
    f0 = f0 * f1;
    *(f32*)(s1 + 2880) = f0;
}

void func_0017e210(u32 a0) {
    u32 s0 = a0 + 2800;
    s32 s1 = 1;
    u32 s2 = a0;

    do {
        u32 t7 = *(u32*)(s0 + 8);
        if (t7 != 0) {
            func_00185a28(t7);
            *(u32*)(s0 + 8) = 0;
        }
        s1 -= 1;
        s0 += 4;
    } while (s1 >= 0);

    u32 t6 = *(u32*)(s2 + 0);
    u32 fn = *(u32*)(t6 + 40);
    ((void(*)(u32))fn)(s2);

    func_0016a2e0(s2);
}

u32 func_0017e3b8(u32 a0) {
    u32 s1 = a0;
    u32 s0 = 0;

    if (func_0017e280(s1) != 0) {
        u32 v0 = func_001a8bd0((u32)-1);
        s0 = v0;
        v0 = func_0016a070(s1);
        v0 = func_001a90a8(s0, v0);
        s0 = (u32)(v0 < 1);
    }

    return s0;
}

u32 func_0017e668(u32 a0) {
    u32 s1 = 0;
    u32 s2 = a0;

    do {
        u32 v0 = func_0017df58(s1);
        s1 += 1;
        u32 s0 = v0;

        if (v0 != 0) {
            if (func_0016a070(v0) == s2) {
                return s0;
            }
        }
    } while ((s32)s1 < 2);

    return 0;
}

void func_0017f430(u32 a0, u32 a1, f32 a2, f32 a3) {
    f32 f21 = a2;
    f32 f20 = a3;
    u32 s0 = a0;
    u32 s1 = a1;

    func_0017f380(s0);
    func_0017efa0(s0, s1, f21, f20);
}

void func_0017f540(u32 a0, u32 a1, f32 a2, f32 a3) {
    f32 f21 = a2;
    f32 f20 = a3;
    u32 s0 = a0;
    u32 s1 = a1;

    func_0017f380(s0);
    u32 v0 = func_0017f4e0(s0, s1);

    if (v0 != 0) {
        f32 f0 = func_00180448(s0, s1, f21, f20);
        ((u32(*)(u32, u32, f32, f32))func_0017f488)(s0, s1, f21, f0);
    }
}

void func_0017fd60(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a0 + 148);
    u32 t4 = a0 + 148;

    u32 t5;
    if (a1 == t7) {
        t7 = *(u32*)(a1 + 156);
        t5 = 0;
        *(u32*)(a0 + 148) = t7;
    } else {
        u32 t6 = *(u32*)(t7 + 156);
        t5 = t7;
        if (t6 != a1) {
            do {
                t7 = *(u32*)(t6 + 156);
                t5 = t6;
                t6 = t7;
            } while (t7 != a1);
        }
        t7 = *(u32*)(a1 + 156);
        *(u32*)(t5 + 156) = t7;
    }

    t7 = *(u32*)(t4 + 4);
    if (a1 == t7) {
        *(u32*)(t4 + 4) = t5;
    }

    *(u32*)(a1 + 156) = 0;
}

void func_0017fff8(u32 a0) {
    u8 buf[32];

    u32 s0 = a0;
    u32 s1 = (u32)(buf + 16);

    if (func_00180cd0(s0) == 0) {
        u32 t5 = *(u32*)(s0 + 12);
        u32 fn = *(u32*)(*(u32*)(t5 + 0) + 20);
        ((void(*)(u32, u32, u32))fn)(t5, (u32)buf, s1);

        func_001447e0(s0 + 216, (u32)buf, s1);
    }
}

void func_001802d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, f32 a6) {
    f32 f20 = a6;
    u32 s4 = a0;
    u32 s2 = a1;
    u32 s1 = a2;
    u32 s0 = a3;
    u32 s3 = a4;
    u32 s5 = a5;

    func_0017f380(s0 + 320);
    u32 v0 = func_001a97b8(s2, s3);

    func_001801b0(s4, v0, s1, s0, s5, f20);

    *(u32*)(s0 + 576) = s2;
    *(u32*)(s0 + 340) = s3;
}

u32 func_00180510(u32 a0) {
    u32 s1 = 0;

    u32 v0 = func_0017ec98(a0);
    v0 = func_0017edf0(a0, v0);

    Obj_00180510 *s0 = (Obj_00180510 *)func_00180408(a0, v0);
    if (s0 != 0) {
        float f20 = s0->vt->fn28(s0);
        s32 v1 = s0->vt->fn8(s0);
        if (f20 < (float)v1) {
            s1 = 1;
        }
    }

    return s1;
}

u32 func_00180698(u32 a0, s32 a1) {
    if (a1 >= 0) {
        if ((u32)a1 != *(u32 *)(a0 + 20)) {
            u32 v0 = func_0017ec98(a0, (u32)a1);
            v0 = func_0017edf0(a0, v0);
            return func_00180408(a0, v0);
        }
    }
    return *(u32 *)(a0 + 12);
}

float func_001806f8(u32 a0, s32 a1) {
    if (a1 < 0 || (u32)a1 == *(u32 *)(a0 + 20)) {
        return *(float *)(a0 + 44);
    }

    func_00180698(a0, (u32)a1);
    Obj_001806f8 *o = (Obj_001806f8 *)func_00180698(a0, (u32)a1);
    return (float)o->vt->fn8(o);
}

void func_00181778(void) {
    if (func_00181550() == 0) {
        return;
    }
    if (func_00181500(6151) != 0) {
        return;
    }
    if (func_00181500(6153) != 0) {
        return;
    }
    if (func_00181500(6178) == 0) {
        return;
    }

    if (func_00181500(6245) != 0) {
        func_00181178(6153);
    } else {
        func_00181178(6151);
    }
}

u32 func_00181c28(const s8 *a0) {
    s32 c1 = (s32)a0[1];
    s32 d3 = (s32)a0[3];
    s32 e2 = (s32)a0[2];
    c1 <<= 8;
    s32 a2 = (s32)a0[0];
    d3 <<= 24;
    e2 <<= 16;
    a2 |= d3;
    u32 a0v = D_0034ecf4;
    e2 |= c1;
    u32 ret = func_00168b88(a0v, 22, (u32)(a2 | e2), 0);
    return *(u32 *)(ret + 8);
}

void func_00181d30(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1 = a2;
    u32 s2 = a0;

    if (s0 < s1) {
        do {
            if (func_00181da0(s2, s0) == 0) {
                return;
            }
            s16 off = *(s16 *)(s0 + 2);
            s0 = s0 + ((s32)off << 2) + 4;
        } while (s0 < s1);
    }
}

void func_00182860(u32 a0) {
    u32 t7 = *(u32 *)(a0 + 4);
    t7 &= 1;
    if (t7 != 0) {
        return;
    }
    u32 p = *(u32 *)(a0 + 8);
    if (p == 0) {
        return;
    }
    func_00199cd0(p);
    func_00199998(p);
}

void func_001828b8(u32 a0) {
    u32 t7 = *(u32 *)(a0 + 4);
    t7 &= 1;
    if (t7 != 0) {
        return;
    }
    u32 p = *(u32 *)(a0 + 8);
    if (p == 0) {
        return;
    }
    func_00199cd0(p);
    func_00199998(p);
}

u32 func_001844e8(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 0;
    if (func_00184478(s0) != 0) {
        s1 = 1;
    } else {
        volatile float *p1 = (volatile float *)(s0 + 1348);
        float f1 = *p1;
        volatile float *p0 = (volatile float *)(s0 + 2116);
        float f0 = *p0;
        if (!(f0 == f1)) {
            s1 = 1;
        }
    }
    return s1;
}

u32 func_00185be0(u32 a0, u32 a1, float a2) {
    u32 s0 = func_001050d8(2816);
    func_00185b70(s0, a0, a1, a2);
    return s0;
}

void func_00186020(u32 a0) {
    u32 s0 = a0;
    if ((*(u32*)(s0 + 264) & 0x10000000) == 0) {
        func_0019f9a8(s0 + 2568);
        u32 t7 = *(u32*)(s0 + 2784);
        if (t7 != 0) {
            func_001dc920(t7);
            *(u32*)(s0 + 2784) = 0;
        }
    }
    func_0016b5b8(s0);
}

void func_00187890(u32 a0) {
    u32 s0 = a0;
    if ((*(u32*)(a0 + 2040) & 4) != 0) return;
    u32 t7 = *(u32*)(a0 + 2072);
    if (t7 != 0) func_0019aa00(t7, s0);
    func_00187868(s0);
}

void func_001881f8(u32 a0, u32 a1) {
    u32 s0 = a0;
    if ((*(u32*)(a0 + 156) & 1) != 0) return;
    u32 v0 = func_00187ab8(*(u32*)(a0 + 140), a1);
    if (v0 == 0) return;
    func_00187ef0(s0, v0);
}

void func_001880b0(u32 a0, u32 a1) {
    u32 s0 = a0;
    if ((*(u32*)(a0 + 156) & 1) != 0) return;
    u32 s1 = func_00187ab8(*(u32*)(a0 + 140), a1);
    if (s1 == 0) return;
    func_00187f90(s0);
    func_00187fd8(s0, s1);
}

void func_00188250(u32 a0, u32 a1) {
    u32 s0 = a0;
    func_001881f8(s0, a1);

    s32 t15 = *(s32*)(s0 + 0);
    s32 t14 = t15 + 15;
    s32 t13 = 0;
    if (t14 < 0) t13 = 1;
    t15 = t15 + 30;
    if (t13 == 0) t15 = t14;
    t15 = (t15 >> 4) << 4;
    t14 = t14 - t15;

    u32 p = s0 + ((u32)t14 << 3);
    *(u32*)(p + 12) |= 1;
}

void func_00189258(u32 a0) {
    u32 s0 = a0;
    func_001805e8(a0);
    u32 t = *(u32*)(s0 + 8);
    func_0019f480(t + 1140);
    t = *(u32*)(s0 + 8);
    RECOM_FLAG_clear_0019f578(t + 948);
    u32 t6 = *(u32*)(s0 + 8);
    *(u8*)(s0 + 248) = 0;
    u32 t7 = *(u32*)(t6 + 1416);
    if ((t7 & 2) != 0) {
        u32 t5 = t6 + 2748;
        *(u32*)(t5 + 4) = 0;
        *(u32*)(t5 + 8) = 0;
    }
}

void func_0018b988(u32 a0) {
    u32 s1 = a0;
    if (*(u8*)(a0 + 2672) != 0) return;

    u32 s2 = func_0018be00(a0, 0);
    if (s2 == 0) return;
    if ((*(u32*)(s2 + 1416) & 8) == 0) return;

    u32 s0 = func_0018bae8(s1, s2);
    u32 v0 = func_0018bae8(s2, s1);
    if (s0 != 0) return;
    if (v0 != 0) return;
    func_0018ba28(s1, s2);
}

void func_0018bb70(u32 a0, u32 a1, u32 a2, u32 a3, float f12) {
    u32 s0 = a0;
    u32 s1 = a3 & 0xFF;
    u32 s2 = a2;
    u32 s3 = a1;

    func_0018c438(s0 + 2624);
    *(float*)(s0 + 2704) = f12;
    *(u8*)(s0 + 2673) = 1;
    *(u32*)(s0 + 2624) = 5;
    *(u32*)(s0 + 2636) = s2;
    *(u32*)(s0 + 2628) = 1;
    *(u8*)(s0 + 2660) = (u8)s1;
    *(u32*)(s0 + 2632) = func_0018c528(*(u8*)(s3 + 1));
}

void func_0018c960(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    *(u32*)(a0 + 28) = a1;
    *(u32*)(a0 + 32) = a2;

    u32 t = *(u32*)(a1 + 8);
    *(u32*)(a0 + 20) = a3;
    *(u32*)(a0 + 16) = t;
    *(u8*)(a0 + 37) = (u8)a4;

    u8 v = *(u8*)(a2 + 10);
    *(u8*)(a0 + 39) = v;
    *(u8*)(a0 + 38) = v;

    func_0018ce08(a0);

    u32 t0 = *(u32*)(a0 + 20);
    u32 s1 = *(u32*)(t0 + 1164);
    if (s1 != 0) {
        *(u32*)(a0 + 40) = func_001a1e20(s1, *(u32*)(a0 + 28), *(u32*)(a0 + 32), *(u8*)(a0 + 37));

        u32 t1 = *(u32*)(a0 + 32);
        u32 t2 = (u32)*(u8*)(s1 + 430);
        u32 t3 = (u32)*(u8*)(t1 + 9);
        t3 = t3 + s1;
        u32 t4 = (u32)*(u8*)(t3 + 424);
        if ((t4 * t2) == 0) {
            *(u8*)(a0 + 38) = 0;
            *(u32*)(a0 + 24) |= 4;
        }
    } else {
        *(u32*)(a0 + 40) = 0;
    }
}

void func_0018ea40(u32 a0, u32 a1) {
    u32 o0 = *(u32*)a0;
    if ((*(u32*)(o0 + 4) & 0x80) != 0) {
        return;
    }

    u32 o1 = *(u32*)a1;
    if ((*(u32*)(o1 + 4) & 0x80) != 0) {
        return;
    }

    u32 p = *(u32*)(o0 + 36);
    if (*(u32*)p == 0) {
        return;
    }

    u32 q = *(u32*)(o0 + 40);
    u32 idx = (u32)*(u8*)(q + 11);
    if (idx == 0) {
        return;
    }

    u64 mask = 1;
    mask <<= 32;
    mask <<= (idx - 1);
    mask |= 0x10;
    s32 r = func_001de2e0(p, mask);
    if (r < 0) {
        return;
    }

    func_0018e8f0(a0, *(u32*)(*(u32*)a0 + 36), (u32)r, a1);
}

void func_0018f6c0(u32 a0) {
    u32 s0 = a0;
    u32 s1 = func_001050d8(320);

    u32 t = *(u32*)s0;
    u32 a2 = *(u32*)(s0 + 4);
    u32 a3 = *(u32*)(s0 + 8);
    u32 t0 = *(u32*)(s0 + 12);
    func_001a4498(s1, *(u32*)(t + 4), a2, a3, t0, 0xffffffffu);
    *(u32*)s0 = s1;
}

void func_0018f718(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)a0;
    if (func_0018f070(s0) != 0) {
        func_001a49d8(s0, *(f32*)(s1 + 4), *(f32*)(s1 + 8));
    }
}

void func_0018f9f8(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)a0;
    if (func_0018f070(s0) != 0) {
        func_001a4d70(s0, *(u32*)(s1 + 4));
    }
}

void func_0018fa50(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)a0;
    if (func_0018f070(s0) != 0) {
        func_001a4d78(s0, *(f32*)(s1 + 4), *(f32*)(s1 + 8), *(f32*)(s1 + 12));
    }
}

u32 func_00190208(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1;
    u32 s2;
    if (*(u32*)(s0 + 8) != 0) {
        s2 = 0;
        goto out;
    }

    s1 = a1 & 0xff;
    s2 = 0;
    if (func_0019ba60(*(u32*)s0) == 0) {
        goto out;
    }

    u32 a2v;
    if (s1 != 0) {
        a2v = *(u32*)(s0 + 4);
    } else {
        if (func_0019bd08(*(u32*)s0, *(u32*)(s0 + 4)) == 0) {
            goto out;
        }
        a2v = *(u32*)(s0 + 4);
    }

    s2 = func_0016bc20(*(u32*)s0, 3, a2v);
    if (s2 == 0) {
        s2 = func_0016bba8(*(u32*)s0, 3, 0);
    }

out:
    return s2;
}

f32 func_00191b70() {
    s32 s1 = 0;
    u32 base = 0x01c60000;
    f32 s = *(f32*)(base + 6500);
loop:
    u32 s0 = func_00176b20(s1);
    s1 += 1;
    if (func_0019ba60(s0) != 0) {
        if (*(u32*)(s0 + 1164) != 0) {
            u32 p = func_00177860(s0);
            s += *(f32*)(p + 100);
        }
    }
    if (s1 < 3) {
        goto loop;
    }
    return s;
}

u32 func_001923c8(u32 a0) {
    if (a0 == 0) {
        return 0;
    }
    u32 s0 = a0;
    u32 s1 = 16;
    while (1) {
        if (func_00192440(s0, 0) != 0) {
            if (*(u8*)s0 == s1) {
                return func_00192388(s0);
            }
        }
        u32 v = func_00192388(s0);
        if (v == 0) {
            return 0;
        }
        s0 = v;
    }
}

u32 func_001924c0(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 1;
    while (s0 != 0) {
        if (func_00192440(s0, 0) != 0) {
            u32 t = s1 + 1;
            if (*(u8*)s0 == 0x10) {
                s1 = t;
            }
        }
        s0 = func_00192388(s0);
    }
    return s1;
}

u32 func_00194010(u32 a0) {
    u32 s0 = a0;
    func_001ad9c8(a0 + 2092);
    func_001ad9c8(s0 + 2240);
    func_001942b8(s0);
    if (func_001ad9c8(s0 + 2248) != 0) {
        func_00194120(s0, *(f32*)(s0 + 2248));
    }
    func_001ad9c8(s0 + 2256);
    return func_001ad9c8(s0 + 2100);
}

f32 func_00194690(u32 a0) {
    u32 s0 = a0;
    f32 s4 = *(f32*)(a0 + 2092) * *(f32*)(a0 + 2100);
    if (func_001c0cd8(a0) != 0) {
        if ((*(u16*)(s0 + 1398) & 4) == 0) {
            s4 = s4 * func_00194690(*(u32*)(s0 + 1392));
        }
    }
    return s4;
}

void func_00197280(u32 a0) {
    u32 s0 = a0;
    if (func_00170cd0(a0) != 0) {
        *(u32*)(s0 + 52) = 1;
        return;
    }
    u32 t = *(u32*)(s0 + 60);
    u32 f = (u32)*(u16*)(t + 2);
    if ((u8)((f >> 1) & 1) == 0) {
        if (func_00197c28(s0) != 0) {
            *(u32*)(s0 + 52) = 1;
            return;
        }
    }
    func_00197738();
    func_002bc798();
    func_002ba600();
    func_00196e88(s0, 2, 3, 0.0f);
}

u32 func_001984b8(u32 a0) {
    u32 s0 = a0;
    u32 s1 = s0 + 128;
    func_00180ce0(s0 + 320);
    if (*(u32*)(s0 + 128) != 0) {
        func_001de450(s1);
        func_001dde40(s1);
    }
    return func_0016a328(s0);
}

u32 func_00198510(u32 a0) {
    u32 s0 = a0;
    if (func_0016b638(a0) == 0) {
        return 0;
    }
    u32 r = 0;
    if (*(u32*)(s0 + 128) != 0) {
        if (*(u32*)(s0 + 140) != 0) {
            return r;
        }
    }
    func_00198660(s0);
    u32 p = *(u32*)(s0 + 2488);
    if (p != 0) {
        if (func_001b0320(p) != 0) {
            return r;
        }
    }
    r = 1;
    return r;
}

u32 func_001987a8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u32 s1 = a0;
    u32 s2 = func_00198738(a0);
    s1 += 128;
    u32 s3 = func_001050d8(176);
    func_00196ca8(s3, 11, s2);
    *(u32*)(s3 + 8) = s1;
    if (s0 != 0) {
        func_00196e98(s3, s0);
    }
    return func_00196f00(s3);
}

void func_0019ab80(u32 a0) {
    u32 t7 = *(u32*)(a0 + 4);
    u8 t6 = (u8)(t7 & 1);
    if (t6 != 0) {
        return;
    }

    t7 = *(u32*)(a0 + 24);
    t7 = t7 - 1;
    *(u32*)(a0 + 24) = t7;
    if (t7 == 0) {
        func_001991a8(3, *(u16*)(*(u32*)(a0 + 8) + 2));
    }

    if (func_0019abe8() != 0) {
        return;
    }

    func_001991a8(2, 0);
}

void func_0019b5d8(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    u32 t6 = *(u32*)(a1 + 0x6c);
    u32 t7 = *(u8*)(t6 + 0x2e);
    if (t7 != 0) {
        if (func_0015f718(t7 - 1) == 0) {
            u32 t7b = *(u32*)(s0 + 0x6c);
            func_0015ee90(*(u8*)(t7b + 0x2e) - 1);
        }
        t6 = *(u32*)(s0 + 0x6c);
    }

    t7 = *(u8*)(t6 + 0x2f);
    if (t7 != 0) {
        if (func_0015f718(t7 - 1) != 0) {
            u32 t7b = *(u32*)(s0 + 0x6c);
            func_0015ee10(*(u8*)(t7b + 0x2f) - 1);
            return;
        }
    }
}

void func_0019be88(u32 a0) {
    u32 v0 = (*(u32 (**)(u32))(*(u32*)a0 + 0x40))(a0);
    if (v0 == 0) {
        return;
    }
    if ((*(u32*)(a0 + 0x588) & 4) == 0) {
        return;
    }
    if ((*(u32*)(a0 + 0x108) & 0x00100000) == 0) {
        return;
    }
    if (YS_STATUS_IsBattleMode() != 0) {
        return;
    }
    *(u32*)(a0 + 0x108) = *(u32*)(a0 + 0x108) & 0xffefffff;
}

u32 func_0019c5d0(u32 a0) {
    u32 uVar1;
    u32 s0 = a0;
    u32 t7;
    u32 t6;

    t7 = *(u32 *)(s0 + 0x10c);
    t6 = t7 & 0x100;
    t7 = t7 & 0x80;
    uVar1 = 0;
    if (t7 != 0) {
        goto LAB_TRUE;
    }
    if (t6 != 0) {
        uVar1 = 1;
        goto LAB_RET;
    }
    if (func_0019c590() != 0) {
        goto LAB_TRUE;
    }
    if (func_0019c768(s0) != 0) {
        uVar1 = 1;
        goto LAB_RET;
    }
    if (func_002be5f8() != 0) {
LAB_TRUE:
        uVar1 = 1;
    }
LAB_RET:
    return uVar1;
}

u32 func_0019c6f0(u32 a0) {
    u32 s0 = a0;
    u32 uVar1;

    uVar1 = 0;
    if (func_001d7b80(a0 + 0x518) != 0) {
        goto LAB_TRUE;
    }
    if (func_0019c590(s0) != 0) {
        goto LAB_TRUE;
    }
    if (func_0019c768(s0) != 0) {
        uVar1 = 1;
        goto LAB_RET;
    }
    if (func_002be5f8() != 0) {
LAB_TRUE:
        uVar1 = 1;
    }
LAB_RET:
    return uVar1;
}

void func_0019ca90(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 uVar1;

    if (*(u32 *)s0 != 0) {
        func_0019cc20();
    }
    *(u32 *)s0 = s1;
    if ((s2 != 0) && (func_00190140(s2) != 0)) {
        func_0019ca28(s0, s2);
    }
    if (s1 == 1) {
        goto LAB_SET_ZERO;
    }
    if (s1 == 2) {
        func_002ba2e8(7, 0);
        func_0019d438(s0);
        uVar1 = func_0016bff0(*(u32 *)s2);
        func_001991a8(0x9e, uVar1);
    }
LAB_TAIL:
    func_0019cb48(s0);
    func_0019d260(s0);
    return;
LAB_SET_ZERO:
    *(u32 *)(s0 + 0x1c) = 0;
    goto LAB_TAIL;
}

void func_0019cc88(u32 a0, u32 a1) {
    u32 s0 = a0 + 4;
    u32 s1 = a0;
    u32 s2 = a1;
    u32 v0;
    u32 t7;

    if (func_00190680(s0) != 0) {
        return;
    }
    v0 = func_001906c0(s0);
    s0 = v0;
    v0 = func_001906c0(s2);
    if (s0 != v0) {
        func_0019ca90(s1, *(u32 *)s1, s2);
        goto LAB_TAIL;
    }
    func_0019ca28(s1, s2, s2);
    t7 = *(u32 *)(s1 + 0x18);
    if (t7 != 0) {
        *(u32 *)(s1 + 0x18) = func_0013e5a8(t7);
    }
LAB_TAIL:
    func_0019cb48(s1);
}

void func_0019eda0(u32 a0) {
    u32 *s0 = (u32 *)a0;
    u32 t7;
    f32 f1;
    f32 f0;
    s32 i0;

    t7 = s0[0];
    t7 = t7 & 1;
    if (t7 == 0) {
        return;
    }
    func_001ad9c8((void *)((u8 *)s0 + 28));
    f1 = *(f32 *)((u8 *)s0 + 28);
    if (f1 == 0.0f) {
        func_0019ed48((u32)s0);
        return;
    }
    i0 = *(s32 *)((u8 *)s0 + 8);
    f0 = (f32)i0;
    f0 = f0 * f1;
    i0 = (s32)f0;
    func_0014a768((u32)i0 & 0xff);
}

void func_0019f610(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 v0;

    v0 = func_0019f5d8(s0);
    if (v0 == 0) {
        v0 = func_0019f5a8(s0);
    }
    *(u32 *)(v0 + 0) = s1;
    *(u32 *)(v0 + 4) = s2;
    *(u8 *)(v0 + 8) = 1;
}

void func_0019f670(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 v0;

    v0 = func_0019f5d8(s0);
    if (v0 == 0) {
        v0 = func_0019f5a8(s0);
    }
    *(u32 *)(v0 + 0) = s1;
    *(u32 *)(v0 + 4) = s2;
    *(u8 *)(v0 + 8) = 0;
}

void func_0019fd00(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1;
    f32 f20;
    u32 v0;
    u32 t7;

    func_0016bd60(s0, a2);
    s1 = s0 + 0x140;
    f20 = 0.0f;
    v0 = func_0019fdb0(s0);
    ((void(*)(u32, u32, f32, f32))func_0017f488)(s1, v0, f20, f20);
    ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(s1, 0, 0, f20, f20);
    t7 = *(u32 *)(s0 + 0x108);
    t7 = t7 | 0x08000000;
    *(u32 *)(s0 + 0x108) = t7;
}

u32 func_0019fe90(u32 a0, u32 a1, u32, u32, u32, u32, u32, u32) {
    u32* base = *(u32**)(&D_01c60000[0x2fb4]);
    u32 v0 = func_002fd248((a0 << 16) | (a1 << 8), (u32)(base + 2), base[1], 48, (u32)&D_0031f158);
    if (*(u8*)(v0 + 37) == 2) {
        return v0 - 48;
    }
    return v0;
}

u8* func_0019fee8(u8* a0, s32 a1, u32, u32, u32, u32, u32, u32) {
    u8* base = (u8*)*(u32**)(&D_01c60000[0x2fb4]);
    u32 stride = 48;
    u8* limit = base + 8 + (*(u32*)(base + 4) * stride);
    u8* cur = a0 + 48;
    u8* out = a0;
    if (cur < limit) {
        s32 mask = -256;
        s32 key = *(s32*)a0 & mask;
        do {
            if (((*(s32*)cur) & mask) != key) {
                break;
            }
            s32 b0 = cur[0];
            if (a1 < b0) {
                break;
            }
            s32 cls = ((a1 - b0) & 1) + 1;
            s32 tag = cur[37];
            if (tag == 0) {
                out = cur;
                cur += 48;
            } else if (cls != tag) {
                cur += 48;
            } else {
                out = cur;
                cur += 48;
            }
        } while (cur < limit);
    }
    return out;
}

void func_001a0bc0() {
    u8* base = D_01c62fb8;
    s32 i = 0;
    u32 off = 0x9a00;
    u32* p = (u32*)(base + off);
    do {
        *p = (u32)i;
        i += 1;
        p += 1;
    } while (i < 64);

    u8* base2 = D_01c62fb8;
    u32 off2 = 0x8000;
    u32 value = 64;
    *(u32*)(base2 + off2 + 6912) = value;
    D_01c70000[-3409] = 0;
}

void* func_001a0e78() {
    u8* base = D_01c62fb8;
    u32 off = 0x8000;
    u8* p = base + off;
    u32 n = *(u32*)(p + 6912) - 1;
    *(u32*)(p + 6912) = n;
    u32 idx = *(u32*)(base + 0x9a00 + (n << 2));
    void* out = base + (idx * 616);
    func_001a0d48(out);
    return out;
}

u32 func_001a1540(u32 a0) {
    u32 s1 = a0;
    u32 s0 = func_001a1490(a0);
    if (s0) {
        func_001a11e0(s0, 0);
        return s0;
    }

    s0 = func_001a0e78();
    *(u32*)(s0 + 596) = s1;
    u32 r = func_00188fe0((u32)&D_0032e020, 1);
    func_001a11e0(s0, r);
    func_001a1950(s0, *(u32*)(s0 + 4), 0, 0);
    return s0;
}

u32 func_001a15d0(u32 a0, s32 a1) {
    u32 s1 = a0;
    s32 s2 = a1;
    u32 s0 = func_001a1490(a0);
    if (s0) {
        if (s1 == 1 || s1 == 14) {
            if (*(u32*)(s0 + 608) == 0) {
                *(u32*)(s0 + 608) = (u32)&D_0032e020;
            }
            if (s2 >= 0) {
                func_001a11b0(s0, (u32)s2);
            }
        }
        func_001a11e0(s0, 0);
    }
    return s0;
}

u32 func_001a1728(u32 a0, u32 a1) {
    u32 s2 = a0;
    u32 s0 = a1;
    u32 s1 = func_001a0e78();
    *(u32*)(s1 + 596) = s2;

    u32 s3 = (u32)&D_0032e020;
    *(u32*)(s1 + 580) = func_00188fe0(s3, s2);

    if (s2 == 1 || s2 == 14) {
        if (*(u32*)(s1 + 608) == 0) {
            *(u32*)(s1 + 608) = s3;
        }
        func_001a11b0(s1, s0);
    }

    func_001a11e0(s1, 0);
    return s1;
}

u32 func_001a1990(u32 a0, s32 a1) {
    u32 s1 = a0;
    s32 s0 = a1;
    if (func_001a1de0(a0)) {
        if (s0 > 0) {
            f32 k = *(f32*)(*(u32*)&D_00352130 + 124);
            f32 v = (f32)s0 * k;
            func_001a1d50(s1, -v);
        }
        return *(u32*)(s1 + 384);
    }

    s32 sum = *(s32*)(s1 + 384) + s0;
    s32 out;
    if (sum < 0) {
        goto neg;
    }
    out = sum;
    {
        s32 hi = *(s32*)(s1 + 388);
        if (hi < sum) {
            out = hi;
        }
        goto store;
    }
neg:
    out = 0;
store:
    *(s32*)(s1 + 384) = out;
    return (u32)out;
}

u32 func_001a1cc0(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 z = 0;
    u32 v1 = *(u32*)(s0 + 4);
    func_001a1950(s0, v1, z, z);
    func_001a1a50(s0, 0);
    if (s1 == 6) {
        s2 = *(u32*)(*(u32*)&D_00352130 + 140) - 2;
    }
    return func_001a1c90(s0, 2, s2);
}

void func_001a26b8(u32 a0) {
    u32 s0 = a0;
    u32 flags = *(u32*)(a0 + 592);
    if ((flags & 1) == 0) {
        u32 v0;
        u32 v1;
        u32 p = *(u32*)(a0 + 604);
        if (func_0016c060(p, (u32)&v0, (u32)&v1)) {
            func_0013dab0();
        }
        *(u32*)(s0 + 592) = *(u32*)(s0 + 592) | 1;
    }
}

void func_001a27f0(u32 a0, u32 a1) {
    if (a1 == 0xffff && a0 == 1) {
        u8* p = D_01c62fb8;
        s32 i = 63;
        do {
            func_001a0d48((u32)p);
            i = i - 1;
            p = p + 616;
        } while (i != -1);

        u8* base = D_01c62fb8;
        u32* t = (u32*)(base + 0x9a00);
        s32 n = 0;
        do {
            *t = (u32)n;
            n = n + 1;
            t = t + 1;
        } while (n < 64);
        *(u32*)(base + 0x8000 + 6912) = 64;
    }
}

u32 func_001a3570(u32 a0) {
    u8* p = func_001a80c8(a0);
    u32 out = 0;
    u32 f = p[3];
    f = f & 1;
    if (f != 0) {
        u32 idx = *(u16*)(p + 18);
        u32 bit = 1u << (idx & 31);
        u32 w = idx >> 5;
        u32 v = *(u32*)((&D_0032f1f0) + (w << 2));
        out = ((v & bit) != 0);
        return out;
    }

    u32 t = p[2];
    if (t == 19) {
        return out;
    }
    u32 idx = *(u16*)(p + 18);
    u8* b = (&D_0032bb30) + idx;
    out = b[13696];
    return out;
}

void func_001a3710() {
    s32 s0 = 0;
    u32 s1 = func_001a8bd0(0xffffffff);
    do {
        u32 v = func_001a8c10(s1, s0);
        s0 = s0 + 1;
        u32 p = func_00188fe0((u32)&D_0032e020, v);
        if (p) {
            func_00188ac8(p);
        }
    } while (s0 < 4);
}

u32 func_001a3788(u8* a0, u32 a1, s32 a2) {
    u8* s1 = a0;
    s32 s0 = a2;
    u8* p = func_001a80c8(a1);
    if (s0 < 0) {
        s0 = p[23];
    }
    s1[1] = (u8)s0;
    s1[0] = 9;
    u32 r = func_00192048(*(u16*)(p + 8));
    u32 r2 = func_00192c90(r, (u32)(s1 + 2));
    return r2 + 2;
}

u32 func_001a3bf0(u32 a0, u32, u32 a2, u32 a3, u32 a4, u32 a5) {
    u32 s0 = a0;
    u32 s1 = a3;
    u32 s2 = a4;
    u32 s3 = a5;
    u32 s4 = a2;
    s32 r = func_001de2e0(s0);
    if (r < 0) {
        return 0;
    }
    return func_001de168(s0, (u32)r, s1, s2, s3, s4);
}

void func_001a3c88() {
    u32* s0 = &D_01c70000[-3392];
    s32 s1 = 3;
    do {
        u32 p = *s0;
        if (p) {
            if (!func_001dc9d0(p)) {
                *s0 = 0;
            }
        }
        s1 = s1 - 1;
        s0 = s0 + 1;
    } while (s1 >= 0);
}

u32 func_001a4550(u32 a0, u32 a1) {
    u32 s1 = func_001050d8(320);
    func_001a4498(
        s1,
        *(u32*)(a0 + 12),
        a1,
        *(u32*)(a0 + 32),
        *(u32*)(a0 + 24),
        *(u32*)(a0 + 28));
    *(u32*)(s1 + 36) = *(u32*)(a0 + 36);
    return s1;
}

void func_001a5990(u32 a0, u32 a1, f32 a2) {
    u32 s0 = D_0034e948;
    if (func_0019ba60(s0) == 0) {
        return;
    }
    if ((*(u32*)(a0 + 40) & 1) == 0) {
        return;
    }
    if (((u32(*)(u32, u32, f32, f32))func_001c7950)(a0, s0, 0.0f, 0.0f) == 0) {
        return;
    }
    func_001c79a0(a0, s0, 0);
    func_001d8d08(a1, a2);
}

u32 func_001a5b68(u32 a0) {
    u32 s1 = D_01c6cb1c;
    u32 s0 = (u32)&D_0031f288;
    u32 v0 = func_002fd248(a0, s1 + 8, *(u32*)(s1 + 4), 24, s0);
    if (v0 == 0) {
        u32 p = D_01c6cb1c;
        v0 = func_002fd248(72, p + 8, *(u32*)(p + 4), 24, s0);
    }
    return v0;
}

void func_001a5d48(u32 a0) {
    f32 f0 = *(f32*)(a0 + 8);
    if (f0 > 0.0f) {
        func_001826c8(-f0);
    }

    u32 p = *(u32*)a0;
    if (p != 0) {
        func_0016cab8(p);
        func_0016c7d8(p);
    }

    func_0031f298((u32)&D_01c6cb20, a0);
}

void func_001a5ec0(void) {
    func_001a5e38();

    s32 i = 5;
    u32 off = 0;
    u32 base = (u32)&D_00350800;
    u32 base2 = base + 12;
    while (1) {
        u32 p = off + base;
        if (*(u32*)p != 0) {
            u32 q = off + base2;
            if (*(u32*)q != 0) {
                func_001dde40(q);
            }
            func_00170950(*(u32*)p);
        }
        i -= 1;
        if (i < 0) {
            return;
        }
        off += 44;
    }
}

u32 func_001a6118(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s1 = func_0016cf00(a0, 0, a1, a2, a3);
    u32 s0 = func_001050d8(16);
    func_001a5c48(s0, s1, 0);
    return s0;
}

u32 func_001a6598(u32 a0) {
    u8* p = func_001b8e88(func_001a67b0(a0));
    u32 bit = a0 & 0x1Fu;
    u32 mask = 1u << bit;
    if (*(u8*)(p + 28) >= 255u) {
        return 2u;
    }
    return (D_0032f274[a0 >> 5] & mask) == 0;
}

void func_001a6e88(u32 a0, u32 a1, u32 a2) {
    func_001c1130(12);
    func_001b9c28(0);
    func_001a6dd8(a0, a1, a2, (u32)&func_001a6ef0, (u32)&func_001a6fe8);
}

void func_001a70a0(u32 a0, u32 a1, u32 a2) {
    func_001c1130(12);
    func_001b9c28(0);
    func_001a6dd8(a0, a1, a2, (u32)&func_001a7108, (u32)&func_001a7440);
}

void func_001a8618(u32 a0, u32 a1, u32 a2) {
    func_001980d0(a0, a1, 8, a2);
    *(u32*)a0 = (u32)&D_003509c0;
    u32 ok = func_00198738(a0, D_003509b0);
    *(u8*)(a0 + 2548) = (ok != 0);
    *(u32*)(a0 + 2552) = 0;
    *(u32*)(a0 + 1416) |= 0x200;
}

s32 func_001a9018(u32 a0, s32 a1) {
    s32 i = 0;
    do {
        if (func_001a8c10(a0, i) == a1) {
            return i;
        }
        i = i + 1;
    } while (i < 4);
    return -1;
}

void func_001a9218(u32* a0) {
    u32 v0 = func_0016f470(a0[2], 0);
    a0[3] = func_001708f8(v0, a0[0]);

    if (func_0016f6f8(a0[1]) == 0) {
        if (func_0016f770(a0[1]) == 0) {
            u32 t7 = ((u8*)(a0[2]))[0x48];
            t7 = t7 ^ 1;
            t7 = t7 & 1;
            if (t7 != 0) {
                v0 = func_0016f4b8(a0[2], 0);
                a0[4] = func_001708f8(v0, a0[0]);
            }
        }
    }

    if (func_0016f6f8(a0[1]) == 0) {
        v0 = func_0016f520(a0[2], a0[1], 0);
        if (v0 != 0) {
            a0[5] = func_001708f8(v0, 0xffffffffU);
        }
    }
}

void func_001a9350(u32* a0) {
    u32 t7 = a0[3];
    if (t7 != 0) {
        func_00170950(t7);
    }

    t7 = a0[4];
    if (t7 != 0) {
        func_00170950(t7);
    }

    t7 = a0[5];
    if (t7 != 0) {
        func_00170950(t7);
    }

    func_001a91f8(a0);
}

u32 func_001a9808(u32 a0, s32 a1) {
    s32 s0 = a1;
    if (s0 < 0) {
        s0 = D_0032bae0;
    }

    u32 a1v = D_01c6cc50[0];
    u32 a3v = 80;
    u32 a2v = *(u32*)(a1v + 4);
    u32 v0 = func_002fd248(a0, a1v + 8, a2v, a3v, (u32)func_001a97f8);
    return v0 + (s0 << 2) + 4;
}

void func_001a9860(u32* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
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

void func_001aa850(s32* a0, s32 a1) {
    func_001b7e68(a0 + 16, (*(s32*)(a0[0] + 0x18) * a1) + 1);
    s32 t15 = a0[18];
    a0[1] = 0;
    s32 t14 = t15;
    t15 = t15 + 16;
    a0[19] = t14;
    a0[18] = t15;
}

void func_001aad28(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4, u32 a5) {
    u8 stack_70[96];
    func_002f28b8(stack_70, (u32)a0, (u32)a1, (u32)a2, 0, 0, (u32)a3, (u32)a4);
    func_003058a0(0);
    func_002f2be0(stack_70, a5);
    func_002f25a0(0, 0);
}

u32 func_001ab820(u32 a0) {
    s32 v0 = func_00105c30();
    if ((v0 == 1) || (v0 == 8)) {
        s32 t = (s32)(((u32)*(u8*)(a0 + 0x10)) << 1);
        return (u32)(t / 3);
    }
    return ((u32)*(u8*)(a0 + 0x10)) / 3;
}

void func_001ac908(u32* a0) {
    s32 t6 = (s32)a0[28];
    if (t6 == 1) goto L_state1;
    if (t6 < 2) {
        if (t6 == 0) {
            a0[28] = 1;
        }
        return;
    }
    if (t6 == 4) {
        a0[28] = 7;
    }
    return;

L_state1:
    u32 t7 = a0[3];
    t7 = t7 & 1;
    t7 = (u8)t7;
    if (t7 == 0) {
        return;
    }
    func_001ac728((u32)a0);
}

void func_001adea8() {
    u32* p = *(u32**)((u8*)D_01c70000 - 12364);
    u32 n = p[0];
    u32 v = ((u32)p + (n << 4) + 67) & (u32)-64;
    *(u32*)((u8*)D_01c70000 - 12360) = v;
    return func_00168388((u32)D_0036d830, v, (u32)D_001adc08, (u32)D_01c94000);
}

u32 func_001ae460(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001ae308(*(u32*)((u8*)D_01c70000 - 12368), s0);
    if (v0 == 0) {
        v0 = func_001ae308(*(u32*)((u8*)D_01c70000 - 12364), s0);
        if (v0 == 0) {
            v0 = func_001ae308(*(u32*)((u8*)D_01c70000 - 12360), s0);
        }
    }
    return v0;
}

void func_001ae590(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;
    const u32 s2 = 2;
    const u32 s3 = 1;

    while (1) {
        if (func_002f79c8(1) == s2) {
            if (func_002f6fa0(s1, s0) == s3) {
                return;
            }
            *(u32*)(D_00350000 + 3208) = func_002f7dc8();
        }
        func_001ae690();
    }
}

u32 func_001aea60(u32 a0) {
    u32 s0 = a0;
    func_00185d10(s0);

    *(u32*)(D_00350000 + 3272) = s0;

    u32 v0 = func_0016a020(s0);
    *(u32*)(D_00350000 + 3280) = v0;

    v0 = func_0016ac38(s0, 0, 1, 0, 0);
    *(u32*)(D_00350000 + 3276) = v0;
    if (v0 != 0) {
        *(u32*)(v0 + 4) = 3;
    }

    v0 = func_0016a020(s0);
    return func_001991a8(4, v0);
}

void func_001af210(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)(a0 + 4);
    if (t7 != 0) {
        func_00170950(t7);
        func_00170320(5000);
    }

    u32 t7b = *(u32*)(D_00350000 - 3520);
    t7b &= (u32)-3;
    *(u32*)(D_00350000 - 3520) = t7b;

    u32 t6 = *(u32*)(s0 + 0);
    if (t6 != 2) {
        func_001c8d98((u32)(D_00350000 + 7880), 1);
    }

    func_001384a0(2);
    *(u32*)(D_00350000 + 3568) = 0;
}

void func_001af290(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(D_00350000 + 3568) != 0) {
        return;
    }
    u32 v0 = func_001050d8(80);
    return func_001aedf8(v0, s0, 0);
}

u32 func_001af8d8(u32 a0) {
    u32 s0 = a0;
    func_00170320(5000);
    u32 v0 = func_00170518(*(u32*)((u8*)D_00350000 + 3564), 5000, 0);

    u32 t7 = *(u32*)(s0 + 48);
    if (t7 != 0) {
        return func_0016ed50(t7, (u32)-1, 30);
    }
    return v0;
}

void func_001afa88(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(D_00350000 + 3576) != 0) {
        do {
            func_00102448(s0, 0);
        } while (*(u32*)(D_00350000 + 3576) != 0);
    }
    *(u32*)(D_00350000 + 3576) = s0;
}

void func_001afaf0(u32 a0) {
    func_001afa88(a0);

    u32* p = (u32*)(D_01c90000 + 16528);
    u32* end = (u32*)(D_01c90000 + 16564);
    do {
        *p &= (u32)-2;
        p = (u32*)((u8*)p + 12);
    } while ((s32)(u32)p < (s32)(u32)end);

    u32 s0 = func_00170b30(0x00080000);
    func_001afc00(566, s0);
    func_001afc00(567, s0);
    func_001afc00(568, s0);
    func_00170c00(s0);
    return func_001afae0();
}

void func_001afb80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a2;
    u32 s1 = a1;
    u32 s2 = a3;

    func_001afa88(a0);

    s32 idx = func_001afe30(s0);
    if (idx >= 0) {
        u32* p = (u32*)(D_01c90000 + 16528 + idx * 12);
        *p &= (u32)-2;
    }

    func_001afc00(s2, s1);
    return func_001afae0();
}

void func_001b03b0(s32 a0, s32 a1) {
    if ((u32)a1 == 0xffffu && a0 == 1) {
        u32* s0 = (u32*)(D_01c90000 + 16528);
        s32 s2 = 2;
        const s32 s1 = -1;
        do {
            s0[0] = 0;
            s2 -= 1;
            func_0031cc28((u32)s0);
            s0[1] = (u32)-1;
            s0[2] = (u32)-1;
            s0 = (u32*)((u8*)s0 + 12);
        } while (s2 != s1);
    }
}

void func_001b04d8(u32 a0) {
    u32 s0 = a0;

    if (func_001b0498(s0) == 0) {
        const f32 z = 0.0f;
        u32 t7 = 1;
        if (*(f32*)(s0 + 20) == z) {
            t7 = 0;
        }
        u32 t6 = t7 & 0xff;
        if (t6 != 0) {
            *(f32*)(s0 + 16) = z;
        }
        return;
    }

    func_001ad9c8(s0 + 16);

    if (*(f32*)(s0 + 16) == 0.0f) {
        *(u32*)(s0 + 4) = 0;
    }

    if (*(u32*)(s0 + 4) != 2) {
        return;
    }

    u32 v0 = func_0019ba60(*(u32*)(s0 + 48));
    if (v0 != 0) {
        u8 tmp[16];
        func_0016c2b0(tmp, *(u32*)(s0 + 48));
        func_001b0940(s0, tmp);
    } else {
        *(u32*)(s0 + 4) = 0;
    }
}

void func_001b1da0(u32 a0) {
    u32 s0 = a0;

    u32 v0 = func_0016bff0(a0);
    func_001991a8(75, v0);

    f32 f12 = 0.0f;
    u32 t6 = *(u32*)(s0 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    t7 ^= 0x17;
    if (t7 == 0) {
        ((void(*)(u32, u32, f32, f32))func_0017f488)(s0 + 320, 16, f12, f12);
    }

    return func_00185d10(s0);
}

u32 func_001b2b80(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s0 = a1;

    if (func_0019c090(a1) == 0) {
        u32 v0 = func_0016c028(s0);
        *(f32*)(s0 + 224) = *(f32*)(v0 + 4);
    }

    return func_0017c578(s1, s0);
}

u32 func_001b3b10(u32 a0) {
    u32 s0 = a0;
    func_00190920(a0 + 2548, 3, s0);
    func_00198450(s0);
    u32 v0 = func_0016a070(s0);

    u32 a1 = 19;
    if (v0 != 5008) {
        return;
    }
    return func_0016bd60(s0, a1);
}

void func_001b3c00(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    u32 t7 = *(u32*)(a0 + 1164);
    if (t7 != 0) {
        func_001a17c8(t7);
    }

    u32 v0 = func_001a1018(s1);
    *(u32*)(s0 + 1164) = v0;
    if (v0 != 0) {
        *(u32*)(v0 + 604) = s0;
    }
}

void func_001b3c58(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    u32 t7 = *(u32*)(a0 + 1164);
    if (t7 != 0) {
        func_001a17c8(t7);
    }

    u32 v0 = func_001a1060(s1);
    *(u32*)(s0 + 1164) = v0;
    if (v0 != 0) {
        *(u32*)(v0 + 604) = s0;
    }
}

void func_001b4d10(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)(*(u32*)(a0 + 0x10) + 0x484);
    if (s0 != 0) {
        u32 stack0 = s1;
        u32 a2 = func_0016cb88(s0, 22);
        u32 v0 = func_0016cf00(s0, 0, a2, &stack0, 1);
        *(u32*)(s1 + 0x34) = v0;
    }
}

void func_001b4d70(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)(*(u32*)(a0 + 0x0c) + 0x484);
    if (s0 != 0) {
        u32 stack0 = s1;
        u32 a2 = func_0016cb88(s0, 22);
        u32 v0 = func_0016cf00(s0, 0, a2, &stack0, 1);
        *(u32*)(s1 + 0x34) = v0;
    }
}

void func_001b5588(u32 a0) {
    u32 s0 = a0;
    u32 t6 = *(u32*)(s0 + 0x40);
    u32 a0p = a0 + 0x68;
    if ((t6 & 4) == 0) {
        if ((*(u32*)(s0 + 0x74) & 4) != 0) {
            func_001d1b28((void*)a0p);
        }
        func_001b5878(s0);
        t6 = *(u32*)(s0 + 0x40);
    }
    *(u32*)(s0 + 0x40) = t6 | 4;
}

u32 func_001b5680(u32 a0) {
    u32 s0 = a0;
    u32 t5 = 0;

    if (func_001d1f08((void*)(a0 + 0xa8)) == 0) {
        return t5;
    }

    if (((*(u32*)(*(u32*)(s0 + 0x0c) + 0x168) & 1) & 0xff) != 0) {
        return t5;
    }

    u32* p = (u32*)(s0 + 0x10);
    for (s32 i = 0; i < 2; i++) {
        u32 v = *p;
        p += 1;
        if (v != 0) {
            if (((*(u32*)(v + 0x168) & 1) & 0xff) != 0) {
                return t5;
            }
        }
    }

    t5 = 1;
    return t5;
}

void func_001b57f8(u32 a0) {
    if ((*(u32*)(a0 + 0x40) & 8) != 0) {
        u32 s0 = a0;
        u32 obj = *(u32*)(*(u32*)(a0 + 0x0c) + 0x0b44);
        FnA0 fn = (FnA0)(*(u32*)(*(u32*)obj + 0x18));
        fn(obj);
        *(u32*)(s0 + 0x3c) = *(u32*)(s0 + 0x3c) - 1;
        *(u32*)(s0 + 0x40) = *(u32*)(s0 + 0x40) & (u32)-9;
    }
}

u32 func_001b5918(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 v0;
    u32 t6 = D_01d48cb0;
    u32 t7;
    if (t6 == 0) {
        goto ret0;
    }

    t7 = t6 + 0x18;
    if (a0 == t7) {
        goto callpath;
    }

ret0:
    v0 = 0;
    goto done;

callpath:
    u32 args[3];
    args[0] = a1;
    args[1] = a2;
    args[2] = a3;
    func_0016cce8(*(u32*)(t6 + 0x34), 24, args, 3, 0);
    v0 = 1;
done:
    return v0;
}

void func_001b5f68(u32 a0) {
    u32 s0 = a0;
    u32 s1 = *(u32*)(a0 + 4);
    u32 stack_buf[4];

    u32 a3 = func_0017df70(3);
    func_001b5ce8(stack_buf, 0, s1, a3);

    *(u32*)(s0 + 8) = func_0016a070(s1);

    u32 v0 = func_001b5cf8(stack_buf, s0);
    VirtCall fn = (VirtCall)(*(u32*)(*(u32*)v0 + 0x54));
    fn(v0, 17, 0);
}

void func_001b5fe0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001a8bd0(-1);
    func_001a8f68(v0, *(u32*)(s0 + 8));
    func_001afae0();
    func_001c8d98((u32)&D_00351ec0, 2);
    D_00351180 = 0;
}

void func_001b6450(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 0x10);
    if (p != 0) {
        func_001b1ab8(p);
        *(u32*)(s0 + 0x10) = 0;
    }

    func_0019ed48((u32)&D_00350448);
    func_001b6ab8(s0);

    if (*(u8*)(s0 + 0x1c) != 0) {
        func_001c9b90();
    }
    func_001c8d98((u32)&D_00351ec0, 1);

    u32 s1 = (u32)&D_00351eb8;
    if ((*(u32*)(s0 + 0x0c) & 8) == 0) {
        u32 v0 = func_001c8db8(s1, 0);
        if (v0 != 0) {
            func_001c8d98(s1, 0);
        }
    }

    u32 t6 = D_00351184;
    if ((t6 ^ s0) == 0) {
        t6 = 0;
    }
    D_00351184 = t6;
}

void func_001b6518(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 0x10);
    if (p != 0) {
        func_001b1ab8(p);
        *(u32*)(s0 + 0x10) = 0;
    }

    func_0019ed48((u32)&D_00350448);
    func_001b6ab8(s0);

    if (*(u8*)(s0 + 0x1c) != 0) {
        func_001c9b90();
    }
    func_001c8d98((u32)&D_00351ec0, 1);

    u32 s1 = (u32)&D_00351eb8;
    if ((*(u32*)(s0 + 0x0c) & 8) == 0) {
        u32 v0 = func_001c8db8(s1, 0);
        if (v0 != 0) {
            func_001c8d98(s1, 0);
        }
    }

    u32 t6 = D_00351184;
    if ((t6 ^ s0) == 0) {
        t6 = 0;
    }
    D_00351184 = t6;
}

void func_001b6e08(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    *(u32*)(a1 + 0xf0) = *(u32*)(*(u32*)(a1 + 0x0c) + 4);
    func_0017c578();

    f32 f20 = func_00184a90(s0);
    f32 f1 = *(f32*)(func_0016c028(s0) + 4);
    f20 = f20 - f1;

    if (0.0f < f20) {
        f20 = func_00184a90(s0);
        f1 = f20 - *(f32*)(func_0016c028(s0) + 4);
    } else {
        f1 = 0.0f;
    }

    *(f32*)(s0 + 0xe0) = f1;
}

void func_001b6e90(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s0 = a1;

    func_0017c690(s1);

    f32 f1cmp = *(f32*)(s0 + 0xd0);
    f32 f0cmp = *(f32*)(s0 + 0xd4);
    if (f0cmp <= f1cmp) {
        f32 f20 = func_00184a90(s0);
        f32 f1 = *(f32*)(func_0016c028(s0) + 4);
        f20 = f20 - f1;

        if (0.0f < f20) {
            f20 = func_00184a90(s0);
            f1 = f20 - *(f32*)(func_0016c028(s0) + 4);
        } else {
            f1 = 0.0f;
        }

        if (f1 <= *(f32*)(s0 + 0xe0)) {
            VirtCall2 fn = (VirtCall2)(*(u32*)(*(u32*)s1 + 0x14));
            fn(s1, s0);
        }
    }
}

u32 func_001b7038() {
    u32 t7 = 0;
    if (func_001bbb28() != 0) {
        return t7;
    }

    u32 s2 = 0;
    u32 s1 = func_001a8b68(0);
    u32 s0 = D_0034e948;
    if (func_0019ba60(s0) != 0) {
        if (func_0016a070(s0) == s1) {
            u32 v0 = func_00177860(s0);
            u32 masked = *(u32*)(v0 + 0x0c) & 0x00100000;
            s2 = (masked < 1);
        }
    }

    t7 = s2;
    return t7;
}

void func_001b7538(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 stack_buf[8];

    if (a1 != 0) {
        func_001a3788(stack_buf, a1, -1);
        u32 v0 = func_00192048(0x8ae8);

        u32 s0 = *(u32*)(s1 + 8);
        u32 base = s1 + (s0 << 5) + 12;
        u32 out_index = (s0 << 2) + s1;
        v0 = func_00192e50(v0, base, 32, (u32)stack_buf);

        u32 next = *(u32*)(s1 + 8);
        *(u32*)(out_index + 0) = v0;
        next = next + 1;
        *(u32*)(s1 + 8) = next;
    }
}

u32 func_001b75e8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s3 = a2;
    u32 s2 = func_001b77a8(s1);
    u32 t0 = func_001b75b0(s0, s1);
    return func_001531f8(s2, *(u32*)(s0 + 0), *(u32*)(s0 + 4), s3, t0);
}

u32 func_001b7658(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s3 = a2;
    u32 s2 = func_001b77a8(s1);
    u32 t0 = func_001b75b0(s0, s1);
    return func_00153310(s2, *(u32*)(s0 + 0), *(u32*)(s0 + 4), s3, t0);
}

void func_001b76c8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    if (*(u32*)(a0 + 0) == 0) {
        return;
    }

    u32 out;
    if (s1 == 0) {
        out = func_001b77a8(1);
    } else {
        u32 v0 = func_001a36e0(s1);
        v0 = func_001a80c8(v0);
        out = func_00192048(*(u16*)(v0 + 8));
    }

    func_00153350(out, *(u32*)(s0 + 0), *(u32*)(s0 + 4), s2, s1);
}

u32 func_001b7850(u32 a0, u32 a1, u32 a2) {
    u32 s1 = a0;
    u32 s0 = a2;
    u32 v0 = func_0018a218(a1, a2);
    u32 t6 = 0;
    if (v0 != 0) {
        u32 p = func_001050d8((v0 << 5) + 16);
        *(u32*)(p + 4) = s1;
        t6 = p;
        *(u32*)(p + 8) = s0;
        *(u32*)(p + 0) = 0;
    }
    return t6;
}

void func_001b8348() {
    u32 buf[12];
    func_001b82d8(buf);

    u32 v0 = func_001708f8(buf, -1);
    D_01d48cc0 = v0;
    v0 = func_00168b38(v0, 2, 0);
    D_01d48cc4 = *(u32*)(v0 + 8);

    u32 t4 = 0;
    u32* t7 = &D_01d48cc8;
    u32* t6 = t7 + 40;
    do {
        *t6 = t4;
        t4 = t4 + 1;
        t6 = t6 + 1;
    } while ((s32)t4 < 8);

    D_01d48d88 = 8;
}

void func_001b8450(u32 a0, u32 a1, u32 a2) {
    u32 s1 = a0;
    u32 s0 = a1;
    u32 s2 = a2;
    u32 v0 = func_001b83f0(s0);
    *(u32*)(s1 + 0) = s0;
    if (v0 != 0) {
        *(u32*)(s1 + 4) = *(u16*)(v0 + 2);
    } else {
        *(u32*)(s1 + 4) = 0;
    }
    *(u32*)(s1 + 12) = s2;
    *(u32*)(s1 + 8) = 0;
    *(u32*)(s1 + 16) = 0;
}

void func_001b8718(u32 a0, u32 a1) {
    if (a1 != 0xffff) {
        return;
    }
    if (a0 != 1) {
        return;
    }

    u32* p = &D_01d48cc8;
    s32 i = 7;
    do {
        *(u32*)((u8*)p + 0) = 0;
        *(u32*)((u8*)p + 4) = 0;
        i = i - 1;
        p = (u32*)((u8*)p + 20);
    } while (i != -1);

    func_00320418((u32)&D_01d48cc8);
}

void func_001b8bf8(u32 a0, u32 a1) {
    u32 s1 = 0;
    u32 s2 = a0;
    u32 s3 = a1;
    if (*(u16*)(a0 + 2) != 0) {
        u32 s0 = a0 + 4;
        do {
            u32 v0 = func_001b6d70(*(u16*)(s0 + 0));
            s1 = s1 + 1;
            s0 = s0 + 4;
            func_001b6d88(v0, s3);
        } while ((s32)s1 < (s32)*(u16*)(s2 + 2));
    }
}

void func_001b8c70(u32 a0, u32 a1) {
    u32 s1 = 0;
    u32 s2 = a0;
    u32 s3 = a1;
    if (*(u16*)(a0 + 2) != 0) {
        u32 s0 = a0 + 4;
        do {
            u32 v0 = func_001c2b58(*(u16*)(s0 + 0));
            s1 = s1 + 1;
            *(u8*)(v0 + 0) = (u8)s3;
            if (!((s32)s1 < (s32)*(u16*)(s2 + 2))) {
                break;
            }
            s0 = s0 + 4;
        } while (true);
    }
}

void func_001b8da0() {
    u8 buf[256];
    u32 s0 = 0;
    u32 s1 = func_001b8d60(buf);
    if ((s32)s1 > 0) {
        do {
            u32 v0 = func_001b8800(buf[s0]);
            s0 = s0 + 1;
            func_001b8988(v0, 0);
        } while ((s32)s0 < (s32)s1);
    }
}

u32 func_001b91d0(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 t5 = a0;
    u16 t6 = *(u16*)(a0 + 2);
    u16 t7 = *(u16*)(a0 + 0);
    if (t7 != t6) {
        u32 v0 = func_001b8e88(t6);
        u32 (*rec)(u32, u32) = func_001b91d0;
        u32 out = rec(v0, s0);
        return out;
    }
    s32 bits = (u32)*(u16*)(t5 + 0x2c);
    bits = bits >> s0;
    bits = bits & 1;
    u32 v = (u8)bits;
    return v;
}

void func_001b9230() {
    D_01d48db8 = 0;
    D_00351210 = 0;

    u32 v0 = func_00102c18(1, 20000, (u32)&D_001b92d0);
    *(u32*)(v0 + 0x30) = (u32)&D_001b92f8;
    v0 = func_001050c8();
    v0 = func_001024b0(v0);

    D_00351214 = v0;
    func_00102788(v0, 0, 5, (u32)&D_001b9670);
    func_001123f0();

    v0 = func_00102c18(1, 0x00016378, (u32)&D_001b9880);
    *(u32*)(v0 + 0x30) = (u32)&D_001b99b0;
    func_00188670();
    return func_001b2f10();
}

void func_001b9b28(u32 a0) {
    D_00351210 = a0;

    if (func_0019c768(a0) == 0) {
        if (func_001c0cd8(a0) != 0) {
            func_00193608(*(u32*)(a0 + 1392));
        }

        func_00193608(a0);
        func_0017fba0(a0 + 320, a0 + 1712);

        if (func_0019c470(a0) == 0) {
            func_001b3118(a0 + 2048, a0);
        }

        u32 t7 = *(u32*)(a0 + 1296);
        if (t7 != 0) {
            func_001b78d0(t7);
        }
    }

    u32 t7 = *(volatile u32*)(a0 + 2040);
    *(u32*)(a0 + 2040) = t7 | 0x500;
}

u32 func_001ba528(u32 a0, u32 a1, u32 a2) {
    (void)a0;
    u32 s1 = a1;
    u32 s0 = func_00176b58(a2);
    if (s0 == 0) {
        return;
    }
    u32 v0 = func_001a3a78();
    return func_001de168(v0, s1, 1, 1, 10002, s0);
}

void func_001ba650(u32 a0) {
    u32 s0 = a0;
    if (func_00176e78(a0, *(u16*)(a0 + 2860), *(u16*)(a0 + 2862)) == 0) {
        return;
    }

    u32 v0 = func_001050d8(24);
    return func_001ba1f8(v0, s0, *(u16*)(s0 + 2860), *(u32*)(s0 + 2864));
}

void func_001ba6b0() {
    u32 s0 = D_01d48de0;
    if (s0 == 0) {
        return;
    }

    while (1) {
        u32 s1 = *(u32*)(s0 + 20);
        if (func_001ba408(s0) == 0) {
            if (s0 != 0) {
                func_001ba310(s0);
                func_00105110(s0);
            }
        }

        if (s1 == 0) {
            return;
        }
        s0 = s1;
    }
}

void func_001ba740() {
    u32 s0 = D_01d48de0;
    if (s0 == 0) {
        return;
    }

    while (1) {
        u32 s1 = *(u32*)(s0 + 20);
        if (s0 != 0) {
            func_001ba310(s0);
            func_00105110(s0);
        }
        if (s1 == 0) {
            return;
        }
        s0 = s1;
    }
}

void func_001bb020(u32 a0) {
    u32 s0 = a0;
    func_001d7380(*(u32*)a0);
    func_0014ca20();

    s32 t7 = *(s32*)(s0 + 716);
    if (t7 >= 0) {
        func_001969c0((u32)t7);
    }

    if (*(u32*)(s0 + 72) != 0) {
        u32 p = s0 + 12;
        if (*(u32*)(s0 + 12) != 0) {
            func_001dde40(p);
        }
        func_00170950(*(u32*)(s0 + 72));
    }

    return ((void(*)())func_001bbb50)();
}

void func_001bb630(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    if (func_001bbb50() == 0) {
        if (s0 != 156) {
            goto L001bb684;
        }
    }
L001bb660:
    {
        u32 v0 = func_001c10f8(26);
        return func_00253410(v0, 0);
    }

L001bb684:
    if (func_001991a8(s0, s1) != 0) {
        return func_001bb468();
    }
    if (s0 == 8) {
        return func_001bbc30();
    }
    (void)s1;
}

void func_001bb6d0(u32 a0) {
    u32 s0 = a0;
    u32 a1_live = s0;
    u32 v0 = func_001bc090(a0);
    if (v0 != 0) {
        v0 = func_00198bd0(7, a1_live);
        if (v0 != 0) {
            u32 t6 = *(u32*)(v0 + 8);
            if (t6 != 0xffff) {
                if (func_00181500(t6) != 0) {
                    return func_001bb4f0(D_01d49320, 156, s0);
                }
            }
        }
    }

    return func_001bb4f0(D_01d49320, 7, s0);
}

void func_001bb8f0() {
    u32 g = D_01d49320;
    *(u32*)(g + 4) &= 0xffffffef;
    func_001919a8();

    D_0034f240 &= 0xfffffffd;
    func_001d6c88();
    func_001bbac0();
    func_002bc798();
    return func_001c8d98((u32)&D_00351ec8, 0);
}

void func_001bbcf8(u32 a0) {
    u32 s0 = a0;
    if (func_001bb4a0(a0) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    if ((*(u32*)(v0 + 752) & 4) == 0) {
        return;
    }

    v0 = func_001bbcb0();
    return func_001d4e50(v0 + 740, s0);
}

void func_001bbd58(u32 a0) {
    u32 s0 = a0;
    if (func_001bb4a0(a0) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    if ((*(u32*)(v0 + 752) & 4) == 0) {
        return;
    }

    v0 = func_001bbcb0();
    return func_001d4ef0(v0 + 740, s0);
}

void func_001bc990(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;
    u32 v1 = *(u16*)(s0 + 0);
    s0 += 2;
    if (v1 == 0) {
        return;
    }

    while (1) {
        func_001bc780(s1, v1, 0, 1);
        v1 = *(u16*)(s0 + 0);
        s0 += 2;
        if (v1 == 0) {
            return;
        }
    }
}

void func_001bd2d0(u32 a0, u32 a1, u32 a2) {
    *(u32*)(a0 + 2528) = a1;
    *(u32*)(a0 + 2532) = a2;
    *(u32*)(a0 + 32) = 0;
    u32 s0 = a0 + 1312;
    u32 s1 = a0;

    func_001bc778(s0);
    func_001bc780(s0, 439, 0, 1);
    func_001bd668(s1);

    u32 vt = *(u32*)(s1 + 0);
    ((void (*)(u32))(*(u32*)(vt + 12)))(s1);

    if (func_001818a0() == 0) {
        *(u32*)(s1 + 32) |= 0x8;
    }

    if (func_001bdd20(s1) != 0) {
        *(u32*)(s1 + 32) |= 0x10;
    }
}

u32 func_001bd918(u32 a0, u32 a1, u32 a2) {
    u32 s2 = a1;
    u32 s0 = a2;
    u32 s1 = a0;
    u32 v0 = func_001b8f10(s2, *(u32*)(a0 + 2528));
    u32 t6 = 0;
    if (v0 != 0) {
        func_0017bfa0(s1 + 4, *(u16*)(s2 + 0), s0, 0);
        *(u8*)(s1 + 9) = *(u8*)(s2 + 28);
        t6 = 1;
    }
    return t6;
}

void func_001bdab0(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)(a0 + 2240);
    if (t7 == 0) {
        return;
    }
    u32 s1 = a0 + 2536;
    if (!(s1 < t7)) {
        return;
    }

L001bdae0:
    func_001bd618(s0, 0);
    t7 = *(u32*)(s0 + 2240);
    if (t7 == 0) {
        return;
    }
    if (s1 < t7) {
        goto L001bdae0;
    }
}

u32 func_001bdb10(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t7 = *(u32*)(a0 + 2536);
    if (t7 != 0) {
        if (*(u32*)(t7 + 0) == a1) {
            return 0;
        }
    }

    func_001bd668();
    func_001bd5b0(s0, s1, 0);
    return 1;
}

void func_001bdf68(u32 a0) {
    u32 s0;
    u32 s1;
    u32 s2;
    u32 s3;
    u32 v0;

    s0 = 0;
    s1 = a0 + 2628;
    s2 = 0;
    s3 = a0;
L001bdf94:
    v0 = func_001a67b0(s0++);
    if (v0 != 0) {
        *(u16*)s1 = (u16)v0;
        s2 = s2 + 1;
        s1 = s1 + 2;
    }
    if ((s32)s0 < 6) {
        goto L001bdf94;
    }
    *(u16*)(((s2 << 1) + s3) + 2628) = 0;
}

void func_001c36e8(u32 a0) {
    u32 s0 = a0;
    func_00320c18(D_01d49560, s0);

    u32 idx = s0 >> 5;
    u32* bits = &D_0032fcb8[idx];
    u32 bit = 1u << (s0 & 31);
    *bits = *bits & ~bit;
}

u32 func_001c5c08(void* a0) {
    if (D_01d498a4 < 50) {
        if (func_001dbd68() != 0) {
            func_001c6c60(a0);
            return 1;
        }
    }
    return 0;
}

u32 func_001c6f10(u8* a0, void* a1, void* a2, void* a3) {
    u32 out = 0;
    u8* p = *(u8**)(a0 + 2548) + 20;
    if (*(u32*)(p + 8) != 0) {
        u32 ret = func_001db888(p, 96, (u32)__builtin_return_address(0));
        func_001c7048(ret, (u32)a0, (u32)a1, (u32)a2, (u32)a3);
        out = ret;
    }
    return out;
}

u32 func_001c8290(u8* a0, s32 a1) {
    if (a1 < 0) {
        s32 i1 = a1;
        f32 f1 = (f32)i1;
        u8* p = (u8*)D_00352130;
        u8* obj = *(u8**)(a0 + 1164);
        f32 f12 = *(f32*)(p + 104);
        s32 i0 = *(s32*)(obj + 4);
        f32 f0 = (f32)i0;
        u8* g = (u8*)D_0034e948;
        f12 = f12 * f1;
        f12 = f12 / f0;
        func_001a1b68(*(u32*)(g + 1164), f12);
    }
    return *(u32*)(*(u8**)(a0 + 1164) + 4);
}

void func_001c8838(u32 a0) {
    u32 s17 = a0 & 0xff;
    u8* s16 = (u8*)func_001d6d88(a0);
    if (s16 != 0) {
        func_001d6e08(s16);
        func_001d4078(*(u16*)(s16 + 12));
        if (s17 != 0) {
            func_001c8d80((u32)&D_00351eb8, 0);
        }
    }
}

u32 func_001c8ad8() {
    if (func_001c8ab0() != 0) {
        u32* p = &D_01d49960;
        u32 v = *p;
        if (func_0019ba60(v) != 0) {
            return func_0016a070(*p);
        }
    }
    return 0;
}

u32 func_001c8bb8(u8* a0) {
    s32 s16 = 1;
    s32 s17 = 0;
    s32 s18 = 3;
    u8* s19 = a0;
    while (s16 < 6) {
        if (s16 != s18) {
            u32 v0 = func_001a36e0(s16);
            v0 = func_001a3570(v0);
            if ((s32)v0 > 0) {
                *(u8*)(s19 + s17) = (u8)s16;
                s17 = s17 + 1;
            }
        }
        s16 = s16 + 1;
    }
    return (u32)s17;
}

u32 func_001c9110(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001c90f0(s17, s16) == 0 && func_001c9100(s17, s16) == 0 && func_0017fd20(s16 + 320) == 0) {
        return func_0016bd60(s16, 0);
    }

    if (func_001c9100(s17, s16) != 0) {
        u32 t = *(u32*)(s16 + 2884);
        if ((*(u32*)(t + 8) & 4) == 0) {
            return func_0016bd60(s16, 0);
        }
    }

    u32 vt = *(u32*)s16;
    u32 fn_addr = *(u32*)(vt + 64);
    Fn001c9110 fn = (Fn001c9110)fn_addr;
    u32 r = fn(s16);
    if (r != 0) {
        return r;
    }
    return func_0016bd60(s16, 0);
}

void func_001c98f0(f32 a0) {
    s32 s17 = 0;
    while (s17 < 2) {
        u32 s16 = func_0017df58((u32)s17);
        s17 = s17 + 1;
        if (func_0019ba60(s16) != 0) {
            func_001c9780(s16, a0);
        }
    }
}

void func_001ca830(u32, u8* a1) {
    u32* base = (u32*)0x00350000;
    u32 s0 = *(u32*)((u8*)base + (s16)0xe948);
    if (func_0019ba60(s0) == 0) {
        return;
    }
    if ((*(u32*)(a1 + 40) & 1u) == 0) {
        return;
    }
    if (((u32(*)(u32, u32, f32, f32))func_001c7950)((u32)a1, s0, 0.0f, 0.0f) == 0) {
        return;
    }
    func_001c79a0(a1, s0, 0);
    func_001d86a0(D_0036e128[(u32)*(u8*)(a1 + 20)], 0);
}

u32 func_001cbab0(Arg* a0) {
    Obj* s0 = (Obj*)func_002d1260(a0);
    u32 t6 = 0;

    if (func_0019ba60((u32)s0) == 0) {
        return t6;
    }

    if ((a0->flags & 1u) == 0) {
        return t6;
    }

    VirtFn fn = (VirtFn)s0->vtbl[42];
    t6 = fn(s0, a0);
    return t6;
}

u32 func_001cc920(u32 a0, u32 a1, s32 a2) {
    V4 pos;
    func_0016bda8((u32)&pos, a1);

    s32 i = 0;
    if (a2 > 0) {
        while (1) {
            if (*(u32*)(a1 + 2760) == 0) {
                return 1;
            }
            u32 obj = func_001cc128(D_00352050, (u32)&pos);
            if (obj == 0) {
                return 1;
            }
            func_001ccac0(obj, a0);
            i = i + 1;
            *(u32*)(a1 + 2760) = *(u32*)(a1 + 2760) - 1;
            if (!(i < a2)) {
                break;
            }
        }
    }

    return 0;
}

void func_001ceb40(u8* a0, u32 a1) {
    s32 i = 0;
    while (i < 2) {
        s32 x = *(s32*)(a0 + 4);
        s32 v = (x >> i) & 1;
        u8 b = (u8)v;
        if (b != 0) {
            func_002877a0((u32)(a0 + 12), (u32)i, a1);
        }
        i = i + 1;
    }
}

void func_001cec70(u32 a0, u32 a1, u32 a2) {
    u32 p = D_003521d0;
    if (p == 0) {
        return;
    }

    a2 = a2 & 0xffu;
    *(u32*)(p + 4) = a1;

    if (a2 != 0) {
        u32 p1 = D_003521d0;
        u32 t = *(u32*)(p1 + 8);
        t = t | 1u;
        *(u32*)(p1 + 8) = t;

        u32 p2 = D_003521d0;
        *(u32*)(p2 + 52) = a0;
        return;
    }

    u32 p1 = D_003521d0;
    u32 t = *(u32*)(p1 + 8);
    t = t | 2u;
    *(u32*)(p1 + 8) = t;

    u32 p2 = D_003521d0;
    *(u32*)(p2 + 56) = a0;
}

void func_001d0558(u8* a0) {
    s32 i = 10;
    u8* s1 = a0;

    while (1) {
        func_0016ac38((u32)s1, (u32)i, 1, 0, 0);
        i = i + 1;
        if (i < 22) {
            continue;
        }
        break;
    }

    *(u8*)(s1 + 2928) = 1;
}

void func_001d05b8(u32 a0) {
    u32 s1 = a0;
    u8 st[16];
    u8 pad[16];
    (void)pad;

    if (*(u32*)(*(u32*)(a0 + 1164) + 0) == 1) {
        func_001d6a80(*(u32*)(a0 + 2876));

        *(u32*)(s1 + 264) = *(u32*)(s1 + 264) | 0x100u;

        u32 s2 = func_001b8e88(554);
        if (func_0019c218(s1, s2) != 0) {
            u32 s0 = func_001d14a0();
            func_00190128((u32)st);
            func_00190878((u32)st, s0, 0);
            func_00176dd8(s1, s2, (u32)st, 0);
            func_001d07e0(s1);
        }
    }

    func_001788b8(s1);
}

extern "C" u32 func_001d1438(u32) asm("_ZN2YS4SORA10GetEntryIdEi");

void func_001d17b0(u32 a0) {
    u32 s0 = a0;

    if (*(s32*)(s0 + 28) <= 0) {
        return;
    }

    if (func_001d1760() != 0) {
        if ((*(u32*)(s0 + 12) & 8u) != 0) {
            return;
        }
        u32* vt = *(u32**)s0;
        ((Cb)vt[3])(s0);
        return;
    }

    if ((*(u32*)(s0 + 12) & 8u) == 0) {
        return;
    }

    u32* vt = *(u32**)s0;
    ((Cb)vt[4])(s0);
}

void func_001d1a50(u32 a0) {
    u32 s0 = a0;

    func_001d16f8(s0);

    if (*(u32*)(s0 + 4) == 0) {
        return;
    }

    if (*(u32*)(s0 + 52) == 0) {
        *(u32*)(s0 + 52) = func_0017d930(*(u32*)(s0 + 24));
    }

    u32 f = *(u32*)(s0 + 12);
    u32 arg3 = f & 2u;
    arg3 = (0u < arg3);

    u32 v = func_0014f8d0(
        *(u32*)(s0 + 4),
        *(u32*)(s0 + 8),
        *(u32*)(s0 + 32),
        arg3,
        *(u32*)(s0 + 52),
        s0 + 44,
        s0 + 24,
        *(u32*)(s0 + 36));

    *(u32*)(s0 + 48) = v;

    if ((*(u32*)(s0 + 12) & 8u) != 0) {
        func_00150610(v);
    }
}

void func_001d1b60(u32 a0, s32 a1) {
    s32 s0 = a1;
    s32 v = *(s32*)(a0 + 24);

    if (a1 >= v) {
        if (*(s32*)(a0 + 44) < v) {
            func_001d1720(a0, 123);
            v = *(s32*)(a0 + 24);
        }
        s0 = v;
    } else {
        if (a1 <= 0) {
            if (*(s32*)(a0 + 44) > 0) {
                func_001d1720(a0, 14);
            }
            s0 = 0;
        }
    }

    func_001d17b0(a0, s0);
    *(u32*)(a0 + 44) = (u32)s0;
}

void func_001d1d00(u32 a0) {
    u32 s0 = a0;

    func_001d16f8(s0);

    f32 v = (f32)*(s32*)(s0 + 20);
    *(f32*)(s0 + 44) = v;

    if (*(u32*)(s0 + 4) != 0) {
        func_001d1ed0(s0);

        f32 f = (f32)*(s32*)(s0 + 24);
        *(u32*)(s0 + 48) = func_0014fa48(
            *(u32*)(s0 + 4),
            *(u32*)(s0 + 8),
            *(u32*)(s0 + 32),
            s0 + 44,
            *(u32*)(s0 + 36),
            f);
    }
}

void func_001d20a8(u32 a0) {
    u32 s0 = a0;

    func_001d16f8(s0);

    if (*(u32*)(s0 + 52) == 0) {
        *(u32*)(s0 + 52) = func_0017d930(*(u32*)(s0 + 24));
    }

    u32 v = func_0014f8d0(
        *(u32*)(s0 + 4),
        *(u32*)(s0 + 8),
        *(u32*)(s0 + 32),
        1,
        *(u32*)(s0 + 52),
        s0 + 44,
        s0 + 56,
        *(u32*)(s0 + 36));

    *(u32*)(s0 + 48) = v;
}

void func_001d3c18(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001d3f98(s0);
    func_00170530(v0, 5000, 7, 0);

    u32 p = *(u32*)(s0 + 36);
    if (p != 0) {
        func_0016ed50(p, 5000, 7);
    }
}

u32 func_001d3de0(u32 a0) {
    u32 s0 = a0;
    u32 t15;
    u32 b;
    u8 c;

    if (func_00170978(func_001d3f98(s0)) == 0) {
        t15 = 0;
        goto end;
    }

    t15 = *(u32*)(s0 + 36);
    if (t15 == 0) {
        goto set1;
    }

    b = func_0016f7d0(t15, 0);
    b = b & 1u;
    c = (u8)b;
    b = c;
    if (b != 0) {
        t15 = 0;
        goto end;
    }

set1:
    t15 = 1;
end:
    return t15;
}

u32 func_001d48e8(u32* a0) {
    u32* s0 = a0;
    if (s0[0] == 0) {
        return 0;
    }
    if (func_001d4940() != 0) {
        return 1;
    }
    u32 p = s0[1];
    if (p != 0) {
        func_00198970(p);
    }
    return 0;
}

u32 func_001d4bd8(u32 a0, u32 a1, u32 a2) {
    u32 s17 = a0 + 12;
    u32 s18 = a2;
    u32 s16 = func_0016b740(2113);
    u32 ret = 0;

    if (func_0019ba60(s16) == 0) {
        return ret;
    }

    func_00190878(s17, s16, 0);

    u8* e0 = func_001bc780(s18, 1, 0, 1);
    e0[6] = 1;

    u8* e1 = func_001bc780(s18, 617, s17, 1);
    e1[6] = 3;

    u8* e2 = func_001bc780(s18, 618, s17, 1);
    e2[6] = 4;

    ret = 1;
    return ret;
}

void func_001d5770(u32* a0, u32 a1) {
    u32* s16 = a0;
    u32 s17 = a1;
    u32 t6 = s16[2];

    if (t6 != 0) {
        if (s16[1] != t6) {
            func_001d5730();
            u32 v0 = func_002bc188(s16[2], s17);
            s16[0] = v0;
            s16[1] = s16[2];
        }

        if (s16[0] != 0) {
            func_002bc398(s16[0], s17);
        }
        s16[2] = 0;
        return;
    }

    func_001d5730();
}

void func_001d5800(u16* a0) {
    u32 t6 = a0[0];
    if (t6 == 2) goto L2;
    if ((s32)t6 < 3) {
        if (t6 != 1) goto Lret;
        goto L1;
    }
    if (t6 != 3) goto Lret;
    func_001a6c90(a0[1]);
    return;

L1:
    func_00181178(a0[1]);
    return;

L2:
    func_001b8838(a0[1]);
    return;

Lret:
    return;
}

u32 func_001d58f0(u32 a0) {
    s32 s17 = 12;
    s32 s18 = 0;
    u32 s19 = a0;
    u32 s16 = a0 + 4;

    do {
        u32 v0 = func_001d5868(s16);
        s17 = s17 - 1;
        s16 = s16 + 4;
        s32 t15 = s18 + 1;
        if (v0 != 0) {
            s18 = t15;
        }
    } while ((s32)s17 >= 0);

    s32 v2 = *(s32*)(s19 + 56);
    u32 v = (s18 < v2);
    v = v ^ 1;
    return v;
}

u32 func_001d5af8(u8* a0, s32 a1, u32 a2) {
    u32 v0 = 0;
    s32 t6 = a0[0];
    u32 t7;
    if (a1 < t6) {
        return v0;
    }

    if (a1 == 4 || a1 == 6) {
        if (a1 != t6) {
            *(u32*)(a0 + 4) = a2;
            goto L_set;
        }
        t7 = *(u32*)(a0 + 4);
        v0 = 0;
        t7 = (a2 < t7);
        if (t7 == 0) {
            return 0;
        }
        *(u32*)(a0 + 4) = a2;
        goto L_set;
    }

    if (a1 != t6) {
        *(u32*)(a0 + 4) = a2;
        goto L_set;
    }

    t7 = *(u32*)(a0 + 4);
    v0 = 0;
    t7 = (t7 < a2);
    if (t7 == 0) {
        return 0;
    }
    *(u32*)(a0 + 4) = a2;

L_set:
    v0 = 1;
    a0[0] = a1;
    return v0;
}

u32 func_001d5bb8() {
    u32 s16 = 1;
    u32 s17 = 2;

    do {
        u32 v0 = func_001a36e0(s16);
        s16 = s16 + 1;
        s32 v1 = func_001a3570(v0);
        v0 = (0 < v1);
        s17 = s17 + v0;
    } while ((s32)s16 < 6);

    return s17;
}

u32 func_001d5c10(u32 a0, u8* a1) {
    u32 t14 = func_001d5bb8();
    u32 t15 = a1[2];
    if ((s32)t15 < (s32)t14) {
        return func_001d5b78(a0, t15);
    }
    return 0;
}

u32 func_001d5c70(u32 a0, u8* a1) {
    u8* s16 = a1;
    u32 v0 = func_001d5b78(a0, 1);
    u32 t4 = s16[2];
    u32 t5 = 1;
    u32 t6 = *(u32*)(s16 + 4);

    if ((s32)t5 < (s32)t4) {
        t5 = t4 - 1;
        do {
            u32 t7 = *(u32*)(v0 + 4);
            t5 = t5 - 1;
            t6 = t6 + t7;
            if (t5 != 0) {
                v0 = v0 + 8;
            }
        } while (t5 != 0);
    }

    return t6;
}

void func_001d6020(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 t7 = *(u32*)(s16 + 28);
    if (func_0019ba60(*(u32*)(t7 + 8)) == 0) {
        return;
    }

    u32 t6 = *(u32*)(s16 + 28);
    u32 p = *(u32*)(t6 + 8);
    u32 t = *(u32*)(p + 1416) & 0x80;
    if (t == 0) {
        return;
    }
    if (*(u32*)(p + 2896) != 1) {
        return;
    }
    func_001d5f30(p, 1);
}

u32 func_001d6578(u32 a0, u32 a1, f32 a2) {
    f32 f20 = a2;
    u32 s19 = a1;
    u32 s18 = a0;
    u32 s17 = func_001db9a8(a0, 0, 6000);
    u32 s16 = func_001050d8(2560);
    func_001d6538(s16, s17, s18, s19, f20);
    return s16;
}

void func_001d6a28(u32 a0) {
    u32 s16 = a0;
    func_0019d720(s16 + 2552);

    *(u32*)(s16 + 2584) = *(u32*)(s16 + 2584) & ~1u;
    *(u32*)(s16 + 32) = *(u32*)(s16 + 32) | 1u;
    *(u32*)(s16 + 2800) = *(u32*)(s16 + 2800) & ~1u;
    *(u8*)(s16 + 2808) = 0;
}

void func_001d6ae0(u32 a0) {
    u32 s16 = a0;
    if ((*(u32*)(s16 + 2800) & 0x2u) == 0) {
        func_0013b348();
        func_001bdc48(s16);
        u32 t7 = *(u32*)(s16 + 2804);
        u32 t6 = *(u32*)(t7 + 1164);
        if (t6 != 0) {
            func_001a26b8(t6);
        }
        *(u32*)(s16 + 2800) = *(u32*)(s16 + 2800) | 0x2u;
    }
}

void func_001d6b40(u32 a0) {
    u32 s16 = a0;
    if ((*(u32*)(s16 + 2800) & 0x2u) != 0) {
        func_001bdc88();
        u32 t7 = *(u32*)(s16 + 2804);
        u32 t6 = *(u32*)(t7 + 1164);
        if (t6 != 0) {
            func_001a2710(t6);
        }
        *(u32*)(s16 + 2800) = *(u32*)(s16 + 2800) & ~2u;
    }
}

void func_001d7000(u32 a0, u32 a1) {
    u8 buf[80];
    u32 s16 = a1;
    u32 s17 = a0;
    u32 s18 = D_0034e948;

    func_001b74b8((u32)buf);
    func_001b74c8((u32)buf, 0xc5bd);

    u32 t7 = *(u16*)(s16 + 2);
    if (t7 != 0) {
        func_001a3188(t7, 1, 0);
        func_001b7538((u32)buf, *(u16*)(s16 + 2));
    }

    func_001b7768((u32)buf, s17);
    func_001a1460(*(u32*)(s18 + 1164));
    func_001d7778();
}

void func_001d7828() {
    if (func_001a6d08(103) != 0) {
        return;
    }

    if (func_001a6d08(101) != 0) {
        if (D_0032f056[0] >= 5) {
            func_001a6c90(103);
            return;
        }
    }
}

void func_001d7a88(u32 a0) {
    u32 s16 = a0;
    s32 s17 = 3;
    u32 s18 = a0;

    do {
        if (*(u32*)(s16 + 4) != 0) {
            f32 f1 = *(f32*)(s16 + 8);
            if (0.0f < f1) {
                f32 f0 = f1 - D_00349e10;
                *(f32*)(s16 + 8) = f0;
                if (f0 <= 0.0f) {
                    *(u32*)(s16 + 4) = 0;
                    func_001d7b10(s18);
                }
            }
        }
        s17 = s17 - 1;
        s16 = s16 + 8;
    } while (s17 >= 0);
}

void func_001d7c38(u32 a0) {
    u32 s16 = a0;
    func_001d16f8(s16);

    U32U8_001d7c38 t7;
    t7.u = *(u32*)(s16 + 12);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    u32 v0 = func_0014f788(
        *(u32*)(s16 + 4),
        *(u32*)(s16 + 8),
        *(u32*)(s16 + 32),
        *(u32*)(s16 + 36),
        *(u32*)(s16 + 48));
    *(u32*)(s16 + 44) = v0;
}

void func_001d8010(u32 a0) {
    u32 v0 = func_001bb4a0(a0);
    if (v0 == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 t7 = *(u32*)(v0 + 4);
    t7 = t7 & 1u;
    if (t7 != 0) {
        v0 = func_001bbcb0();
        func_001d8070(v0);
    }

    v0 = func_001bbcb0();
    func_001d7f80(v0);
}

void func_001d80f0(u32 a0) {
    u32 v0 = func_001bb4a0(a0);
    if (v0 == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 t7 = *(u32*)(v0 + 4);
    t7 = t7 & 1u;
    if (t7 != 0) {
        v0 = func_001bbcb0();
        func_001d8070(v0);
        return;
    }

    v0 = func_001bbcb0();
    t7 = *(u32*)(v0 + 4);
    t7 = t7 | 2u;
    *(u32*)(v0 + 4) = t7;
}

void func_001d8270(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d8270 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 188);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d8270)fn)(a4 + 188, a5, a6, a7);
}

void func_001d8310(s32 a0, u32 a1) {
    u32 s16 = a1;
    s32 s17 = a0;

    if (func_001bb4b0((u32)s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d8310 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;

    u32 t5 = *(u32*)(v0 + 200);
    s16 = v0 + 188;
    t5 = t5 & 4u;
    if (t5 == 0) {
        u32 vt = *(u32*)(v0 + 188);
        u32 fn = *(u32*)(vt + 4);
        ((Fn_001d8310)fn)(s16);
    }

    u32 p5;
    if (s17 >= 0) {
        p5 = (u32)s17;
    } else {
        p5 = *(u32*)(s16 + 24);
    }

    func_001d1950(s16, p5);
}

u32 func_001d83c0(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return 0;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d83c0 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return 0;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    return func_001d1998(a4 + 188);
}

void func_001d8470(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d8470 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 vt = *(u32*)(a4 + 188);
    u32 fn = *(u32*)(vt + 12);
    ((Fn_001d8470)fn)(a4 + 188);
}

void func_001d84e0(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d84e0 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1878(a4 + 188);
}

void func_001d8578(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8578 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 232);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d8578)fn)(a4 + 232, a5, a6, a7);
}

void func_001d8618(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8618 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1b60(a4 + 232, s17);
}

void func_001d8820(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4b0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8820 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    a4 = a4 + 232;
    func_001d1b60(a4, *(u32*)(a4 + 20));
}

void func_001d8908(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8908 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1878(a4 + 232);
}

void func_001d8978(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8978 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    *(u32*)(v0 + 272) = s17;
}

void func_001d8b68(u32 a0, u32 a1) {
    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = 52;

    u32 a2 = *(u8*)(s17 + 19);
    a2 = a2 * s18;
    a2 = add_left_u32(s16, a2);
    func_001d8190(s16, s17, a2 + 400);

    u32 t7 = *(u8*)(s17 + 19);
    f32 f12 = (f32)(s32)*(u32*)(s17 + 4);
    t7 = t7 * s18;
    s16 = s16 + t7;
    s16 = s16 + 400;
    func_001d1da0(s16, f12);
}

void func_001d8bd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8bd0 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 400);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d8bd0)fn)(a4 + 400, a5, a6, a7);
}

void func_001d8c70(u32 a0, f32 a1) {
    f32 s20 = a1;
    u32 s16 = a0;

    if (func_001bb4b0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    u32 t7 = *(u32*)(v0 + 1320);
    if (t7 != 0) {
        return;
    }

    v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8c70 t8;
    t8.u = *(u32*)(v0 + 412);
    t8.u = t8.u & 1u;
    if (t8.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1da0(a4 + 400, s20);
}

void func_001d8da0(u32 a0, f32 a1) {
    f32 s20 = a1;
    u32 s16 = a0;

    if (func_001bb4b0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    u32 s17 = s16 * 52;
    v0 = v0 + s17;

    U32U8_001d8da0 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s17;
    f32 f12 = (f32)(s32)*(u32*)(v0 + 424);
    f12 = f12 * s20;
    func_001d8c70(s16, f12);
}

f32 func_001d8e38(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return 0.0f;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8e38 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return 0.0f;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    v0 = v0 + 400;
    f32 f0 = (f32)(s32)*(u32*)(v0 + 24);
    f32 f1 = *(f32*)(v0 + 44);
    return f1 / f0;
}

f32 func_001d8eb8(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return 0.0f;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8eb8 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return 0.0f;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    v0 = v0 + 400;
    f32 f0 = (f32)(s32)*(u32*)(v0 + 28);
    f32 f1 = (f32)(s32)*(u32*)(v0 + 24);
    f0 = f0 / f1;
    return f0;
}

void func_001d9050(u32 a0, u32 a1, f32 a2) {
    f32 s20 = a2;
    u32 s16 = a1 << 6;
    u32 s17 = a0;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d9050 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d2130(a4 + 608, s17, s20);
}

void func_001d90e0(u32 a0) {
    u32 s16 = a0 << 6;

    if (func_001bb4b0(a0) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d90e0 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d2180(a4 + 608);
}

void func_001d91a8(u32 a0, u32 a1) {
    u32 s16 = a1 << 6;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d91a8 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d2248(a4 + 608, s17);
}

void func_001d9288(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3 << 6;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d9288 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 608);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d9288)fn)(a4 + 608, a5, a6, a7);
}

void func_001d9388(u32 a0, u32 a1) {
    u32 s16 = a1 << 6;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d9388 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    *(u32*)(v0 + 648) = s17;
}

void func_001d9418(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d9418 t7;
    t7.u = *(u32*)(v0 + 568);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    *(u32*)(v0 + 604) = s17;
}

void func_001d9488(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d9488 t7;
    t7.u = *(u32*)(v0 + 568);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1878(a4 + 556);
}

void func_001d9768(u16* a0) {
    a0[0] = 0;
    a0[1] = 0;
    a0[2] = 0;

    s32 t6 = 6;
    u16* t7 = a0 + 3;
    do {
        *t7 = 0;
        t6 = t6 - 1;
        t7 = t7 + 1;
    } while (t6 >= 0);

    a0 = a0 + 10;
    s32 t7c = 3;
    do {
        *a0 = 0;
        t7c = t7c - 1;
        a0 = a0 + 1;
    } while (t7c >= 0);
}

void func_001da340(u32 a0, u32 a1) {
    (void)a0;
    u32 s17 = a1;
    u32 s16 = D_0034e948;

    if (func_0019ba60(s16) != 0) {
        u32 t7 = *(u32*)(s17 + 40);
        t7 = t7 & 1u;
        if (t7 != 0) {
            if (((u32(*)(u32, u32, f32, f32))func_001c7950)(s17, s16, 0.0f, 0.0f) != 0) {
                func_001c79a0(s17, s16, 0);
                func_001d86a0(1, 0);
                return;
            }
        }
    }
}

u32 func_001db610(u32 a0, Func_001db610_cb a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a2;
    Func_001db610_cb s2 = a1;
    u32 ret;

    if (*(u16*)(s0 + 0) == 0) {
        goto L_zero;
    }

    while (1) {
        u32 v0 = s2(s0, s1);
        u32 t7 = *(u16*)(s0 + 2);
        t7 = t7 << 2;
        t7 = func_001db610_add(s0, t7);
        s0 = t7 + 4;
        if (v0 == 0) {
            ret = s0;
            goto L_ret;
        }
        t7 = *(u16*)(t7 + 4);
        if (t7 == 0) {
            goto L_zero;
        }
    }

L_zero:
    ret = 0;

L_ret:
    return ret;
}

void func_001dc8c8(u32 a0, f32 a1) {
    if (0.0f < a1) {
        f32 f0 = *(f32*)(a0 + 32);
        u32 t7 = *(u32*)(a0 + 8);
        f0 = f0 / a1;
        t7 = t7 | 0x00020000u;
        *(u32*)(a0 + 8) = t7;
        f0 = -f0;
        *(f32*)(a0 + 36) = f0;
        return;
    }
    ((void(*)(u32, f32))func_001dc878)(a0, a1);
}

void func_001dc978(u32 a0, f32 a1) {
    if (0.0f < a1) {
        f32 f0 = *(f32*)(a0 + 32);
        u32 t6 = *(u32*)(a0 + 8);
        u32 t7 = 0x00020000u;
        t7 = t7 | 1u;
        f0 = f0 / a1;
        t6 = t6 | t7;
        *(u32*)(a0 + 8) = t6;
        f0 = -f0;
        *(f32*)(a0 + 36) = f0;
        return;
    }
    func_001dc920(a0);
}

void func_001dcf58(u32 a0) {
    u32 s1 = a0;
    u32 s0;
    u32 t7 = 0x00350000u;
    u32 a0v = *(u32*)(t7 + 10976);
    if (a0v == 0) {
        return;
    }

    while (1) {
        u32 t7 = *(u32*)(a0v + 4);
        s0 = *(u32*)(a0v + 40);
        if (t7 == s1) {
            func_001dc878(a0v);
        }
        if (s0 != 0) {
            a0v = s0;
            continue;
        }
        return;
    }
}

u32 func_001dcff0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5) {
    f32 f20 = a5;
    u32 s4 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a1;
    u32 s5 = a4;

    u32 s0 = func_001dc488(56);
    func_001dc278(s0, s1, s2);
    func_001dc4e8(s0, s4, s3, s5);
    func_001dc558(s0, f20);
    return s0;
}

u32 func_001dd098(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5) {
    f32 f20 = a5;
    u32 s4 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a1;
    u32 s5 = a4;

    u32 s0 = func_001dc488(56);
    func_001dc278(s0, s1, s2);
    func_001dc540(s0, s4, s3, s5);
    func_001dc558(s0, f20);
    return s0;
}

u32 func_001dd140(u32 a0) {
    u32 s1 = a0;
    u32 s0 = func_001dc488(56);
    func_001dc278(s0, 1, 4);
    *(u32*)(s0 + 20) = s1;
    func_001dc558(s0, 0.0f);
    return s0;
}

void func_001de3d8(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s3 = a0;
    u32 s0 = *(u32*)(a0 + 12);
    if (s0 == 0) {
        return;
    }

    while (1) {
        u32 t6 = *(u32*)(s0 + 68);
        u32 t7 = *(u8*)(t6 + 4);
        u32 s1 = *(u32*)(s0 + 96);
        if (t7 == s2) {
            func_00321ce8(s3 + 12, s0);
            func_001dc920(*(u32*)(s0 + 64));
            func_001e0058(s0);
        }
        if (s1 != 0) {
            s0 = s1;
            continue;
        }
        return;
    }
}

void func_001e0868(u32 a0) {
    s32 t6 = 19;
    u32 t7 = a0 + 3712;
    do {
        *(u32*)(t7 + 0) = 0;
        t6 = t6 - 1;
        t7 = t7 + 4;
    } while (t6 >= 0);

    *(u32*)(a0 + 3792) = 0;
    *(u32*)(a0 + 3796) = 0;
    *(u32*)(a0 + 3800) = 0;
    *(u32*)(a0 + 3804) = 0;
    func_001e08c8(a0);
    func_001e0958(a0);
}

void func_001e0ac0(u32 a0) {
    u8 spv[64];
    u32 s1 = a0;
    u32 t7 = *(u32*)(a0 + 0);
    u32 s0 = *(u32*)(t7 + 4);
    func_00190128((u32)&spv[0]);
    func_00190878((u32)&spv[0], s0, 0);
    *(u32*)(&spv[44]) = 0;
    func_001902a8((u32)&spv[0], (u32)&spv[32]);
    f32 f0 = *(f32*)(&spv[36]);
    *(f32*)(s1 + 0) = f0;
}

void func_001e16c0(u32 a0) {
    u32 s0 = a0;
    u32* base = (u32*)0x00350000;
    func_001e0d08(a0, a0);
    func_001e0d68(s0, s0 + 16);
    func_001e0dc8(s0);
    if (func_001e2778(base[0x0AF4])) {
        func_001e0e40(s0);
        return;
    }
    *(u32*)(s0 + 36) = 0;
}

void func_001e18d8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = *(u32*)(s0 + 3540);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3540) = 0;
    }

    v0 = *(u32*)(s0 + 3544);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3544) = 0;
    }

    v0 = *(u32*)(s0 + 3548);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3548) = 0;
    }

    v0 = *(u32*)(s0 + 3552);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3552) = 0;
    }

    v0 = *(u32*)(s0 + 3524);
    if (v0 != 0) {
        func_00105110(v0);
        *(u32*)(s0 + 3524) = 0;
    }

    v0 = *(u32*)(s0 + 3528);
    if (v0 != 0) {
        func_00105110(v0);
        *(u32*)(s0 + 3528) = 0;
    }
}

void func_001e2938(u32 a0) {
    u32 s1 = a0;
    u32* base = (u32*)0x00350000;
    func_001e2298(base[0x0AF4]);
    if (*(u32*)(base[0x0AF4] + 3520) == 7) {
        func_001024a8(s1);
        return;
    }
}

void func_001e5990(u32 a0) {
    s32 s0 = (s32)a0;
    s32 s1 = (s32)a0 + 816;
    s32 s2 = (s32)a0;
    while (1) {
        func_001e5970((u32)s0);
        s0 += 24;
        if (s0 < s1) {
            continue;
        }
        break;
    }

    s0 = s2 + 816;
    s1 = 19;
    do {
        u32 a0_call = (u32)s0;
        s1 -= 1;
        func_001e5970(a0_call);
        s0 += 24;
    } while ((s32)s1 >= 0);
}

void func_001e74d8(u32 a0) {
    u32 s0 = a0;
    volatile u32* st = (volatile u32*)0x10003c00;
    while ((*st & 3) != 0) {
    }

    func_002f3bb8(0x10009000, 0, 0);
    func_002f3918(0x10009000, s0);
}

void func_001e8fe0(u32 a0, u32 a1) {
    u32 s0 = a1;
    B64_001e8fe0 b0;
    B64_001e8fe0 b1;
    B64_001e8fe0 b2;
    B64_001e8fe0 b3;

    func_0021ead0(&b0, *(u32*)(s0 + 8));
    func_0021ea50(&b1, *(u32*)(s0 + 4));
    func_002f3d08((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021e9d0(&b3, *(u32*)(s0 + 0));
    func_002f3d08(a0, (u32)&b2, (u32)&b3);
}

void func_001f00f8(s32* a0) {
    s32 v = a0[0];
    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[0] = t;
                break;
            }
        }
        v = a0[1];
    } else {
        v = a0[1];
    }

    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[1] = t;
                break;
            }
        }
        v = a0[2];
    } else {
        v = a0[2];
    }

    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[2] = t;
                break;
            }
        }
    }
}

void func_001fa7b0(u32 a0, u32 a1, u32 a2) {
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 t2 = t4 + 160;

    if (t5 != t6) {
        return;
    }

    u32 t7b = *(u32*)(t3 + 4);
    u32 t7p = a0 + t7b + 160;
    *(u32*)(t4 + 160) = t7p;

    u32 t6b = *(u32*)(a1 + 4);
    if (t6b == 0xFFFF) {
        *(u32*)(t2 + 4) = 0;
        return;
    }

    u32 t3off = t6b << 3;
    u32 t7c = 0x01da0000;
    volatile u32* gp = (volatile u32*)t7c;
    u32 t4p = *(u32*)(t2 + 4);
    u32 t6c = gp[-1607];
    u32 t5c = *(u32*)(t6c + 20);
    u32 t5ptr = t5c + t3off;
    if (t5ptr == t4p) {
        return;
    }

    *(u32*)(t2 + 4) = t5ptr;
    u32 t7d = *(u32*)(t5ptr + 0);
    u16 t6h = *(u16*)(t7d + 18);
    *(u8*)(t2 + 10) = 0;
    *(u16*)(t2 + 8) = t6h;
}

void func_001fa950(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 s1 = t4 + 160;

    if (t5 == t6) {
        u32 t7b = *(u32*)(t3 + 4);
        u32 t7p = a0 + t7b + 160;
        *(u32*)(t4 + 160) = t7p;

        u32 t6b = *(u32*)(a1 + 4);
        if (t6b == 0xFFFF) {
            *(u32*)(s1 + 4) = 0;
        } else {
            u32 t3off = t6b << 3;
            u32 k = 0x01da0000;
            volatile u32* gp = (volatile u32*)k;
            u32 oldp = *(u32*)(s1 + 4);
            u32 t6c = gp[-1607];
            u32 t5c = *(u32*)(t6c + 20);
            u32 t7c = t5c + t3off;
            if (t7c != oldp) {
                u32 a2c = *(u8*)(s0 + 22);
                func_0021f908(s1, t7c, a2c);
            }
        }

        u16 t7h = *(u16*)(s0 + 18);
        *(u16*)(s1 + 10) = t7h;
        u16 t6h = *(u16*)(s0 + 16);
        *(u16*)(s1 + 12) = t6h;
        u8 t7u = *(u8*)(s0 + 23);
        *(u8*)(s1 + 14) = t7u;
    }
}

void func_001facf8(u32 a0, u32 a1, u32 a2) {
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 t2 = t4 + 160;

    if (t5 != t6) {
        return;
    }

    u32 t7b = *(u32*)(t3 + 4);
    u32 t7p = a0 + t7b + 160;
    *(u32*)(t4 + 160) = t7p;

    u32 t6b = *(u32*)(a1 + 4);
    if (t6b == 0xFFFF) {
        *(u32*)(t2 + 4) = 0;
        return;
    }

    u32 t3off = t6b << 3;
    u32 k = 0x01da0000;
    volatile u32* gp = (volatile u32*)k;
    u32 oldp = *(u32*)(t2 + 4);
    u32 t6c = gp[-1607];
    u32 t5c = *(u32*)(t6c + 20);
    u32 t5ptr = t5c + t3off;
    if (t5ptr == oldp) {
        return;
    }

    *(u32*)(t2 + 4) = t5ptr;
    u32 t7d = *(u32*)(t5ptr + 0);
    u16 t6h = *(u16*)(t7d + 18);
    *(u8*)(t2 + 10) = 0;
    *(u16*)(t2 + 8) = t6h;
}

void func_001fb558(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 0);
    u32 t7p = a0 + t7;
    u32 s2 = t7p + 160;
    func_001fa7b0(s0, s1, a2);

    u32 t6b = *(u32*)(s0 + 12);
    u32 t7b = *(u32*)(s1 + 0);
    if (t7b != t6b) {
        return;
    }
    f32 f0 = *(f32*)(s1 + 12);
    *(f32*)(s2 + 32) = f0;
}

void func_001fc678(u32 a0) {
    u32 buf[20];
    volatile u32* gp = (volatile u32*)0x01da0000;
    u32 s0 = *(u32*)(a0 + 4);
    u32 s2 = s0 + 16;
    u32 s3 = (u32)buf + 64;

    func_002f3d98((u32)buf, s2);
    func_002f3d98((u32)buf + 16, s0 + 32);
    u32 a0c = (u32)buf + 32;
    u32 a1c = s0 + 48;
    s0 = a1c;
    func_002f3d98(a0c, a1c);

    u32 t6 = gp[-1606];
    func_002f3cd8(s3, s2, t6 + 64);

    u32 t4 = gp[-1606] + 16;
    func_002f3d08(t4, (u32)buf, t4);

    u32 t5 = gp[-1606] + 64;
    func_002f3f88(t5, s3);
}

s32 func_00203a88(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 t7 = s0 << 1;
    f32 f20 = (f32)(s32)t7;
    s0 = s0 >> 1;
    f32 f0 = func_00203a40();
    f20 = f20 * f0;
    f0 = (f32)(s32)s0;
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    v0 = (v0 << 24) >> 24;
    return v0;
}

void func_00204fe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t6 = a2;
    u32 s0 = a1;
    if (*(u8*)(t6 + 204) != 0) {
        return;
    }
    func_002f3d08(a1, a3, a1 + 256);
    func_002f3d08(s0 + 64, s0 + 128, s0);
}

void func_002070d0(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_002061f8(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}

void func_00207150(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_002062c0(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}

void func_002071d8(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_00206388(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}

void func_002090f8(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6 + 160;

    u32 p0 = *(u32*)(s0 + 16);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 16) = 0;
    }

    u32 p1 = *(u32*)(s0 + 20);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s0 + 20) = 0;
    }

    u32 p2 = *(u32*)(s0 + 24);
    if (p2 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p2);
        *(u32*)(s0 + 24) = 0;
    }
}

s32 func_0020a000(u32 a0) {
    u32 s0 = a0 & 0xff;
    f32 f20 = (f32)(s32)(s0 << 1);
    f32 f0 = func_00209fb8(a0);
    f20 = f20 * f0;
    f0 = (f32)(s32)(s0 >> 1);
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    return (s8)v0;
}

void func_0020b3a0(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6;
    u32 s1 = s0 + 160;

    u32 p0 = *(u32*)(s0 + 160);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 160) = 0;
    }

    u32 p1 = *(u32*)(s1 + 4);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s1 + 4) = 0;
    }
}

s32 func_0020b458(u32 a0) {
    u32 s0 = a0 & 0xff;
    f32 f20 = (f32)(s32)(s0 << 1);
    f32 f0 = func_0020b410(a0);
    f20 = f20 * f0;
    f0 = (f32)(s32)(s0 >> 1);
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    return (s8)v0;
}

void func_0020cdf0(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6;
    u32 s1 = s0 + 160;

    u32 p0 = *(u32*)(s0 + 160);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 160) = 0;
    }

    u32 p1 = *(u32*)(s1 + 4);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s1 + 4) = 0;
    }
}

void func_0020ced0(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    if (*(s32*)(D_00350000 + 18056) != 0) {
        if (*(s32*)(D_00350000 + 18060) > 0) {
            u32 a2 = *(u8*)(s0 + 24);
            u32 a3 = *(u8*)(s0 + 25);
            func_00224358(*(u32*)(s0 + 16), s0 + 20, a2, a3);

            a2 = *(u8*)(s0 + 24);
            a3 = *(u8*)(s0 + 25);
            func_00223af8(*(u32*)(s0 + 4), s0 + 8, a2, a3);
        }
    }
}

u32 func_0020ecc8(u32 a0, u32 a1) {
    u32 s18 = a1;
    s32 s17 = func_0030a8f8(a0, 1);
    if (s17 < 0) {
        *(volatile u32*)0 = 0;
        return 0;
    }

    s32 s16 = func_0030ad00(s17, 0, 2);
    func_0030ad00(s17, 0, 0);

    s32 t = func_0030af40(s17, s18, s16);
    if ((s16 ^ t) != 0) {
        s16 = 0;
    }

    func_0030ab88(s17);
    func_003058a0(0);
    return (u32)s16;
}

void func_0021eb50(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ea50(&b0, *(u32*)(s0 + 4));
    func_0021ead0(&b1, *(u32*)(s0 + 8));
    func_002f3d08((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021e9d0(&b3, *(u32*)(s0 + 0));
    func_002f3d08((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021ebe8(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021e9d0(&b0, *(u32*)(s0 + 0));
    func_0021ead0(&b1, *(u32*)(s0 + 8));
    func_002f3d08((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ea50(&b3, *(u32*)(s0 + 4));
    func_002f3d08((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021ec80(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ead0(&b0, *(u32*)(s0 + 8));
    func_0021e9d0(&b1, *(u32*)(s0 + 0));
    func_002f3d08((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ea50(&b3, *(u32*)(s0 + 4));
    func_002f3d08((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021ed18(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ea50(&b0, *(u32*)(s0 + 4));
    func_0021e9d0(&b1, *(u32*)(s0 + 0));
    func_002f3d08((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ead0(&b3, *(u32*)(s0 + 8));
    func_002f3d08((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021edb0(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021e9d0(&b0, *(u32*)(s0 + 0));
    func_0021ea50(&b1, *(u32*)(s0 + 4));
    func_002f3d08((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ead0(&b3, *(u32*)(s0 + 8));
    func_002f3d08((u32)a0, (u32)&b2, (u32)&b3);
}

void func_00221fb8(u32 a0, u32 a1, u32 a2) {
    a2 = a2 & 0xff;
    a1 = a1 & 0xff;

    *(u8*)(a0 + 1) = (u8)a2;
    u32 t7 = a2 - 1;
    u32 t6 = a0 + 16;
    *(u8*)(a0 + 0) = (u8)a1;

    a2 = t7 & 0xff;
    *(u32*)(a0 + 4) = t6;

    t7 = 48;
    a1 = a1 - 1;
    t7 = a2 * t7;
    t7 = t7 + 128;
    a2 = t7 & 0xffff;

    *(u16*)(a0 + 2) = (u16)a2;
    if ((s32)a1 > 0) {
        do {
            u32 t7p = t6;
            a1 = a1 - 1;
            t6 = t6 + a2;
            *(u32*)(t7p + 0) = t6;
        } while ((s32)a1 > 0);
    }

    *(u32*)(t6 + 0) = 0;
}

void func_00222018(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s3 = a0;
    u32 s1 = *(u32*)(a0 + 0);

    if (s1 != 0) {
        do {
            u32 s0 = s1;
            s1 = *(u32*)(s1 + 0);
            func_00221ed0(s0);
            u32 t7 = *(u32*)(s2 + 4);
            *(u32*)(s0 + 0) = t7;
            *(u32*)(s2 + 4) = s0;
        } while (s1 != 0);
    }

    *(u32*)(s3 + 0) = 0;
}

void func_00224b08(u32 a0) {
    u32 s0 = a0;
    if (func_00224e90(s0) == 0) {
        return;
    }

    func_00224998();
    func_0022b930();
    func_00102448(s0, 1);
    func_0022b948();
}

void func_00224e28() {
    if (func_00224e90() == 0) {
        return;
    }

    if (func_00224988() == 0) {
        func_0022b930();
        func_0013a218();
        func_0022b948();
    }

    func_0022b968();
    func_0022b7b0();
    func_0014ce20(1);
}

void func_00224ea0(u32 a0) {
    u32 s0 = a0;
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }

    s32 v = func_00224968() ? func_00224978() : *(s16*)(s0 + 6);
    func_00224940();
    func_00226f78(v);
}

void func_00225cd8() {
    if (*(u8*)((u32)&D_00360000 - 8696) != 1) {
        return;
    }

    func_002ba620();
    u32 v0 = func_0014ac08();
    ((dk::Fade*)v0)->fadeOut(0, false);
    func_002252b0();
    func_00226dc8();
}

u32 func_002263f0(u32 a0, u32 a1) {
    u32 t4;
    s32 t5;
    u32 t7;
    u32 p;
    s32 n;

    t4 = D_0035dd08[D_0035de60];

    if (t4 == 0) {
        goto FAIL;
    }

    t5 = *(s16*)(t4 + 8);
    t7 = D_0035de5c;
    if ((s32)t7 < t5) {
        goto STORE_FAIL;
    }

    *(u32*)(a0 + 0) = (u32)t5;

    p = D_0035dd08[D_0035de60];

    n = *(s16*)(p + 8);
    n = n - 1;
    *(u32*)(a1 + 0) = (u32)n;

    D_0035de60 = D_0035de60 + 1;
    return 1;

STORE_FAIL:
    *(u32*)(a0 + 0) = t7;
FAIL:
    return 0;
}

u32 func_00226ce8(u32 a0) {
    s32 s1;
    u32 v0;

    func_0022bb60();
    func_0022bbc8();
    s1 = 0;

    if (a0 != 0) {
LOOP:
        v0 = func_00170cd0();
        if (v0 != 0) {
            goto LOOP_CALL;
        }
        if (func_00225e48(a0) == 0) {
            goto CLEANUP;
        }
        if (s1 != 0) {
            goto CLEANUP;
        }
        func_00102448(a0, 0);
    }

CLEANUP:
    func_00226bd0(a0);
    func_00228240();
    func_0022c108();
    return func_0015f288();

LOOP_CALL:
    func_00102448(a0, 0);
    s1 = 1;
    goto LOOP;
}

void func_00227200(u32 a0) {
    func_002bbe38(a0);
    func_00161ee8();
    D_0035db10 = 1;
    func_00226ee8(a0);
    func_00226f90();
    func_00226fa8();
    func_00226fc8();
    func_0022bd80();
    D_0035de10 = -1;
    D_0035de64 = 0;
    D_0035de55 = 0;
    D_0035de08 = 0;
    D_0035de58 = 0;
    D_0035de0a = 0;
    D_0035de0b = 0;
    D_0035de26 = 0;
}

u32 func_00227870(u32 a0, u32 a1, u32 a2) {
    u32 s0;
    u32 s1;
    u32 s2;

    (void)a0;
    s1 = a2;
    s2 = a1;

    s0 = func_00225eb8((u32)&D_0035db00, func_00227818(), s1);
    func_002fde18(s0, 0, 2048);
    return func_00227858(s0, s2, s1);
}

void func_002280f8() {
    func_0022d820();
    func_0022e288();
    func_00227078();
    func_00224e28();
    func_00224bd0();
    func_00226fc8();
    func_002267a0();
    D_0035db10 = 0;
}

u32 func_00228490(u32 a0, u32 a1) {
    u32 s0;
    u32 v0;

    s0 = func_0022b9e0(a0);
    v0 = func_0022b720();
    return func_001386e0(a0, 3000, s0, v0, a1, 11);
}

u32 func_00228518() {
    u32 p;
    u32 a0;
    u32 vtbl;
    u32 fnp;
    u32 obj;
    u32 table_a;
    u32 table_b;
    u32 (*fn)(u32, u32, u32);

    p = *(u32*)((u32)&D_00340000 + 32640);
    a0 = *(u32*)(p + 20);
    vtbl = *(u32*)(a0 + 0);
    fnp = *(u32*)(vtbl + 0);
    fn = (u32 (*)(u32, u32, u32))fnp;
    obj = fn(a0, 408, 0);
    *(u32*)(obj + 12) = 0;

    table_a = (u32)&D_00340000 + 32352;
    *(u32*)(obj + 0) = table_a;
    func_00239700(obj + 24);

    table_b = (u32)&D_0035df98;
    *(u32*)(obj + 0) = table_b;
    func_00228490(obj, 143);
    return func_002251c8(12020);
}

u32 func_00228590() {
    u32 p;
    u32 a0;
    u32 vtbl;
    u32 fnp;
    u32 obj;
    u32 (*fn)(u32, u32, u32);

    p = *(u32*)((u32)&D_00340000 + 32640);
    a0 = *(u32*)(p + 20);
    vtbl = *(u32*)(a0 + 0);
    fnp = *(u32*)(vtbl + 0);
    fn = (u32 (*)(u32, u32, u32))fnp;
    obj = fn(a0, 408, 0);
    *(u32*)(obj + 0) = (u32)&D_00347f98;
    func_0031a838(obj + 12);
    *(u32*)(obj + 0) = (u32)&D_00347e60;
    func_00239700(obj + 24);
    *(u32*)(obj + 0) = (u32)&D_0035df98;
    func_00228490(obj, 144);
    return func_002251c8(12021);
}

u32 func_00229370() {
    u32 p;
    u32 a0;
    u32 vtbl;
    u32 fnp;
    u32 (*fn)(u32, u32, u32);
    u32 s16;
    s32 s17;
    u32 s18;
    u32 s19;
    u32 s20;
    s32 s21;

    p = *(u32*)((u32)&D_00340000 + 32640);
    a0 = *(u32*)(p + 20);
    vtbl = *(u32*)(a0 + 0);
    fnp = *(u32*)(vtbl + 0);
    fn = (u32 (*)(u32, u32, u32))fnp;
    s17 = 5;
    s18 = fn(a0, 2476, 0);
    s21 = -1;
    *(u32*)(s18 + 12) = 0;
    *(u32*)(s18 + 0) = (u32)&D_0035e168;
    s20 = (u32)&D_00347f98;
    s16 = s18 + 24;
    s19 = (u32)&D_00347e60;
LOOP:
    *(u32*)(s16 + 0) = s20;
    func_0031a838(s16 + 12);
    *(u32*)(s16 + 0) = s19;
    func_00239700(s16 + 24);
    s17 = s17 - 1;
    if (s17 != s21) {
        s16 = s16 + 408;
        goto LOOP;
    }
    return func_00229120(s18);
}

void func_00229678(u32 a0, u32 a1, u32 a2) {
    u32 s16;
    u32 s17;
    u32 s18;
    u32 t;

    s16 = a0 + 24;
    s17 = a0;
    *(u32*)(s16 + 396) = a1;
    s18 = a2;
    func_001396b0(s16);
    if (*(u32*)(s16 + 396) != 0) {
        *(u32*)(s16 + 400) = 0;
        func_001396b0(s16);
        if (*(u32*)(s16 + 400) != 0) {
            func_0031a260(s16, 0);
        }
    }

    t = s17 + 2896;
    *(u32*)(s17 + 2896) = s18;
    *(u32*)(s17 + 2880) = t;
    return;
}

u32 func_00229840(u32 a0) {
    u32 p;
    u32 a1;
    u32 vtbl;
    u32 fnp;
    u32 obj;
    u32 (*fn)(u32, u32, u32);

    p = *(u32*)((u32)&D_00340000 + 32640);
    a1 = *(u32*)(p + 20);
    vtbl = *(u32*)(a1 + 0);
    fnp = *(u32*)(vtbl + 0);
    fn = (u32 (*)(u32, u32, u32))fnp;
    obj = fn(a1, 2992, 0);
    func_00322418(obj);
    func_002298a8(obj, a0);
    return obj;
}

u32 func_00229d90(u32 a0) {
    u32 s16;
    u32 s17;
    s32 s18;

    s16 = a0;
    s17 = a0;
    func_00229d90_call20(a0);
    func_00229d90_call20(s17 + 440);

    s18 = 1;
    do {
        func_00229d90_call20(s16 + 864);
        s18 = s18 - 1;
        s16 = s16 + 848;
    } while (s18 >= 0);

    return func_00139510(s17 + 2560);
}

u32 func_0022a368(u32 a0) {
    u32 p;
    u32 a1;
    u32 vtbl;
    u32 fnp;
    u32 obj;
    u32 (*fn)(u32, u32, u32);

    p = *(u32*)((u32)&D_00340000 + 32640);
    a1 = *(u32*)(p + 20);
    vtbl = *(u32*)(a1 + 0);
    fnp = *(u32*)(vtbl + 0);
    fn = (u32 (*)(u32, u32, u32))fnp;
    obj = fn(a1, 5504, 0);
    func_00322790(obj);
    func_0022a7e0(obj, a0);
    return obj;
}

void func_0022abd8(u32 a0, u32 a1) {
    u32 s16;
    u32 s17;

    s16 = a1;
    s17 = a0;
    if (func_0022ab80(a0) == 0) {
        return;
    }
    if (s16 != 0) {
        return;
    }
    s16 = s17 + 5072;
    func_00138c10(s16, 100);
    *(u32*)(s16 + 392) = 97;
    return;
}

void func_0022ac60(u32 a0) {
    u32 s0;
    f32 f12;

    s0 = a0;
    f12 = (f32)*(s32*)(a0 + 5488);
    func_0022a5c8(a0, 3, 200, 0, f12);

    f12 = (f32)*(s32*)(s0 + 5484);
    func_0022a5c8(s0, 2, 600, 0, f12);

    f12 = (f32)*(s32*)(s0 + 5492);
    return func_0022a5c8(s0, 1, 800, 0, f12);
}

u32 func_0022acf8(u32 a0) {
    u32 s16;
    u32 s18;
    s32 s17;

    s16 = a0;
    s18 = a0;
    s17 = 2;
    func_0022acf8_call20(a0);
LOOP_A:
    func_0022acf8_call20(s16 + 440);
    s17 = s17 - 1;
    s16 = s16 + 412;
    if (s17 >= 0) {
        goto LOOP_A;
    }

    s16 = s18;
    s17 = 3;
LOOP_B:
    func_0022acf8_call20(s16 + 1680);
    s17 = s17 - 1;
    s16 = s16 + 848;
    if (s17 >= 0) {
        goto LOOP_B;
    }
    return func_00139510(s18 + 5072);
}

u32 func_0022b0a0(u32 a0, u32 a1) {
    s32 s16;
    u32 s17;
    u32 v0;

    s16 = (s32)a0;
    s17 = a1;
    func_002248c0(a0);
    s16 = func_0022b028(s16);
    if (s16 > 0) {
        v0 = func_0022ae98(s17);
    } else {
        v0 = func_0022af48(s17);
    }
    return func_0022ad88(s16, v0);
}

u32 func_0022b688(u32 a0) {
    u32 p;
    u32 a1;
    u32 vtbl;
    u32 fnp;
    u32 obj;
    u32 (*fn)(u32, u32, u32);
    u32 v;

    p = *(u32*)((u32)&D_00340000 + 32640);
    a1 = *(u32*)(p + 20);
    vtbl = *(u32*)(a1 + 0);
    fnp = *(u32*)(vtbl + 0);
    fn = (u32 (*)(u32, u32, u32))fnp;
    obj = fn(a1, 448, 0);

    *(u32*)(obj + 12) = 0;
    *(u32*)(obj + 0) = (u32)&D_00347e60;
    func_00239700(obj + 24);
    *(u32*)(obj + 432) = 0;
    *(u8*)(obj + 436) = 0;
    *(u32*)(obj + 0) = (u32)&D_0035e2a8;

    v = D_0035e298;
    func_0022b558(obj, a0, v + 32);
    return obj;
}

u32 func_0022b838() {
    u32 s16;
    u32 v0;

    s16 = func_001050d8(144);
    func_0023f800(s16);
    func_0023c008(s16 + 28);
    func_002369a0(s16 + 120);
    D_0035e2e8 = s16;
    v0 = func_0022b7f0();
    return func_0023fa70(D_0035e2e8, v0, -200);
}

void func_0022ba08(u32 a0, u32 a1) {
    u32 s16;

    s16 = a1;
    func_002bbed0(a0);
    func_0014a4b0();
    func_0015e038();
    func_002ef6b0();
    func_002ef750();
    while (1) {
        if (func_002ef7b8() != 0) {
            break;
        }
        func_0014a1f0();
        func_00102448(s16, 0);
    }
    func_0022d6d8();
    func_001ddb58();
    func_00143268();
    return;
}

void func_0022ba88(u32 a0) {
    u32 s16;
    u32 p;
    u64 q;

    s16 = a0;
    if (func_002ef7b8(a0) == 0) {
        func_001024a8(s16, 0);
        return;
    }

    p = func_002ef7a0(6);
    if (p == 0) {
        return;
    }

    func_0014d910(p);
    if (func_0014a1f0() == 0) {
        return;
    }

    p = func_00167f18(0);
    if (D_0035de20 < 10) {
        return;
    }
    q = *(u64*)p;
    if (q == 0) {
        return;
    }
    if (func_00225e48() != 0) {
        return;
    }
    func_00225e28();
    return;
}

void func_0022bda0(u32 a0, u32 a1, u32 a2) {
    u32 s16;
    u32 s17;
    u32 s18;
    u32 p;
    u32 v;

    a2 = a2 & 0xFF;
    s17 = a1;
    s18 = a0;
    *(u8*)(a0 + 864) = a2;
    s16 = func_00197df8();

    v = *(u32*)(s16 + 0);
    func_00138650(s18 + 416, 26000, v, 16);

    v = *(u32*)(s16 + 4);
    func_001386e0(s18, 26000, v, s18 + 448, s17, 16);

    p = func_00239cf0(s18 + 24, s17);
    if (p != 0) {
        *(u8*)(s18 + 864) = 0;
    }
    return;
}

void func_0022c440(u32 a0) {
    u32 s16;
    u32 s17;
    s32 s18;
    u32 obj;
    u32 vt;
    u32 fp;
    void (*fn)(u32);

    if (func_00139d78(*(u32*)(a0 + 24)) != 0) {
        return;
    }

    s17 = a0;
    s18 = 2;
    do {
        s16 = s17 + 28;
        if (func_00139d78(s16) != 0) {
            obj = *(u32*)(s17 + 28);
            fp = *(u32*)(obj + 20);
            fn = (void (*)(u32))fp;
            fn(s16);
        }
        s18 = s18 - 1;
        s17 = s17 + 408;
    } while (s18 >= 0);
    return;
}

void func_0022c530(u32 a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    func_00153f08(func_0022c4b8(a0 + 8), *(u16*)(a0 + 6));
}

void func_0022c7c0(u32 a0) {
    s32 v0;
    u32 fp;
    void (*fn)(u32);

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    v0 = func_00227ca8(a0 + 8);
    if (v0 >= 100) {
        func_0022c8f8(v0);
        return;
    }
    fp = D_0035de8c;
    if (fp == 0) {
        return;
    }
    fn = (void (*)(u32))fp;
    fn(v0);
}

void func_0022c998(u32 a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    func_001a84f0();
    dk::TREASURE_INFO::openEventInfo(*(u16*)(a0 + 6));
}

void func_0022cba0(u32 a0) {
    u32 s17 = a0;
    u32 s16 = *(u32*)(a0 + 8);
    u32 vt;
    u32 fp;
    void (*fn)(u32);

    if (func_0023d240(a0) != 0) {
        return;
    }
    if (s16 != 0) {
        vt = *(u32*)(s16 + 0);
        fp = *(u32*)(vt + 4);
        fn = (void (*)(u32))fp;
        fn(s16);
    }
    *(u32*)(s17 + 8) = 0;
    func_001024a8(s17);
}

void func_0022d000(u32 a0) {
    u32 s17 = a0;
    u32 s16 = *(u32*)(a0 + 8);
    f32 f12;

    if (func_0014f0e0(s16) != 0) {
        goto L0022d054;
    }
    f12 = *(f32*)(s16 + 0);
    func_0015c880(f12);
    func_00106420(s16);
    *(u32*)(s17 + 8) = 0;
    func_001024a8(s17);
    return;

L0022d054:
    f12 = *(f32*)(s16 + 0);
    func_0015c880(f12);
}

void func_0022d288(u32 a0) {
    u32 s16v = a0;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s16*)(s16v + 6) == 0) {
        func_001b9ee8(2000);
        return;
    }
    func_001b9f80(2000);
}

void func_0022d3c8(u32 a0) {
    u32 s17 = a0;
    f32 f0;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f20;

    if (func_002282f0(*(u16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(u16*)(s17 + 4)) != 0) {
        return;
    }
    f0 = func_00227c78(s17 + 8);
    f20 = f0;
    f13 = f0;
    f14 = (f32)(*(u16*)(s17 + 6));
    f12 = D_0035de48;
    func_0014cde0(f12, f13, f14);
    D_0035de48 = f20;
}

void func_0022d598(u32 a0, u32 a1) {
    u32 s16v = a0;
    u32 s17 = a1;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    func_0022d440();
    func_00225a10();
    func_00102448(s17, 2);
    func_00170320(-200);
    func_0022d4e8(s16v);
    func_00170888(s17);
    func_00225a20();
}

void func_0022d618(u32 a0) {
    u32 s16v = a0;
    s32 a4;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s8*)(s16v + 7) == 0) {
        func_0015ee10(*(s8*)(s16v + 6));
        return;
    }
    a4 = *(s8*)(s16v + 6);
    if (func_0015f718(a4) != 0) {
        return;
    }
    func_0015ee90(*(s8*)(s16v + 6));
}

void func_0022e3e8(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    func_001ba028(*(u32*)(s17 + 8));
    if (*(s16*)(s16v + 10) != 0) {
        func_00194468(*(u32*)(s17 + 8));
        return;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 268);
    q = q | 0x200;
    *(u32*)(p + 268) = q;
}

void func_0022e468(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;
    s32 d;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    func_001ba028(*(u32*)(s17 + 8));
    d = 0xbfff0000;
    d = d | 0xffff;
    if (*(s16*)(s16v + 10) != 0) {
        u32 p1 = *(u32*)(s17 + 8);
        u32 q1 = *(u32*)(p1 + 264);
        q1 = q1 & (u32)d;
        *(u32*)(p1 + 264) = q1;
        goto L0022e4c0;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 264);
    q = q | 0x40000000;
    *(u32*)(p + 264) = q;
L0022e4c0:
    return;
}

void func_0022e5f8(u32 a0) {
    u32 s18 = a0;
    u32 s16v;
    u32 s17;
    f32 f0;
    f32 f20;
    f32 f21;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s16v = func_00227d10(*(s16*)(s18 + 6));
    func_001ba028(*(u32*)(s16v + 8));
    s17 = *(u32*)(s16v + 8);
    f21 = func_00227c78(s18 + 8);
    s17 = s17 + 2248;
    f20 = func_00227c78(s18 + 12);
    f0 = func_00227c78(s18 + 16);
    func_001ad990(s17, f21, f20, f0);
}

void func_0022e998(u32 a0) {
    u32 s17 = a0;
    u32 s16v = *(u32*)(a0 + 8);

    if (func_002f13b0(s16v) != 0) {
        return;
    }
    func_00106420(s16v);
    *(u32*)(s17 + 8) = 0;
    func_001024a8(s17);
}

void func_0022ef50(u32 a0) {
    u32 s17 = a0;
    u32 s16v;
    u32 p;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s16v = func_00227d10(*(s16*)(s17 + 8));
    func_001ba028(*(u32*)(s16v + 8));
    p = *(u32*)(s16v + 8);
    func_0011c798(*(u32*)(p + 1648), s17 + 10);
}

void func_0022f200(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;
    s32 mask = -2;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    func_001ba028(*(u32*)(s17 + 8));
    if (*(s16*)(s16v + 10) != 0) {
        u32 p1 = *(u32*)(s17 + 8);
        u32 q1 = *(u32*)(p1 + 264);
        q1 = q1 & (u32)mask;
        *(u32*)(p1 + 264) = q1;
        goto L0022f254;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 264);
    q = q | 0x1;
    *(u32*)(p + 264) = q;
L0022f254:
    return;
}

void func_0022f280(u32 a0) {
    u32 s16v = a0;
    u32 s17;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 6));
    func_001ba028(*(u32*)(s17 + 8));
    if (*(s8*)(s16v + 10) == 1) {
        func_00194070(*(u32*)(s17 + 8), *(u16*)(s16v + 8));
    } else {
        func_00194088(*(u32*)(s17 + 8), *(u16*)(s16v + 8));
    }
}

void func_00231948(u32 a0) {
    u32 s16v = a0;
    s32 t14;
    s32 a4;
    f32 f12;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(s16v + 4)) != 0) {
        return;
    }

    t14 = 0;
    a4 = *(s16*)(s16v + 6);
    if ((a4 & 0x8000) != 0) {
        a4 = a4 & 0x7fff;
        t14 = 1;
    }
    f12 = (f32)a4;
    func_00161f48(t14, f12);
}

u32 func_00233a18(u32 a0, u32 a1) {
    u32 out;
    u8* pb = (u8*)&out;
    u8* a = (u8*)&a0;
    u8* b = (u8*)&a1;
    u32 t12;
    u32 t14;
    u32 t15;

    t14 = (u32)a[0] + (u32)b[0];
    t12 = out;
    t15 = (u32)-256;
    t12 = t12 & t15;
    t14 = t14 >> 1;
    t12 = t12 | t14;
    out = t12;
    pb[1] = (u8)(((s32)((u32)a[1] + (u32)b[1])) >> 1);
    pb[2] = (u8)(((s32)((u32)a[2] + (u32)b[2])) >> 1);
    pb[3] = (u8)(((s32)((u32)a[3] + (u32)b[3])) >> 1);
    return out;
}

u32 func_00236490(void* a0) {
    s32 key;
    s32 i;
    DivEntry* p;

    key = *(s32*)((u8*)a0 + 0x1c);
    i = 0;
    p = &D_0035ea48[0];

    while (i < 14) {
        if (p->key == key) {
            s32 t6 = *(s32*)((u8*)a0 + 0xc);
            s32 t7 = *(s32*)((u8*)a0 + 0x8);
            s32 d = p->div;
            s32 n = t7 * t6;
            if (n < 0) {
                n += 15;
            }
            n >>= 4;
            return (u32)(n / d);
        }
        i += 1;
        p += 1;
    }

    return 0;
}

u32 func_002364f8(void* a0) {
    s32 key;
    s32 i;
    DivEntry* p;

    key = *(s32*)((u8*)a0 + 0x30);
    i = 0;
    p = &D_0035ea48[0];

    while (i < 14) {
        if (p->key == key) {
            s32 t6 = *(s32*)((u8*)a0 + 0x28);
            s32 t7 = *(s32*)((u8*)a0 + 0x24);
            s32 d = p->div;
            s32 n = t7 * t6;
            if (n < 0) {
                n += 15;
            }
            n >>= 4;
            return (u32)(n / d);
        }
        i += 1;
        p += 1;
    }

    return 0;
}

void func_00236830(void* a0) {
    u64 t6;
    s32 t7;

    if (*(u8*)((u8*)a0 + 0x190) != 0) {
        func_00236d98(a0);
        return;
    }

    t6 = *(u64*)((u8*)a0 + 0x30);
    t7 = ((s32)(t6 >> 32)) & 1;
    if (t7 != 0) {
        func_002f2be0((u8*)a0 + 0x40, *(u32*)((u8*)a0 + 0x38));
        t6 = *(u64*)((u8*)a0 + 0x30);
    }

    t7 = ((s32)(t6 >> 33)) & 1;
    if (t7 != 0) {
        func_002f2be0((u8*)a0 + 0xa0, *(u32*)((u8*)a0 + 0x3c));
    }
}

void func_00236c38(void* a0) {
    u8* base;
    u8* end;

    base = (u8*)*(u32*)((u8*)a0 + 0x14);
    if (base == 0) {
        return;
    }

    end = base + (*(s32*)(base - 4) * 0x1a0);
    for (;;) {
        if (base == end) {
            break;
        }
        end -= 0x1a0;
        ((void(**)(void*))(*(u32*)end))[0]((void*)end);
        base = (u8*)*(u32*)((u8*)a0 + 0x14);
    }

    func_00106450((void*)(base - 0x10));
    *(u32*)((u8*)a0 + 0x14) = 0;
}

u32 func_00239af8(void* a0, u32 a1) {
    u8* s0;
    u8* s1;
    s32 v0;
    s32 t6;
    s32 t7;

    s1 = (u8*)a0;
    v0 = (s32)func_00239b50(a0, a1);

    s0 = (u8*)(a1 * 36u);
    s0 = (u8*)((u32)s0 + *(u32*)(s1 + 0xb4));
    t6 = *(s32*)(s0 + 0xc);
    v0 -= 1;
    if (t6 != 0) {
        t7 = (t6 < v0) ? 1 : 0;
        if (t7 != 0) {
            v0 = t6;
        }
    }
    return (u32)v0;
}

void func_0023c300(void* a0) {
    u8* s1;
    u8* a;
    u8* s0;

    s1 = (u8*)a0;

    a = (u8*)*(u32*)(s1 + 0x2c);
    if (a != 0) {
        s0 = a + (*(s32*)(a - 4) * 344);
        for (;;) {
            if (a == s0) {
                break;
            }
            s0 -= 344;
            ((void(**)(void*))(*(u32*)s0))[0]((void*)s0);
            a = (u8*)*(u32*)(s1 + 0x2c);
        }
        func_00106450((void*)(a - 4));
        *(u32*)(s1 + 0x2c) = 0;
    }

    a = (u8*)*(u32*)(s1 + 0x30);
    if (a != 0) {
        s0 = a + (*(s32*)(a - 4) * 344);
        for (;;) {
            if (a == s0) {
                break;
            }
            s0 -= 344;
            ((void(**)(void*))(*(u32*)s0))[0]((void*)s0);
            a = (u8*)*(u32*)(s1 + 0x30);
        }
        func_00106450((void*)(a - 4));
        *(u32*)(s1 + 0x30) = 0;
    }
}

u32 func_0023c978(void* a0) {
    u8* s2;
    u8* s1;
    u8* s0;
    s32 s3;

    s2 = (u8*)a0;
    s3 = 0;

    s1 = (u8*)(*(u32*)(s2 + 0x14) + (*(u32*)(s2 + 0x4c) * 20u));
    s0 = (u8*)(*(u32*)(s2 + 0x10) + ((u32)*(u16*)(s1 + 0) * 24u));

    if (*(u16*)(s1 + 2) != 0) {
        for (;;) {
            u32 idx;
            u32 v0;

            idx = *(u32*)(s0 + 4);
            v0 = func_00239d30((void*)(*(u32*)(s2 + 0x2c) + (idx * 344u)), *(u32*)(s0 + 8));
            s0 += 24;
            if (v0 != 0) {
                return 1;
            }
            s3 += 1;
            if (s3 < (s32)*(u16*)(s1 + 2)) {
                continue;
            }
            break;
        }
    }

    return 0;
}

void func_0023d368() {
    if (D_0035eb50 != 0) {
        func_0014ce20(0);
    }
    func_0014ce30(D_0035eb54);
    D_0035eb50 = (u8)(D_00349e20 < 1);
    D_0035eb54 = D_00349e1c;
}

u32 func_0023d438(void* a0, u32 a1) {
    u8* s2;
    u8* s0;
    s32 i;

    s2 = (u8*)a0;
    *(u32*)(s2 + 0x0c) = 0;
    *(u32*)(s2 + 0x00) = (u32)&D_0035eb60;

    s0 = s2 + 0x20;
    for (i = 3; i != -1; --i) {
        func_00106ab8(s0);
        func_001070c8(s0 + 0x100);
        s0 += 0x190;
    }

    s0 = s2 + 0x660;
    for (i = 3; i != -1; --i) {
        func_00322ba8(s0);
        s0 += 0x140;
    }

    func_0014c050(s2 + 0xb80);
    func_0014c050(s2 + 0xe90);
    func_0014c050(s2 + 0x11a0);

    *(u32*)(s2 + 0xb6c) = a1;
    return func_0023d5b8(s2);
}

u32 func_0023d4f8(void* a0, u32 a1) {
    u8* s2;
    u8* s0;
    s32 i;

    s2 = (u8*)a0;
    *(u32*)(s2 + 0x0c) = 0;
    *(u32*)(s2 + 0x00) = (u32)&D_0035eb60;

    s0 = s2 + 0x20;
    for (i = 3; i != -1; --i) {
        func_00106ab8(s0);
        func_001070c8(s0 + 0x100);
        s0 += 0x190;
    }

    s0 = s2 + 0x660;
    for (i = 3; i != -1; --i) {
        func_00322ba8(s0);
        s0 += 0x140;
    }

    func_0014c050(s2 + 0xb80);
    func_0014c050(s2 + 0xe90);
    func_0014c050(s2 + 0x11a0);

    *(u32*)(s2 + 0xb6c) = a1;
    return func_0023d5b8(s2);
}

void func_0023e5d0(void* a0, u32 a1, void* a2) {
    u8* s1;
    u8* s0;
    u8 idx;

    s1 = (u8*)a0;
    a1 += (u32)a0;
    idx = *(u8*)(a1 + 0xb64);
    s0 = s1 + ((u32)idx * 0x140) + 0x660;

    *(u32*)(s0 + 0x74) = (u32)a2;
    {
        f32 (*vf)(void*);
        vf = *(f32 (**)(void*))(*(u32*)a2 + 0x1c);
        *(volatile f32*)(s0 + 0x12c) = vf(a2);
    }
    {
        void* obj;
        f32 (*vf)(void*);
        obj = (void*)*(volatile u32*)(s0 + 0x74);
        vf = *(f32 (**)(void*))(*(u32*)obj + 0x1c);
        *(f32*)(s0 + 0x130) = vf(obj);
    }

    *(f32*)(s0 + 0x134) = func_0023e700(s1);
    *(u8*)(s0 + 0x13c) = 1;
    *(u32*)(s0 + 0x128) = 0;

    return func_0011eb08(*(u32*)(s0 + 0x30), 10);
}

void func_0023eae0(void* a0, u32 a1, s32 a2, s32 a3) {
    u8* s1;
    u8 idx;
    s32 s0;
    s32 s2;

    a1 += (u32)a0;
    s0 = a2;
    s2 = a3;

    idx = *(u8*)(a1 + 0xb64);
    s1 = (u8*)a0 + ((u32)idx * 0x140) + 0x660;

    if (a2 < a3) {
        do {
            func_0011c7f8(*(u32*)(s1 + 0x30), s0);
            s0 += 1;
        } while (s0 < s2);
    }
}

void func_0023eb50(void* a0, u32 a1, s32 a2) {
    u8* s2;
    s32 s0;
    s32 s1;
    u32 t7;

    a1 += (u32)a0;
    s1 = a2;

    s2 = (u8*)a0 + ((u32)*(u8*)(a1 + 0xb64) * 0x140) + 0x660;
    if (a2 != 0) {
        s0 = 0;
        do {
            t7 = (u32)(s1 >> s0);
            t7 &= 1u;
            if ((u8)t7 != 0) {
                func_0011c7f8(*(u32*)(s2 + 0x30), s0);
            }
            s0 += 1;
        } while (s0 < 32);
    }
}

u32 func_0023fc40(u32 a0, u32 a1) {
    u32 s1 = a1;
    u32 t7 = D_0035ebe8;
    u32 v0 = func_002fdd68(t7, a0, s1);

    u32 t5 = D_0035ebe8;
    u32 t6 = D_0035ebec;
    u32 t7a = D_0035ebf0;
    t6 = t6 << 3;
    *(u32*)(t6 + t7a) = t5;

    u32 t7b = D_0035ebec;
    u32 t6a = D_0035ebf0;
    t7b = t7b << 3;
    *(u32*)(t7b + t6a + 4) = s1;

    u32 t6b = D_0035ebe8;
    u32 t7c = D_0035ebec;
    t6b = t6b + s1;
    D_0035ebe8 = t6b;
    t7c = t7c + 1;
    D_0035ebec = t7c;
    return v0;
}

void func_0023fd40(u32 a0) {
    u8* s17 = (u8*)func_001058e8();
    u32 s16 = a0;
    D_0035ec84 = s16;
    func_002422b8(s16);
    func_0023fe60();
    func_002400f8(0);

    u8* v0 = (u8*)func_001058e8();
    u32 r = func_00241ed8(v0[12]);
    u32 t6 = 0xFFFFFEFFu;
    u32 t7 = *(u32*)(s17 + 16796);
    t7 = t7 & t6;
    t7 = t7 | ((r & 1u) << 8);
    *(u32*)(s17 + 16796) = t7;
}

u32 func_002416d8(u32 a0) {
    u32 s16 = 964;
    if (a0 != 0) {
        u32 s17 = 1;
        s16 = 0x8A58;
        if (a0 != s17) {
            s16 = 0x10FC0;
            if (func_00240108() == s17) {
                s16 = 1024;
            } else {
                u32 v0 = func_00240108();
                if (v0 == 2) {
                    s16 = 1024;
                }
            }
        }
    }
    return s16;
}

u32 func_00241e18(void) {
    u32 picks[8];
    u16* s16 = D_003717a8;
    s32 s17 = 0;
    u32* s18 = picks;
    u32 s19 = 0;

    do {
        u32 v0;
        u16 t7 = s16[0];
        if (t7 != 0) {
            v0 = func_00181500(t7);
            if (v0 == 0) {
                v0 = 1;
                goto decided;
            }
        }
        v0 = func_00181500(s16[1]);
decided:
        if (v0 != 0) {
            *s18 = s17;
            s19 += 1;
            s18 += 1;
        }
        s17 += 1;
        s16 = (u16*)((u8*)s16 + 4);
    } while (s17 < 8);

    u32 v0 = func_0014cba0();
    u32 t7 = v0 % s19;
    return picks[t7];
}

void func_00242110(u32 a0) {
    u32 s18 = func_002421e8(a0);
    u32 s17 = *(u32*)(a0 + 4);
    func_002efb60(s17);
    func_00242258(a0);
    if (s18 != 0) {
        func_002efa88(s17);
    }
}

void func_002423a0(void) {
    u32 t2 = 0x04C10000u;
    u32 t1 = 0;
    u32 t3 = 0x80000000u;
    t2 = t2 | 0x1DB7u;
    do {
        u32 t4 = t1 << 24;
        u32 t6 = 0;
        do {
            u32 t7 = t4 & t3;
            if (t7 != 0) {
                t7 = t4 << 1;
                t4 = t7 ^ t2;
            } else {
                t4 = t4 << 1;
            }
            t6 += 1;
        } while (t6 < 255);
        u32 t15 = D_0035ecc0;
        u32 t14 = t1 << 2;
        t1 += 1;
        t14 = t14 + t15;
        *(u32*)t14 = t4;
    } while (t1 < 256);
}

extern "C" void func_002436d0(u32) asm("_ZN2Tz4HEFT11PauseThreadEP4TASK");

extern "C" void func_00245400(u32) asm("_ZN2Tz4HECO11PauseThreadEP4TASK");

void func_002468e8(u32 a0, u32 a1) {
    u8 sp_buf[16];
    u8 v;

    if (func_00246840(a0) == 0) {
        v = *((u8*)((u32)&D_00371c98 + a0));
    } else {
        v = *((u8*)((u32)&D_00371ca0 + a0));
    }

    func_00199718(sp_buf, v, -1);
    sp_buf[2] = a1;
    func_00104f58(sp_buf, 1, 0, 0, 12);
}

u32 func_002469a0(u32 a0) {
    s32 s0 = 0;
    s32 s1 = 0;

    while (s0 < 4) {
        if (func_00246968(s0) != 0) {
            if (s1 == a0) {
                s1 = s1 + 1;
                break;
            }
            s1 = s1 + 1;
        }
        s0 = s0 + 1;
    }

    return (u32)s0;
}

u32 func_00246a08(void) {
    if (func_00276c18() != 0) {
        return 1;
    }

    u32 s3 = 0;
    s32 s0 = 0;
    while (s0 < 4) {
        u32 a0;
        if (func_00246840() != 0) {
            a0 = *((u8*)((u32)&D_00371cb0 + s0));
        } else {
            a0 = *((u8*)((u32)&D_00371ca8 + s0));
        }

        u8* p = func_001d56c8(a0);
        if ((u32)p[0] >= 2) {
            s3 = 1;
            break;
        }
        s0 = s0 + 1;
    }
    return s3;
}

u32 func_002474e0(u32 a0) {
    u32 s1 = 0;
    u32 s0 = func_002469a0(a0);
    if (func_00246840() != 0) {
        s0 = *((u8*)((u32)&D_00371cb0 + s0));
    } else {
        s0 = *((u8*)((u32)&D_00371ca8 + s0));
    }

    u8* p = func_001d56c8(s0);
    u32 t = p[0];
    if (t == 3) {
        s1 = 1;
    }
    else if (t == 2) {
        if (s0 == 7) {
            u32 t0 = *(u32*)(p + 4);
            t0 = (u32)(t0 < 10);
            s1 = (u32)(t0 < 1);
        }
    }

    return s1;
}

extern "C" void func_00247ff0(u32) asm("_ZN2Tz4MUMI11PauseThreadEP4TASK");

extern "C" void func_00249940(u32) asm("_ZN2Tz4TRTE11PauseThreadEP4TASK");

extern "C" void func_0024b510(u32) asm("_ZN2Tz4HBTE11PauseThreadEP4TASK");

extern "C" void func_0024cda8(u32) asm("_ZN2Tz4TTPT11PauseThreadEP4TASK");

extern "C" void func_0024e7e8(u32) asm("_ZN2Tz4TTMY11PauseThreadEP4TASK");

extern "C" void func_0024f698(u32) asm("_ZN2Tz4LMMU11PauseThreadEP4TASK");

extern "C" void func_00250748(void) asm("_ZN2Tz4LMMU7CtrlSelEv");

extern "C" void func_002510d0(u32) asm("_ZN2Tz4CANA11PauseThreadEP4TASK");

void func_00251a08(void) {
    if (func_00139d78(D_0035ee80) != 0) {
        u32 p = D_0035ee80;
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 20)))(p);
    }
    if (func_0028acc8(D_0035ee5c) != 0) {
        func_0028abe0(D_0035ee5c);
    }
}

void func_00251f40(void) {
    if (func_00139d78(D_0035ee68) == 0) {
        func_0028d980(D_0035ee68, 30022, 2, 2, D_0035ee60, 20, 21, -1, 0);

        u32 s0 = D_0035ee68;
        *(u32*)(s0 + 408) = func_00192048(18405);

        *(u32*)(D_0035ee68 + 432) = 2;

        u32 a = D_0035ee68 + 24;
        *(u32*)(a + 184) = *(u32*)(a + 184) | 8;

        *(u8*)(D_0035ee68 + 405) = 1;
    }
}

u32 func_00252098(u32 a0) {
    u32 s0 = a0;
    u32 v0 = 1;
    u32 t = D_003725d0[a0];
    if (t != 0) {
        v0 = func_001a6d08(t);
    }
    if (s0 == 1) {
        v0 = (v0 ^ 1) & 0xFF;
    }
    return v0;
}

void func_00252180(void) {
    func_00139d78(D_0035ee6c);
    if (func_00252098(1) != 0) {
        func_0028b300(D_0035ee6c, 30003, 1, 1, D_0035ee60, (u32)&D_00372608, (u32)&D_00372618, 26, 0);
        *(u8*)(D_0035ee6c + 405) = 1;
        u32 a = D_0035ee6c + 24;
        *(u32*)(a + 184) = *(u32*)(a + 184) | 8;
    }
}

void func_00252810(void) {
    u32 p = D_0035ee9c;
    if (p != 0) {
        func_00106450(p);
        D_0035ee9c = 0;
    }

    p = D_0035eea8;
    if (p != 0) {
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 16)))(p);
        D_0035eea8 = 0;
    }

    p = D_0035eea4;
    if (p != 0) {
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 16)))(p);
        D_0035eea4 = 0;
    }
}

void func_00252890(u32 a0) {
    u32 s0 = a0;
    func_002430d8(D_0035ee88);
    func_00102448(s0, 1);
    func_00252900();
    while (1) {
        func_00236d60();
        if (func_00252ad8() != 0) {
            return;
        }
        func_00252f98();
        func_00102448(s0, 0);
    }
}

void func_00253818(s32 a0) {
    s32 s0 = 1;
    u8* t7 = &D_0035eee0;
    Entry00253818* s1 = (Entry00253818*)(t7 + 16);
    s32 s2 = a0;

    while (1) {
        if (s0 != s2) {
            if (s1->a3 != 0) {
                func_00253888(s1->a0);
            }
        }

        s0 = s0 + 1;
        if (s0 < 7) {
            s1 = s1 + 1;
            continue;
        }
        break;
    }
}

void func_00253978(u32 a0, u32 a1, Entry00253978* a2) {
    (void)a0;

    if (a2 != 0) {
        if (a2->v12 != 0) {
            a2->v8 = a1;
            a2->v4 = 1;
            u32* s0 = &D_0035ef50;
            u32 v0 = func_00253948(a1);
            *s0 = *s0 + v0;
        }
    }

    D_0035ef58 = 0;
}

u32 func_00253b30(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    if (func_002ff1a4(D_0035eed4) == 0) {
        func_002fee78(s0, &D_00372858, D_0033caf4, s1);
        return s0;
    }

    func_002fee78(s0, &D_00372868, D_0033caf0, s1);
    return s0;
}

void func_00254f08(void) {
    if (func_00139d78(D_0035f02c) != 0) {
        Obj00254f08* obj = (Obj00254f08*)D_0035f02c;
        obj->vtbl->fn20(obj);
    }

    if (func_00256b80(0) != 0) {
        Obj00254f08* obj2 = (Obj00254f08*)func_00256b68(0);
        obj2->vtbl->fn20(obj2);
    }

    u32 v0 = func_00287dc0();
    func_0023d820(v0);
}

void func_002550e8(void) {
    if (func_00139d78(D_0035f03c) != 0) {
        u32 v0 = func_0023f0c0(D_0035f03c);
        if (v0 != 1) {
            func_0023f070(D_0035f03c, 1, -1);
        }
    }

    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028ab20(D_0035f01c);
    }

    func_0028ff18(D_0035f044);
    func_00290438(D_0035f048);

    if (func_00139d78(D_0035f02c) != 0) {
        u32 p = D_0035f02c;
        if (*(u32*)(p + 388) != 47) {
            func_00138c10(p, 47);
            *(s32*)(D_0035f02c + 392) = -1;
        }
    }
}

void func_00256aa0(void) {
    u32 s0 = func_00287dc0();
    if (func_00139d78(s0) != 0) {
        func_0023d820(s0);
    }

    if (func_00139d78(D_0035f040) != 0) {
        Obj00256aa0* obj = (Obj00256aa0*)D_0035f040;
        obj->vtbl->fn20(obj);
    }

    if (func_00290060(D_0035f044) != 0) {
        func_0028ff68(D_0035f044);
    }

    if (func_00290580(D_0035f048) != 0) {
        func_00290488(D_0035f048);
    }

    func_0028f878();
}

void func_00256c40(u32 a0) {
    u32 s0 = func_00257770(a0) + 2504;

    if (func_00139d78(s0) != 0) {
        *(u32*)(s0 + 396) = 0;
        func_001396b0(s0);

        if (*(u32*)(s0 + 396) != 0) {
            *(u32*)(s0 + 400) = 0;
            func_001396b0(s0);

            if (*(u32*)(s0 + 400) != 0) {
                func_0031a260(s0, 0);
            }
        }

        func_00139510(s0);
    }
}

void func_00257530(u32 a0) {
    u8* p;

    if (a0 != 0) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    func_0028dac8(D_0035f034, *(s16*)(p + 2));

    if (func_0028acc8(D_0035f024) != 0) {
        if (func_0028acb8(D_0035f024) == 0) {
            func_0028aa40(D_0035f024);
        }
    }
}

u32 func_00257610(u32 a0) {
    u32 s0 = a0;
    if (func_002576d0(a0) == 0) {
        return 0;
    }

    u8* p;
    if (s0 != 0) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    s32 t4 = *(s16*)(p + 4);
    u32 t5 = *(u32*)(D_0035f034 + 388);
    u32 t7 = t5 ^ (u32)t4;
    t7 = (t7 < 1) ? 1u : 0u;
    return t7;
}

u32 func_00257910(void) {
    u32 v0 = func_00139d78(D_0035f038 + 0xb350);
    if (v0 != 0) {
        return v0;
    }

    v0 = func_00139d78(D_0035f038 + 0xb504);
    if (v0 != 0) {
        return v0;
    }

    u32 r3 = func_00139d78(D_0035f038 + 0xb6b8);
    v0 = r3;
    return v0;
}

void func_00258c80(void) {
    if (D_0035f08c != 0) {
        if (func_00139d78(D_0035f088) != 0) {
            if (func_00258c48() == 0) {
                return;
            }
        }

        ((void(*)(void))D_0035f08c)();
        D_0035f08c = 0;
    }
}

void func_00259020(
    u32 a0,
    u32 a1,
    u32 a2,
    u32 a3,
    u32 a4,
    u32 a5,
    u32 a6,
    u32 a7
) {
    u32 s0 = a0;
    u32 s1 = a1;

    func_0028e0d8(s0, a2, a3, a4, a5, a6, a7);

    func_001395e8(s0);
    func_00139610(s0);
    func_0028eab8(s0, s1);
    func_0028e710(s0, s1);
    func_00139660(s0);
    func_00139688(s0);
    func_001396b0(s0);
    func_0028ebf0(s0, 3);
}

void func_002590b0(u32 a0) {
    u32 s0 = a0;

    func_0023f1e0(s0);
    u32 v0 = func_0019f880(-1, -1);
    func_0023f618(s0, v0);
    func_001395f8(s0);
    func_0023f6c0(s0, 1);
    func_0023f688(s0, 1);
}

u32 func_00259618(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a2 & 0xff;
    u32 s1 = a0;
    u32 s2 = a1;

    u8* p = func_001a80c8(s1);

    s32 a2v = -1;
    if (s0 != 0) {
        a2v = (s32)func_00259460((u32)p[2], s0);
    }

    func_001a3788(s2, s1, a2v);
    return s2;
}

u32 func_00259690(void) {
    func_002b4ac8(0, 0);
    func_002b4ae0(19);
    func_002b4af0((void*)&D_00372f20);
    func_00258ce8((void*)&D_00372eb8);
    func_002b4440();

    D_0035f0b0 = 1;
    D_0035f0b2 = 0;
    D_0035f0b1 = 0;

    u32 v0 = func_00103eb0();
    u32 a0 = *(u32*)(v0 + 4);
    return func_00102818(a0, 0, 2000, (u32)&D_002598b8, 4096);
}

u32 func_002597f0(void) {
    if (func_00139d78(D_0035f664) != 0) {
        Obj002597f0* obj = (Obj002597f0*)D_0035f664;
        obj->vtbl->fn20(obj);
    }

    if (func_0028acc8(D_0035f64c) != 0) {
        func_0028abe0(D_0035f64c);
    }

    if (func_0028acc8(D_0035f650) != 0) {
        func_0028abe0(D_0035f650);
    }

    func_002b5658();
    func_002b4f50();
    func_0028f7e8(-1);
    func_0028d620(D_0035f67c);
    func_00263d28();
    func_0028ff68(D_0035f66c);
    func_00290488(D_0035f670);
    func_0028ce38();
    return func_002b6418();
}

u32 func_0025ca78(void) {
    func_00259108(D_0035f650, 30064, 0, 0, D_0035f664, 1, (u32)&D_00372e98);
    func_00288f48(D_0035f650, 128, 64, 0, 0);
    func_0028af28(D_0035f650, 64);
    func_00287cc0(0);
    return func_0025d560();
}

void func_0025cd78(void) {
    u32 v0 = func_0014aba8();
    u32 t7 = *(u32*)(v0 + 252);
    t7 = t7 ^ 4;

    s32 a0v = 3;
    if (t7 != 0) {
        return;
    }

    func_00103c80(a0v);
    func_00287cc0(2);
    func_00287da0();
    func_002597f0();
    func_00288658(-1, -1);
    func_00284ea8();
}

void func_0025d4e8(void) {
    if (func_00139d78(D_0035f668) != 0) {
        Obj0025d4e8* obj = (Obj0025d4e8*)D_0035f668;
        obj->vtbl->fn20(obj);
    }

    if (func_00290060(D_0035f66c) != 0) {
        func_0028ff68(D_0035f66c);
    }

    if (func_00290580(D_0035f670) != 0) {
        func_00290488(D_0035f670);
    }

    func_0028f878();
}

u32 func_0025d6b0(void) {
    func_002b4ac8(0, 0);
    func_002b4ae0(19);
    func_002b4af0((u32)&D_00373148);
    func_00258ce8((u32)&D_00373128);
    func_002b4440();

    D_0035f0b3 = 1;
    D_0035f0b4 = 0;

    u32* v0 = (u32*)func_00103eb0();
    return func_00102818(v0[1], 0, 2000, (u32)&func_0025d7f8, 4096);
}

u32 func_0025d748(void) {
    if (func_00139d78((void*)D_0035f664) != 0) {
        u32 t7 = D_0035f664;
        u32 t6 = *(u32*)t7;
        ((void (*)(u32))(*(u32*)(t6 + 20)))(t7);
    }

    if (func_0028acc8(D_0035f64c) != 0) {
        func_0028abe0(D_0035f64c);
    }

    if (func_0028acc8(D_0035f650) != 0) {
        func_0028abe0(D_0035f650);
    }

    func_002b5658();
    func_002b4f50();
    func_0028f7e8(-1);
    func_0028d620(D_0035f67c);
    func_00263d28();
    func_0028ce38();
    return func_002b6418();
}

void func_0025ee88(void) {
    if ((func_0014aba8()->v252 ^ 4) != 0) {
        return;
    }

    func_00103c80(2);
    D_0035f0b4 = 1;
    func_00287cc0(2);
    func_00287da0();
    func_0025d748();
}

u32 func_0025f588(void) {
    u32 v0 = func_00287bc0();

    if (v0 == 1) {
        u32 a3 = func_0028b040(D_0035f64c);
        func_002b6338(D_0035f6c4, 512, 0xB85B, a3);
        return func_00263a90(D_0035f6c4, 1);
    }

    if (v0 == 12) {
        return func_00263a58(0x8AA2, 1);
    }

    return func_00263d28();
}

u32 func_00262300(void) {
    u32 s1 = 0;
    S_00262300* s0 = func_00256b68(1);

    if (s0 != 0) {
        if (func_00139d78((void*)s0) != 0) {
            s1 = (((u32)s0->v388 ^ 0x126) < 1);
        }
    }

    return s1;
}

void func_00262360(void) {
    S_00262360* s0 = func_00256b68(1);
    if (s0 == 0) {
        return;
    }
    if (func_00139d78((void*)s0) == 0) {
        return;
    }
    if (s0->v388 == 294) {
        return;
    }
    func_00138c10((void*)s0, 294);
}

void func_00262768(void) {
    u32 s1 = func_00257770();
    u32 s0 = s1 + 816;

    if (func_00139d78(s0) == 0) {
        func_0028d8c0(s0, (u32)(D_0035f3d4 + 2), (u32)D_0035ef68, (u32)D_0035ef64, (u32)D_0035f03c, 240, (u32)-1, 0);
    }

    func_0028dcc0(s0, s1 + 2504);

    s32 v0;
    s32 v1;
    s32 idx = (s32)D_0035f0b5;
    u32 p = s1 + 3376 + (u32)(idx * 436);

    func_00138c78(p, (u32)&v0, (u32)&v1);
    ((dk::Sprite*)(u32)s0)->setOffsetPos((u32)v0, (u32)v1);
}

u32 func_002632d0(u32 a0) {
    u32 s1 = a0;
    u8* s0 = func_00281f20(func_00257130());

    u32 v0 = func_00281f18(func_00257130());
    if (v0 == 0) {
        return v0;
    }

    u8* p = (u8*)((s1 * 6) + (u32)s0);
    return func_001a80c8((u32)(*(u16*)p));
}

void func_00263340(u32 a0, u32 a1) {
    (void)a0;

    if (a1 == 1) {
        func_00261d48();
        func_00262af8();
        return;
    }

    if (a1 != 10) {
        func_00262af8();
        return;
    }

    if (func_00289358() != 0) {
        func_00262820();
        func_00262a30();
        return;
    }

    func_00262a30();
    func_00262af8();
}

void func_00263570(s32 a0) {
    s32 t;

    if (a0 == -10) {
        t = *(u8*)&D_0035f0b5;
        t = t + 1;
        D_0035f0b5 = (u8)t;
        if ((s8)t >= 5) {
            D_0035f0b5 = 0;
        }
    } else {
        t = *(u8*)&D_0035f0b5;
        t = t - 1;
        D_0035f0b5 = (u8)t;
        if ((s8)t < 0) {
            D_0035f0b5 = 4;
        }
    }

    func_00262768();
}

u32 func_002811b0(u32, s32) asm("_ZN2Tz9PartyInfo10GetPartNumEi");
u32 func_002815b8(void) asm("_ZN2Tz9PartyInfo10GetNowFormEv");

void func_00263720(u32 a0) {
    u16 s0 = *(u16*)func_002632d0((u32)Tz::CmTop::GetSelectPos(10));
    u32 v0 = func_002811b0(D_0035f010, a0);
    u32 (*fp)(u32, u32) = func_001a2d78;
    (void)fp((u32)s0, v0);
}

void func_00263858(s32 a0) {
    s32 s0 = a0;
    s32 s1 = func_00257070(10);
    s32 v0 = func_00257088(10);

    if ((v0 + s1) < s0) {
        return;
    }

    if (s1 != 0) {
        s1 -= 1;
    } else {
        if (v0 != 0) {
            v0 -= 2;
        } else {
            s1 = 0;
        }
    }

    func_00257050(10, s1, v0);
}

void func_002639f8(void) {
    D_0035f0bc = -1;
    D_0035f0c0 = 0;
    D_0035f0b8 = -1;

    Obj_002639f8* obj = D_0035f0dc;
    if (obj != 0) {
        obj->vtbl->fn10((void*)obj);
        D_0035f0dc = 0;
    }
}

void func_00263bb0(u16* a0, u16* a1) {
    for (s32 i = 0; i < 3; i += 1) {
        D_0035f0c8[i] = a0[i];
    }

    for (s32 i = 0; i < 5; i += 1) {
        D_0035f0d0[i] = a1[i];
    }

    if (func_00263cc0() == 0) {
        return;
    }

    func_0028b6f0(D_0035f0dc, (u32)D_0035f0c8);
    func_0028b720(D_0035f0dc, (u32)D_0035f0d0);
}

void func_00263db0(u32 a0) {
    func_00263ea0(a0);
    func_00102448(a0, 1);
    func_00263e10();

    while (1) {
        if (func_00263e18() != 0) {
            return;
        }
        func_00263e98();
        func_00102448(a0, 0);
    }
}

void func_00265580(void) {
    u32 s0 = func_00257770();

    if (func_00287bc0() != 23) {
        return;
    }

    func_0028dac8(s0, 142);
    if (func_0028acb8(D_0035f01c) == 0) {
        func_0028aa40(D_0035f01c);
    }
}

void func_00265a30(void) {
    u32 s0 = func_00257770();

    if (func_00287bc0() != 24) {
        return;
    }

    func_0028dac8(s0, 322);

    if (func_0028acb8(D_0035f01c) == 0) {
        func_0028aa40(D_0035f01c);
    }

    if (func_0028acb8(D_0035f020) == 0) {
        func_0028aa40(D_0035f020);
    }
}

u32 func_00266c00(void) {
    s32 s0 = 0;
    u32 s2 = 0;

    while (s0 < 4) {
        if (func_001a3570((u32)D_00373470[s0]) != 0) {
            s2 |= (1u << s0);
        }
        s0 += 1;
    }

    return s2;
}

void func_00267398(void) {
    s32 s0 = 0;

    while (s0 < 6) {
        u32* base = D_0035f0e4;
        u32 idx = (u32)s0;
        u32 v0 = base[idx];

        if (v0 != 0) {
            func_001a17c8(v0);
            base = D_0035f0e4;
            base[idx] = 0;
        }

        s0 += 1;
    }
}

u32 duplicate_unplaced_002674f8(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 t = func_00257070(23);
    t = func_002670f8(t);
    u32 v0 = func_002674b8();
    u32 s1 = t;
    s32 t6 = (s32)v0 - 1;

    if (s0 != 0) {
        s1 = s1 + 1;
        if (!((s32)s1 < (s32)v0)) {
            s1 = 0;
        }
    } else {
        s1 = s1 - 1;
        if ((s32)s1 < 0) {
            s1 = (u32)t6;
        }
    }

    u32 idx = func_002670a0(s1);
    func_00257050(23, idx, 0);
    func_0028fb28(1, func_00267408(s1));
    return func_00266b58();
}

u32 func_00267620() {
    if (D_0035f0ec == 0) {
        Obj0* o = D_0032ba14;
        u32 s0 = o->vtbl->fn0(o, 4196, __builtin_return_address(0));
        func_00281ec8(s0);
        D_0035f0ec = s0;
    }
    return func_00281f40(D_0035f0ec, D_0035f010);
}

void func_00267690() {
    u32 s0 = D_0035f0ec;
    if (s0 != 0) {
        func_00281f10(s0);
        Obj1* o = (Obj1*)D_0032ba14;
        o->vtbl->fn1(o, s0);
        D_0035f0ec = 0;
    }
}

u32 func_0026acb8(u32 a0) {
    u32 s1 = a0;
    u32 s2 = func_00257070(1);
    u32 v0 = func_00281180(D_0035f010, s2);
    u16* s0 = *(u16**)(v0 + 580);

    u32 cur = s0[0];
    u32 r = 0;
    if (cur == s1) {
        return r;
    }

    u32 z = 0;
    u32 hundred = 100;
    func_001a3188(cur, hundred, z);
    s0[0] = (u16)s1;
    func_001a3458(s1, hundred);

    u32 h = func_002811b0(D_0035f010, s2);
    func_002933d8(h, 0, s1, 0);
    return 1;
}

u32 func_0026ad68(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = func_00257070(1);

    u32 cur = func_002814b0(s0);
    u32 r = 0;
    if (cur == s1) {
        return r;
    }

    func_001a3188(cur, 100, 0);
    func_002814f0(s0, s1);
    func_001a3458(s1, 100);

    if (func_002815b8() == s0) {
        u32 h = func_002811b0(D_0035f010, s2);
        func_002933d8(h, 1, s1, 0);
    }

    return 1;
}

u32 func_0026ae20(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t = func_00257070(1);

    u32 ptr = func_00281180(D_0035f010, t);
    u32 base = *(u32*)(ptr + 580);

    s0 = s0 << 1;
    s0 = s0 + base;

    u32 cur = *(u16*)(s0 + 20);
    if (cur == s1) {
        return 0;
    }

    if (cur != 0) {
        func_001a3188(cur, 100, 0);
    }

    *(u16*)(s0 + 20) = (u16)s1;
    if (s1 != 0) {
        func_001a3458(s1, 100);
    }

    return 1;
}

u32 func_0026aea8(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t = func_00257070(1);

    u32 ptr = func_00281180(D_0035f010, t);
    u32 base = *(u32*)(ptr + 580);

    s0 = s0 << 1;
    s0 = s0 + base;

    u32 cur = *(u16*)(s0 + 36);
    if (cur == s1) {
        return 0;
    }

    if (cur != 0) {
        func_001a3188(cur, 100, 0);
    }

    *(u16*)(s0 + 36) = (u16)s1;
    if (s1 != 0) {
        func_001a3458(s1, 100);
    }

    return 1;
}

u32 func_0026b860(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 s1 = func_00257070(1);
    u32 v0 = func_00281100(D_0035f010);
    s32 t6 = (s32)v0 - 1;

    if (s0 != 0) {
        s1 = s1 + 1;
        if (!((s32)s1 < (s32)v0)) {
            s1 = 0;
        }
    } else {
        s1 = s1 - 1;
        if ((s32)s1 < 0) {
            s1 = (u32)t6;
        }
    }

    func_00257050(1, s1, 0);
    v0 = func_00281140(D_0035f010, s1);
    return func_0028fb68(1, v0);
}

u32 func_0026cb38() {
    u32 a0 = 0x846C;
    if (func_00287bc0() == 20) {
        if ((s32)func_002892f8(D_0035f01c) < 3) {
            a0 = D_00373838;
        } else {
            a0 = D_00373834;
        }
    }
    return func_00263a58(a0, 1);
}

void func_0026cb90() {
    u32 v = func_00287bc0();
    if (v == 20 || v == 22) {
        u32 h = func_00256b68(1);
        func_0028dac8(h, 314);

        if (func_0028acc8(D_0035f01c) != 0) {
            if (func_0028acb8(D_0035f01c) == 0) {
                func_0028aa40(D_0035f01c);
            }
        }

        if (func_0028acc8(D_0035f024) != 0) {
            func_00288e88(D_0035f024);
        }
    }
}

u32 func_0026d560() {
    u32 s1 = 0;
    u32 s0 = func_00256b68(1);
    if (s0 != 0) {
        if (func_00139d78(s0) != 0) {
            u32 v = *(u32*)(s0 + 388);
            s1 = ((v ^ 0x139) < 1);
        }
    }
    return s1;
}

void func_0026d5c0() {
    u32 s0 = func_00256b68(1);
    if (s0 != 0) {
        if (func_00139d78(s0) != 0) {
            if (*(u32*)(s0 + 388) != 313) {
                func_00138c10(s0, 313);
                *(u32*)(s0 + 392) = 0xFFFFFFFF;
            }
        }
    }
}

void func_0026d828() {
    s32 s1 = 0;
    u32 s2 = func_00293bc0();

    while (1) {
        u32 s0 = func_001a8bf8(D_0035f0fc, (u32)s1);
        u32 v = func_001a8bf8(s2, (u32)s1);
        s1 = s1 + 1;
        if (s0 != v) {
            func_00257000();
            return;
        }
        if (s1 >= 4) {
            return;
        }
    }
}

u32 func_0026e340() {
    if (func_00139d78((u32)D_0035f108) != 0) {
        call_f5(D_0035f108);
    }

    if (func_00139d78((u32)D_0035f108) != 0) {
        call_f5(D_0035f108);
    }

    return func_0023d820(func_00287dc0());
}

void func_0026ed48() {
    if (D_0035f12c != 0) {
        return;
    }

    u32 p = func_00103570();
    u32 obj = func_001063c0(152, p);
    D_0035f12c = obj;
    func_002fde18(obj, 0, 152);
}

void func_00273c40(s32 a0) {
    u32 v0 = (u32)Tz::CmTop::GetSelectPos(25);
    u32 p = func_00281180(D_0035f010, v0);
    u8* b = (u8*)(*(u32*)(p + 580));

    if (a0 < 0) {
        u32 n = (u32)b[244] + 1;
        b[244] = (u8)n;
        if ((n & 0xffu) >= 6) {
            b[244] = 0;
        }
    } else {
        b[244] = (u8)a0;
    }

    *(u8*)(D_0035f12c + 3) = b[244];
}

extern "C" u32 func_00273de0(u32, u32) asm("_ZN2Tz6Jiminy4InitEjj");

void duplicate_unplaced_00274ac8() {
    if (func_0028acc8(D_0035f200) != 0) {
        func_0028abe0(D_0035f200);
    }

    if (func_00139d78(D_0035f204) != 0) {
        u32 obj = D_0035f204;
        u32 vtbl = *(u32*)obj;
        u32 fn = *(u32*)(vtbl + 20);
        ((void (*)(u32))fn)(obj);
    }

    if (func_0028be58(D_0035f214) != 0) {
        func_0028be18(D_0035f214);
    }

    func_002766e0();
}

extern "C" void func_00274ee8(u32) asm("_ZN2Tz6Jiminy6WMInitEP9ALLOCATOR");

void func_00275980(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    if (func_0028d008(s0, s1) == 0) {
        func_0028cc78(s0, D_0035f14c, D_0035f148, D_0035f210, 33, 33);
    }
    func_0028cf28(s0, s1);
}

void duplicate_unplaced_002759e8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_0028d6e8(D_0035f218);
    if (v0 == 0) {
        func_0028d1c0(D_0035f218, 30065, D_0035f14c, D_0035f148, D_0035f210, (u32)&D_00373d80, 0);
    } else {
        u32 p = D_0035f218;
        if (*(u32*)(p + 396) == s0) {
            return;
        }
        func_0028d660(p, s0);
        return;
    }
    func_0028d660(D_0035f218, s0);
}

void duplicate_unplaced_00275a80() {
    if (func_00139d78(D_0035f20c + 872) == 0) {
        func_0028d980(D_0035f20c + 872, 30040, D_0035f14c, D_0035f148, D_0035f210, 53, 54, -1, 0);
        *(u32*)(D_0035f20c + 1304) = 2;
    }
    func_00275d10();
}

void func_00275af8() {
    if (func_00139d78(D_0035f20c + 1308) == 0) {
        func_0028d980(D_0035f20c + 1308, 30040, D_0035f14c, D_0035f148, D_0035f210, 44, 45, -1, 0);
    }
}

void func_00275cb8() {
    if (func_00139d78(D_0035f20c + 872) != 0) {
        func_00139510(D_0035f20c + 872);
    }

    if (func_00139d78(D_0035f20c + 1308) != 0) {
        func_00139510(D_0035f20c + 1308);
    }

    func_00275e08();
}

void func_00276a18() {
    s32 s0 = 0;
    s32 s1 = 31;
    do {
        if (func_00139d78(D_0035f21c + s0 + 30360) != 0) {
            u32 p = s0 + D_0035f21c;
            u32 vt = *(u32*)(p + 30360);
            u32 fn = *(u32*)(vt + 20);
            ((void (*)(u32))fn)(p + 30360);
        }
        s1 -= 1;
        s0 += 408;
    } while (s1 >= 0);
}

void func_0027a898(u32 a0) {
    u32 s0 = a0 & 0xff;
    func_00257a00();
    if (s0 != 0) {
        func_0027b510();
    }
    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
    if (func_0028acc8(D_0035f01c) == 0) {
        return;
    }
    func_0028abe0(D_0035f01c);
}

u32 func_0027a990() {
    u32 s0 = func_00257770();
    s32 s1 = 231;

    u32 mode = func_00287bc0();
    if (mode != 16) {
        u32 i = func_0027af58();
        s1 = D_00373e30[i * 3 + 2];
    }

    if (func_00139d78(s0) == 0) {
        return 0;
    }
    return (u32)(*(u32*)(s0 + 388) == (u32)s1);
}

void func_0027b548(u32 a0) {
    u32 s0 = a0 & 0xff;
    s32 idx = Tz::CmTop::GetSelectPos(15);

    if (s0 != 0) {
        idx += 1;
        if (!(idx < (s8)*(s8*)(D_0035f230 + 6))) {
            idx = 0;
        }
    } else {
        idx -= 1;
        if (idx < 0) {
            idx = (s8)*(s8*)(D_0035f230 + 6) - 1;
        }
    }

    func_00257050(15, idx, 0);
    func_0028fb68(1, func_0027b5d0());
}

void func_0027d350(void) {
    func_002579e0();

    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }

    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
}

u32 func_0027d3b0(void) {
    u32 v0 = func_00257780();
    if (v0 == 0) {
        u32 p = D_0035f01c;
        if (p != 0) {
            v0 = func_0028acc8(p);
            v0 = (v0 != 0);
        }
        if (v0 == 0) {
            v0 = func_0028be58(D_0035f04c);
            v0 = (v0 != 0);
        }
    }
    return v0;
}

void func_0027d540(void) {
    u32 i = func_0028b040(D_0035f01c);
    s32 t = (s32)(i * 10u);
    s32 n = (s32)D_0035f234[i];
    t += n;
    u32 p = (u32)&D_00373f10 + ((u32)t << 1);
    func_00263a58(*(u16*)(p + 12), 1);
}

void func_0027d2e8(void) {
    u32 s0 = func_00257770();
    u32 t = func_00287bc0();
    if (t == 36) {
        func_0028dac8(s0, 235);
        if (func_0028be58(D_0035f04c) != 0) {
            func_0028bdb8(D_0035f04c);
        }
    }
}

void func_0027d810(u32 a0) {
    u32 v = func_0028af88(D_0035f01c);
    if (a0 == 9) {
        v &= 0xfff3ffffu;
    } else {
        v |= 0x000c0000u;
    }
    func_0028af18(D_0035f01c, v);
}

void func_0027da60(void) {
    func_0014ace8();

    u32 p = D_0035f238;
    if (p != 0) {
        u32 vt = *(u32*)p;
        u32 fn = *(u32*)(vt + 16);
        ((void (*)(u32))fn)(p);
        D_0035f238 = 0;
    }

    D_0035f23c = 0;
    D_0035f240 = 0;
}

void func_0027dab8(u32 a0) {
    func_00102448(a0, 1);
    func_0027db28();
    func_00242618(11, 1);
    while (true) {
        func_00236d60();
        if (func_0027db58() != 0) {
            break;
        }
        func_0027dbd8();
        func_00102448(a0, 0);
    }
}

void func_0027d9f0(void) {
    u32 root = *(u32*)&D_00347f80;
    u32 obj = *(u32*)(root + 20);
    u32 fn = *(u32*)(*(u32*)obj + 0);
    u32 s0 = ((u32 (*)(u32, u32, u32))fn)(obj, 832, 0);
    u32 v = func_00290610(s0);
    D_0035f238 = s0;
    v = func_00103eb0();
    func_00102818(*(u32*)(v + 4), 0, 2000, (u32)func_0027dab8, 4096);
    func_0014acd8();
}

u32 func_0027ea78(void) {
    func_00139d78(D_0035f244);
    u32 v = *(u32*)(D_0035f244 + 388);
    s32 i = (s32)D_0035f24c;
    s32 off = i * 6;
    u32 p = (u32)&D_00374050 + off;
    s32 y = (s32)*(s16*)(p + 4);
    return ((v ^ (u32)y) == 0);
}

extern "C" void func_0027f370(void) asm("_ZN2Tz9GumiPause8SetupTopEv");

extern "C" void func_0027f2f8(u32) asm("_ZN2Tz9GumiPause11PauseThreadEP4TASK");

void duplicate_unplaced_0027fcc0(void) {
    u32 s1 = func_0028af88(D_0035f254);
    u32 i = func_0028b040(D_0035f254);
    s8 v = *((s8*)&D_00374168 + i);
    s32 m = -13;
    if (v >= 0) {
        goto clear_bits;
    }
    if (i == 2) {
        goto clear_bits;
    }
    s1 |= 0xcu;
    goto apply;
clear_bits:
    s1 &= (u32)m;
apply:
    func_0028af18(D_0035f254, s1);
}

void func_002802e8(void) {
    if (func_00139d78(D_0035f264 + 24) != 0) {
        func_00139510(D_0035f264 + 24);
    }

    if (func_00139d78(D_0035f264 + 460) != 0) {
        func_00139510(D_0035f264 + 460);
    }

    if (func_00139d78(D_0035f264 + 896) != 0) {
        func_00139510(D_0035f264 + 896);
    }
}

u32 func_00280290(void) {
    u32 v = func_00139d78(D_0035f264 + 24);
    if (v == 0) {
        v = func_00139d78(D_0035f264 + 460);
        if (v == 0) {
            v = func_00139d78(D_0035f264 + 896);
        }
    }
    return v;
}

extern "C" void func_002800d0(void) asm("_ZN2Tz9GumiPause12UpdateAdviceEv");

u32 func_00280368(void) {
    u32 ok = 0;
    if (func_00139d78(D_0035f264 + 24) != 0) {
        ok = (*(u32*)(D_0035f264 + 412) == 8);
    }

    if (ok == 0) {
        if (func_00139d78(D_0035f264 + 460) != 0) {
            ok = (*(u32*)(D_0035f264 + 848) == 11);
        }
    }
    return ok;
}

extern "C" void func_00280458(void) asm("_ZN2Tz9GumiPause14ChkLoadRequestEv");

void func_002809d8(u32 a0) {
    func_002593b8(5, a0);
    func_00102448(a0, 1);
    func_002806c8();
    func_00280a50();
    while (true) {
        func_00236d60();
        if (func_00280c38() != 0) {
            break;
        }
        func_00280d40();
        func_00102448(a0, 0);
    }
}

void func_00281058(u32 a0, s32 a1) {
    s32 i = 0;
    do {
        if ((a1 < 0) || (i == a1)) {
            if (*(u32*)(a0 + 16) != 0) {
                func_001a1460(*(u32*)(a0 + 20));
            }
        }
        i += 1;
        a0 += 20;
    } while (i < 4);
}

u32 func_00282ec0(u32 a0) {
    u32 i = 0;
    u32 found = 0;

    if (D_00374230[0].a != 0) {
        do {
            if ((u32)D_00374230[i].b == a0) {
                if (func_001a6d08((u32)D_00374230[i].a) != 0) {
                    found = 1;
                    break;
                }
            }
            i += 1;
        } while (D_00374230[i].a != 0);
    }

    return found;
}

void func_00283730(void) {
    func_0028da70(D_0035f2b8 + 852, 19);
    func_0028da70(D_0035f2b8 + 416, 16);
    func_0028da70(D_0035f2b8 + 1288, 2);
    func_0028da70(D_0035f2b8 + 1696, 5);
}

void func_00283900(u32 a0) {
    if ((a0 & 0xffu) != 0) {
        func_0028dac8(D_0035f2b8 + 416, 17);
    }
    func_0028dac8(D_0035f2b8 + 1288, 3);
    func_0028dac8(D_0035f2b8 + 1696, 6);
}

void func_00283960(u32 a0) {
    if ((a0 & 0xffu) != 0) {
        if (func_00139d78(D_0035f2b8 + 416) != 0) {
            func_00139510(D_0035f2b8 + 416);
        }
    }

    if (func_00139d78(D_0035f2b8 + 1288) != 0) {
        func_00139510(D_0035f2b8 + 1288);
    }

    if (func_00139d78(D_0035f2b8 + 1696) != 0) {
        func_00139510(D_0035f2b8 + 1696);
    }
}

u32 func_002839f0(u32 a0) {
    u32 v = 0;
    if ((a0 & 0xffu) != 0) {
        v = func_00139d78(D_0035f2b8 + 416);
    }

    if (v == 0) {
        v = func_00139d78(D_0035f2b8 + 1288);
        if (v == 0) {
            v = func_00139d78(D_0035f2b8 + 1696);
        }
    }
    return v;
}

u32 func_00283a58(void) {
    u32 out;
    if (func_00181500(2267) == 0) {
        goto L80;
    }
    if (func_00181500(2256) == 0) {
        out = 0;
        goto Lend;
    }

L80:
    if (func_00181500(2256) == 0) {
        goto Lset2;
    }
    if (func_00181500(2257) == 0) {
        out = 1;
        goto Lend;
    }
Lset2:
    out = 2;
Lend:
    return out;
}

void func_00283f50(void) {
    u8 work0[128];
    u8 work1[32];
    u8* p = (u8*)D_0035f2b4;
    p += (s32)(s8)p[14];

    func_00283eb8((u32)work1, (s32)(s8)p[4]);
    func_00253b30((u32)work0, (u32)work1);
    func_00170518((u32)work0, 5100, 0);
    func_00170888(0);
}

void func_00283fb0(void) {
    u8 work0[128];
    u8 work1[32];
    u8* p = (u8*)D_0035f2b4;

    func_00283eb8((u32)work1, (s32)(s8)p[(s32)(s8)p[14] + 4]);
    func_00253b30((u32)work0, (u32)work1);

    func_00290a10(D_0035f2b0, (u32)work0, 24);
    func_002362b0(D_0035f2b8, func_00290948(D_0035f2b0, 0));

    *(u8*)(D_0035f2b8 + 400) = 1;
}

void func_00284738(u32 a0) {
    u32 s0 = a0;

    if (func_00170cd0(s0) != 0) {
        func_00170888(s0);
    }

    func_00285418();
    func_00170888(s0);
    func_00102448(s0, 1);
    func_002853b8();
    func_002847e0();

    if (D_0035f2d0 == 0) {
        func_00284e40();
    }

    while (1) {
        func_00236d60();
        if (func_00284ef0() != 0) {
            return;
        }
        func_002851e0();
        func_00102448(s0, 0);
    }
}

void func_002856c8(void) {
    func_0028dac8(D_0035f2d8, 6);

    if (func_0028acc8(D_0035f2dc) == 0) {
        return;
    }

    if (func_0028acb8(D_0035f2dc) != 0) {
        return;
    }

    func_0028aa40(D_0035f2dc);
}

void duplicate_unplaced_00288370(void) {
    u32 s2 = func_0023f948(D_0035f334, 0);
    u32 s0 = func_0023f908(D_0035f334, 0);
    u32 t = func_00103570();

    func_00236a58(D_0035f33c, s0, t);
    t = func_00103570();

    func_0023c100(D_0035f340, s2, D_0035f33c, t);
}

u32 func_00288400(u32 a0) {
    if (D_0035f32a < 0) {
        func_001039f8();
        return 1;
    }

    if (func_00287db0() != 0) {
        func_00287ad0();
    }

    D_0035f328 = 1;
    func_00288478(a0);
    D_0035f328 = 0;
    return 0;
}

void func_00288870(void) {
    if (D_0035f344 == 0) {
        return;
    }

    if (func_00139d78(D_0035f338) != 0) {
        if (func_00288820() == 0) {
            return;
        }
    }

    ((void(*)(void))D_0035f344)();
    D_0035f344 = 0;
}

void func_00288b18(u32 a0) {
    if (D_0035f34c != a0) {
        if (D_0035f34c != 0) {
            D_0035f350 = D_0035f34c;
        }
        D_0035f34c = a0;
    } else {
        D_0035f348 = (u8)(D_0035f348 + 1);
    }

    if (func_00103b38() != 0) {
        func_00287ed8(D_0035f34c);
    }
}

void func_002890e0(Obj_002890e0* self, u32 a1, s32 a2, u32 a3, s32 a4) {
    s32 i = 0;
    u32 s2 = a1 & 0xFF;
    u32 s3 = a3 & 0xFF;
    s32 s4 = a4;
    s32 s5 = a2;

    if ((s32)self->count <= 0) {
        return;
    }

    do {
        func_00289038((u32)self, i, 0, s2, s5, s3, s4);
        i += 1;
    } while (i < (s32)self->count);
}

void func_0028b8e0(Obj_0028b8e0* self) {
    func_0023fa08((u32)self);
    func_00168aa0(self->field4, 37);

    u32 p0 = func_00168b38(self->field4, 37, 0);
    self->field28 = *(u32*)(p0 + 8);

    u32 p1 = func_00168b38(self->field4, 37, 1);
    self->field32 = *(u32*)(p1 + 8);
}

void func_0028ba20(Obj_0028ba20* self) {
    Obj_0028ba20* s0 = self;

    if (func_0028be58((u32)s0) != 0) {
        u32 p = s0->field0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
    }

    {
        u32 p = s0->field0;
        if (p != 0) {
            ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
            s0->field0 = 0;
        }
    }
}

void func_0028ba80(Obj_0028ba80* self) {
    Obj_0028ba80* s0 = self;

    if (func_0028be58((u32)s0) != 0) {
        u32 p = s0->field0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
    }

    {
        u32 p = s0->field0;
        if (p != 0) {
            ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
            s0->field0 = 0;
        }
    }
}

void func_0028bd60(Obj_0028bd60* self) {
    func_0028be58((u32)self);
    u32 v = func_0028e4c8(self->field0, 1);

    if ((s32)v != (s32)self->field26) {
        func_0028e560(self->field0, (u32)&self->field24, 4, -1);
    }
}

void func_0028c7c0(s32 a0, s32 a1) {
    s32 s0 = a1;
    s32 s1 = a0;

    if (a1 == 0xFFFF) {
        if (a0 == 1) {
            func_0023f800((u32)&D_0035f3a8);
        }
    }

    if (s0 == 0xFFFF) {
        if (s1 == 0) {
            func_0023f848((u32)&D_0035f3a8);
        }
    }
}

void func_0028d730(u32 self, Cb_0028d730 cb, f32 a2, f32 a3, f32 a4, f32 a5) {
    s32 count = (s32)func_002892f8(self);
    s32 i = 0;
    if (count <= 0) {
        return;
    }
    do {
        if (cb((u32)i) == 0) {
            u32 obj = func_002891b8(self, (u32)i);
            func_0028d708(obj, a2, a3, a4, a5);
        }
        i += 1;
    } while (i < count);
}

void func_0028dae0(u32 self, u32 value) {
    if (func_00139d78(self) != 0) {
        u32 cur = func_0023f0c0(self);
        if (cur != value) {
            func_0023f070(self, value, -1);
            return;
        }
    }
}

u32 func_0028db48(u32 self) {
    u32 ret = 0;
    if (self != 0) {
        if (func_00139d78(self) != 0) {
            u32 p = self + 24;
            u32 v = func_00239d30(p, *(u32*)(p + 276));
            ret = ((v & 0xff) != 0);
        }
    }
    return ret;
}

u32 func_0028dba0(u32 self) {
    u32 ret = 0;
    if (self != 0) {
        if (func_0028acc8(self) != 0) {
            ret = (func_0028ae28(self, 0) != 0);
        }
    }
    return ret;
}

void func_0028dd28(Obj_0028dd28* self, u32 value) {
    self->field400 = value;
    func_001396b0((u32)self);
    if (self->field400 != 0) {
        self->field396 = 0;
        func_001396b0((u32)self);
        if (self->field396 != 0) {
            func_0031ac78((u32)self, 0);
        }
    }
    func_00139660((u32)self);
    func_00139688((u32)self);
    func_001396b0((u32)self);
}

void func_0028e080(u32 self) {
    *(u32*)self = addr_D_0035f440();
    func_0028e350(self);
    *(u32*)self = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_0028e080 fn = (Fn_0028e080)*(u32*)(*(u32*)obj + 4);
    fn(obj, self);
}

void func_0028e3b8(Obj_0028e3b8* self, u32 idx, u32 a2, u32 a3, u32 a4) {
    func_00139d78((u32)self);
    func_00239988(self->field56 + idx * 380, a2, a3);
    func_0028e438((u32)self, idx, a4, -1);
}

void func_0028e8b8(Obj_0028e8b8* self, u32 idx, u32 v2, u32 v3) {
    func_00139d78((u32)self);
    u32 stride = 380;
    u32 off = idx * stride;
    u32 base = self->field56;
    *(u32*)((off + base) + 360) = v2;
    u32 base2 = self->field56;
    *(u32*)((off + base2) + 364) = v3;
}

void func_0028e970(Obj_0028e970* self, u32* out1, u32* out2) {
    func_00139d78((u32)self);
    *out1 = self->field28 + self->field36;
    *out2 = self->field32 + self->field40;
}

void func_0028e9d0(Obj_0028e9d0* self, u32 idx, u32 a2, u32 a3) {
    func_00139d78((u32)self);
    func_0023a9c0(self->field56 + idx * 380, a2, a3);
}

void func_0028ea30(Obj_0028ea30* self, u32 idx, u32* p0, u32* p1) {
    func_00139d78((u32)self);
    func_0023a9c0(self->field56 + idx * 380, (u32)p0, (u32)p1);
    *p0 += self->field36;
    *p1 += self->field40;
}

void func_0028fa98(s32 which) {
    u32 i = 0;
    u32 off = 0;
    do {
        if (which < 0 || which == (s32)i) {
            if (func_00139d78(D_0035f480 + off) != 0) {
                u32 p = func_0028f690(i);
                func_0028da70(D_0035f480 + off, (u32)*(s16*)(p + 4));
            }
        }
        i += 1;
        off += 884;
    } while ((s32)i < 4);
}

void func_0028fd68(Obj_0028fd68* self) {
    func_0028ff68((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}

void func_0028fdd0(Obj_0028fdd0* self) {
    func_0028ff68((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}

void func_0028ffe8(Obj_0028ffe8* self, u32 idx) {
    if (func_00290060((u32)self) == 0) {
        return;
    }
    if (func_00139d78(self->field0) != 0) {
        s32 value = (s32)self->arr[idx];
        u32 base = self->field0;
        if (*(s32*)(base + 388) != value) {
            func_00138c10(base, (u32)value);
            *(s32*)(self->field0 + 392) = -1;
        }
    }
}

void func_00290298(Obj_00290298* self) {
    func_00290488((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}

void func_00290300(Obj_00290300* self) {
    func_00290488((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}

void func_00290368(Obj_00290368* self, u32 a1, u32 a2, u32 a3) {
    func_001386e0(self->field0, a1, a2, a3, (u32)(s32)self->field8, 0);
    *(s32*)(self->field0 + 392) = (s32)self->field12;

    u16 tmp[9];
    u16 v = self->field16;
    for (s32 i = 0; i < 9; i += 1) {
        tmp[i] = v;
    }

    func_00259020(self->field4, self->field0, a1, a2, a3, (u32)tmp, 9, 0);
    func_00290420((u32)self);
}

void func_00290508(Obj_00290508* self, u32 idx) {
    if (func_00290580((u32)self) == 0) {
        return;
    }
    if (func_00139d78(self->field0) != 0) {
        s32 value = (s32)self->arr[idx];
        u32 base = self->field0;
        if (*(s32*)(base + 388) != value) {
            func_00138c10(base, (u32)value);
            *(s32*)(self->field0 + 392) = -1;
        }
    }
}

void func_002905b8(u32 self) {
    *(u32*)(self + 12) = 0;
    *(u32*)self = (u32)&D_00347e60;
    func_00239700(self + 24);
    *(u32*)self = (u32)&D_0035f490;
    func_002361a0(self + 416);
    func_00290738(self, 30022);
}

void func_00290760(u32 self, u32 base, u32 count) {
    *(u32*)self = (u32)&D_0035f4b0;
    if (base == 0) {
        base = func_00103570();
    }
    *(u32*)(self + 12) = count;
    *(u32*)(self + 20) = func_001063f0(count << 2, base);
    func_002908a8(self);
}

void func_002907c0(u32 self, u32 base, u32 count) {
    *(u32*)self = (u32)&D_0035f4b0;
    if (base == 0) {
        base = func_00103570();
    }
    *(u32*)(self + 12) = count;
    *(u32*)(self + 20) = func_001063f0(count << 2, base);
    func_002908a8(self);
}

void func_00290a90(u32 self) {
    func_00323e98(self);
    s32 neg1 = -1;
    *(u32*)(self + 11024) = 0;
    *(s32*)(self + 11028) = neg1;
    u32 p = self + 11068;
    *(s32*)(self + 11032) = neg1;
    u32 z = 0;
    *(s32*)(self + 11036) = neg1;
    func_002fde18(p, z, 16);

    self = self + 11076;
    u32 fill = 100;
    s32 n = 6;
    do {
        *(u8*)self = (u8)fill;
        n -= 1;
        self += 1;
    } while (n >= 0);
}

void func_00290b00(u32 self) {
    func_00323e98(self);
    s32 neg1 = -1;
    *(u32*)(self + 11024) = 0;
    *(s32*)(self + 11028) = neg1;
    u32 p = self + 11068;
    *(s32*)(self + 11032) = neg1;
    u32 z = 0;
    *(s32*)(self + 11036) = neg1;
    func_002fde18(p, z, 16);

    self = self + 11076;
    u32 fill = 100;
    s32 n = 6;
    do {
        *(u8*)self = (u8)fill;
        n -= 1;
        self += 1;
    } while (n >= 0);
}

void func_00290b70(u32 self) {
    u32 s18 = self;
    u32 s16;
    u32 s17;

    if (s18 != (u32)-4364) {
        s16 = s18 + 10904;
        s17 = s18 + 4364;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-2184) {
        s16 = s18 + 4364;
        s17 = s18 + 2184;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-4) {
        s16 = s18 + 2184;
        s17 = s18 + 4;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }
}

void func_00290c30(u32 self) {
    u32 s18 = self;
    u32 s16;
    u32 s17;

    if (s18 != (u32)-4364) {
        s16 = s18 + 10904;
        s17 = s18 + 4364;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-2184) {
        s16 = s18 + 4364;
        s17 = s18 + 2184;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-4) {
        s16 = s18 + 2184;
        s17 = s18 + 4;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }
}

void func_00290cf0(u32 self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    s32 i;
    u32 dst;

    *(u32*)(self + 11024) = a1;
    i = 0;
    *(u32*)(self + 11028) = a2;
    dst = self + 11054;
    *(u32*)(self + 11032) = a3;
    *(u32*)(self + 11036) = a4;

    for (;;) {
        *(u16*)dst = *(u16*)a5;
        i = i + 1;
        a5 += 2;
        dst += 2;
        if (i >= 7) {
            break;
        }
    }

    i = 0;
    for (;;) {
        u32 off = (u32)(i << 1);
        *(u16*)(off + self + 11040) = *(u16*)(off + a6);
        i = i + 1;
        if (i >= 7) {
            break;
        }
    }

    func_002fde18(self + 10904, 0, 120);
}

void duplicate_unplaced_00291068(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    u32 s19 = a1;
    u32 s16 = a0;
    u32 s17 = a2;
    u32 s20 = a4;
    u32 s21 = a5;

    func_00290d68(s16, a3);
    func_00290f78(s16);
    u32 s18 = func_00291380(s16, s17);
    func_00291510(s16, s19, s17, s18);
    func_00291ba8(s16, s19, s17, s20, s21, s18);
}

void func_002911f8(u32 self) {
    u32 s16 = self;
    s32 s17 = 0;
    u32 s18 = self;

    for (;;) {
        if (func_00139d78(s16 + 4) != 0) {
            break;
        }
        if (func_00139d78(s16 + 2184) != 0) {
            break;
        }
        s17 += 1;
        u32 cont = (u32)(s17 < 5);
        s16 += 436;
        if (cont != 0) {
            continue;
        }
        {
            s16 = s18 + 4364;
            s17 = 0;
            u32 arg = s16;
            for (;;) {
                if (func_00139d78(arg) != 0) {
                    break;
                }
                s17 += 1;
                if (s17 >= 15) {
                    break;
                }
                s16 += 436;
                arg = s16;
            }
            break;
        }
    }
}

void func_002931a8(u32 a0) {
    u32 s16 = a0;
    func_002ff3fc();
    if (func_002ff1a4(D_0035f4e4, s16) != 0) {
        func_00292a58();
    }
    func_002ff2e8(D_0035f4e4, s16);
}

void func_002932f8(void) {
    if (D_0035f4e8 != 0) {
        func_00106450(D_0035f4e8);
        D_0035f4e8 = 0;
    }

    if (D_0035f4ec != 0) {
        func_00106450(D_0035f4ec);
        D_0035f4ec = 0;
    }

    func_002936e8();
}

void func_00293bd0(u32 a0, u32 a1, u32 a2) {
    u8 buf[128];
    u32 v = a2 & 0xff;
    if (v == 0) {
        func_00170cd0();
    }
    func_00293cb8(buf, a0, a1);
    u32 msg = 5100;
    msg = (a0 != 0) ? 5101 : msg;
    func_00292568(buf, msg, v);
}

void func_00294ea8(void) {
    if (D_0035f580 != 0) {
        if (func_0023f900(D_0035f57c) != 0) {
            func_0023fad0(D_0035f57c);
        }
    }
    func_00293d80(5101);
    D_0035f580 = 0;
}

void func_00296ab0(void) {
    if (D_0035f590 != 0) {
        if (func_0023f900(D_0035f58c) != 0) {
            func_0023fad0(D_0035f58c);
        }
    }
    func_00293d80(5101);
    D_0035f590 = 0;
}

void func_00297d78(void) {
    if (D_0035f598 != 0) {
        func_00106420(D_0035f598);
        D_0035f598 = 0;
    }
    if (D_0035f59c != 0) {
        u32 p = D_0035f59c;
        ((void (*)(u32))(*(u32*)(*(u32*)p + 4)))(p);
        D_0035f59c = 0;
    }
    D_0035f5a0 = -1;
    D_0035f5a1 = -1;
    D_0035f5a3 = 0;
    D_0035f5a2 = 0;
}

void func_00297e00(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00287bc0();
    v0 -= 4;
    if (v0 >= 2) {
        return;
    }
    func_00298f90();
    func_00274ac8();
    if ((u32)(s0 - 4) < 2) {
        return;
    }
    func_0028f7e8(0);
}

void func_00298fe8(s32 a0) {
    u8 buf[32];
    s32 idx = (s8)a0;
    u32 off = (u32)idx;
    off <<= 1;
    off += D_0035f598;
    D_0035f5a1 = a0;
    u32 s0 = (u32)func_002983d8(*(s16*)(off + 4));
    if (func_00292630() != 0) {
        D_0035f5a3 = 0;
        return;
    }
    u32 v = func_00293de8(*(s8*)s0);
    func_002ff2e8(buf, v);
    func_002feee8((u32)buf, s0 + 1);
    func_00298f90();
    func_00293bd0(3, buf, 0);
    func_002925c0();
    D_0035f5a3 = 1;
}

extern "C" void func_0029a2a0(void) asm("_ZN2Tz12JmCollection9FileAllocEv");

void func_0029a310(void) {
    if (D_0035f5a8 != 0) {
        if (func_0023f900(D_0035f5a4) != 0) {
            func_0023fad0(D_0035f5a4);
        }
    }
    func_00293d80(5101);
    D_0035f5a8 = 0;
}

void func_0029dfc0(void) {
    u32 s1 = func_002766d0();
    u32 s0 = s1 + 0x4860;

    if (func_00139d78(s0) != 0) {
        return;
    }

    func_0028d8c0(s0, 30055, D_0035f14c, D_0035f148, D_0035f210, 4, 5, 0);
    func_0028dcc0(s0, s1);
}

void func_0029e298(u32 a0) {
    u32 v0 = func_002766d0();
    a0 += 1;
    u32 s0 = v0 + a0 * 408u;
    u32 s1 = s0 + 17304u;

    if (func_00139d78(s1) == 0) {
        return;
    }

    u32 t7 = *(u32*)(s0 + 17304u);
    (*(void (**)(u32))(t7 + 20))(s1);
}

u32 func_0029e338(u32 a0) {
    a0 += 1;
    u32 s1 = 0;
    u32 v0 = func_002766d0();
    u32 s0 = v0 + a0 * 408u + 17304u;

    if (func_00139d78(s0) != 0) {
        s1 = (*(u32*)(s0 + 388u) == 8u);
    }

    return s1;
}

void func_0029e960(void) {
    if (D_0035f5c0 != 0) {
        return;
    }

    u32 v0 = func_00103b48(0, 0x0001adb0, &D_0015de58);
    D_0035f5c0 = v0;
    u32 v1 = func_00103580();

    u32 t = D_0034b278;
    D_0034b278 = v1;
    D_0034b27c = t;

    func_0015def8();
}

void func_0029e9d0(void) {
    if (D_0035f5c0 == 0) {
        return;
    }

    u32 v0 = func_00103eb0();
    func_00102670(*(u32*)(v0 + 4), D_0035f5c0);
    func_0015df98();

    D_0035f5c0 = 0;
    D_0034b278 = D_0034b27c;
}

extern "C" void func_002a0780(void) asm("_ZN2Tz9JmDiagram10FadeOutAllEv");

void func_002a07f0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00287bc0();

    if (v0 == 6 || v0 == 12 || v0 == 40) {
        func_002a1c68();
        func_00274ac8();
        if (s0 != 16) {
            func_0028f7e8(0);
        }
        func_002a0860();
    }
}

void func_002a45a0(void) {
    u32* s0 = &D_0035f5e8;
    if (func_00139d78(*s0 + 29376) != 0) {
        func_00139510(*s0 + 29376);
    }

    if (func_0028d008(0) != 0) {
        func_0028cdb8(0);
    }

    s0 = &D_0035f218;
    if (func_0028d6e8(*s0) != 0) {
        func_0028d5d0(*s0);
    }
}

u32 func_002a7530(void) {
    u32 s0 = 0;
    if (func_002a7490() != 0) {
        goto L_set;
    }
    if (func_002a74c0() != 0) {
        goto L_set;
    }
    if (func_00276c18() == 0) {
        goto L_ret;
    }
L_set:
    s0 = 1;
L_ret:
    return s0;
}

void func_002a8a00(void) {
    u32 s0;
    u32 s1;

    if (D_0035f608 != 0) {
        func_00106420(D_0035f608);
        D_0035f608 = 0;
    }

    s1 = (u32)D_0035f60c;
    if (s1 == 0) {
        return;
    }

    s0 = s1 + 4360;
L_loop:
    if (s1 == s0) {
        goto L_done;
    }
    s0 = s0 - 436;

    {
        u32 t6 = *(u32*)s0;
        u32 t7 = *(u32*)(t6 + 12);
        ((void (*)(u32))t7)(s0);
    }
    goto L_loop;

L_done:
    func_00106420((void*)s1);
    D_0035f60c = 0;
}


u32 func_002aecf0(u32 a0) {
    u32 s0 = a0 & 0xff;
    u32 v0 = func_00287bc0();

    if ((u32)(v0 - 27) < 4 || v0 == 33 || v0 == 32 || v0 == 31) {
        if (s0 != 0) {
            func_002b2840();
        }
        func_00274ac8();
        return func_002b20b8();
    }

    return v0;
}

s32 func_002b2380(s32 a0, s32 a1) {
    u32* p = func_002b23e0(-1);
    u32 t7 = p[0];
    t7 >>= 25;
    t7 &= 4;
    s32 t5 = D_00374cd0[t7];
    a1 = a1 * t5;
    a1 = a1 + a0;
    return a1;
}

void func_002b4388(Obj4388* a0, u8* a1, u32 a2) {
    u8* s0 = a1 + 20;
    s32 s1 = 2;
    u32 s2 = 0;

    do {
        u32 t7 = *(u16*)(s0 + 0);
        s0 += 2;
        if (t7 != 0) {
            func_0023f5b8((void*)(a0->p4 + s2), t7, a2);
        }
        s1 -= 1;
        s2 += 76;
    } while (s1 >= 0);

    u32 v = *(u16*)(a1 + 26);
    if (v != 0) {
        func_0023f5b8((void*)a0->p8, v, a2);
    }
}


u32 func_002b5978(void) {
    u32 s2 = 0;
    u32 s4 = 0;

    while (1) {
        u32 s1 = 0;
        u32 off = s2 << 2;
        void** s0 = &D_0035f690[off];

        while (1) {
            void* t7 = *s0;
            s0 = s0 + 1;

            if (t7 != 0) {
                if (func_00139d78(t7) != 0) {
                    s4 = 1;
                    break;
                }
            }

            s1 = s1 + 1;
            if ((s32)s1 < 4) {
                continue;
            }
            break;
        }

        s2 = s2 + 1;
        if ((s32)s2 < 3) {
            continue;
        }
        return s4;
    }
}


u32 func_002ba848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s0 = a0;
    func_002b70b8(0, 0, s0);
    func_002b70b8(1, 0, s0);
    func_002b73ac(-100, -1, 0, 0, s0);
    func_002baa60();
    return func_002b83b4();
}

u32 func_002bb1c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s18 = a1;
    u32 s17 = a2;

    func_002bb100(s16, 1, 0);
    func_002bb5a8(s16, s17);
    func_002bb180(s16, s18);
    return func_002bb0e0(s16);
}

u32 func_002bb2b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a2;

    func_002bb100(s16, a3, 2);
    func_002bb180(s16, s17);
    *(u32*)(s16 + 24) = s18;
    return func_002bb0e0(s16);
}

u32 func_002bb310(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a2;
    u32 s19 = a3;

    func_002bb100(s16, 0, 4);
    func_002bb180(s16, s17);
    *(u32*)(s16 + 24) = s18;
    *(u16*)(s16 + 46) = (u16)s19;
    return func_002bb0e0(s16);
}

u32 func_002bb378(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s18 = a1;
    u32 s19 = a2;
    u32 s17 = a3;
    u32 s20 = a4;

    func_002bb100(s16, 1, 5);
    func_002bb5a8(s16, s17);
    *(u32*)(s16 + 24) = s18;
    *(u32*)(s16 + 16) = s19;
    *(u16*)(s16 + 42) = (u16)s20;
    return func_002bb0e0(s16);
}

void func_002bb950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u8 tmp;

    u32 ok = func_0014ee28(*(u16*)(s16 + 46), s16, (u32)&tmp);
    if (ok != 0) {
        func_002bb5f8(s16);
        if (tmp == 1) {
            *(u16*)(s16 + 44) = 64;
        }
        return;
    }

    *(u16*)(s16 + 40) = 0;
    *(u16*)(s16 + 44) = 64;
}

u32 func_002bc288(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = func_002bc158();

    if (s18 == 0) {
        return 0;
    }

    func_002bb2b8(s18, s16, s17, 0);
    return *(u32*)(s18 + 20);
}

u32 func_002bc588(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a2;
    u32 s19 = a3;

    u32 s20 = func_002bc0f0();
    if (s20 == 0) {
        return 0;
    }

    func_002bb378(s20, s16, s17, s18, s19);
    return *(u32*)(s20 + 20);
}

u32 func_002bcb60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a4;
    u32 s19 = a5;

    u32 v = func_002bc988(a2);
    *(u32*)s19 = v;

    s32 r = func_002bca10(s16, v, s17);
    *(u32*)s18 = (u32)r;

    u32 ok = 0;
    if (r == -1) {
        *(u32*)s18 = s17;
        func_002bc9a8(s16, s17, *(u32*)s19);
        ok = 1;
    }

    return ok;
}

void func_002bcc60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a2;
    (void)a3;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s19 = a3;
    u32 s18 = a4;

    func_002bcf58(s16);
    func_002bcfa0(s16);
    func_002bd1c0(s16);

    *(u32*)s18 = func_002bc988(s17);
    *(u32*)s19 = 30;

    func_002bc9a8(s16, 30, *(u32*)s18);
}

u32 func_002bccd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a4;
    u32 s19 = a5;

    u32 v = func_002bc988(a2);
    *(u32*)s19 = v;

    s32 r = func_002bca48(s16, v);
    *(u32*)s18 = (u32)r;

    u32 ok = 0;
    if (r == -1) {
        *(u32*)s18 = s17;
        func_002bc9a8(s16, s17, *(u32*)s19);
        ok = 1;
    }

    return ok;
}

u32 func_002be020(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s17 = a0;
    u32 s19 = a1;
    u32 s18 = a2;

    func_002be0b0(s17);

    if (func_002be5b8(s17) == 0) {
        func_0015f618();
    }

    u32 s16 = func_001050d8(560);
    func_002c1f08(s16, s18 | 0x40000000);

    u32 off = s19 << 2;
    off = off + s17;
    *(u32*)(off + 44) = s16;

    return func_002edfa8(s17 + 8, s16);
}

void func_002be258(u32 a0, u32 a1, u32 a2, s32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 off = a1 << 2;
    off = off + a0;

    u32 s19 = a0;
    u32 s18 = *(u32*)(off + 44);

    if (a3 <= 0) {
        return;
    }

    u32 s17 = a2;
    s32 s16 = a3;
    u32 a2v = *(u32*)s17;

L290:
    u32 h = func_00168b38(*(u32*)(s19 + 104), -1, a2v);
    s16 = s16 - 1;
    s17 = s17 + 4;
    func_002eedd8(s18, *(u32*)(h + 8), 0.0f);
    if (s16 != 0) {
        a2v = *(u32*)s17;
        goto L290;
    }
}

void func_002beb28() {
    u32 v0 = func_002c6218();
    v0 = func_002c61c0(v0);
    v0 = func_002bf2f8();
    if (v0 != 0) {
        u32 vt = *(u32*)v0;
        void (*fn)(u32) = (void (*)(u32))*(u32*)(vt + 4);
        fn(v0);
    }
    func_002be720();
    D_00361898 = 0;
}

u32 func_002beef8(u8* self) {
    u32 a0 = *(u32*)(self + 36);
    u32 t7 = *(u32*)a0;
    ((void (*)(u32))*(u32*)(t7 + 20))(a0);

    u32 t = *(u32*)(self + 40);
    t = t & 1u;
    if (t) {
        return 1;
    }

    u32 t6 = *(u32*)(self + 36);
    if ((*(u32*)(t6 + 112) ^ 3u) != 0) {
        return 1;
    }

    u32 vt = *(u32*)t6;
    u32 fn = *(u32*)(vt + 32);
    ((void (*)(u32))fn)(t6);
    func_002baa60();
    *(u32*)(self + 40) |= 1u;
    return 1;
}

void func_002bf1f0(u8* self) {
    *(u32*)(self + 0) = (u32)&D_003619a8;
    D_00361998 = 0;

    u32 obj = *(u32*)(self + 8);
    if (obj != 0) {
        u32 vt = *(u32*)obj;
        ((void (*)(u32))*(u32*)(vt + 4))(obj);
    }

    func_00170950(*(u32*)(self + 156));
    *(u32*)(self + 0) = (u32)&D_00363880;
    func_0023c098((void*)(self + 64));
    func_002369f0((void*)(self + 40));
    *(u32*)(self + 0) = (u32)&D_003637e0;
}

u32 func_002bf270(u8* self) {
    *(u32*)(self + 0) = (u32)&D_003619a8;
    D_00361998 = 0;

    u32 obj = *(u32*)(self + 8);
    if (obj != 0) {
        u32 vt = *(u32*)obj;
        ((void (*)(u32))*(u32*)(vt + 4))(obj);
    }

    func_00170950(*(u32*)(self + 156));
    *(u32*)(self + 0) = (u32)&D_00363880;
    func_0023c098((void*)(self + 64));
    func_002369f0((void*)(self + 40));
    *(u32*)(self + 0) = (u32)&D_003637e0;
    return func_00105110(self);
}

u32 func_002c0130(u32 a0, u32 a1, f32 a2) {
    u32 s18 = func_001050d8(208);
    func_002bff98(s18, a0, a1, a2);
    u32 v0 = func_002c6218();
    return func_002c6228(v0, 2, s18);
}

u32 func_002c0688(u32 a0, u32 a1) {
    u32 v0 = func_002c6218();
    ((void(*)(u32, u32))func_002c6280)(v0, 1);
    u32 s0 = func_001050d8(128);
    func_002c0370(s0, a0, a1);
    v0 = func_002c6218();
    return func_002c6228(v0, 1, s0);
}

void func_002c1dc0() {
    u8* s0 = &D_00361ba8;
    u32 s1 = 1;
    while ((s32)s1 < 22) {
        u8 t7 = func_001c2b58(s1)[0];
        switch (t7) {
        case 1:
            func_002c2268(s0[1]);
            func_002c2288(s0[0]);
            func_002c2248(s0[2]);
            break;
        case 2:
            func_002c2288(s0[1]);
            func_002c2268(s0[0]);
            func_002c2228(s0[2]);
            break;
        default:
            func_002c2288(s0[1]);
            func_002c2288(s0[0]);
            func_002c2248(s0[2]);
            break;
        }
        s1 = s1 + 1;
        s0 = s0 + 3;
    }
}

u32 func_002c2358(u8* a0) {
    u8* s0 = a0;
    s32 s1 = 2;
    u32 s2 = 0;
loop:
    u16 t7 = *(u16*)(s0 + 4);
    if (t7 != 0) {
        u32 v0 = func_00181500(t7);
        if (v0 != 0) {
            t7 = *(u16*)(s0 + 6);
            if (t7 != 0) {
                v0 = func_00181500(t7);
                u32 t6 = s2 + 1;
                if (v0 != 0) {
                    s2 = t6;
                }
            }
        }
    }
    s1 = s1 - 1;
    if (s1 >= 0) {
        s0 = s0 + 4;
        goto loop;
    }
    return s2;
}

void func_002c23f0() {
    u32 v0 = func_00170b30(0x00100000u);
    D_00361c08 = v0;
    func_001036d0(v0, 0x00100000u);
    u32 s0 = func_00103570();
    func_00288b18(s0);
    func_0028c3f0(s0);
    func_0028c878(s0, 2);
    func_00274ee8(s0);
}

void func_002c3da0(u8* self) {
    u32 v0 = func_002c3240((u32)self, 1);
    u8* s0 = self + 876;
    func_0023f070(self + 28, v0, -1);
    func_0028aa40(*(u32*)(self + 872));
    func_0028ce38();
    if (func_0028d6e8(s0) != 0) {
        func_00139510(s0);
    }

    if (func_002c5120(self) == 0) {
        return;
    }
    if (func_002c5130(self) == 0) {
        func_00139510(self + 11872);
        return;
    }
    func_00138c10(self + 11872, 96);
}

void func_002c4240(u8* self) {
    u8* s2 = self + 876;
    u32 s1 = *(u32*)(self + 872);
    if (((Tz::Select*)s1)->isCursorMove() == 0) {
        return;
    }

    u32 s0 = func_002891e8(s1);
    func_002890e0(s1, 1, 2, 0, -1);
    func_00289038(s1, s0, 1, 1, 2, 0, -1);
    u32 v0 = func_002891d0(s1);
    func_0028d660(s2, v0);
    func_001396b0(s2);
}

void func_002c42f8(u8* self) {
    u8* s0 = self + 28;
    if (func_00139538(s0) != 0) {
        return;
    }
    u32 v = func_0023f0c0(s0);
    if (v != func_002c3240((u32)self, 2)) {
        return;
    }
    if (func_002c5120(self) != 0) {
        func_002c40d8(self);
        return;
    }
    func_002c4240(self);
}

void func_002c5190(u32 a0) {
    if (D_00361c10 != 0) {
        return;
    }

    func_00138480(0);
    func_0014f2d8();

    u32 t6 = D_00347f80;
    u32 obj = *(u32*)(t6 + 20);
    u32 vt = *(u32*)obj;
    u32 s0 = ((u32 (*)(u32, u32, u32))*(u32*)(vt + 0))(obj, 14096, 0);
    func_002c29d8(s0);
    u32 v0 = func_002beb90();
    func_002c4e98(s0, v0, a0);
    func_002cac40(3);
}

u32 func_002c5d38(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;

    if (a1 == 930) {
        if (func_001b8958(1) != 0) {
            if (func_001b8958(2) == 0) {
                func_002bf9d8(1837);
                return 1;
            }
        }
    }

    if (s0 != 1110) {
        goto fail;
    }

    if (func_001b8958(53) == 0) {
        goto fail;
    }

    if (func_001b8958(55) != 0) {
        goto fail;
    }

    func_002bf9d8(1836);
    return 1;

fail:
    return 0;
}

u32 func_002c5ed8(u32 a0, u32 a1, f32 a2) {
    u32 s1 = a0;
    u32 s2 = a1;
    f32 f20 = a2;
    u32 s0 = func_001050d8(3040);
    u32 v0 = func_00167f18(0);
    func_002c5850(f20, s0, s1, v0, s2);
    return s0;
}

void func_002c6c60(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s2 = a1;

    u32 s0 = func_001050d8(160);
    func_002c6780(s0, s1, s2);

    u32 v0 = func_002c6218();
    func_002c6228(v0, 0, s0);
}

void func_002c83c0(u8* a0) {
    u8* s1 = a0;
    u8* t6 = a0 + 196;
    u8* s0;

    u32 t7 = *(u32*)(a0 + 24);
    t7 = t7 & 1;
    if (t7 != 0) {
        u32* vt = *(u32**)a0;
        ((VCall20)vt[5])(a0);
        return;
    }

    if (func_00139538(t6) == 0) {
        goto L_fail;
    }
    if (func_00139538(s1 + 1856) == 0) {
        goto L_fail;
    }
    if (func_00139538(s1 + 2264) == 0) {
        goto L_fail;
    }

    s0 = s1 + 28;
    if (func_00139d78(s0) != 0) {
        func_00139510(s0);
    }

    t7 = *(u32*)(s1 + 24);
    t7 = t7 | 1;
    *(u32*)(s1 + 24) = t7;
    return;

L_fail:
    func_00236d60();
}

void func_002c8490(u8* a0) {
    u8* s0 = a0 + 196;
    u8* s1 = a0 + 1856;
    u8* s2 = a0 + 2264;

    if (func_00139d78(s0) != 0) {
        func_00139510(s0);
    }

    if (func_00139d78(s1) != 0) {
        func_00139510(s1);
    }

    if (func_00139d78(s2) != 0) {
        func_00139510(s2);
    }
}

void func_002c8550(u8* a0) {
    u8* s0 = a0;
    u8* s2 = a0 + 196;
    s32 s1 = -1;

    func_00138c10(s2, 154);
    *(s32*)(s2 + 392) = s1;

    u8* s3 = s0 + 1856;
    func_00138c10(s3, 74);
    *(s32*)(s3 + 392) = s1;

    s0 = s0 + 2264;
    func_00138c10(s0, 67);
    *(s32*)(s0 + 392) = s1;
}

void func_002c9f60(u8* a0) {
    u8* s1 = a0;
    u8* t6 = a0 + 188;
    u8* s0;

    u32 t7 = *(u32*)(a0 + 24);
    t7 = t7 & 1;
    if (t7 != 0) {
        u32* vt = *(u32**)a0;
        ((VCall20)vt[5])(a0);
        return;
    }

    if (func_00139538(t6) == 0) {
        goto L_fail;
    }

    s0 = s1 + 28;
    if (func_00139d78(s0) != 0) {
        func_00139510(s0);
    }

    t7 = *(u32*)(s1 + 24);
    t7 = t7 | 1;
    *(u32*)(s1 + 24) = t7;
    return;

L_fail:
    func_00236d60();
}

void func_002ca410(u8* a0) {
    u8* s1 = a0;

    func_00170950(*(u32*)(a0 + 636));
    func_002c5f60();

    u32 v0 = func_002c6218();
    func_002c6280(v0, 2);

    u32 t6 = *(u32*)(s1 + 644);
    if (t6 != 0) {
        if (t6 == 1) {
            u32 a = *(u32*)(s1 + 640);
            func_002c5418(a - 1);
        }
    }

    func_00167f38(1);

    u32 s0 = *(u32*)(s1 + 188);
    if (s0 != 0) {
        func_00288b00(s0);
        func_00288c20(s0);
    }

    if (s1 != 0) {
        u32* vt = *(u32**)s1;
        ((VCall16)vt[4])(s1);
    }

    func_001384a0(0);
    func_0014f2b0();
}

void func_002ca5b8(u8* a0) {
    u8* s0 = a0;

    u32 v0 = func_002ca3d0((u32)a0, 1);
    u8* s1 = s0 + 192;

    func_0023f070(s0 + 28, v0, -1);
    func_0028aa40(*(u32*)(s0 + 188));
    func_0028ce38();

    if (func_0028d6e8(s1) != 0) {
        func_00139510(s1);
    }
}

void func_002ca630(u8* a0) {
    u8* s0 = a0;
    func_00236d60();
    u8* s1 = s0 + 28;

    if (func_00139d78(s1) != 0) {
        if (func_00139538(s1) != 0) {
            if (func_0028acc8(*(u32*)(s0 + 188)) != 0) {
                func_0028abe0(*(u32*)(s0 + 188));
            }
        }
    }

    if (func_00139d78(s1) == 0) {
        u32* vt = *(u32**)s0;
        ((VCall20)vt[5])(s0);
        return;
    }

    func_002ca010(*(u32*)(s0 + 640));
    u32 s2 = func_0023f0c0(s1);
    u32 v0 = func_002ca3d0((u32)s0, 2);
    if (s2 != v0) {
        return;
    }

    func_002ca4c0((u32)s0);
}

void func_002ca6f8(u8* a0) {
    u8* s2 = a0 + 192;
    u32 s1 = *(u32*)(a0 + 188);

    if (((Tz::Select*)s1)->isCursorMove() == 0) {
        return;
    }

    u32 s0 = func_002891e8(s1);
    func_002890e0(s1, 1, 2, 0, -1);
    func_00289038(s1, s0, 1, 1, 2, 0, -1);

    u32 v0 = func_002891d0(s1);
    func_0028d660(s2, v0);
    func_001396b0(s2);
}

void func_002ca7b0(u8* a0) {
    u8* s0 = a0 + 28;
    u8* s1 = a0;

    if (func_00139538(s0) == 0) {
        u32 v1 = func_0023f0c0(s0);
        u32 v0 = func_002ca3d0((u32)s1, 2);
        if (v1 == v0) {
            func_002ca6f8((u32)s1);
            return;
        }
    }
}

void func_002cab98(u32 a0) {
    u32 s1 = a0;

    if (D_00361e28 != 0) {
        return;
    }

    func_00138480(0);
    func_0014f2d8();

    u32 t6 = D_00347f80;
    u32 obj = *(u32*)(t6 + 20);
    u32* vt = *(u32**)obj;
    u32 s0 = ((FnAlloc)vt[0])(obj, 652, 0);

    func_002ca170(s0);
    u32 v0 = func_002beb90();
    func_002caa50(s0, v0, s1);

    func_002cac40(3);
}

void func_002cb0e8(u32 a0, u32 a1, f32 a2) {
    u32 s1 = a0;
    u32 s2 = a1;
    f32 f20 = a2;

    func_002cb160(s1);

    u32 s0 = func_001050d8(112);
    func_002cae60(f20, s0, s1, s2);

    u32 v0 = func_002c6218();
    func_002c6228(v0, 2, s0);
}

void func_002cb4a0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_0016a070(a0);

    u8* p = &D_00361e70;
    u8* end = p + 108;

    while (1) {
        u32 t7 = *(u32*)p;
        if (v0 == t7) {
            u8* obj = func_001b6d70(*(u32*)(p + 4));
            if (*(u8*)obj < 2) {
                func_002c5608(s0);
                return;
            }
            func_002c5628(s0);
            return;
        }

        p = p + 12;
        if ((s32)(u32)p < (s32)(u32)end) {
            continue;
        }
        return;
    }
}

void func_002cb748() {
    u32 s0 = D_01e2be18;
    if (s0 == 0) {
        return;
    }

    while (1) {
        u32 s1 = *(u32*)(s0 + 148);
        if (s0 != 0) {
            func_002cb708(s0);
            func_00105110(s0);
        }
        if (s1 == 0) {
            break;
        }
        s0 = s1;
    }
}

void func_002ccf98(u32 a0) {
    u32 s0 = a0;

    if (*(u8*)(a0 + 135) == 0) {
        return;
    }

    u32 t7 = *(u32*)(a0 + 136);
    if (t7 != 0) {
        if (func_0019ba60(t7) != 0) {
            func_002cd3e0(s0, *(u32*)(s0 + 136));
            return;
        }
    }

    func_002cd260(s0);
}

u32 func_002cd878(u32 a0, u32 a1, s32 a2, f32 a3) {
    u32 s3 = a0;
    u32 s1 = a1;
    s32 s0 = a2;
    f32 f20 = a3;

    u32 s2 = func_002cb890(s1, (u32)s0);

    s0 = s0 + 1;
    s32 t7 = *(s32*)(s1 + 8);
    s32 rem = s0 % t7;
    u32 v0 = func_002cb890(s1, (u32)rem);

    func_002cd770(f20, s3, s1, s2, v0);
    return s3;
}

u32 func_002cda68(u32 a0, u32 a1, s32 a2, f32 a3) {
    u32 s3 = a0;
    u32 s1 = a1;
    s32 s0 = a2;
    f32 f20 = a3;

    u32 s2 = func_002cb890(s1, (u32)s0);

    s0 = s0 + 1;
    s32 t7 = *(s32*)(s1 + 8);
    s32 rem = s0 % t7;
    u32 v0 = func_002cb890(s1, (u32)rem);

    func_002cd950(f20, s3, s1, s2, v0);
    return s3;
}

u32 func_002cdb00(u32 a0, u32 a1, f32 a2) {
    f32 f20 = a2;
    u32 s0 = a1;
    u32 s1 = a0;

    f32 f0 = func_002f8888(a0);
    f20 = f20 - f0;
    s32 t6 = (s32)f0;

    func_002cda68(s1, s0, t6, f20);
    return s1;
}

void func_002ce870(u8* a0, u32 a1) {
    u8* s0 = a0;
    u32 s1 = a1;

    f32 f12;
    if (*(u8*)(a0 + 16) != 0) {
        f12 = (f32)(*(s32*)(a0 + 8));
    } else {
        s32 t7 = *(s32*)(a0 + 8);
        t7 = t7 - 1;
        f12 = (f32)t7;
    }

    f32 f20 = func_00106558(f12);
    u32 v0 = func_001064a8(2);

    s32 t6 = (s32)f20;
    *(u8*)(s0 + 132) = (v0 != 0);

    f32 ftmp = (f32)t6;
    f32 frac = f20 - ftmp;

    u8 tmp[16];
    func_002cd878(tmp, (u32)s0, t6, frac);
    func_0016ace0(s1, tmp);

    *(f32*)(s0 + 24) = f20;
}

void func_002d2948(u8* a0) {
    u8* s0 = a0;

    func_002cfeb0((u32)a0);

    *(u32*)(s0 + 0) = (u32)(&D_00360000 + 0x2230);
    func_002cf280(s0 + 2800, 1, 0);

    u32 t7 = *(u32*)(s0 + 268);
    u32 t6 = *(u32*)(s0 + 264);
    t7 = t7 | 0x8000;
    *(u32*)(s0 + 2852) = 0;
    t6 = t6 | 0x1;
    *(u32*)(s0 + 268) = t7;
    *(u32*)(s0 + 264) = t6;
}

void func_002d29a8(u8* a0) {
    u8* s0 = a0;

    func_002cfeb0((u32)a0);

    *(u32*)(s0 + 0) = (u32)(&D_00360000 + 0x2230);
    func_002cf280(s0 + 2800, 1, 0);

    u32 t7 = *(u32*)(s0 + 268);
    u32 t6 = *(u32*)(s0 + 264);
    t7 = t7 | 0x8000;
    *(u32*)(s0 + 2852) = 0;
    t6 = t6 | 0x1;
    *(u32*)(s0 + 268) = t7;
    *(u32*)(s0 + 264) = t6;
}

void func_002d5af0(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(s0 + 3128);
    func_002cf2b0(p + 2800, 1);
    func_002d2a90(*(u32*)(s0 + 3128));
    func_00190128(s0 + 2548);
    u32 a1 = 56;
    if (*(u32*)(s0 + 3132) == 0) {
        a1 = 55;
    }
    func_0016bd60(s0, a1);
}

void func_002d5b48(u32 a0) {
    u8* s0 = (u8*)a0;
    s32 t7 = -1;
    u32 v0 = *(u32*)(s0 + 3128);
    if (v0 != 0) {
        if (*(s32*)(s0 + 3132) >= 0) {
            u32* vtbl = *(u32**)v0;
            ((void (*)(u32))vtbl[8])(v0);
            t7 = -1;
        }
    }
    *(u32*)(s0 + 3128) = 0;
    *(s32*)(s0 + 3132) = t7;
    func_0016bd60(a0, 37);
}

u32 func_002d5c40(u32 a0) {
    u32 s0 = a0;
    u32 t4;
    if (func_002d5578(a0) != 0) {
        t4 = 1;
    } else {
        u32 t6 = *(u32*)(*(u32*)(s0 + 12) + 4);
        t4 = 2;
        if ((t6 ^ 0x37) != 0) {
            u32 a0v = t6 ^ 0x38;
            u32 t7 = 3;
            t4 = 0;
            if (a0v == 0) {
                t4 = t7;
            }
        }
    }
    return t4;
}

void func_002d7390(u32 a0) {
    *(u32*)a0 = (u32)&D_003625a8;
    u32 s0 = *(u32*)(a0 + 160);
    if (s0 != 0) {
        func_002e70b0(s0);
        func_00106420(s0);
    }
    func_002cea28(a0);
    func_00105110(a0);
}

void func_002d7420(u32 a0) {
    u8* s1 = (u8*)a0;
    u32 s0 = 0;
    while (1) {
        u8* t7 = *(u8**)(s1 + 184);
        u32 t6 = t7[9];
        if (s0 == t6) {
            func_0015ee90(s0);
            func_00160f10(s0);
        } else {
            func_0015ee10(s0);
        }
        s0 += 1;
        if (!(s0 < 16)) {
            u8* t7f = *(u8**)(s1 + 184);
            u8* t6p = t7f + 12;
            u8 t5 = t6p[4];
            u8 t7v = t6p[5];
            f32 f12 = (f32)*(s32*)(t6p + 8);
            f32 f13 = (f32)*(s32*)(t6p + 12);
            f32 f14 = (f32)t5;
            f32 f15 = (f32)t7v;
            func_0015ca40(
                t6p[0],
                t6p[1],
                t6p[2],
                f12,
                f13,
                f14,
                f15);
            return;
        }
    }
}

void func_002d7630(u32 a0) {
    *(u32*)(a0 + 468) = 0;
    *(u32*)(a0 + 472) = 0;
    *(u8*)(a0 + 144) = 0;
    u32 t5 = a0;
    s32 t4 = 2;
    do {
        *(u32*)(t5 + 108) = 0;
        t4 -= 1;
        *(u32*)(t5 + 120) = 0;
        *(u32*)(t5 + 132) = 0;
        t5 += 4;
    } while (t4 >= 0);
    u32 a1 = *(u32*)(a0 + 104);
    *(u8*)(a0 + 192) = 0;
    *(u8*)(a0 + 193) = 0;
    *(u8*)(a0 + 201) = 0;
    func_002d74c8(a0, a1 & 0xfff, 0);
}

void func_002da8f0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t7 = *(u32*)(a0 + 3060);
    if (t7 != 0) {
        func_002db610(t7);
    }
    t7 = *(u32*)(s0 + 3056);
    if (t7 != 0) {
        func_002dc1b8(t7, s1);
    }
}

void func_002dd968(u32 a0) {
    u32 scratch[8];
    func_00190128(scratch);
    func_00190878(scratch, a0, 0);
    func_001bd3e0(*(u32*)(a0 + 0xb44), 1, 565, scratch, 1, 100);
}

void func_002de888(u32 a0) {
    func_00187750(a0);
    if (func_001c0cd8(a0) != 0) {
        return;
    }
    u32 v = D_0034e948;
    if (v == 0) {
        return;
    }
    func_001c0d38(a0, v, 67, 0);
}

void func_002def70(u32 a0, u32 a1) {
    u32 a = a1 + 320;
    f32 z = 0.0f;

    u32 v = call_vt_48(a0);
    ((u32(*)(u32, u32, f32, f32))func_0017f488)(a, v, z, z);

    v = call_vt_40(a0);
    ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(a, v, 0, z, z);
}

void func_002df758(u32 a0, u32 a1) {
    u32 p = D_00361f60;
    u32 s = func_002dc7c8(p);
    u32 t = func_002dc7c8(p);

    func_002deac0(a0, *(f32*)(s + 244), *(f32*)(t + 248));
    func_002deb18(a0, a1);
    *(u32*)(a0 + 52) = 0xffffffffu;
}

void func_002e0f20(u32 a0) {
    *(u32*)a0 = (u32)&D_00362dc8;
    u32 p = *(u32*)(a0 + 112);
    if (p != 0) {
        func_002e70b0(p);
        func_00106420(p);
    }
    func_002cea28(a0);
    func_00105110(a0);
}

void func_002e22f0(u32 a0) {
    *(u32*)a0 = (u32)&D_00362eb8;
    u32 p = *(u32*)(a0 + 108);
    if (p != 0) {
        func_002e70b0(p);
        func_00106420(p);
    }
    func_002cea28(a0);
    func_00105110(a0);
}

void func_002e2660(u32 a0) {
    if (*(u32*)(a0 + 272) != 0) {
        return;
    }

    s32 a1 = (s32)*(u32*)(a0 + 264) - 1;
    if (a1 < 0) {
        a1 = (s32)func_002e34c8(a0 + 104) - 1;
    }

    func_002e2728(a0, a1, 0);
}

void func_002e26c0(u32 a0) {
    if (*(u32*)(a0 + 272) != 0) {
        return;
    }

    s32 s = *(s32*)(a0 + 264);
    if ((s32)func_002e34c8(a0 + 104) < s) {
        s = 0;
    }

    func_002e2728(a0, s, 1);
}

void func_002e3688(u32 a0) {
    u32 s16 = a0;
    u32 e0 = *(u32*)a0;
    u32 p0 = *(u32*)(e0 + 4);
    if (*(u32*)(p0 + 1288) == 0) {
        return;
    }

    u32 v = func_0016c028(p0);
    u32 e1 = *(u32*)s16;
    u32 p1 = *(u32*)(e1 + 4);
    u32 flag = *(u32*)(s16 + 4);
    u32 node = *(u32*)(p1 + 1288);
    func_002cb7a0(node, (flag != 0), v);
}

void func_002e36f0(u32 a0) {
    u32 s16 = a0;
    u32 e0 = *(u32*)a0;
    u32 p0 = *(u32*)(e0 + 4);

    if (*(u32*)(p0 + 1288) != 0) {
        u32 v = func_0016c028(p0);
        u32 e1 = *(u32*)s16;
        u32 p1 = *(u32*)(e1 + 4);
        *(u32*)s16 = func_002cb800(*(u32*)(p1 + 1288), v);
    } else {
        *(u32*)s16 = 0;
    }
}

void func_002e39c0(u32 a0) {
    u32 s16 = *(u32*)(*(u32*)a0 + 4);
    if (s16 == 0) {
        return;
    }

    u32 p = *(u32*)(s16 + 1288);
    if (p == 0) {
        return;
    }

    u32 v = func_0016c028(s16);
    func_002cbec0(*(u32*)(s16 + 1288), v);
}

void func_002e3de0(u32 a0) {
    u32 s16 = a0;
    u32 v = func_0019b260(*(u32*)(a0 + 4) & 0xfffeffffu);
    if (v != 0) {
        *(u32*)s16 = func_00184eb8(*(u32*)(*(u32*)s16 + 4), -1, v);
    } else {
        *(u32*)s16 = 0;
    }
}

void func_002e3fa0(f32* a0, f32* a1, f32 a2) {
    f32 v = func_002f87c0((u32)a0, (u32)a1);
    a0[3] = v;
    f32 s = func_002f8960(a2);

    a0[0] = a1[0] * s;
    a0[1] = a1[1] * s;
    a0[2] = a1[2] * s;
}

void func_002e4010(f32* a0, f32* a1, f32 a2) {
    f32 v = func_002f87c0((u32)a0, (u32)a1);
    a0[3] = v;
    f32 s = func_002f8960(a2);

    a0[0] = a1[0] * s;
    a0[1] = a1[1] * s;
    a0[2] = a1[2] * s;
}

void func_002e73d8(u32 a0) {
    f32 t = *(f32*)(a0 + 28) - D_00349e10;
    *(f32*)(a0 + 28) = t;
    if (t <= 0.0f) {
        u32 v0 = func_001064a8(*(u32*)(a0 + 8));
        u32 obj = *(u32*)(a0 + 4);
        u32 t7 = *(u32*)(a0 + 12) + v0;
        u32 vt = *(u32*)obj;
        u32 a2 = *(u32*)(a0 + 24);
        VFn73d8 fn = *(VFn73d8*)(vt + 84);
        fn(obj, *(u8*)t7, a2);
        func_002e73a8(a0);
    }
}

void func_002eb920(u32 a0, u32 a1, f32 a2) {
    u32 s1 = a0;
    u32 s0 = a1;
    f32 s20 = a2;

    func_002eaf38(s1);
    func_002eb778(s1, s0, 1, s20);

    u32 t14 = *(u32*)(s1 + 12);
    u32 t15 = *(u32*)(t14 + 4) ^ 0x31;
    if (t15 == 0) {
        u32 v = *(u32*)(s1 + 268);
        v = v & 0xFFFFFFFEu;
        *(u32*)(s1 + 268) = v;
    }
}

void func_002ec1d0(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    f32 z = 0.0f;

    func_002eb778(s0, *(u32*)(s0 + 260), 1, z);
    func_002eb7f0(s0, 252, z);
    func_0016bd60(s0, 48);

    *(u32*)(s0 + 264) = *(u32*)(s0 + 264) | 0x08000000u;

    func_002edaf8(D_003637d0);
}

void func_002edb38(void) {
    if (D_003637d0 != 0) {
        return;
    }

    u32 p = func_001050d8(4);
    func_002eda10(p);
    u32 q = func_00102c18(1, 20500, (u32)&D_002edb90);
    *(u32*)(q + 48) = (u32)&D_002edbb0;
}

void func_002edfd8(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a0 + 8);
    u32 t5;
    u32 t4 = a0 + 8;

    if (a1 == t7) {
        t7 = *(u32*)(a1 + 32);
        t5 = 0;
        *(u32*)(a0 + 8) = t7;
    } else {
        u32 t6 = *(u32*)(t7 + 32);
        t5 = t7;
        while (t6 != a1) {
            t7 = *(u32*)(t6 + 32);
            t5 = t6;
            t6 = t7;
        }
        t7 = *(u32*)(a1 + 32);
        *(u32*)(t5 + 32) = t7;
    }

    t7 = *(u32*)(t4 + 4);
    if (a1 == t7) {
        *(u32*)(t4 + 4) = t5;
    }
    *(u32*)(a1 + 32) = 0;
    *(u32*)(a1 + 28) = 0;
}

void func_002eefc8(u32 a0, u32 a1, float a2) {
    u32 t2 = a0 + 24;
    if (*(u32*)(a0 + 8) == 0) {
        func_002eef08(a0, a1, a2);
        return;
    }

    s32 idx = *(s32*)(a0 + 24);
    s32 next = idx + 1;
    s32 q = next;
    if (next < 0) {
        q = next + 3;
    }
    q >>= 2;
    q <<= 2;
    next -= q;
    u32 entry = t2 + ((u32)idx << 3);
    *(volatile s32*)(a0 + 24) = next;
    *(volatile float*)(entry + 12) = a2;
    *(volatile u32*)(entry + 8) = a1;
}

u32 func_002ef1f8(u32 a0, u32 a1, u32 a2) {
    func_00236a58(a0 + 40, a2, *(u32*)(a0 + 36));
    return func_0023c100(a0 + 64, a1, a0 + 40, *(u32*)(a0 + 36));
}

u32 func_002ef370(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a0 + 48;
    u32 t6 = a1;

    u32 v = *(u32*)a1;
    *(u32*)(s0 + 36) = v;
    *(u32*)(s0 + 40) = *(u32*)(t6 + 4);
    func_002362b0(s1, v);

    *(u32*)(s0 + 464) = s1;
    return func_00239988(s0 + 468, *(u32*)(s0 + 40), s1);
}

u32 func_002ef3c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a0 + 468;
    u32 s3 = a3;

    *(u32*)(s0 + 464) = func_00236ca8(*(u32*)(a1 + 40), a2);
    u32 v0 = func_0023c4b8(s1, s3);
    return func_00239988(s2, v0, *(u32*)(s0 + 464));
}

void func_002efa98(u32 a0) {
    u32 s2 = a0;
    u8* s0 = (u8*)(a0 + 8);
    s32 s1 = 7;

    do {
        *s0 = (u8)func_001064a8(255);
        s1 -= 1;
        s0 += 1;
    } while (s1 >= 0);

    u32 v0 = func_001064a8(-1);
    u32 t2 = v0 << 1;
    u32 t7 = *(u32*)(s2 + 16);
    t7 = (t7 & 1) | t2;
    *(u32*)(s2 + 16) = t7;
}

void func_002efb08(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001058e8(a0);
    s0 += 20;
    v0 += 7312;
    u32 t4 = 0;

    do {
        u32 t7 = *(u32*)s0;
        t4 += 1;
        u32 t6 = *(u32*)v0;
        u32 t5 = (t4 < 152);
        t7 |= t6;
        v0 += 4;
        *(u32*)s0 = t7;
        s0 += 4;
        if (t5 == 0) {
            break;
        }
    } while (1);
}

void func_002f0970(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)s0;
    u32 v0 = func_0010c7e8(*(u32*)(t7 + 4));

    u32 a2 = 0;
    u32 t7b = *(u32*)(s0 + 8);
    if (t7b != 0) {
        a2 = *(u32*)(t7b + 4);
    }

    u32 a5 = (*(u32*)(s0 + 20) != 0);
    u32 r = func_00117970(
        v0,
        *(u32*)(s0 + 4),
        a2,
        *(u32*)(s0 + 12),
        *(u32*)(s0 + 16),
        a5,
        *(u32*)(s0 + 24),
        *(u32*)(s0 + 28)
    );
    *(u32*)s0 = r;
}

f32 func_002f8a18(f32 a0) {
    union {
        f32 f;
        u32 u;
    } bits;
    bits.f = a0;

    s32 abits = (s32)(bits.u & 0x7FFFFFFFu);
    if (!((s32)0x3F490FDA < abits)) {
        return func_002fb558(1, a0, 0.0f);
    }

    f32 tmp[2];
    s32 q = (s32)(func_002fa678((void*)tmp) & 1u);
    s32 s = 1 - (q << 1);
    return func_002fb558(s, tmp[0], tmp[1]);
}

s32 func_002fea18() {
    u32 base36 = 0x00360000u;
    u32 base37 = 0x00370000u;

    u32 root = *(u32*)(base36 + 0x5C48u);
    s64 step = *(s64*)(base37 + 0x78E0u);
    s64 cur = *(s64*)(root + 168u);

    s64 v = func_00311aa0(cur, step) + 1ll;
    *(s64*)(root + 168u) = v;

    u64 hi = (u64)v >> 32;
    hi &= 0x7FFFFFFFu;
    s64 sx = (s64)(hi << 32);
    sx >>= 32;
    return (s32)sx;
}

s32 func_002feac0(u32 a0) {
    if (*(u32*)(a0 + 468u) == 0u) {
        u32 p = func_002fd680(a0, 128u);
        *(u32*)(a0 + 468u) = p;
        if (p == 0u) {
            return -1;
        }
        for (s32 i = 31; i >= 0; --i) {
            *(u32*)(p + ((u32)(31 - i) << 2)) = 0u;
        }
    }
    return 0;
}

void func_002fed98(u32* a0, u32 a1, u32 a2) {
    u32* b = (u32*)0x00380000u;
    b[-7495] = 0u;
    s32 r = func_00305df8(a1, a2);
    if (r == -1) {
        u32 v = b[-7495];
        if (v != 0u) {
            *a0 = v;
        }
    }
}

u32 func_00302c88(u32 a0, u32 a1) {
    u32 size = 88u * a1;
    u32 h = func_002fd680(a0, size + 12u);
    if (h == 0u) {
        return 0u;
    }

    u32 p = h + 12u;
    *(u32*)(h + 4u) = a1;
    *(u32*)(h + 0u) = 0u;
    *(u32*)(h + 8u) = p;
    func_002fde18(p, 0u, size);
    return h;
}

void func_00302e10(u32 a0) {
    *(u32*)(a0 + 472u) = 0u;
    *(u32*)(a0 + 60u) = (u32)func_00302dd0;
    *(u32*)(a0 + 56u) = 1u;
    *(u32*)(a0 + 480u) = a0 + 484u;
    *(u32*)(a0 + 476u) = 3u;

    func_00302c28(*(u32*)(a0 + 4u), 4u, 0u, a0);
    func_00302c28(*(u32*)(a0 + 8u), 9u, 1u, a0);
    func_00302c28(*(u32*)(a0 + 12u), 10u, 2u, a0);
}

u32 func_00303e80(u32 a0) {
    u32 x = a0;
    u32 n = 0u;

    if ((x & 0xFFFF0000u) == 0u) {
        n = 16u;
        x <<= 16;
    }
    if ((x & 0xFF000000u) == 0u) {
        n += 8u;
        x <<= 8;
    }
    if ((x & 0xF0000000u) == 0u) {
        n += 4u;
        x <<= 4;
    }
    if ((x & 0xC0000000u) == 0u) {
        n += 2u;
        x <<= 2;
    }

    if ((s32)x < 0) {
        goto ret_n;
    }

    {
        u32 mask = 0x40000000u;
        n += 1u;
        if ((x & mask) == 0u) {
            return 32u;
        }
    }

ret_n:
    return n;
}

u32 func_00303f00(u32* p) {
    u32 t6 = p[0];
    u32 t7 = t6 & 7u;
    if (t7 == 0u) {
        goto L00303f44;
    }

    t7 = t6 & 1u;
    if (t7 != 0u) {
        return 0u;
    }

    if ((t6 & 2u) != 0u) {
        t7 = t6 >> 1;
        p[0] = t7;
        return 1u;
    }

    t7 = t6 >> 2;
    p[0] = t7;
    return 2u;

L00303f44:
    t7 = t6 & 0xFFFFu;
    u32 t5 = 0u;
    if (t7 == 0u) {
        t5 = 16u;
        t6 >>= 16;
    }

    t7 = t6 & 0xFFu;
    if (t7 == 0u) {
        t5 += 8u;
        t6 >>= 8;
    }

    t7 = t6 & 0xFu;
    if (t7 == 0u) {
        t5 += 4u;
        t6 >>= 4;
    }

    t7 = t6 & 3u;
    if (t7 == 0u) {
        t5 += 2u;
        t6 >>= 2;
    }

    t7 = t6 & 1u;
    if (t7 == 0u) {
        t5 += 1u;
        t6 >>= 1;
        if (t6 == 0u) {
            return 32u;
        }
    }

    p[0] = t6;
    return t5;
}

s32 func_003050b8(u32* out, u32 a1, u32 a2) {
    D_00378ae4 = 0;
    s32 r = func_00305dd8(a1, a2);
    if (r == -1) {
        u32 t = D_00378ae4;
        if (t != 0u) {
            out[0] = t;
        }
    }
    return r;
}

s32 func_00305110(u32* out, u32 a1, u32 a2, u32 a3) {
    D_00378ae4 = 0;
    s32 r = func_00305d18(a1, a2, a3);
    if (r == -1) {
        u32 t = D_00378ae4;
        if (t != 0u) {
            out[0] = t;
        }
    }
    return r;
}

void func_0030f068() {
    func_0030ee18();
    func_0030ef58();
    func_0030f548();
    func_0030f6c0(2u);
    func_0030f900();
    func_003063f8();
    func_0030f190();
    func_00311368();
    func_00310d80();
}

u32 func_003166f0(u32 a0) {
    u32 s0 = a0 - 48u;
    u32 v0 = func_00316af8();

    s32 t14 = *(s32*)(s0 + 20u);
    u32 t13 = *(u32*)(v0 + 0u);

    if (t14 < 0) {
        u32 t15 = 1u;
        t14 = (s32)(t15 - (u32)t14);
    } else {
        t14 = t14 + 1;
    }

    *(u32*)(s0 + 20u) = (u32)t14;

    u32 t15 = *(u32*)(v0 + 4u);
    t15 = t15 - 1u;
    *(u32*)(v0 + 4u) = t15;

    if (s0 != t13) {
        *(u32*)(s0 + 16u) = t13;
        *(u32*)(v0 + 0u) = s0;
    }

    return *(u32*)(s0 + 40u);
}

void func_00319930(u32 a0) {
    s32 t14 = 19;
    u32 t15 = a0;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 80u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 92u;
    t14 = 17;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 164u;
    t14 = 8;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    *(volatile u32*)(a0 + 204u) = 0u;
    *(volatile u32*)(a0 + 200u) = 0u;
}

void func_003199d0(u32 a0) {
    *(u32*)(a0 + 0u) = 0u;
    s32 t14 = 2;
    *(u32*)(a0 + 4u) = 0u;
    u32 t15 = a0 + 16u;
    *(u32*)(a0 + 8u) = 0u;
    *(u32*)(a0 + 12u) = 0u;

    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 28u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 40u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    *(volatile u8*)(a0 + 577u) = 0u;
    *(volatile u32*)(a0 + 52u) = 0u;
    *(volatile u32*)(a0 + 56u) = 0u;
}

void func_003181a0(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;

    func_00317fc8(a0);

    u32 t15 = *(u8*)(s0 + 2888u);
    t15 = t15 << 2;
    t15 = t15 + s1;
    u32 t13 = *(u32*)t15;
    s32 t14 = (s32)(u32)(*(u64*)t13);
    t14 = t14 & -2;
    *(u32*)(s1 + 712u) = (u32)t14;
}

void func_0031d8f8(u32 self) {
    *(u32*)self = addr_D_0034aad8();
    func_002361d0(self + 416);
    *(u32*)self = addr_D_00347e60();
    func_00239870(self + 24);
    *(u32*)self = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_0031d8f8 fn = (Fn_0031d8f8)*(u32*)(*(u32*)obj + 4);
    fn(obj, self);
}

void func_0031d9b8(u32 self) {
    *(u32*)self = addr_D_0034ab80();

    if (self != (u32)-440) {
        u32 end = self + 2848;
        u32 begin = self + 440;
        do {
            if (begin == end) {
                break;
            }
            end -= 344;
            Fn_0031d9b8 fn = (Fn_0031d9b8)*(u32*)(*(u32*)end + 0);
            fn(end);
        } while (1);
    }

    *(u32*)self = addr_D_00347e60();
    func_00239870(self + 24);
    *(u32*)self = addr_D_00347f98();
}

void func_0031daf0(u32 self) {
    u32 s18 = self;
    u32 s16 = s18 + 880;
    s32 s17 = 3;
    s32 s19 = -1;

    func_0014ba90(s18);
    func_0013ee88(s18 + 336);
    func_0014b668(s18 + 624);

    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    s16 = self + 1904;
    s17 = 3;
    s18 = (u32)-1;
    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != (s32)s18);
}

void func_0031dd50(u32 self) {
    *(u8*)(self + 4) = 0;
    *(u32*)self = addr_D_0034b250();

    u32 s18 = self;
    u32 s16 = s18 + 1072;
    s32 s17 = 5;
    s32 s19 = -1;

    func_0014c5a0(s18 + 16);
    func_0014c5a0(s18 + 544);

    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    s16 = s18 + 2608;
    s17 = 5;
    s19 = -1;
    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    func_0014c050(s18 + 4144);
}

void func_0031e740(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32*)(self + 2824) = c2824;
    *(u32*)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32*)(s18 + 0) = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)(s18 + 0) = addr_D_003503e0();
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
    func_00105110(s18);
}

void func_0031e820(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
}

void func_0031e878(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_0031e948(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
}

void func_0031e9a0(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_0031ea80(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031ebf8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031ec98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031ed48(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031edc8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031eed8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031ef58(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031f0c0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031f388(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031f408(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031f968(u32 self) {
    *(u32*)self = addr_D_00350c30();
    u32 s16 = self;

    u32 p = *(u32*)(self + 24);
    if (p != 0) {
        Fn_0031f968 fn = (Fn_0031f968)*(u32*)(*(u32*)p + 8);
        fn(p);
    }

    *(u32*)s16 = addr_D_00347f98();
}

void func_0031f9c0(u32 self) {
    *(u32*)self = addr_D_00350c30();
    u32 s16 = self;

    u32 p = *(u32*)(self + 24);
    if (p != 0) {
        Fn_0031f9c0 fn = (Fn_0031f9c0)*(u32*)(*(u32*)p + 8);
        fn(p);
    }

    *(u32*)s16 = addr_D_00347f98();
    func_00105110(s16);
}

void func_0031fec0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031ffc0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
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

void func_003202d8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
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

void func_00320368(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
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
    func_00105110(s18);
}

void func_00320968(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_003209e8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320af0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320d30(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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
    func_00105110(s18);
}

void func_00320da8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

void func_00320e20(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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
    func_00105110(s18);
}

void func_00320e98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00320f18(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320fa8(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32*)(self + 2824) = c2824;
    *(u32*)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32*)(s18 + 0) = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);
    func_001c0248(s18 + 2640);

    *(u32*)(s18 + 0) = addr_D_003503e0();
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

void func_003211c0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00321240(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321338(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_003521e0();
    func_001d5718(s16 + 2932);

    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);

    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_003213a8(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
}

void func_00321400(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_00321498(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
}

void func_003214f0(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_003215a8(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_003217b0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00321830(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321958(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_003219d8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321b48(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00321bc8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

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

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321de8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e028();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321de8 fn = (Fn_00321de8)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00321e60(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e028();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321e60_dtor fn = (Fn_00321e60_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00321e60_mgr fn2 = (Fn_00321e60_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00321ef8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e050();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321ef8 fn = (Fn_00321ef8)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00321f70(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e050();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321f70_dtor fn = (Fn_00321f70_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00321f70_mgr fn2 = (Fn_00321f70_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00322008(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e168();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2472;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322008 fn = (Fn_00322008)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00322080(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e168();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2472;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322080_dtor fn = (Fn_00322080_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322080_mgr fn2 = (Fn_00322080_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00322118(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e190();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2880;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322118_dtor fn = (Fn_00322118_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322118_mgr fn2 = (Fn_00322118_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_003221b0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e190();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2880;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_003221b0 fn = (Fn_003221b0)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00322908(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322908 fn = (Fn_00322908)*(u32*)(*(u32*)obj + 4);
    fn(obj, s16);
}

void func_00322a98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e320();

    if (s18 != (u32)-28) {
        u32 s16 = s18 + 1252;
        u32 s17 = s18 + 28;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322a98 fn = (Fn_00322a98)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_003229a0(u32 self) {
    u32 c0 = addr_D_0035e340();
    u32 c416 = addr_D_00347e80();
    *(u32*)(self + 416) = c416;
    *(u32*)self = c0;

    u32 s16 = self;
    func_002361d0(s16 + 448);

    u32 s17 = addr_D_00347f98();
    *(u32*)(s16 + 416) = s17;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = s17;
}

void func_00322a10(u32 self) {
    u32 c0 = addr_D_0035e340();
    u32 c416 = addr_D_00347e80();
    *(u32*)(self + 416) = c416;
    *(u32*)self = c0;

    u32 s16 = self;
    func_002361d0(s16 + 448);

    u32 s17 = addr_D_00347f98();
    *(u32*)(s16 + 416) = s17;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = s17;

    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322a10 fn = (Fn_00322a10)*(u32*)(*(u32*)obj + 4);
    fn(obj, s16);
}

void func_00322b10(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e320();

    if (s18 != (u32)-28) {
        u32 s16 = s18 + 1252;
        u32 s17 = s18 + 28;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322b10_dtor fn = (Fn_00322b10_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322b10_mgr fn2 = (Fn_00322b10_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00323b90(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323c30(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323cd0(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323d70(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323dd0(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_0035f490();
    func_002361d0(s0 + 416);
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();
}

void func_00323e28(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_0035f490();
    func_002361d0(s0 + 416);
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00324380(u32 self) {
    u32 s18 = self;
    s32 s23 = 3;
    s32 s19 = -1;
    s32 s30 = -1;

    do {
        u32 s16 = s18;
        s32 s17 = 1;
        do {
            *(u32*)s16 = addr_D_00347f98();
            func_0031a838(s16 + 12);
            *(u32*)s16 = addr_D_00347e60();
            func_00239700(s16 + 24);
            *(u32*)s16 = addr_D_00347e40();
            *(u32*)(s16 + 408) = 0;
            s16 += 436;
            --s17;
        } while (s17 != s19);

        --s23;
        s18 += 872;
    } while (s23 != s30);
}

void func_00324448(u32 self) {
    u32 s18 = self;
    s32 s23 = 9;
    s32 s19 = -1;
    s32 s30 = -1;

    do {
        u32 s16 = s18;
        s32 s17 = 1;
        do {
            *(u32*)s16 = addr_D_00347f98();
            func_0031a838(s16 + 12);
            *(u32*)s16 = addr_D_00347e60();
            func_00239700(s16 + 24);
            *(u32*)s16 = addr_D_00347e40();
            *(u32*)(s16 + 408) = 0;
            s16 += 436;
            --s17;
        } while (s17 != s19);

        --s23;
        s18 += 872;
    } while (s23 != s30);
}

void func_00324808(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_0034ee08();
    func_0019f9a8(s2 + 2568);
    func_001c0248(s2 + 2640);
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    func_0031e7f8(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00324898(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_0034ee08();
    func_0019f9a8(s2 + 2568);
    func_001c0248(s2 + 2640);
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    func_0031e7f8(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00324eb8(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00324f38(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

u32 func_00325040(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00325218(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00325298(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00325320(u32 a0, u32 a1) {
    u32 t7 = *(u32*)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32*)(a1 + 148);
        t5 = 0;
        *(u32*)a0 = t7n;
    } else {
        u32 t6 = *(u32*)(t7 + 148);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32*)(t6 + 148);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32*)(a1 + 148);
        *(u32*)(t5 + 148) = t7n;
    }

    u32 t7c = *(u32*)(a0 + 4);
    if (a1 == t7c) {
        *(u32*)(a0 + 4) = t5;
    }
    *(u32*)(a1 + 148) = 0;
}

void func_00325700(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00325780(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00325840(u32 a0, u32 a1) {
    u32 t7 = *(u32*)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32*)(a1 + 32);
        t5 = 0;
        *(u32*)a0 = t7n;
    } else {
        u32 t6 = *(u32*)(t7 + 32);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32*)(t6 + 32);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32*)(a1 + 32);
        *(u32*)(t5 + 32) = t7n;
    }

    u32 t7c = *(u32*)(a0 + 4);
    if (a1 == t7c) {
        *(u32*)(a0 + 4) = t5;
    }
    *(u32*)(a1 + 32) = 0;
}
u32 func_002677f0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    u16* p = func_002570e0(s0);
    func_0028fb28(0, p[9]);
    func_00257050(0, 0, 0);

    if (s0 == 1) {
        return func_0025f7f0(s1);
    }

    if (func_00257070(1) != s1) {
        func_00257050(2, 0, 0);
        func_00257050(1, s1, 0);
    }

    u32 v = func_00281140(D_0035f010, s1);
    func_0028fb68(1, v);
    return func_002678a8();
}
