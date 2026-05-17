#ifndef KH2_SRC_YASUI_LIBYS_EVENTSKIP_HPP
#define KH2_SRC_YASUI_LIBYS_EVENTSKIP_HPP

#include "../../common/types.h"

class AREA;
class JUMPER;

namespace YS {

    class EVENT_SKIP {
    public:
     void ResetSkipFlag(void);
     void FieldInit(void);
     u64 IsSkip(AREA* a0, JUMPER* a1);
     void SetSkipFlag(void);
    };

}  // namespace YS

#endif
