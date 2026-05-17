#include "npc.hpp"

namespace YS {


u8 NPC::is_rtn_change_dir() {
    return reinterpret_cast<const NPCLayout*>(this)->rtn_change_dir;
}
}  // namespace YS
