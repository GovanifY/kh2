#ifndef KH2_SRC_YASUI_LIBYS_PREF_HPP
#define KH2_SRC_YASUI_LIBYS_PREF_HPP

#include "../../common/types.h"

namespace YS {

    class PREF {
    public:
     s32 Party(s32 a0);
     s32 Get(u32 a0, char* a1);
     void Init(void* a0);
     s32 Player(s32 a0);
     s32 FormAbility(s32 a0);
     s32 Magic(s32 a0);
    };

}  // namespace YS

#endif
