#ifndef KH2_SRC_YASUI_LIBYS_LMPLAYER_HPP
#define KH2_SRC_YASUI_LIBYS_LMPLAYER_HPP

#include "../../common/types.h"

class COMMAND_ELEM;
class FVector;
class LMPLAYER;
class OBJENTRY;
class PAD;

namespace YS {

    class LMPLAYER {
    public:
     void swim(void);
     void _OVR_exec_command_player(COMMAND_ELEM* a0);
     LMPLAYER(LMPLAYER* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
    };

}  // namespace YS

#endif
