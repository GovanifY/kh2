#ifndef KH2_SRC_LIBYW_BUTTON_HPP
#define KH2_SRC_LIBYW_BUTTON_HPP

#include "../common/types.h"

class COLOR;
class EVENT;
class FuncDef23;
class RECT;

namespace YW {

class BUTTON {
public:
    BUTTON(BUTTON* a0, char* a1, s32 a2, s32 a3, s32 a4, s32 a5, FuncDef23* a6, void* a7);
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    ~BUTTON();
};

}  // namespace YW

#endif
