#ifndef KH2_SRC_YASUI_LIBYSDBG_WIDGET_FLOATVALUE_HPP
#define KH2_SRC_YASUI_LIBYSDBG_WIDGET_FLOATVALUE_HPP

#include "../../common/types.h"

namespace YS {

class COLOR;
class RECT;

class WIDGET_FLOAT_VALUE {
public:
    WIDGET_FLOAT_VALUE(WIDGET_FLOAT_VALUE* a0, s32 a1, s32 a2, s32 a3, s32 a4, float* a5, f32 a6, f32 a7, f32 a8,
                       char* a9, char* a10, u32 a11);
    void draw_func(RECT* a0, COLOR* a1);
    ~WIDGET_FLOAT_VALUE();
};

}  // namespace YS

#endif
