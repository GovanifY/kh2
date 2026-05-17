#pragma once

#include "../common/types.h"

namespace YS { namespace TREASURE { struct TABLE; } }

namespace Tz {

class JmTreasure {
public:
    static void LeaveAll();
    static u32 isEnableNavi(YS::TREASURE::TABLE const*);
};

}  // namespace Tz

