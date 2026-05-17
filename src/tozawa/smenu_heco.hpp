#ifndef KH2_SRC_TOZAWA_SMENU_HECO_HPP
#define KH2_SRC_TOZAWA_SMENU_HECO_HPP

#include "types.h"

struct TASK;

namespace Tz {

class HECO {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
