#pragma once

#include "../../common/types.h"

class FVector;
class OBJ;
class OBJENTRY;
class STDOBJ;
class UNIT_DATA_OBJ;
class UNIT_GROUP;

namespace YS {

class STDOBJ {
public:
 void _OVR_initialize(void);
 void _OVR_post_exec(void);
 void _OVR__destroy(void);
 u64 _OVR_check_leave(void);
 STDOBJ(STDOBJ* a0, OBJENTRY* a1, u32 a2, FVector* a3, f32 a4);
 void _OVR_voice(s32 a0, s32 a1);
 void call_se(s32 a0, FVector* a1);
 u32 get_camera_data(char* a0);
 void start_camera(char* a0, OBJ* a1);
 void show_picture(s32 a0);
 void reset_special_command(void);
 void set_special_command(s32 a0);
 void hook_command_image(void);
 void reset_command_image(void);
 void play_singleton_se(s32 a0, s32 a1, s32 a2);
 void motion_attack_on(s32 a0, s32 a1, s32 a2);
};

class STDOBJ> {
public:
 void initialize(OBJ* a0);
 void pre_exec(OBJ* a0);
 void exec(OBJ* a0);
 void post_exec(OBJ* a0);
 void _destroy(OBJ* a0);
 void leave_req(OBJ* a0);
 u64 check_leave(OBJ* a0);
 void leave(OBJ* a0);
 void fall(OBJ* a0);
 void land(OBJ* a0);
 void signal_callback(OBJ* a0, s32 a1, s32 a2);
 void set_unit_data(OBJ* a0, UNIT_GROUP* a1, UNIT_DATA_OBJ* a2);
 void get_data_priority(OBJ* a0);
 void is_control(OBJ* a0);
 void hide(OBJ* a0);
 void show(OBJ* a0);
 void voice(STDOBJ* a0, s32 a1, s32 a2);
};

}  // namespace YS

