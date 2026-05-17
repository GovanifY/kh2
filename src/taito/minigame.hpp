#ifndef KH2_SRC_TAITO_MINIGAME_HPP
#define KH2_SRC_TAITO_MINIGAME_HPP

#include "../common/types.h"

namespace Ti {

    class LFlag {
    public:
        LFlag(u32);
        bool check(u32);
        void reset(u32);
        void zero();
    };

}  // namespace Ti

#endif
