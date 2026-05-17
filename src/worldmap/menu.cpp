#include "menu.hpp"

namespace MENU {
void DestoryAllocator();
}

namespace Tz {
namespace CampMenu {
u32 StartJiminy(s32, s32);
}
namespace Jiminy {
void WMExit();
}
namespace MenuCursor {
void Exit();
}
namespace MenuItem {
void update();
}
namespace Select {
void End();
}
}

namespace YS {
namespace CACHE_BUFF {
void FixFree(void*);
}
}

namespace worldmap {
extern "C" u32 func_002764b0(u32);

void Menu::toJiminy(s32 index) {
    if (index == -1) {
        Tz::CampMenu::StartJiminy(0, -1);
    } else {
        Tz::CampMenu::StartJiminy(0, (s32)func_002764b0((u32)index));
    }
}

void Menu::exit() {
    Tz::Jiminy::WMExit();
    Tz::MenuCursor::Exit();
    Tz::MenuItem::update();
    Tz::Select::End();
    MENU::DestoryAllocator();
    u32* global = reinterpret_cast<u32*>(0x360000);
    u32 ptr = global[7176 / 4];
    YS::CACHE_BUFF::FixFree(reinterpret_cast<void*>(ptr));
    global[7176 / 4] = 0;
}
}  // namespace worldmap
