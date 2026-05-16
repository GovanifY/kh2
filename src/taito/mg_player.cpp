#include "types.h"


namespace Ti {

} // namespace Ti

class FVector;
class MGPlayer;
class OBJENTRY;
class PAD;

class MGPlayer {
public:
 s32 _OVR_get_prize_pick_center_matrix(void);
 s32 _OVR_get_prize_pick_center_inverse_matrix(void);
 void _OVR_pre_exec(void);
 void _OVR_post_exec(void);
 MGPlayer(MGPlayer* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
 ~MGPlayer();
 u32 current(void);
};
