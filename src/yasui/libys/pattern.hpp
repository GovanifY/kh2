#ifndef KH2_SRC_YASUI_LIBYS_PATTERN_HPP
#define KH2_SRC_YASUI_LIBYS_PATTERN_HPP

#include "../../common/types.h"

class BTLOBJ;
class DAMAGE;

namespace YS {

    class PATTERN {
    public:
     void Init(void* a0);
     void Convert(u32 a0, DAMAGE* a1, BTLOBJ* a2);
    };

}  // namespace YS

#endif
