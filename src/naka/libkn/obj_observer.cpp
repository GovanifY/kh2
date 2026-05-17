#include "obj_observer.hpp"

namespace kn {

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
