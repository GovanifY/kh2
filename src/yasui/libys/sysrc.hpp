#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class CODE;
class LIBRETTO;
class PLAYER;
class SYSRC;
class TARGET;

namespace YS {

    class SYSRC {
    public:
     void CheckThread(TASK* a0);
     void TalkThread(TASK* a0);
     u64 CheckCallback(CODE* a0, LIBRETTO* a1);
     u64 TalkCallback(CODE* a0, LIBRETTO* a1);
     ~SYSRC();
     void check(PLAYER* a0, TARGET* a1);
     void talk(PLAYER* a0, TARGET* a1);
    };

}  // namespace YS

