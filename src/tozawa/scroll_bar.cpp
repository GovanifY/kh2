#include "types.h"


namespace Tz {

} // namespace Tz

class IMAGE;
class ScrollBar;
class Sprite;

class ScrollBar {
public:
 ScrollBar();
 void isExist(void);
 ~ScrollBar();
 void Create(s32 a0, void* a1, IMAGE* a2, short* a3, s32 a4, s32 a5, Sprite* a6, s32 a7);
 void FadeOut(void);
 void Loop(void);
 void Leave(void);
 void SetPos(s32 a0);
 void SetMax(s32 a0);
};
