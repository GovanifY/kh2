#include "../common/types.h"
#include "auto200_999_queue_decls.hpp"

void func_00101d68(void) {
    u32 s1 = 1000;
    func_00105a10();
    D_0032b91c = func_00102508((u32)&D_0037aa40, 0x00010000);
    func_0016f970();
    func_002f3610(1);
    func_002f49c0();
    func_00106490(0x00875b2f);
    func_001674c8();
    func_001385f8();
    func_0016fa58();
    func_00105b58();
    func_00102e40();
    func_00168f18();
    func_00101d50();
    func_00138620();
    func_001dcd50();
    func_00226978();
    func_00233580();
    func_0011b3e0();
    func_00102e18();
    func_00102bd8();
    func_00103480();
    func_00105d50();
    func_0023d260();
    func_00104080();
    func_00104560();
    func_002cb530();
    func_00105748((u32)&D_0032bb30);
    func_00102080((u32)&D_0032b9a0);

    while (1) {
        func_001029e8(D_0032b91c);
        u32 v = D_0032b920 + 1;
        D_0032b920 = v % s1;
    }
}

void func_00103a40(void) {
    u8* s0;

    if (func_00105300() == 0) {
        if (func_00103c90() == 0) {
            u32 t = D_0032ba24;
            if (t == 1 || t == 5 || t == 6) {
                if (D_003a6a50 != 10) {
                    func_0014df98();
                }
            }
        }
    }

    func_0023fb28();
    D_0032ba1c = func_001384c0();
    func_001ddc48();
    func_001e0328();

    if (func_00103c90() != 0) {
        func_00103ca0();
        func_00167ea8();
    }

    s0 = (u8*)&D_0032b968;
    if (*(u32*)(s0 + 28) == 0) {
        s0 = (u8*)&D_0032ba48;
        if (*(u32*)(s0 + 28) == 0) {
            return;
        }
    }

    func_0023d368();
    func_00167ea8();
    *(u32*)(s0 + 28) = 1;
}

void func_00104910(void) {
    D_0032bad8 = 1;
    func_001021f0();

    func_001cd168();

    u32 v0 = func_0014ac08();
    func_0014aa80(v0, 0, 0);

    v0 = func_0014abb8();
    func_0014aa80(v0, 0, 0);

    v0 = func_0014abc8();
    func_0014aa80(v0, 0, 0);

    v0 = func_0014abe8();
    func_0014aa80(v0, 0, 0);

    v0 = func_0014abf8();
    func_0014aa80(v0, 0, 0);

    v0 = func_0014abd8();
    func_0014aa80(v0, 0, 0);

    v0 = func_0014aba8();
    func_0014aa80(v0, 0, 0);

    v0 = func_001050c8();
    func_001de7d8(v0, D_0034ecec, D_0034ecf0);

    func_001e06b8();
    func_00149c40(*(u64*)&D_0034ecc0);
    func_00169210();
    func_00108068();
    func_00149cb8();
    func_00226a78();
    func_00136fa8();
    func_0013f0d0();
    func_001bb438();
}

void func_00105a20(void) {
    volatile u8 pad[64];

    func_002bd260(0);

    f32 f20 = 0.0f;
    func_002bd310(0);

    func_002ba220(0, 12288, 12288, 0, 0, 0);

    func_00106048();
    func_00105fc8();

    func_002bd788(0);
    func_002bd730(0, 0, 0, 0);
    func_002bd760(720);
    func_002bd7d8();

    func_002f8aa0(f20);
    func_002f87c0(f20);

    func_0016f448(0);
    func_002fd3d0(0, 0);

    func_00170b30(0);
    func_00170c00(0);
    func_00170320(0);

    func_00102f70();
    func_00102f80();
}

void func_00108ae0(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7) {
    func_00109008();
    func_00134408();

    if (((a1 & 1u) & 0xffu) != 0) {
        func_00134428(76, a2);
        a0[0] = a2;
    }

    if ((a1 & 2u) != 0) {
        func_00134428(78, a3);
        a0[1] = a3;
    }

    if ((a1 & 4u) != 0) {
        func_00134428(71, a4);
        a0[2] = a4;
    }

    if ((a1 & 8u) != 0) {
        func_00134428(66, a5);
        a0[3] = a5;
    }

    if ((a1 & 0x10u) != 0) {
        func_00134428(61, a6);
        a0[4] = a6;
    }

    if ((a1 & 0x20u) != 0) {
        func_00134428(1, a7);
        a0[5] = a7;
    }

    func_00134450(1);
    *(u8*)((u8*)a0 + 48) = 0;
}

void func_00108c00(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7) {
    func_00109008();
    func_00134408();

    if (((a1 & 1u) & 0xffu) != 0) {
        if (a2 != a0[0]) {
            func_00134428(76, a2);
            a0[0] = a2;
        }
    }

    if ((a1 & 2u) != 0) {
        if (a3 != a0[1]) {
            func_00134428(78, a3);
            a0[1] = a3;
        }
    }

    if ((a1 & 4u) != 0) {
        if (a4 != a0[2]) {
            func_00134428(71, a4);
            a0[2] = a4;
        }
    }

    if ((a1 & 8u) != 0) {
        if (a5 != a0[3]) {
            func_00134428(66, a5);
            a0[3] = a5;
        }
    }

    if ((a1 & 0x10u) != 0) {
        if (a6 != a0[4]) {
            func_00134428(61, a6);
            a0[4] = a6;
        }
    }

    if ((a1 & 0x20u) != 0) {
        if (a7 != a0[5]) {
            func_00134428(1, a7);
            a0[5] = a7;
        }
    }

    func_00134450(1);
    *(u8*)((u8*)a0 + 48) = 0;
}

u32 func_0010f340(u32 a0, u32 a1, u32 a2, f32 a3) {
    (void)a0;
    u32 flags = *(u32*)(a2 + 12);

    if ((flags & 1u) == 0) {
        f32 f1 = *(f32*)(a1 + 44);
        if (*(f32*)(a2 + 20) + a3 < f1) {
            return 0;
        }
        if (f1 < (*(f32*)(a2 + 16) - a3)) {
            return 0;
        }
    }

    if ((flags & 2u) == 0) {
        u32 ok = 1;
        if ((flags & 8u) != 0) {
            f32 f1 = *(f32*)(a1 + 44);
            if (*(f32*)(a2 + 48) + a3 < f1) goto clear_ok;
            if (f1 < (*(f32*)(a2 + 44) - a3)) goto clear_ok;
            goto after_ok_check;
clear_ok:
            ok = 0;
after_ok_check:
            ;
        }

        if (ok != 0) {
            f32 f1 = *(f32*)(a1 + 0);
            if (f1 < (-*(f32*)(a2 + 28) - a3)) {
                return 0;
            }
            if ((a3 - *(f32*)(a2 + 24)) < f1) {
                return 0;
            }
        }
    }

    {
        f32 f1 = *(f32*)(a1 + 44);
        if (!(f1 < *(f32*)(a2 + 52))) {
            return 1;
        }
        f32 v = func_002f8870(*(f32*)(a1 + 0));
        if (*(f32*)(a2 + 56) < v) {
            return 0;
        }
    }
    return 1;
}

u32 func_001e3660(u32 a0, s32 a1) {
    if (a1 <= 0) {
        return a0;
    }

    u32 v0 = a0;
    do {
        u32 t7 = *(u32*)v0;
        a1 -= 1;
        t7 <<= 2;
        v0 += 4;
        v0 += t7;
    } while (a1 != 0);
    return v0;
}
