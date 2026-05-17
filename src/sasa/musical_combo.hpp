#ifndef KH2_SRC_SASA_MUSICAL_COMBO_HPP
#define KH2_SRC_SASA_MUSICAL_COMBO_HPP

#include "../common/types.h"

class MUSICAL_COMBO;
struct TASK;

namespace sa {

    class MUSICAL_COMBO {
    public:
     void createCircle(f32 a0, s32 a1, s32 a2, s32 a3);
     void updateGauge(void);
     void update(void);
     void close(void);
     void setMax(s32 a0);
     void setTime(s32 a0);
     void showFace(void);
     void hideFace(void);
     void create(s32 a0);
     void printTask(TASK* a0);
     ~MUSICAL_COMBO();
    };

}  // namespace sa

#endif
