#ifndef KH2_SRC_TOZAWA_LAYFILE_HPP
#define KH2_SRC_TOZAWA_LAYFILE_HPP

#include "../common/types.h"

namespace Tz {

class LayFile {
public:
    static void free();
    s32 getFileAddress() const;
};

}  // namespace Tz

#endif
