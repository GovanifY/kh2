#ifndef KH2_SRC_TOZAWA_JM_COLLECTION_HPP
#define KH2_SRC_TOZAWA_JM_COLLECTION_HPP

#include "../common/types.h"

namespace Tz {

class Select;

class JmCollection {
public:
    static void FileAlloc();
    static u32 DrawUpdate(Select*, s32, s32);
};

}  // namespace Tz

#endif
