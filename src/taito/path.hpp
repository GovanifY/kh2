#pragma once

#include "../common/types.h"

namespace YS {
struct UNIT_DATA_PATH;
}

namespace Ti {

    class Path {
    public:
        u32 check_data(const YS::UNIT_DATA_PATH*);
    };

}  // namespace Ti

