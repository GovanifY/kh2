#ifndef KH2_SRC_TOZAWA_SMENU_TTPT_HPP
#define KH2_SRC_TOZAWA_SMENU_TTPT_HPP

#include "types.h"

struct TASK;

namespace Tz {

class TTPT {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
