#pragma once

#include "../../common/types.h"

namespace kn {

class Friend;
class VecSet;
typedef int (*FriendCallback)(Friend*, int);

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

