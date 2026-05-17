#ifndef KH2_SRC_TOZAWA_SUB_MENU_HPP
#define KH2_SRC_TOZAWA_SUB_MENU_HPP

#include "types.h"

namespace Tz {

class SubMenu {
public:
    static u32 Exit(s32);
    static u32 GetCallSignal();
    static void SetLeadData(const char*);
};

}  // namespace Tz

#endif
