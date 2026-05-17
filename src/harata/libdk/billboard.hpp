#ifndef KH2_SRC_HARATA_LIBDK_BILLBOARD_HPP
#define KH2_SRC_HARATA_LIBDK_BILLBOARD_HPP

#include "../../common/types.h"

class MESSAGE;
class MapFile;

namespace dk {

    class BILLBOARD {
    public:
     void init(MapFile* a0);
     void exit(void);
     void DrawGuide(s32 a0, s32 a1, bool a2);
     void DrawPlace(void);
     void DrawDisableReason(MESSAGE* a0, f32 a1);
    };

}  // namespace dk

#endif
