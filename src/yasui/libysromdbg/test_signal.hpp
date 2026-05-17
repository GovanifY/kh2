#ifndef KH2_SRC_YASUI_LIBYSROMDBG_TEST_SIGNAL_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_TEST_SIGNAL_HPP

#include "types.h"

namespace YS {

class COLOR;
class EVENT;
class RECT;

class TEST_SIGNAL {
public:
    TEST_SIGNAL();
    void idle_func(void);
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    void Open(s32 a0);
    void ChangePage(s32 a0, void* a1);
    void Init(void);
    ~TEST_SIGNAL();
};

}  // namespace YS

#endif
