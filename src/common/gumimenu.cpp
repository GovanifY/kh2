#include "types.h"


class CAMERA;
class FuncDef11;
class FuncDef12;
struct TASK;

class GUMI_MENU {
public:
 void ensure(void);
 void SetGumiMenuHelpMessage(s32 a0);
 void packet_kick(TASK* a0);
 void packet_close(TASK* a0);
 void draw_queue_flush(TASK* a0);
 void vu1draw_wait(TASK* a0);
 void startMenuBgm(void);
 void startEditBgm(void);
 void startSortieBgm(void);
 void CreateGumiMenuBGObj(CAMERA* a0);
 void init(TASK* a0);
 void thread_main(TASK* a0);
 u32 GetGumiMenuBGObj(void);
 u32 GetTaskManager(void);
 u64 IsTinySystemExist(void);
};

void Init(void);
void CreateTask(s32 a0, s32 a1, FuncDef11* a2);
void CreateThread(s32 a0, s32 a1, FuncDef12* a2, s32 a3);
void Start(TASK* a0);
void Ensure(TASK* a0);
u64 entry(s32 a0, void* a1);
