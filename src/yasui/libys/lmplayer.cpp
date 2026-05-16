#include "types.h"


namespace YS {

} // namespace YS

class COMMAND_ELEM;
class FVector;
class LMPLAYER;
class OBJENTRY;
class PAD;

class LMPLAYER {
public:
 void swim(void);
 void _OVR_exec_command_player(COMMAND_ELEM* a0);
 LMPLAYER(LMPLAYER* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
};
