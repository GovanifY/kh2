#ifndef KH2_SRC_SASA_MUSICAL_GAUGE4_HPP
#define KH2_SRC_SASA_MUSICAL_GAUGE4_HPP

#include "../common/types.h"

class MUSICAL_GAUGE4;

namespace sa {

    class MUSICAL_GAUGE4 {
    public:
     void update(void);
     void create(void);
     void init(void);
     ~MUSICAL_GAUGE4();
    };

}  // namespace sa

#endif
