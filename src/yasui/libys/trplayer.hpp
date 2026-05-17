#pragma once

#include "../../common/types.h"

class ATTACK;
class BTLOBJ;
class COMMAND_ELEM;
class DAMAGE;
class FVector;
class OBJENTRY;
class PAD;
class TRPLAYER;

namespace YS {

    class TRPLAYER {
    public:
     void _OVR_exec(void);
     void _OVR_exec_command_player(COMMAND_ELEM* a0);
     TRPLAYER(TRPLAYER* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
     void ExecDamageReaction(BTLOBJ* a0, DAMAGE* a1);
     void ExecReflect(BTLOBJ* a0, ATTACK* a1, ATTACK* a2);
    };

}  // namespace YS

