#ifndef KH2_SRC_TOZAWA_SMENU_LM_HPP
#define KH2_SRC_TOZAWA_SMENU_LM_HPP

#include "../common/types.h"

struct TASK;

namespace Tz {

class LMMU {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
