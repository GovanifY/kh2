#pragma once

#include "../common/types.h"

namespace Tz {

class ChgMember {
public:
    static u32 isLoadExec();
    static u32 isLoadFinish();
    static u32 Load();
    static void* GetMember();
};

}  // namespace Tz

