#ifndef KH2_SRC_TOZAWA_JM_REPORT_HPP
#define KH2_SRC_TOZAWA_JM_REPORT_HPP

#include "../common/types.h"

namespace Tz {

class Select;

class JmReport {
public:
    static void DrawUpdate(Select*, s32, s32);
    static u32 GetData(u32);
    static u32 GetIndex(u32);
    static void DrawMessage(u32, u32);
};

}  // namespace Tz

#endif
