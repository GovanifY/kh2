#include "types.h"

namespace YS {
class COMMAND_SLOT {
public:
    void clear();
    bool is_exist();
};

class COMMAND_MENU {
public:
    void clear();
    void reset_cursor();
};

struct COMMAND_SLOT_Layout {
    char _pad0[2];
    u16 value;
};

struct COMMAND_MENU_Layout {
    char _pad0[8];
    s32 value;
    char _pad1[96];
    s32 cursor0;
    s32 cursor1;
};

void COMMAND_SLOT::clear() {
    u32 r4 = (u32)this, r15;
    r15 = (u32)((s32)0u + 5);
    *(u32*)(r4 + 8) = 0u;
    *(volatile u8*)(r4 + 5) = (u8)r15;
    *(volatile u16*)(r4 + 0) = (u16)0u;
    *(volatile u16*)(r4 + 2) = (u16)0u;
    *(volatile u8*)(r4 + 4) = (u8)0u;
    *(volatile u8*)(r4 + 6) = (u8)0u;
}
bool COMMAND_SLOT::is_exist() { return reinterpret_cast<COMMAND_SLOT_Layout*>(this)->value != 0; }
void COMMAND_MENU::clear() { reinterpret_cast<COMMAND_MENU_Layout*>(this)->value = 0; }
void COMMAND_MENU::reset_cursor() {
    COMMAND_MENU_Layout* m = reinterpret_cast<COMMAND_MENU_Layout*>(this);
    m->cursor0 = 0;
    m->cursor1 = -1;
}
}  // namespace YS
