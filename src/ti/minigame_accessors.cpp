#include "minigame_accessors.hpp"
#include "../taito/mg_hachimitsu_po.hpp"

namespace Ti {

void MGHachimitsuGopher::set_balloon(MGObj* v) {
    reinterpret_cast<MGHachimitsuGopherLayout*>(this)->balloon = v;
}
u8 MGHachimitsuPo::is_separate_blow() {
    return reinterpret_cast<MGHachimitsuPoLayout*>(this)->separate_blow;
}
}  // namespace Ti
