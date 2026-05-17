#ifndef KH2_SRC_SASA_MUSICAL_INPUT_HPP
#define KH2_SRC_SASA_MUSICAL_INPUT_HPP

#include "../common/types.h"

class FVector;
class MUSICAL_INPUT;
class Sprite;
struct TASK;

namespace sa {

    class MUSICAL_INPUT {
    public:
     u64 createCircleSize(s32 a0, f32 a1, int* a2, int* a3, int* a4, int* a5, int* a6, int* a7, int* a8, int* a9, float* a10);
     void createCircle(f32 a0, s32 a1, s32 a2, s32 a3);
     void updateGauge(void);
     void update(void);
     void create(s32 a0);
     void close(void);
     void initFace(s32 a0);
     void setFace(s32 a0);
     void setMax(s32 a0);
     void setInput(s32 a0);
     void setExcellent(s32 a0);
     void setTime(s32 a0);
     void scorePrint(s32 a0, Sprite* a1);
     u64 BadPrint(FVector* a0);
     u64 ExcellentPrint(FVector* a0);
     s64 BadScore(s32 a0);
     u64 GoodPrint(FVector* a0);
     s32 GoodScore(s32 a0);
     s32 ExcellentScore(s32 a0);
     void printTask(TASK* a0);
     ~MUSICAL_INPUT();
    };

}  // namespace sa

#endif
