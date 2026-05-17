#ifndef KH2_SRC_YASUI_LIBYS_BATTLELEVEL_HPP
#define KH2_SRC_YASUI_LIBYS_BATTLELEVEL_HPP

#include "../../common/types.h"

namespace YS {

    class BATTLELEVEL {
    public:
     void calc(void);
     void Init(void* a0);
     void AreaInit(s32 a0);
     s32 GetCurrent(void);
     void ProgressCallback(s32 a0);
    };

}  // namespace YS

#endif
