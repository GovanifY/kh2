#ifndef KH2_SRC_SASA_MUSICAL_2D_HPP
#define KH2_SRC_SASA_MUSICAL_2D_HPP

#include "../common/types.h"

namespace sa {

    class MUSICAL_2D {
    public:
     void getImd(void);
     void getSqd(void);
     void read(void);
     void init(void);
     void leave(void);
     void exit(void);
     void free(void);
    };

}  // namespace sa

#endif
