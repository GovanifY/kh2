#ifndef KH2_SRC_YASUI_LIBYS_SIZEBLOCK_HPP
#define KH2_SRC_YASUI_LIBYS_SIZEBLOCK_HPP

#include "../../common/types.h"

class ALLOCATOR;
class SIZEBLOCK;

namespace YS {

    class SIZEBLOCK {
    public:
     SIZEBLOCK(SIZEBLOCK* a0, ALLOCATOR* a1, u32 a2, u32 a3);
     ~SIZEBLOCK();
     s32 alloc(u32 a0, void* a1);
     void free(void* a0);
    };

}  // namespace YS

#endif
