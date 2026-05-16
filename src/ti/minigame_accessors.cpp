#include "types.h"

namespace Ti {
class MGObj;

class MGHachimitsuGopher {
public:
    void set_balloon(MGObj* v);
};

class MGHachimitsuPo {
public:
    u8 is_separate_blow();
};

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
