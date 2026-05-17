#include "mutex.hpp"

namespace YS {



void MUTEX::lock(s32 index) {
    u32* bits = reinterpret_cast<u32*>(this);
    *bits |= 1u << index;
}

u32 MUTEX::is_lock(s32 index) {
    u32* bits = reinterpret_cast<u32*>(this);
    if (index != 0) {
        u32 mask = 1u;
        mask <<= index;
        return ((*bits & mask) != 0);
    }
    return (*bits != 0);
}

}  // namespace YS
