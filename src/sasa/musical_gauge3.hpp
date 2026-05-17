#ifndef KH2_SRC_SASA_MUSICAL_GAUGE3_HPP
#define KH2_SRC_SASA_MUSICAL_GAUGE3_HPP

#include "../common/types.h"

class MUSICAL_GAUGE3;

namespace sa {

    class MUSICAL_GAUGE3 {
    public:
     void calcCursorPos(void);
     void update(void);
     void create(void);
     void init(void);
     ~MUSICAL_GAUGE3();
    };

}  // namespace sa

#endif
