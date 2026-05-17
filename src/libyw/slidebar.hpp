#ifndef KH2_SRC_LIBYW_SLIDEBAR_HPP
#define KH2_SRC_LIBYW_SLIDEBAR_HPP

#include "../common/types.h"

class COLOR;
class EVENT;
class FuncDef25;
class RECT;

namespace YW {

class SLIDEBAR {
public:
    SLIDEBAR(SLIDEBAR* a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 a5, f32 a6, f32 a7, FuncDef25* a8);
    void set_value(f32 a0);
    void idle_func();
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    ~SLIDEBAR();
};

}  // namespace YW

#endif
