#ifndef KH2_SRC_HARATA_LIBDK_OBJ2D_HPP
#define KH2_SRC_HARATA_LIBDK_OBJ2D_HPP

#include "types.h"

namespace dk {

class Obj2D {
public:
    static u32 GetAllocator();
    void create(s32, s32);
    void link(s32);
    static u32 isExist(Obj2D*);
    void leave();
    void resetLeave();
    u32 isLeave();
    void setNoKick();
    void hide();
    void show();
    void localHide();
    void localShow();
    void getSeqColorOff();
    void getSeqColorOn();
    void resetSeqAlphaOnly();
    void getSeqAlphaOnly();
    void getSeqPraramXYOff();
    void getSeqPraramXYOn();
    void getParentSeqColorOff();
    void getParentSeqColorOn();
    void getParentSeqAlphaOnly();
    void DoubleSuicideOn();
    u32 isHide();
};

}  // namespace dk

#endif
