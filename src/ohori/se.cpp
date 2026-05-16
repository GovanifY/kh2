#include "types.h"


class FVector;
struct TASK;

class SE {
public:
 void setBackGround(TASK* a0);
 void BgSePlay(void);
 void BgSeFadeout(void);
 void Init(void);
 void Ensure(void);
 void Load(TASK* a0);
 u32 Play(s32 a0, FVector* a1);
 u32 Play(s32 a0);
 void Fadeout(s32 a0, f32 a1);
 void playSe(s32 a0);
 void destroyCheck(void);
 void Play(s32 a0);
};
