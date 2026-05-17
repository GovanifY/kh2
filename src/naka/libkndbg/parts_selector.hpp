#ifndef KH2_SRC_NAKA_LIBKNDBG_PARTS_SELECTOR_HPP
#define KH2_SRC_NAKA_LIBKNDBG_PARTS_SELECTOR_HPP

#include "../../common/types.h"

class MODE;
class OBJ;
class PartsSelector;

namespace kn {

    class PartsSelector {
    public:
     PartsSelector(PartsSelector* a0, OBJ* a1, MODE a2);
     ~PartsSelector();
     void toggle(s32 a0);
     void init(void);
    };

}  // namespace kn

#endif
