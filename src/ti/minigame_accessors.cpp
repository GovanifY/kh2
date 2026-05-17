#include "minigame_accessors.hpp"
#include "../taito/mg_hachimitsu_po.hpp"

namespace Ti {

struct MGHachimitsuGopherLayout {
    char _pad0[2836];
    MGObj* balloon;
};

struct MGHachimitsuPoLayout {
    char _pad0[3008];
    u8 separate_blow;
};

void MGHachimitsuGopher::set_balloon(MGObj* v) {
    reinterpret_cast<MGHachimitsuGopherLayout*>(this)->balloon = v;
}
u8 MGHachimitsuPo::is_separate_blow() {
    return reinterpret_cast<MGHachimitsuPoLayout*>(this)->separate_blow;
}
}  // namespace Ti
