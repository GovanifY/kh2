#include "commandmenu.hpp"
#include "types.h"


namespace YS {

} // namespace YS

class LIMIT_TABLE {
public:
 u64 is_read_request(void);
 u64 can_exec(void);
 u64 is_change_idle(void);
 void update_score(s32 a0);
 bool is_summon(void);
 u64 is_kh1(void);
 void Init(void* a0);
 u64 is_enable(void);
 s32 Get(s32 a0);
 void CheckRead(void);
 u64 CanExec(void);
 void MakeMenu(COMMAND_MENU* a0);
 void SummonRead(s32 a0);
 s32 Search(s32 a0);
 u16 get_score(void);
};
