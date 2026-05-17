#ifndef KH2_SRC_YASUI_LIBYSROMDBG_ROOTWINDOW_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_ROOTWINDOW_HPP

#include "../../common/types.h"

class COLOR;
class EVENT;
class RECT;
class ROOTWINDOW;

namespace YS {

    class ROOTWINDOW {
    public:
     void focus_func(EVENT a0, s32 a1, s32 a2);
     void draw_func(RECT* a0, COLOR* a1);
     ~ROOTWINDOW();
    };

}  // namespace YS

#endif
