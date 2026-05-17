#ifndef KH2_SRC_TOZAWA_MUNNYDRAW_HPP
#define KH2_SRC_TOZAWA_MUNNYDRAW_HPP

#include "types.h"

class IMAGE;

namespace Tz {

class MunnyDraw {
public:
    MunnyDraw(MunnyDraw* a0, s32 a1, s32 a2, short* a3);
    void Leave(void);
    ~MunnyDraw();
    void Update(void);
    void isExist(void);
    void Create(s32 a0, void* a1, IMAGE* a2, s32 a3);
    void Loop(void);
    void SetSeqNum(s32 a0);
};

}  // namespace Tz

#endif
