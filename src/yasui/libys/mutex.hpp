#ifndef KH2_SRC_YASUI_LIBYS_MUTEX_HPP
#define KH2_SRC_YASUI_LIBYS_MUTEX_HPP

#include "../../common/types.h"

namespace YS {

    class MUTEX {
    public:
        void lock(s32);
        u32 is_lock(s32);
    };

}  // namespace YS

#endif
