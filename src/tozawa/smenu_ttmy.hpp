#ifndef KH2_SRC_TOZAWA_SMENU_TTMY_HPP
#define KH2_SRC_TOZAWA_SMENU_TTMY_HPP

#include "../common/types.h"

struct TASK;

namespace Tz {

class TTMY {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
