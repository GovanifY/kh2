#pragma once

#include "../../common/types.h"

class ACTION_CHICKENLITTLE_FPS;
class FVector;
class OBJ;

namespace kn {

    class ACTION_CHICKENLITTLE_FPS {
    public:
     void jump(OBJ* a0, FVector* a1);
     void jump_height(OBJ* a0, f32 a1);
     void party_jump(OBJ* a0, bool a1);
     ~ACTION_CHICKENLITTLE_FPS();
    };

}  // namespace kn

