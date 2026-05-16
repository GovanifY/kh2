#include "types.h"


namespace dk {

} // namespace dk

class AREA;
struct TASK;

class Area {
public:
 void setMapFile(char* a0);
 void readData(void);
 void initMap(u64 a0);
 void init(void);
 void start(void);
 void exit(void);
 void cacheBuffDestroy(AREA* a0);
 void finalizer(AREA* a0);
};

void change(AREA* a0);
void Init(AREA* a0);
void Init(s32 a0, s32 a1, s32 a2);
void MapJump(AREA* a0, u32 a1, s32 a2, bool a3, s32 a4);
u32 GetAllocator(void);
void Alloc(u32 a0);
void Free(void* a0);
void DestroyAllocator(void);
void Exit(void);
void ErrorHook(void);
void InitTaskMapJump(void);
u64 IsMapJumpExec(void);
u64 is_same_area(AREA* a0);
void CreateAllocator(u32 a0, u32 a1);
void InitThread(TASK* a0);
void MapJumpTask(TASK* a0);
void start(void);
void StartTask(TASK* a0);
