#pragma once

#include "../common/types.h"

namespace ryj {

struct EFFECT_DATA_Layout {
    void* value;
};

    class EFFECT_DATA {
    public:
        void set(void* v);
    };

}  // namespace ryj
