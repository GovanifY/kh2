#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_ACT_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_ACT_HPP

#include "../../common/types.h"

class WIDGET;

namespace YS {

    class TEST_ACT {
    public:
     void Open(s32 a0);
     void Close(WIDGET* a0);
     void Init(void);
    };

}  // namespace YS

#endif
