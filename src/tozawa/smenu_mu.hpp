#ifndef KH2_SRC_TOZAWA_SMENU_MU_HPP
#define KH2_SRC_TOZAWA_SMENU_MU_HPP

#include "../common/types.h"

struct TASK;

namespace Tz {

class MUMI {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
