#include "types.h"

namespace worldmap {

class RootWindow {
public:
    static void* get();
};

void* RootWindow::get() {
    u32 b = (0x0036u << 16);
    return reinterpret_cast<void*>(*(u32*)((u32)b + (6552)));
}

}  // namespace worldmap
