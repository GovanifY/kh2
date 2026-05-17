#ifndef KH2_SRC_YASUI_LIBYS_PLAYERCOMMAND_HPP
#define KH2_SRC_YASUI_LIBYS_PLAYERCOMMAND_HPP

#include "../../common/types.h"

class COMMAND_ELEM;
class PAD;
class PLAYER;
class PLAYER_COMMAND;
class STDOBJ;
class TARGET;

namespace YS {

    class PLAYER_COMMAND {
    public:
     void clear_override(void);
     void clear_menu(void);
     PLAYER_COMMAND();
     void close(bool a0);
     void open(s32 a0, bool a1);
     void close_all(void);
     u64 change_type(s32 a0);
     bool decide_command(COMMAND_ELEM* a0, TARGET* a1);
     u64 override(s32 a0, s32 a1, TARGET* a2, s32 a3, s32 a4);
     void close_submenu(void);
     void override_top(int* a0, TARGET* a1);
     s32 get_override(s32 a0);
     u64 is_override_top(void);
     void check_alpha(void);
     void exec(void);
     void decide(void);
     u64 is_disable_item(void);
     void initialize(PLAYER* a0, PAD* a1);
     void _exec(void);
     bool _decide(void);
     void set_special_command(s32 a0, void* a1, void* a2, STDOBJ* a3);
     void reset_special_command(void);
     void show(void);
     void hide(void);
     u64 is_disable_change_side(void);
     ~PLAYER_COMMAND();
     void make(void);
    };

}  // namespace YS

#endif
