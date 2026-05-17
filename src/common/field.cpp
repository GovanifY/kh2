#include "../harata/libdk/field.hpp"


struct TASK;

void CacheBuffDestroyEnable(void);
void Init(void);
void CreateTask(s32 a0, s32 a1, FuncDef8* a2);
void CreateThread(s32 a0, s32 a1, FuncDef9* a2, s32 a3);
void soundInit(void);
void CacheBuffDestroyDisable(void);
void Start(TASK* a0);
void Ensure(TASK* a0);
