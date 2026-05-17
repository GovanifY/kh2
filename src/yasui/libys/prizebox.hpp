#ifndef KH2_SRC_YASUI_LIBYS_PRIZEBOX_HPP
#define KH2_SRC_YASUI_LIBYS_PRIZEBOX_HPP

#include "../../common/types.h"

class BTLOBJ;
class FVector;
class OBJENTRY;
class PRIZEBOX;

namespace YS {

    class PRIZEBOX {
    public:
     void get(BTLOBJ* a0);
     void _OVR_exec(void);
     PRIZEBOX(PRIZEBOX* a0, OBJENTRY* a1, FVector* a2, s32 a3, f32 a4);
     u64 Appear(s32 a0, FVector* a1);
     void ClearAll(void);
     void Read(void);
     void AladdinDrain(void);
     void DropNmPresent(BTLOBJ* a0, s32 a1);
    };

}  // namespace YS

#endif
