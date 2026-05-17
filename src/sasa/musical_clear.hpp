#ifndef KH2_SRC_SASA_MUSICAL_CLEAR_HPP
#define KH2_SRC_SASA_MUSICAL_CLEAR_HPP

#include "../common/types.h"

class MUSICAL_CLEAR;

namespace sa {

    class MUSICAL_CLEAR {
    public:
     void destroy(void);
     void startClear(void);
     void startFailed(void);
     ~MUSICAL_CLEAR();
    };

}  // namespace sa

#endif
