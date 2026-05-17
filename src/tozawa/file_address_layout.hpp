#pragma once

#include "../common/types.h"

namespace Tz {

struct FileAddressLayout {
    char _pad0[4];
    s32 fileAddress;
};

}  // namespace Tz
