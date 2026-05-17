#ifndef KH2_SRC_YASUI_LIBYS_BONUSLEVEL_HPP
#define KH2_SRC_YASUI_LIBYS_BONUSLEVEL_HPP

#include "../../common/types.h"

class SHEET;

namespace YS {

    class BONUSLEVEL {
    public:
     void up(SHEET* a0);
     void Init(void* a0);
     bool IsUp(s32 a0);
     s32 Up(s32 a0);
    };

}  // namespace YS

#endif
