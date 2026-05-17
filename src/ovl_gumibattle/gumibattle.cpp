#include "../common/types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace GUMIBATTLE {

} // namespace GUMIBATTLE

class FuncDef10;
struct TASK;

void Init(void);
void SetPauseParam(char a0, char a1, char a2, FuncDef10* a3);
s32 GetPauseParam(void);
void ChangeGameModeFromPause(void);
void Start(TASK* a0);
void Ensure(TASK* a0);
u64 entry(s32 a0, void* a1);
