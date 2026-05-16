#include "types.h"

namespace dk {

extern u32 D_00348638 asm("D_00348638");
extern "C" u32 wtarget_0013dbe0(u32, u32, u32, u32) asm("_Z16wtarget_0013dbe0jjjj");

class GAUGE {
public:
    void init();
};

class GAUGE_DRAW {
public:
    static void* getImage();
    static u32 getFriend1();
    static void checkAlertOff();
};

class GAUGE_PARTY {
public:
    u32 getGroup();
    u32 isAlertStart();
    u32 isAlertEnd();
};

u32 GAUGE_init_raw(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk5GAUGE4initEv");
u32 GAUGE_init_raw(u32 a0, u32 a1, u32 a2, u32 a3) {
    return wtarget_0013dbe0((u32)&D_00348638, a1, a2, a3);
}

extern u32 D_003485e8 asm("D_003485e8");
extern u32 D_003485f0 asm("D_003485f0");

void* GAUGE_DRAW::getImage() {
    u32 p = D_003485e8;
    return (void*)((s32)p + 32);
}

u32 GAUGE_DRAW::getFriend1() { return D_003485f0; }

extern u8 D_003485ec asm("D_003485ec");
extern "C" void func_00157880(u32);

void GAUGE_DRAW::checkAlertOff() {
    u32 t6 = *(u32*)((u32)&D_003485ec + 0);
    if (t6 != 0u) {
        func_00157880(t6);
    }
}

u32 GAUGE_PARTY::getGroup() {
    u32 v = *(u32*)((u32)this + 44) + *(u32*)((u32)this + 48);
    return (u32)((s32)v + 3);
}

u32 GAUGE_PARTY::isAlertStart() {
    u32 t4 = *(u32*)((u8*)this + 28);
    u32 v0 = 0;
    if (t4 != 1) {
        if (*(u32*)((u8*)this + 24) == 1) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}

u32 GAUGE_PARTY::isAlertEnd() {
    u32 t4 = *(u32*)((u8*)this + 28);
    u32 v0 = 0;
    if (t4 == 1) {
        if (*(u32*)((u8*)this + 24) != t4) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}

}  // namespace dk
