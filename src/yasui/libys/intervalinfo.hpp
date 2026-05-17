#ifndef KH2_SRC_YASUI_LIBYS_INTERVALINFO_HPP
#define KH2_SRC_YASUI_LIBYS_INTERVALINFO_HPP

#include "../../common/types.h"

namespace YS {

    class INTERVAL_INFO {
    public:
     void push(s32 a0, f32 a1);
     void start(s32 a0, f32 a1);
     void stop(void);
     void exec(void);
    };

}  // namespace YS

#endif
