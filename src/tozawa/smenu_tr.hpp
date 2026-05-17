#ifndef KH2_SRC_TOZAWA_SMENU_TR_HPP
#define KH2_SRC_TOZAWA_SMENU_TR_HPP

#include "../common/types.h"

struct TASK;

namespace Tz {

class TRTE {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
