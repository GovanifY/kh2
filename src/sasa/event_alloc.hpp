#ifndef KH2_SRC_SASA_EVENT_ALLOC_HPP
#define KH2_SRC_SASA_EVENT_ALLOC_HPP

#include "../common/types.h"

namespace sa {

    class EVENT_ALLOC {
    public:
     u64 is_index_ok(void);
     s32 dump_index(void);
     void init(void* a0, s32 a1);
     void free(void* a0);
    };

}  // namespace sa

#endif
