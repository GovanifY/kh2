#include "../common/types.h"
#include "../common/task.hpp"


class EventViewInfo;
class FuncDef16;

void Init(void);
void BootInit(void);
u32 GetAllocator(void);
void Alloc(u32 a0);
void Free(void* a0);
void CreateTask(s32 a0, s32 a1, FuncDef16* a2);
bool isFirstBoot(void);
void ClrFirstBoot(void);
void SetShowVersion(bool a0);
u64 isExec(void);
void SetEvViewInfo(EventViewInfo* a0);
void GetEvViewInfo(EventViewInfo* a0);
void SetFindClearKH2(bool a0);
void SetFindClearCOM(bool a0);
u64 isFindClearKH2(void);
u64 isFindClearCOM(void);
void SetEvViewEnableAll(bool a0);
u64 isEvViewEnableAll(void);
void Start(TASK* a0);
void Ensure(TASK* a0);
u64 entry000(s32 a0, void* a1);
