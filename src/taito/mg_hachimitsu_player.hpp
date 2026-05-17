#ifndef KH2_SRC_TAITO_MG_HACHIMITSU_PLAYER_HPP
#define KH2_SRC_TAITO_MG_HACHIMITSU_PLAYER_HPP

#include "../common/types.h"

class COMMAND_ELEM;
class FMatrix;
class FVector;
class MGHachimitsuPlayer;
class OBJENTRY;
class PAD;
class PRIZEEFFECT;

namespace Ti {

    class MGHachimitsuPlayer {
    public:
     bool _OVR_can_get_prize(PRIZEEFFECT* a0);
     void _OVR_initialize(void);
     bool is_combine_ready(void);
     bool is_gopher_ready(void);
     void _OVR_pre_exec(void);
     void _OVR_exec(void);
     void damage(void);
     void set_matrix(FMatrix* a0);
     void decide_pos_with_pooh(void);
     void _OVR_post_exec(void);
     void _OVR_exec_command_player(COMMAND_ELEM* a0);
     void _OVR_make_movement(void);
     MGHachimitsuPlayer(MGHachimitsuPlayer* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
     void set_run_effect(s32 a0);
     void start_special_motion(void);
    };

}  // namespace Ti

#endif
