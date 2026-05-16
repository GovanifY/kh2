#include "types.h"


namespace dk {

} // namespace dk

class MESSAGE;
class MapFile;

class BILLBOARD {
public:
 void init(MapFile* a0);
 void exit(void);
 void DrawGuide(s32 a0, s32 a1, bool a2);
 void DrawPlace(void);
 void DrawDisableReason(MESSAGE* a0, f32 a1);
};
