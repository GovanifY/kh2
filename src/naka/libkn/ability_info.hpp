#ifndef KH2_SRC_NAKA_LIBKN_ABILITY_INFO_HPP
#define KH2_SRC_NAKA_LIBKN_ABILITY_INFO_HPP

#include "../../common/types.h"

namespace kn {

class AbilityInfo {
public:
    static u32 ability2item(s32);
    static s32 item2index(s32);
};

}  // namespace kn

#endif
