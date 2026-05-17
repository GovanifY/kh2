#ifndef KH2_SRC_TOZAWA_SMENU_CANA_HPP
#define KH2_SRC_TOZAWA_SMENU_CANA_HPP

#include "../common/types.h"

struct TASK;

namespace Tz {

class CANA {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz

#endif
