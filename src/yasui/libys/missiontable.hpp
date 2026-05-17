#ifndef KH2_SRC_YASUI_LIBYS_MISSIONTABLE_HPP
#define KH2_SRC_YASUI_LIBYS_MISSIONTABLE_HPP

#include "../../common/types.h"

class MISSION_TABLE;

namespace YS {

    class MISSION_TABLE {
    public:
     MISSION_TABLE();
     u64 is_colosseum(void);
     void Init(void);
    };

}  // namespace YS

#endif
