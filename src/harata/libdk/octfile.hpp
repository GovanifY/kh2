#ifndef KH2_SRC_HARATA_LIBDK_OCTFILE_HPP
#define KH2_SRC_HARATA_LIBDK_OCTFILE_HPP

#include "../../common/types.h"

namespace dk {

    class OctCollFile {
    public:
        u32 getAttr(u16);
        void sethitCollPolygonTableAddress(u16* v);
    };

}  // namespace dk

#endif
