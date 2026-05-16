#include "types.h"


namespace Ti {

} // namespace Ti

class FVector;
class MG_EHSidecar;
class OBJ;
struct TASK;

class MG_EHSidecar {
public:
 void reset(void);
 MG_EHSidecar(MG_EHSidecar* a0, s32 a1);
 ~MG_EHSidecar();
 void play_path(s32 a0, bool a1);
 void exec(void);
 void post_exec(void);
 void update_camera(void);
 void stop(void);
 void correct_pos(FVector* a0, FVector* a1, FVector* a2);
 void _check_collision(OBJ* a0, FVector* a1, FVector* a2);
 void task_exec(TASK* a0);
 void task_update_camera(TASK* a0);
 void task_post_exec(TASK* a0);
 void PadToMovement(FVector* a0);
 s32 pre_camera_matrix(void);
 s32 camera_matrix(void);
 void init(s32 a0);
 void PlayPath(s32 a0, bool a1);
 void MoveToNextPoint(void);
 void MoveToBeforePoint(void);
 u64 IsPointMoving(void);
 u32 GetCurrentPoint(void);
};
