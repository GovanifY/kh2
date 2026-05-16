#include "types.h"


struct TASK;

class SHAKE {
public:
 void Drain(s32 a0);
 void DamageL(void);
 void DamageM(void);
 void DamageS(void);
 void DamagePinch(void);
 void DamageDead(void);
 void exec(void);
 void Init(void);
 void Start(f32 a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6);
 void ExecTask(TASK* a0);
 void Finalizer(TASK* a0);
};

class Shake {
public:
 void start(s32 a0, f32 a1, f32 a2, f32 a3, f32 a4);
 void calc(f32 a0);
 void exec(void);
};
