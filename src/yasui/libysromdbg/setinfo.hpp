#ifndef KH2_SRC_YASUI_LIBYSROMDBG_SETINFO_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_SETINFO_HPP

#include "../../common/types.h"

class COLOR;
class RECT;
class SETINFO;

namespace YS {

    class SETINFO {
    public:
     void draw_func(RECT* a0, COLOR* a1);
     void Init(void);
     void Open(s32 a0);
     ~SETINFO();
    };

}  // namespace YS

#endif
