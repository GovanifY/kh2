#include "types.h"


namespace YS {

} // namespace YS

class COMMAND_MENU;
class OBJ;
class PLAYER;
class SORA;
class STDOBJ;

class SPECIAL_COMMAND {
public:
 void set(s32 a0, void* a1, void* a2, STDOBJ* a3);
 void reset(void);
 u64 make_sidecar_menu(PLAYER* a0, COMMAND_MENU* a1);
 u64 make_skateboard_menu(SORA* a0, COMMAND_MENU* a1);
 u64 _check(OBJ* a0, COMMAND_MENU* a1);
 u64 check(OBJ* a0, COMMAND_MENU* a1);
 void LimitTrinityComboStart(s32 a0);
};
