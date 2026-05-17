#ifndef KH2_SRC_YASUI_LIBYSROMDBG_TEST_MUNNY_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_TEST_MUNNY_HPP

#include "../../common/types.h"

namespace YS {

class TEST_MUNNY {
public:
    void Open(s32 a0);
    void UpdateCallback(s32 a0);
    void Init(void);
};

}  // namespace YS

#endif
