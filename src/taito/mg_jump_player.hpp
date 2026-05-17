#pragma once

#include "../common/types.h"

class FVector;
class MGJumpPlayer;
class OBJENTRY;
class PAD;

namespace Ti {

    class MGJumpPlayer {
    public:
     void _OVR_initialize(void);
     void _OVR_exec(void);
     MGJumpPlayer(MGJumpPlayer* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
     void ready_jump_reaction(void);
    };

}  // namespace Ti

