#ifndef KH2_SRC_TAITO_MG_AL_ESCAPE_HPP
#define KH2_SRC_TAITO_MG_AL_ESCAPE_HPP

#include "../common/types.h"

class FVector;
class MG_ALEscape;
class OBJ;
struct TASK;

namespace Ti {

    class MG_ALEscape {
    public:
     MG_ALEscape(MG_ALEscape* a0, s32 a1);
     ~MG_ALEscape();
     void exec(void);
     void post_exec(void);
     void camera_matrix(void);
     void correct_pos(FVector* a0, FVector* a1, FVector* a2);
     void stop(void);
     void _check_collision(OBJ* a0, FVector* a1, FVector* a2);
     void task_exec(TASK* a0);
     void task_update_camera(TASK* a0);
     void task_post_exec(TASK* a0);
     void player_control_ok(void);
     s32 pre_camera_matrix(void);
     void player_base_matrix(void);
     void carpet_base_matrix(void);
     void PadToMovement(FVector* a0);
     void init(s32 a0);
    };

}  // namespace Ti

#endif
