#include "types.h"


namespace dk {

} // namespace dk

class FuncDef8;
class FuncDef9;
struct TASK;

class Field {
public:
 void WorldMapStart(s32 a0, u32 a1);
 void TitleStart(bool a0);
 void init(void);
 void execTitle_task(TASK* a0);
};

void CacheBuffDestroyEnable(void);
void Init(void);
void CreateTask(s32 a0, s32 a1, FuncDef8* a2);
void CreateThread(s32 a0, s32 a1, FuncDef9* a2, s32 a3);
void soundInit(void);
void CacheBuffDestroyDisable(void);
void Start(TASK* a0);
void Ensure(TASK* a0);
