#pragma once

#include "../../common/types.h"

namespace kn {

class Friend;
class VecSet;
typedef int (*FriendCallback)(Friend*, int);

struct FriendLayout {
    char _pad0[2912];
    s32 personality;
    char _pad1[404];
    s32 toScript;
    FriendCallback callFromScript;
};

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

}  // namespace kn
