#ifndef KH2_SRC_YASUI_LIBYS_SIGNALHOOK_HPP
#define KH2_SRC_YASUI_LIBYS_SIGNALHOOK_HPP

#include "../../common/types.h"

class SIGNAL_HOOK;

namespace YS {

    class SIGNAL_HOOK {
    public:
     void exec(void);
     SIGNAL_HOOK();
     void set_progress_flag(s32 a0);
     void set_menu_flag(s32 a0);
     void set_event(u32 a0, s32 a1);
     void set_treasure(s32 a0, int* a1);
     void set_enable_unit_group(s32 a0);
     void set_disable_unit_group(s32 a0);
     void Init(void);
     u64 SignalCall(s32 a0, s32 a1);
     bool IsHook(s32 a0, s32 a1);
     u32 CheckHook(s32 a0);
     void GetJumper(s32 a0);
    };

}  // namespace YS

#endif
