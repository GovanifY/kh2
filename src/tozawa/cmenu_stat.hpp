#ifndef KH2_SRC_TOZAWA_CMENU_STAT_HPP
#define KH2_SRC_TOZAWA_CMENU_STAT_HPP

#include "types.h"

namespace Tz {

class CmStat {
public:
    static u32 ChgSelector();
    static u32 ChgSelChara(bool);
    static void FadeOutAll();
};

}  // namespace Tz

#endif
