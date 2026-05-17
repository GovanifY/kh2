#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_WATCH_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_WATCH_HPP

#include "types.h"

namespace YS {

class TEST_WATCH {
public:
    void Select(s32 a0);
    void Init(void);
    void Exec(void);
};

}  // namespace YS

#endif
