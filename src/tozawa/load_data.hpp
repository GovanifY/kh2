#ifndef KH2_SRC_TOZAWA_LOAD_DATA_HPP
#define KH2_SRC_TOZAWA_LOAD_DATA_HPP

#include "../common/types.h"

struct TASK;

namespace Tz {

class LoadData {
public:
    static void Request(const char*, s32, bool);
    static void FlushTask(TASK*);
    static void Clear(s32);
    static void* CacheAlloc(const char*);
};

}  // namespace Tz

#endif
