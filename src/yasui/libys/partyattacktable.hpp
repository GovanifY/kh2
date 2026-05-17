#ifndef KH2_SRC_YASUI_LIBYS_PARTYATTACKTABLE_HPP
#define KH2_SRC_YASUI_LIBYS_PARTYATTACKTABLE_HPP

#include "../../common/types.h"

namespace YS {

    class PARTYATTACK_TABLE {
    public:
     s64 get_num(s32 a0);
     void Init(void* a0);
     s32 Get(s32 a0);
    };

}  // namespace YS

#endif
