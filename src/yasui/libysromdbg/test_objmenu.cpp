#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class ELEM;
class EVENT;
class OBJ;
class TEST_OBJMENU;
class WIDGET;

class TEST_OBJMENU {
public:
 void Finalizer(WIDGET* a0);
 void idle_func(void);
 void focus_func(EVENT a0, s32 a1, s32 a2);
 TEST_OBJMENU(TEST_OBJMENU* a0, OBJ* a1, s32 a2, s32 a3);
 void Init(void);
 u32 GetObj(void);
 void AddMenu(ELEM* a0);
 ~TEST_OBJMENU();
};
