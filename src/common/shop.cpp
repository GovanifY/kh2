#include "./types.h"


class FuncDef15;
struct TASK;

namespace SHOP {

void Start(TASK* a0);
s32 Ensure(TASK* a0);
void Init(void);
void CreateTask(s32 a0, s32 a1, FuncDef15* a2);
s32 StartMenu(s32 a0);
u32 GetSignal(void);

} // namespace SHOP
