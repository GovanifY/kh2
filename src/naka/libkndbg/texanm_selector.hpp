#ifndef KH2_SRC_NAKA_LIBKNDBG_TEXANM_SELECTOR_HPP
#define KH2_SRC_NAKA_LIBKNDBG_TEXANM_SELECTOR_HPP

#include "../../common/types.h"

class OBJ;
class TexanmSelector;

namespace kn {

    class TexanmSelector {
    public:
     void readHeader(void);
     TexanmSelector(TexanmSelector* a0, OBJ* a1);
     ~TexanmSelector();
     void init(void);
    };

}  // namespace kn

#endif
