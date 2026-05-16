#include "types.h"

extern u32 Friend_getPartner_raw(u32) asm("_Z16wtarget_00111d98jjjj");
extern void Friend_followMove(void*, void const*) asm("_ZN2kn6Friend10followMoveEPKNS_6VecSetE");
extern void ObjObserver_Create(void*) asm("_ZN2kn11ObjObserver6CreateEPPS0_");

namespace kn {
class Friend;
class VecSet;
typedef int (*FriendCallback)(Friend*, int);
extern u32 D_00341708 asm("D_00341708");

class Friend {
public:
    u32 getObjObserver();
    s32 getPersonality();
    s32 getToScript();
    void followEnemy();
    u32 getPartner();
    static u32 getPartyChara(s32);
    void setCallFromScript(FriendCallback v);
};

struct FriendLayout {
    char _pad0[2912];
    s32 personality;
    char _pad1[404];
    s32 toScript;
    FriendCallback callFromScript;
};

u32 Friend::getObjObserver() {
    u32 r2 = *(volatile u32*)((u32)this + 2904);
    if (r2 == 0u) {
        ObjObserver_Create((void*)((u32)this + 2904));
        r2 = *(volatile u32*)((u32)this + 2904);
    }
    return r2;
}

s32 Friend::getPersonality() { return reinterpret_cast<FriendLayout*>(this)->personality; }
s32 Friend::getToScript() { return reinterpret_cast<FriendLayout*>(this)->toScript; }
void Friend::followEnemy() {
    Friend_followMove(this, reinterpret_cast<u8 const*>(this) + 2992u);
}
u32 Friend::getPartner() { return Friend_getPartner_raw((u32)this); }
u32 Friend::getPartyChara(s32 index) {
    return *(u32*)((u32)&D_00341708 + ((u32)index << 2));
}
void Friend::setCallFromScript(FriendCallback v) {
    reinterpret_cast<FriendLayout*>(this)->callFromScript = v;
}
}  // namespace kn
