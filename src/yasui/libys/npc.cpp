#include "npc.hpp"

namespace YS {


struct NPCLayout {
    char _pad0[2660];
    u8 rtn_change_dir;
};

u8 NPC::is_rtn_change_dir() {
    return reinterpret_cast<const NPCLayout*>(this)->rtn_change_dir;
}
}  // namespace YS
