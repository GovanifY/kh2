#ifndef KH2_SRC_TOZAWA_JM_STORY_HPP
#define KH2_SRC_TOZAWA_JM_STORY_HPP

#include "../common/types.h"

namespace Tz {

class JmStory {
public:
    static u32 Init();
    static void LeaveAll();
    static void LeaveAllPost(...);
};

}  // namespace Tz

#endif
