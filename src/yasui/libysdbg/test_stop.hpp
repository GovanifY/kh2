#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_STOP_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_STOP_HPP

#include "types.h"

namespace YS {

class TEST_STOP {
public:
    void Init(void);
    void StartCallback(s32 a0);
    void EndCallback(s32 a0);
};

}  // namespace YS

#endif
