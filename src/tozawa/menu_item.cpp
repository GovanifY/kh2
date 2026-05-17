#include "layout.hpp"
#include "types.h"


namespace Tz {

} // namespace Tz

class ALLOCATOR;
class IMAGE;
class MenuItem;

class MenuItem {
public:
 void destroy(void);
 void update(void);
 void draw(void);
 s32 start(s32 a0, s32 a1, s32 a2, Layout* a3, s32 a4, s32 a5, s32 a6);
 s32 start(void* a0, IMAGE* a1, s32 a2, s32 a3, s32 a4);
 void init(ALLOCATOR* a0);
 void exit(void);
 ~MenuItem();
};
