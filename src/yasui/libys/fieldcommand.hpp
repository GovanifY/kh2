#ifndef KH2_SRC_YASUI_LIBYS_FIELDCOMMAND_HPP
#define KH2_SRC_YASUI_LIBYS_FIELDCOMMAND_HPP

#include "../../common/types.h"

class FIELD_COMMAND;
class PAD;
class PLAYER;
class TABLE;

namespace YS {

    class FIELD_COMMAND {
    public:
     void make_top_a(void);
     s32 make_genie_form(void);
     void make_top_b(void);
     void make_item(void);
     void make_form(void);
     void make_shortcut(void);
     void make_changein(void);
     void init_field(void);
     void InitShortcut(void);
     void init_area(void);
     void check_shortcut(void);
     void set_side(s32 a0);
     void set_minigame(TABLE* a0, s32 a1);
     void initialize(PLAYER* a0, PAD* a1);
     void make(void);
     void _exec(void);
     u64 _decide(void);
     void reset_special_command(void);
     void disable_group(s32 a0);
     void enable_group(s32 a0);
     u64 is_disable_group(s32 a0);
     ~FIELD_COMMAND();
    };

}  // namespace YS

#endif
