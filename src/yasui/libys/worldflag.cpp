#include "types.h"


namespace YS {

} // namespace YS

class CODE;

class WORLDFLAG {
public:
 u64 CodeParser(CODE* a0, void* a1);
 void exec(bool a0);
 void Init(void* a0);
 u8 GetUpdateFlag(uchar* a0);
 void ExecUpdateFlag(void);
 bool Check(s32 a0);
 u32 Set(s32 a0);
 void NewGame(void);
 void ProgressCallback(s32 a0);
 void ClearGumiStage(s32 a0);
};
