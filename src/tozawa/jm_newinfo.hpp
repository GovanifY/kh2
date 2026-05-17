#ifndef KH2_SRC_TOZAWA_JM_NEWINFO_HPP
#define KH2_SRC_TOZAWA_JM_NEWINFO_HPP

#include "types.h"

namespace Tz {

class JmNewInfo {
public:
    static void Exit();
    static u32 GetSram();
    static void CheckAll();
};

}  // namespace Tz

#endif
