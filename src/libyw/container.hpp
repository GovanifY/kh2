#ifndef KH2_SRC_LIBYW_CONTAINER_HPP
#define KH2_SRC_LIBYW_CONTAINER_HPP

#include "types.h"

class WIDGET;

namespace YW {

class CONTAINER {
public:
    CONTAINER(CONTAINER* a0, s32 a1, s32 a2, s32 a3, s32 a4);
    ~CONTAINER();
    void link(WIDGET* a0);
    void unlink(WIDGET* a0);
    void get_icon_pos(s32 a0, s32 a1);
    void idle_func();
};

}  // namespace YW

#endif
