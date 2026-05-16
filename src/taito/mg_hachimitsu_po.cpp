#include "types.h"


namespace Ti {

} // namespace Ti

class FMatrix;
class FVector;
class MGHachimitsuPo;
class OBJENTRY;

class MGHachimitsuPo {
public:
 void play_interval_voice(bool a0);
 void _OVR_initialize(void);
 void _OVR_pre_exec(void);
 void _OVR_post_exec(void);
 MGHachimitsuPo(MGHachimitsuPo* a0, OBJENTRY* a1, FVector* a2, f32 a3);
 double get_horizontal_pos(void);
 u64 is_separate_blow(void);
 double get_vertical_pos(void);
 void set_matrix(FMatrix* a0);
 void combine(bool a0);
 void separate(f32 a0);
 void set_run_effect(s32 a0);
};
