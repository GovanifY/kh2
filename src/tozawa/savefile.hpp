#ifndef KH2_SRC_TOZAWA_SAVEFILE_HPP
#define KH2_SRC_TOZAWA_SAVEFILE_HPP

#include "types.h"

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

#endif
