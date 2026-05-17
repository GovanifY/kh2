#ifndef KH2_SRC_YASUI_LIBYS_EPISODE_HPP
#define KH2_SRC_YASUI_LIBYS_EPISODE_HPP

#include "../../common/types.h"

namespace YS {

    class EPISODE {
    public:
     bool is_set(void);
     bool is_new(void);
     void Init(void* a0);
     void SetFlag(s32 a0);
     void ResetNewFlag(s32 a0);
    };

}  // namespace YS

#endif
