#ifndef KH2_SRC_TOZAWA_CHG_MEMBER_HPP
#define KH2_SRC_TOZAWA_CHG_MEMBER_HPP

#include "types.h"

namespace Tz {

class ChgMember {
public:
    static u32 isLoadExec();
    static u32 isLoadFinish();
    static u32 Load();
    static void* GetMember();
};

}  // namespace Tz

#endif
