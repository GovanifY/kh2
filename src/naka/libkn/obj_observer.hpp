#pragma once

#include "../../common/types.h"

namespace kn {

struct ObjObserverClearLayout {
    char _pad0[12];
    u32 entryNum;
    u32 array[32];
};

struct ObjObserverLayout {
    char _pad0[12];
    s32 entryNum;
};

    class ObjObserver {
    public:
        void clear();
        s32 getEntryNum();
    };

}  // namespace kn
