#pragma once

#include "../common/types.h"

class ALLOCATOR;
class IMAGE_FREEZE;

namespace YI {

class LAYOUT {
public:
 LAYOUT();
 void Free(void);
 ~LAYOUT();
 void Reset(void);
 u64 GetLoopMode(void);
 s32 GetAllFrame(s32 a0);
 void ChangeNumber(s32 a0);
 void SetNumber(s32 a0);
 void SetOffset(s32 a0, s32 a1);
 u64 Init(void* a0, IMAGE_FREEZE* a1, ALLOCATOR* a2);
 s32 GetEntrySequence(s32 a0);
 s32 SearchSequence(s32 a0, s32 a1);
 s32 GetSequenceUnit(s32 a0);
 void GetImageUnit(s32 a0);
 u32 GetScreenSequenceUnit(s32 a0);
 u32 GetScreenImageUnit(s32 a0);
 u32 GetScreenSequenceID(s32 a0);
 u64 GetPlayMode(void);
 void Control(void);
 void Draw(void);
};

} // namespace YI

