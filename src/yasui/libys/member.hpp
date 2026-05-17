#ifndef KH2_SRC_YASUI_LIBYS_MEMBER_HPP
#define KH2_SRC_YASUI_LIBYS_MEMBER_HPP

#include "../../common/types.h"

namespace YS {

    class MEMBER {
    public:
        static u32 Get(s32);
        u32 is_exist(s32) const;
    };

}  // namespace YS

#endif
