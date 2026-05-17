#ifndef KH2_SRC_YASUI_LIBYS_SORA_HPP
#define KH2_SRC_YASUI_LIBYS_SORA_HPP

#include "../../common/types.h"

namespace YS {

    class SORA {
    public:
        static u32 Get();
        static u32 GetEntryId(s32);
        void set_skateboard_mode(s32 v);
    };

}  // namespace YS

#endif
