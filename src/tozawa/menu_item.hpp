#pragma once

#include "layout.hpp"
#include "../common/types.h"

class ALLOCATOR;

namespace YI {
class IMAGE;
}

namespace Tz {

class MenuItem {
public:
 void destroy(void);
 void update(void);
 void draw(void);
 s32 start(s32 a0, s32 a1, s32 a2, Layout* a3, s32 a4, s32 a5, s32 a6);
 s32 start(void* a0, YI::IMAGE* a1, s32 a2, s32 a3, s32 a4);
 void init(ALLOCATOR* a0);
 void exit(void);
 ~MenuItem();
};

} // namespace Tz

