#ifndef KH2_SRC_YASUI_LIBYS_LANDING_HPP
#define KH2_SRC_YASUI_LIBYS_LANDING_HPP

#include "../../common/types.h"

namespace YS {

    class LANDING {
    public:
     u32 get_imd(void);
     void Init(void);
     void Ensure(void);
     u32 GetList(void);
     s32 GetSqd(void);
     void ReadRequest(void);
    };

}  // namespace YS

#endif
