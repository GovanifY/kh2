#ifndef KH2_SRC_LIBYW_TEXT_HPP
#define KH2_SRC_LIBYW_TEXT_HPP

#include "types.h"

class ...;
class COLOR;
class RECT;
class TEXT;

namespace YW {

class TEXT {
public:
    void clear(void);
    TEXT(TEXT* a0, s32 a1, s32 a2, s32 a3, u32 a4);
    ~TEXT();
    void printf(char* a0, ...);
    void idle_func(void);
    void draw_func(RECT* a0, COLOR* a1);
};

}  // namespace YW

#endif
