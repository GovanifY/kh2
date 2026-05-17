#ifndef KH2_SRC_YASUI_LIBYS_MINIGAME_HPP
#define KH2_SRC_YASUI_LIBYS_MINIGAME_HPP

#include "../../common/types.h"

namespace YS {

    class MINIGAME {
    public:
     s32 GetScore(s32 a0);
     bool IsShowHelp(s32 a0);
     void CheckShowHelp(s32 a0);
    };

}  // namespace YS

#endif
