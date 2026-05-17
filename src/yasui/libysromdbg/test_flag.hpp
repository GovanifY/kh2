#ifndef KH2_SRC_YASUI_LIBYSROMDBG_TEST_FLAG_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_TEST_FLAG_HPP

#include "../../common/types.h"

class COLOR;
class EVENT;
class RECT;
class TEST_FLAG;

namespace YS {

    class TEST_FLAG {
    public:
     TEST_FLAG(TEST_FLAG* a0, char* a1);
     ~TEST_FLAG();
     void idle_func(void);
     void focus_func(EVENT a0, s32 a1, s32 a2);
     void draw_func(RECT* a0, COLOR* a1);
     s32 reset_flag(s32 a0);
    };

}  // namespace YS

#endif
