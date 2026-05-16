#include "types.h"


namespace YS {

} // namespace YS

class COMMAND_ELEM;
class FVector;
class NMPLAYER;
class OBJENTRY;
class PAD;

class NMPLAYER {
public:
 void set_lamp(s32 a0);
 void _OVR_control(void);
 void _OVR_exec_command_player(COMMAND_ELEM* a0);
 NMPLAYER(NMPLAYER* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
 void set_param(f32 a0, f32 a1, f32 a2, f32 a3);
};
