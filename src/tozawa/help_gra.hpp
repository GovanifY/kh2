#pragma once

#include "../common/types.h"

namespace Tz {

class HelpGra {
public:
    void update(void);
    void draw(void);
    u32 isExist();
    void create(void* a0, void* a1, s32 a2);
    HelpGra();
    ~HelpGra();
};

}  // namespace Tz
