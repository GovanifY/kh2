#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace GUMIMENU {

} // namespace GUMIMENU

class FuncDef11;
class FuncDef12;
struct TASK;

void Init(void);
void CreateTask(s32 a0, s32 a1, FuncDef11* a2);
void CreateThread(s32 a0, s32 a1, FuncDef12* a2, s32 a3);
void Start(TASK* a0);
void Ensure(TASK* a0);
u64 entry(s32 a0, void* a1);
