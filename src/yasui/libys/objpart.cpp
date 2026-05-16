#include "types.h"


namespace YS {

} // namespace YS

class OBJPART {
public:
 void GetMessage(s32 a0);
 u16 GetMessageId(s32 a0);
 u16 GetTargetCommand(s32 a0);
 u16 GetChangeinCommand(s32 a0);
 s32 GetSaveRamPart(s32 a0);
};
