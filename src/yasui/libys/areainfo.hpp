#ifndef KH2_SRC_YASUI_LIBYS_AREAINFO_HPP
#define KH2_SRC_YASUI_LIBYS_AREAINFO_HPP

#include "../../common/types.h"

namespace YS {

    class AREAINFO {
    public:
     s32 Get(s32 a0, s32 a1);
     u64 IsCheck(s32 a0, s32 a1, s32 a2);
     void SysInit(void* a0);
     void SetBgm(void);
     void CheckNavimap(void);
     void Init(void);
     void IsKnown(s32 a0, s32 a1);
     void IsIndoor(void);
     void IsMonochrome(s32 a0, s32 a1);
     void IsNoShadow(void);
     void IsGlow(void);
     u64 IsShowNavimap(void);
     u8 GetCommand(void);
    };

}  // namespace YS

#endif
