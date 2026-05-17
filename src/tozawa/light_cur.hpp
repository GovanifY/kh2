#ifndef KH2_SRC_TOZAWA_LIGHT_CUR_HPP
#define KH2_SRC_TOZAWA_LIGHT_CUR_HPP

#include "../common/types.h"

namespace Tz {

class LightCur {
public:
    void FadeOut();
    void Leave();
    u32 isExist();
};

}  // namespace Tz

#endif
