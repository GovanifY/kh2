#ifndef KH2_SRC_LIBYW_MENULIST_HPP
#define KH2_SRC_LIBYW_MENULIST_HPP

#include "types.h"

class COLOR;
class ELEM;
class EVENT;
class FuncDef76;
class RECT;

namespace YW {

class MENULIST {
public:
    MENULIST(MENULIST* a0, s32 a1, s32 a2, ELEM* a3, FuncDef76* a4, void* a5);
    void idle_func();
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    ~MENULIST();
};

}  // namespace YW

#endif
