#ifndef KH2_SRC_YASUI_LIBYS_SOUNDINFO_HPP
#define KH2_SRC_YASUI_LIBYS_SOUNDINFO_HPP

#include "../../common/types.h"

class AREA;

namespace YS {

    class SOUNDINFO {
    public:
     void Init(void);
     void SetArea(AREA* a0);
     u32 Get(void);
    };

}  // namespace YS

#endif
