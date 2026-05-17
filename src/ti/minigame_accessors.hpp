#pragma once

#include "../common/types.h"

namespace Ti {

class MGObj;

struct MGHachimitsuGopherLayout {
    char _pad0[2836];
    MGObj* balloon;
};

struct MGHachimitsuPoLayout {
    char _pad0[3008];
    u8 separate_blow;
};

class MGHachimitsuGopher {
public:
    void set_balloon(MGObj* v);
};

}  // namespace Ti
