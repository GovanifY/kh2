#pragma once

#include "../../common/types.h"

class ACTION_HANG;
class OBJ;
class PARTY;

namespace YS {

    class ACTION_HANG {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void control(OBJ* a0);
     void party_jump(OBJ* a0, bool a1);
     u64 Check(PARTY* a0);
     void ToFall(OBJ* a0);
     ~ACTION_HANG();
     ACTION_HANG();
    };

}  // namespace YS

