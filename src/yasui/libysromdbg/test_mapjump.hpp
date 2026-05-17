#ifndef KH2_SRC_YASUI_LIBYSROMDBG_TEST_MAPJUMP_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_TEST_MAPJUMP_HPP

#include "../../common/types.h"

class COLOR;
class RECT;
class TEST_MAPJUMP;
class WIDGET;

namespace YS {

    class TEST_MAPJUMP {
    public:
     TEST_MAPJUMP();
     void draw_func(RECT* a0, COLOR* a1);
     void Jump(void* a0);
     void Open(s32 a0);
     void Finalizer(WIDGET* a0);
     void Reset(void* a0);
     void Init(void);
     void Exec(void);
     ~TEST_MAPJUMP();
    };

}  // namespace YS

#endif
