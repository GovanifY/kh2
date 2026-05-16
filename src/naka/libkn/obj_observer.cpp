#include "types.h"

namespace kn {
class ObjObserver {
public:
    void clear();
    s32 getEntryNum();
};

struct ObjObserverClearLayout {
    char _pad0[12];
    u32 entryNum;
    u32 array[32];
};

struct ObjObserverLayout {
    char _pad0[12];
    s32 entryNum;
};

void ObjObserver::clear() {
    ObjObserverClearLayout* l = reinterpret_cast<ObjObserverClearLayout*>(this);
    l->entryNum = 0;
    u32 i = 31;
    u32* p = l->array;
    do {
        *p++ = 0;
    } while ((s32)--i >= 0);
}

s32 ObjObserver::getEntryNum() { return reinterpret_cast<ObjObserverLayout*>(this)->entryNum; }
}  // namespace kn
