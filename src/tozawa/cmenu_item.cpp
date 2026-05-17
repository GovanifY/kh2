#include "cmenu_item.hpp"
#include "cmenu_slbase.hpp"
#include "cmenu_top.hpp"

namespace Tz {

void CmItem::FadeOutAll() {
    u32 v0 = (u32)MenuBase::GetMode();
    if (v0 != 1 && v0 != 10 && v0 != 11 && v0 != 12 && v0 != 13 && v0 != 14) {
        return;
    }
    FadeOutTop();
    FadeOutCategory();
    ScrollBar::FadeOut();
    FadeOutWarn();
    FadeOutStock();
    FadeOutHelp();
    if (isPadHelpVisible() != 0) {
        CmTop::FadeOutPadHelp();
    }
}

void CmItem::LeaveAll() {
    u32 v0 = (u32)MenuBase::GetMode();
    if (v0 != 1 && v0 != 10 && v0 != 11 && v0 != 12 && v0 != 13 && v0 != 14) {
        return;
    }
    LeaveTop();
    LeaveCategory();
    LeaveStock();
    LeaveWarn();
    LeaveHelp();
    LeavePopup();
    CmTop::LeavePadHelp();
}

}  // namespace Tz
