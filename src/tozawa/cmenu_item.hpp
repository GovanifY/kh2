#ifndef KH2_SRC_TOZAWA_CMENU_ITEM_HPP
#define KH2_SRC_TOZAWA_CMENU_ITEM_HPP

#include "scroll_bar.hpp"
#include "types.h"

namespace Tz {

class CmItem {
public:
    static void FadeOutAll();
    static void LeaveAll();
    static u32 isPadHelpVisible();
    static void FadeOutTop();
    static void FadeOutCategory();
    static void FadeOutWarn();
    static void FadeOutStock();
    static void FadeOutHelp();
    static void LeaveTop();
    static void LeaveCategory();
    static void LeaveStock();
    static void LeaveWarn();
    static void LeaveHelp();
    static void LeavePopup();
};

}  // namespace Tz

#endif
