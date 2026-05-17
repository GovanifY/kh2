#ifndef KH2_SRC_YASUI_LIBYS_COMMANDMENU_HPP
#define KH2_SRC_YASUI_LIBYS_COMMANDMENU_HPP

#include "../../common/types.h"

namespace YS {

class COMMAND_ELEM;
class OBJ;
class PLAYER;
class TARGET;

class COMMAND_SLOT {
public:
    u64 CanDrive(COMMAND_ELEM* a0, PLAYER* a1);
    void clear(void);
    u64 GetStatus(COMMAND_ELEM* a0, OBJ* a1, TARGET* a2);
    void set(COMMAND_ELEM* a0, OBJ* a1, TARGET* a2, s32 a3);
    bool is_exist();
    bool is_beep(void);
};

class COMMAND_MENU {
public:
    void clear();
    void reset_cursor();
};

}  // namespace YS

#endif
