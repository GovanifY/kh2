#ifndef KH2_SRC_TOZAWA_JM_TREASURE_HPP
#define KH2_SRC_TOZAWA_JM_TREASURE_HPP

#include "types.h"

namespace YS { namespace TREASURE { struct TABLE; } }

namespace Tz {

class JmTreasure {
public:
    static void LeaveAll();
    static u32 isEnableNavi(YS::TREASURE::TABLE const*);
};

}  // namespace Tz

#endif
