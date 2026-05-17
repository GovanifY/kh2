#ifndef KH2_SRC_TOZAWA_SMENU_HB_HPP
#define KH2_SRC_TOZAWA_SMENU_HB_HPP

#include "../common/types.h"

struct TASK;

namespace Tz {

class HBTE {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
