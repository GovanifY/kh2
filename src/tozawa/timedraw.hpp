#ifndef KH2_SRC_TOZAWA_TIMEDRAW_HPP
#define KH2_SRC_TOZAWA_TIMEDRAW_HPP

#include "../common/types.h"

class IMAGE;

namespace Tz {

class TimeDraw {
public:
    TimeDraw(TimeDraw* a0, s32 a1, s32 a2, s32 a3, short* a4);
    void Leave(void);
    ~TimeDraw();
    void Update(void);
    void Create(s32 a0, void* a1, IMAGE* a2, s32 a3);
    void isExist(void);
    void Loop(void);
    void SetSeqNum(s32 a0);
};

}  // namespace Tz

#endif
