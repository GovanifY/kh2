#ifndef KH2_SRC_YASUI_LIBYS_OBJPART_HPP
#define KH2_SRC_YASUI_LIBYS_OBJPART_HPP

#include "../../common/types.h"

namespace YS {

    class OBJPART {
    public:
     void GetMessage(s32 a0);
     u16 GetMessageId(s32 a0);
     u16 GetTargetCommand(s32 a0);
     u16 GetChangeinCommand(s32 a0);
     s32 GetSaveRamPart(s32 a0);
    };

}  // namespace YS

#endif
