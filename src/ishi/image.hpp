#pragma once

#include "../common/types.h"

class IMAGE;

namespace YI {

    class IMAGE {
    public:
     void CreateImage(void* a0);
     void ReleaseImage(void* a0);
     IMAGE();
     ~IMAGE();
     void Reset(void);
     void MakePacket(void);
     void Init(void* a0);
     void SetTexBP(s32 a0);
     void SetClutBP(s32 a0);
     s32 GetTexSize(void);
     s32 GetClutSize(void);
     void LoadImage(void);
     void SetGS(void);
     void ResetGS(void);
     void InitLoadImage(void);
     void ClutGray(f32 a0);
     void LoadTexture(void);
     void LoadClut(void);
     void SendInitPacket(void);
     void SendInitTestPacket(void);
     void SendResetPacket(void);
    };

}  // namespace YI

