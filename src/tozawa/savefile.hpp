#pragma once

#include "../common/types.h"

namespace Tz {

class SaveFile {
public:
    SaveFile();
    ~SaveFile();
    s32 getIcoAddress(void);
    s32 getSysIcoAddress(void);
    void buildData(void* a0);
};

}  // namespace Tz

