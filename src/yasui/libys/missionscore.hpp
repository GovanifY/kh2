#pragma once

#include "../../common/types.h"

class COMMAND_ELEM;
class MISSION_SCORE;
class PARTYATTACK;

namespace YS {

    class MISSION_SCORE {
    public:
     MISSION_SCORE();
     void open(s32 a0, s32 a1, s32 a2);
     void activate(void);
     void exec_command(COMMAND_ELEM* a0);
     void exec_partyattack(PARTYATTACK* a0);
     void add_time_bonus(void);
     s32 reduce_exp(void);
     ~MISSION_SCORE();
    };

}  // namespace YS

