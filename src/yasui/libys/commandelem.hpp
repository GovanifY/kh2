#pragma once

#include "../../common/types.h"

class OBJ;
class PLAYER;
class TARGET;

namespace YS {

    class COMMAND_ELEM {
    public:
     u64 can_decide(OBJ* a0, TARGET* a1);
     bool is_menu(void);
     u64 is_invalid(OBJ* a0);
     u64 can_use(PLAYER* a0);
     u64 is_disable_form(s32 a0);
     u16 get_use_count(void);
     void SysInit(void* a0);
     void GetForm(s32 a0);
    };

}  // namespace YS

