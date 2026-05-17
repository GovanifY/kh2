#include "../../common/types.h"


namespace YS {

} // namespace YS

class ALLOCATOR;
class BD_STATUS;
class BD_TRAP;
union BD_VALUE;
class OBJ;
class VM;
class WORK;
class _BD_PROCESS;

class VM {
public:
 VM(VM* a0, void* a1, WORK* a2, OBJ* a3);
 void Debugger(_BD_PROCESS* a0, BD_STATUS a1, void* a2);
 void end(void);
 ~VM();
 void get_func_addr(s32 a0);
 void call_pc(s32 a0, BD_VALUE* a1, s32 a2);
 void call(s32 a0, BD_VALUE* a1, s32 a2);
 u64 exec(VM* a0);
 void syscallback(s32 a0, BD_VALUE* a1, s32 a2, VM* a3);
 void callback(s32 a0, BD_VALUE* a1, s32 a2, VM* a3);
 void destroy(void);
 void stop(s32 a0, s32 a1);
 void Init(ALLOCATOR* a0);
 void ExecDestroy(void);
 void Exit(void);
 void SetTrapTable(s32 a0, BD_TRAP* a1);
 void SetGumiBattleTrap(BD_TRAP* a0);
 void ErrorHook(void);
};
