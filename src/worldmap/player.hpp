#ifndef KH2_SRC_WORLDMAP_PLAYER_HPP
#define KH2_SRC_WORLDMAP_PLAYER_HPP

#include "../common/types.h"

class COMMAND_ELEM;
class FVector;
class OBJ;
class OBJENTRY;
class PAD;
class Player;
class TARGET;

namespace worldmap {

    class Player {
    public:
     void _OVR_exec_command_player(COMMAND_ELEM* a0);
     void _OVR_get_lockon_pos(void);
     void endDash(void);
     u64 appear(OBJENTRY* a0, FVector* a1, f32 a2);
     void controlOff(void);
     void controlOn(void);
     void _OVR_initialize(void);
     void _OVR_control(void);
     void _OVR_exec(void);
     void _OVR_post_exec(void);
     void _OVR_touch_barrier(s32 a0);
     Player(Player* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
     void landingWorld(TARGET* a0);
     void landingGumi(TARGET* a0);
     void execInformation(OBJ* a0);
     u64 checkEvent(s32 a0);
     void checkDark(s32 a0);
    };

}  // namespace worldmap

#endif
