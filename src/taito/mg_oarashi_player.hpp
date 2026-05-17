#pragma once

#include "../common/types.h"

class COMMAND_ELEM;
class DAMAGE;
class FVector;
class MGOarashiPiglet;
class MGOarashiPlayer;
class OBJENTRY;
class PAD;

namespace Ti {

    class MGOarashiPlayer {
    public:
     void _OVR_initialize(void);
     bool is_combine_ready(void);
     bool is_contact_piglet_ready(void);
     void _OVR_pre_exec(void);
     void _OVR_exec(void);
     void _OVR_exec_damage(DAMAGE* a0);
     void _OVR_attack(void);
     void _OVR_make_movement(void);
     void start_tornado_attack(void);
     void _OVR_exec_command_player(COMMAND_ELEM* a0);
     MGOarashiPlayer(MGOarashiPlayer* a0, OBJENTRY* a1, PAD* a2, FVector* a3, f32 a4);
     void set_piglet(MGOarashiPiglet* a0);
     void get_tornado_movement(void);
     void stop_tornado_attack(void);
     u64 get_current_attack_type(void);
     u64 is_attack_move(void);
     u64 appear_prize_ok(void);
     void get_attack_dir(void);
    };

}  // namespace Ti

