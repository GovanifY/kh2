#pragma once

#include "../../common/types.h"

class Aabbox;
class FVector;

namespace YS {

class BG {
public:
 u32 GetCrossPos(FVector* a0, FVector* a1, FVector* a2, s32 a3);
 u64 CanSee(FVector* a0, FVector* a1, s32 a2);
 void GetGroundPos(FVector* a0, FVector* a1, f32 a2, f32 a3, s32 a4);
 void GetFootPrintPos(FVector* a0, FVector* a1, s32 a2);
 void RandomPos(FVector* a0, f32 a1, f32 a2, s32 a3);
 void RandomPosAir(FVector* a0, f32 a1, f32 a2, f32 a3, f32 a4, s32 a5);
 u64 IsCulling(Aabbox* a0);
};

} // namespace YS

