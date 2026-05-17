#ifndef KH2_SRC_YASUI_LIBYSROMDBG_TEST_PROGRESS_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_TEST_PROGRESS_HPP

#include "../../common/types.h"

namespace YS {

class TEST_PROGRESS {
public:
    void set_flag(s32 a0);
    void reset_flag(s32 a0);
    void check_flag(s32 a0);
    void reset(void);
    void Reset(void* a0);
    void Open(s32 a0);
    void Init(void);
    ~TEST_PROGRESS();
};

}  // namespace YS

#endif
