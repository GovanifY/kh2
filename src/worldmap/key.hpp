#pragma once

#include "../common/types.h"

namespace worldmap {

    class Key {
    public:
     s32 getOpenNum(void);
     s32 getCloseNum(void);
     void initialize(void* a0);
    };

}  // namespace worldmap

