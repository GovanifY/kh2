#pragma once

#include "../common/types.h"
#include "../yasui/libys/unit_data_path.hpp"

namespace Ti {

    class Path {
    public:
        u32 check_data(const YS::UNIT_DATA_PATH*);
    };

}  // namespace Ti
