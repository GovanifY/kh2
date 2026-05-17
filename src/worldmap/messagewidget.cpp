#include "messagewidget.hpp"

namespace worldmap {

u32 MessageWidget::isEnd() {
    u32 p = *(u32*)((u32)this + 36);
    u32 v = *(u32*)((u32)p + 112);
    v ^= 0x7u;
    return (v < 1u);
}

}  // namespace worldmap
