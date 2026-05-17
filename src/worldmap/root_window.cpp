#include "rootwindow.hpp"

namespace worldmap {

void* RootWindow::get() {
    u32 b = (0x0036u << 16);
    return reinterpret_cast<void*>(*(u32*)((u32)b + (6552)));
}

}  // namespace worldmap
