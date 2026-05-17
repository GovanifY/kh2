#ifndef KH2_SRC_TOZAWA_CMENU_EQUIP_HPP
#define KH2_SRC_TOZAWA_CMENU_EQUIP_HPP

#include "../common/types.h"

namespace Tz {

class CmEquip {
public:
    static void* GetFormMsgTbl();
    static void FadeOutAll();
    static void LeaveAll();
};

}  // namespace Tz

#endif
