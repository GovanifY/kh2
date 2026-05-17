#include "./types.h"

namespace MENU {

u32 getType() {
    u32 b = (0x003au << 16);
    return (u32)(*(u32*)((u32)b + 27216));
}

}  // namespace MENU
