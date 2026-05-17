#ifndef KH2_SRC_TOZAWA_SEL_HIST_HPP
#define KH2_SRC_TOZAWA_SEL_HIST_HPP

#include "layout.hpp"
#include "types.h"

class MESSAGE;

namespace Tz {

class SelHist {
public:
    void Init(s32 a0, s32 a1, Layout* a2, short* a3, short* a4);
    void Exit(void);
    void SetSeqList2(short* a0);
    void SetMsg(s32 a0, MESSAGE* a1);
    void SetMsgId(s32 a0, s32 a1);
    void Create(s32 a0, s32 a1, bool a2);
    void FadeOut(s32 a0);
    void FadeOutAll(void);
    void Leave(s32 a0);
    void LeaveAll(void);
    u64 isExist(s32 a0);
    void Loop(s32 a0);
};

}  // namespace Tz

#endif
