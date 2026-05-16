#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace GUMIBATTLE {

} // namespace GUMIBATTLE

class FuncDef13;
class FuncDef14;
class MemoryAllocator;
struct TASK;

u64 isRunning(void);
void setType(s32 a0);
void SetPauseExitCallBack(FuncDef13* a0);
void Init(void);
s64 Type2LocalId(s32 a0);
u64 Type2MenuMode(s32 a0);
u64 isPauseMenu(s32 a0);
u32 getType(void);
u32 getReserveType(void);
void pauseExit(void);
void createExecTask(void);
void pauseExecTask(TASK* a0);
void CreateTask(s32 a0, s32 a1, FuncDef14* a2);
u32 GetAllocator(void);
u32 GetObjAllocator(void);
void CreateAllocator(s32 a0, MemoryAllocator* a1);
void CreateAllocator(char* a0, u32 a1);
void DestoryAllocator(void);
void SetGameMode(s32 a0);
u32 GetGameMode(void);
void SetMapJump(s32 a0);
void CreateTaskManager(void);
void Start(TASK* a0);
void MapJump(void);
void finalize(void);
void Ensure(TASK* a0);
