#include "types.h"

namespace {

void set_game_speed_value(f32 value) { *reinterpret_cast<volatile f32*>(0x00349e0c) = value; }

void reset_sysobj_state(s32 type, s32 index) {
    if ((index == 0xffff) && (type == 1)) {
        u32* state = reinterpret_cast<u32*>(0x0034dca0);
        state[0] = 0;
        state[1] = 0;
    }
    if ((index == 0xffff) && (type == 1)) {
        u32* state = reinterpret_cast<u32*>(0x0034dcb8);
        state[0] = 0;
        state[1] = 0;
    }
}

void reset_btlobj_target_state(s32 type, s32 index) {
    if ((index == 0xffff) && (type == 1)) {
        *reinterpret_cast<volatile f32*>(0x001c60000 + 3280) =
            *reinterpret_cast<const f32*>(0x00370000 - 13096);
    }
    if ((index == 0xffff) && (type == 1)) {
        u32* state = reinterpret_cast<u32*>(0x001c60000 + 3288);
        state[0] = 0;
        state[1] = 0;
    }
}

void increment_effect_counter() {
    volatile u16* counter = reinterpret_cast<volatile u16*>(0x0032fb00);
    if (*counter < 999) {
        *counter = static_cast<u16>(*counter + 1);
    }
}

void update_limit_reference(s32 limit) {
    if ((*(u32*)(limit + 0x40) & 8) != 0) {
        u32 obj = *(u32*)(*(u32*)(limit + 0x0c) + 0x0b44);
        typedef void (*VirtualCall)(u32);
        VirtualCall fn = reinterpret_cast<VirtualCall>(*(u32*)(*(u32*)obj + 0x18));
        fn(obj);
        *(u32*)(limit + 0x3c) = *(u32*)(limit + 0x3c) - 1;
        *(u32*)(limit + 0x40) &= ~8u;
    }
}

u32 get_current_friend_value() {
    u32 current = *reinterpret_cast<u32*>(0x01d48cb0);
    if (current == 0) {
        return 0;
    }
    if ((*(u32*)(current + 64) & 4) == 0) {
        return *(u16*)(*(u32*)current + 40);
    }
    return 0;
}

void player_push_ability_button_impl(void* player) {
    reinterpret_cast<void (*)(void*)>(0x001e29e0)(player);
}

s32 bghit_get_cross_pos_impl(s32 hit) { return reinterpret_cast<s32 (*)(s32)>(0x001d36e8)(hit); }

void camera_apply_pos_impl(s32 enabled) {
    reinterpret_cast<void (*)(s32)>(0x00226e60)(enabled);
}

}  // namespace

extern "C" void* func_00102c80(void*);
extern "C" void* func_00102788(void*, s32, s32, const char*);
extern "C" void* func_001050d8(s32);
extern "C" void func_001e27c0(void*);
extern "C" void func_001d97c8(BD_VALUE*);
extern "C" void func_00170ee8(s32, s32);
extern "C" void func_0018f0b0(s32, s32);
extern "C" u32 func_001b5af0(void);
extern "C" void func_001e29e0(void*);

extern s32 YS_abs_int(s32) asm("_ZN2YS3absEi");
extern s32 YS_FILE_IsReading(void) asm("_ZN2YS4FILE9IsReadingEv");
extern void YS_CACHE_BUFF_Flush(s32) asm("_ZN2YS10CACHE_BUFF5FlushEP4TASK");
extern void YS_PROGRESS_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
extern s32 YS_WORLDFLAG_Check(s32) asm("_ZN2YS9WORLDFLAG5CheckEi");
extern void ryj_EFFECT_loop_end(s32) asm("_ZN3ryj6EFFECT8loop_endEv");
extern void ryj_EFFECT_loop_end_kill(s32) asm("_ZN3ryj6EFFECT13loop_end_killEv");
extern void ryj_EFFECT_kill(s32) asm("_ZN3ryj6EFFECT4killEv");
extern void AREA_Free(s32) asm("_ZN4AREA4FreeEPv");
extern void dk_Timer_setCountDown(s32) asm("_ZN2dk5Timer12setCountDownEj");
extern void dk_Timer_start(void) asm("_ZN2dk5Timer5startEv");
extern void YS_SAVEFLAG_Reset(s32) asm("_ZN2YS8SAVEFLAG5ResetEj");
extern s32 YS_SAVEFLAG_Check(s32) asm("_ZN2YS8SAVEFLAG5CheckEj");
extern void YS_MENUFLAG_Reset(s32) asm("_ZN2YS8MENUFLAG5ResetEi");
extern void YS_OBJ_set_pos(void*, s32) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
extern void YS_OBJ_set_pos_trans(void*, s32) asm("_ZN2YS3OBJ13set_pos_transERKN2kn7FVectorE");
extern void YS_STDOBJ_set_special_command(void*, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
extern void YS_STDOBJ_hook_command_image(void*) asm("_ZN2YS6STDOBJ18hook_command_imageEv");
extern void YS_OBJ_scatter_prize(void*, s32) asm("_ZN2YS3OBJ13scatter_prizeEi");
extern void YS_FIELDOBJ_mark_history(void*) asm("_ZN2YS8FIELDOBJ12mark_historyEv");
extern void YS_BLUR_init(void) asm("_ZN2YS4BLUR4initEv");
extern void dk_Camera_singleCrossFadeStart(f32) asm("_ZN2dk6Camera20singleCrossFadeStartEf");
extern void YS_ITEM_Reduce(s32, s32) asm("_ZN2YS4ITEM6ReduceEii");
extern void YS_BTLOBJ_blow(void*) asm("_ZN2YS6BTLOBJ4blowERKN2kn7FVectorE");
extern "C" void func_0014ce50(f32);
extern "C" void func_0019ec88(u32);
extern "C" u32 func_00198580(u32, u32);
extern "C" f32 func_0018cb30(s32);
extern "C" void func_0018e040(s32);
extern "C" u32 func_00153f08(u32, u32, u32, u32);
extern "C" u32 func_00186888(u32, u32, u32, u32);
extern "C" u32 func_001880b0(u32, u32, u32, u32);
extern "C" u32 func_00188170(u32, u32, u32, u32);
extern "C" u32 func_00177460(u32, u32, u32, u32);
extern "C" u32 func_00180d40(u32, u32, u32, u32);
extern "C" u32 func_001de508(u32, u32, u32, u32);
extern "C" u32 func_0019eb60(u32, u32, u32, u32);
extern "C" u32 func_0017ec30(u32, u32, u32, u32);
extern "C" u32 func_00190878(u32, u32, u32, u32);
extern "C" void func_00226e60(u32);
extern "C" u32 func_001a27d8(u32, u32, u32, u32);
extern "C" u32 func_0023f070(u32, u32, u32, u32);
extern "C" void func_001b57f8(s32);
extern "C" s32 func_001d36e8(s32);
extern void YS_SORA_set_skateboard_mode(void*, s32) asm("_ZN2YS4SORA19set_skateboard_modeEi");
extern void YS_OCC_disable(void*) asm("_ZN2YS6OBJOCC11disable_allEv");
extern void YS_OCC_enable(void*) asm("_ZN2YS6OBJOCC10enable_allEv");
extern void YS_OCC_disable_bone(void*, s32) asm("_ZN2YS6OBJOCC7disableEi");
extern void YS_OBJ_ControlOff(s32) asm("_ZN2YS3OBJ10ControlOffEi");
extern void YS_OBJ_ControlOn(s32) asm("_ZN2YS3OBJ9ControlOnEi");
extern void YS_OBJ_detach(void*) asm("_ZN2YS3OBJ6detachEv");
extern void YS_ACT_clear(void*) asm("_ZN2YS3ACT5clearEv");
extern void YS_ACT_push(void*) asm("_ZN2YS3ACT4pushEPc");
extern void YS_ACT_start_pri(void*) asm("_ZN2YS3ACT9pri_startEPc");
extern void YS_OBJ_change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
extern void YS_PARTY_hook(void*) asm("_ZN2YS5PARTY4hookEPNS_2VME");
extern void YS_EFFECT_unbind(void*) asm("_ZN3ryj3PAX6unbindEPNS_6EFFECTE");
extern void YS_UNIT_Activate(char*) asm("_ZN2YS4UNIT8ActivateEPc");
extern void YS_PLAYER_set_exec_rc(void*, s32) asm("_ZN2YS6PLAYER11set_exec_rcEi");
extern void YS_TARGET_set_obj(void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
extern void YS_TARGET_ClearBeforePlayer(void) asm("_ZN2YS6TARGET17ClearBeforePlayerEv");
extern void Tz_Layout_setNum(s32, s32) asm("_ZN2Tz6Layout6setNumEii");

namespace YS {

void trap_abs(BD_VALUE* bd) { bd->i = YS_abs_int(bd->i); }

void method_blur_init(BD_VALUE* bd) { func_0019ec88(*(u32*)((u32)bd + 0u)); }

void trap_file_is_reading(BD_VALUE* bd) { bd->i = YS_FILE_IsReading(); }

void trap_file_flush(BD_VALUE* bd) {
    (void)bd;
    YS_CACHE_BUFF_Flush(0);
}

void trap_progress_set_flag(BD_VALUE* bd) { YS_PROGRESS_SetFlag(bd->i); }

void trap_worldflag_check(BD_VALUE* bd) { bd->i = YS_WORLDFLAG_Check(bd->i); }

void trap_effect_loop_end(BD_VALUE* bd) { ryj_EFFECT_loop_end(bd->i); }

void trap_effect_loop_end_kill(BD_VALUE* bd) { ryj_EFFECT_loop_end_kill(bd->i); }

void trap_effect_kill(BD_VALUE* bd) { ryj_EFFECT_kill(bd->i); }

void trap_memory_free(BD_VALUE* bd) { AREA_Free(bd->i); }

void trap_timer_count_down(BD_VALUE* bd) {
    dk_Timer_setCountDown(bd->i);
    dk_Timer_start();
}

void trap_saveflag_reset(BD_VALUE* bd) { YS_SAVEFLAG_Reset(bd->i); }

void trap_saveflag_check(BD_VALUE* bd) { bd->i = YS_SAVEFLAG_Check(bd->i); }

void trap_menuflag_reset(BD_VALUE* bd) { YS_MENUFLAG_Reset(bd->i); }

u32 trap_screen_cross_fade(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_screen_cross_fadeEP8BD_VALUE");
u32 trap_screen_cross_fade(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00153f08(*(u32*)(a0 + 0u), *(u32*)(a0 + 4u), a2, a3);
}

void trap_item_reduce(BD_VALUE* bd) { YS_ITEM_Reduce(bd->i, bd[1].i); }

void trap_obj_set_pos_trans(BD_VALUE* bd) {
    YS_OBJ_set_pos_trans(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_obj_capture_command(BD_VALUE* bd) {
    YS_STDOBJ_set_special_command(*(void**)((char*)bd->i + 4), bd[1].i);
}

u32 trap_obj_get_weight(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_obj_get_weightEP8BD_VALUE");
u32 trap_obj_get_weight(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00198580(*(u32*)(*(u32*)(a0 + 0u) + 4u), *(u32*)(a0 + 4u));
}

void trap_obj_hook_command_image(BD_VALUE* bd) {
    YS_STDOBJ_hook_command_image(*(void**)((char*)bd->i + 4));
}

void trap_obj_scatter_prize(BD_VALUE* bd) {
    YS_OBJ_scatter_prize(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_obj_history_mark(BD_VALUE* bd) {
    YS_FIELDOBJ_mark_history(*(void**)((char*)bd->i + 4));
}

u32 trap_obj_blow(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS13trap_obj_blowEP8BD_VALUE");
u32 trap_obj_blow(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00186888(*(u32*)(*(u32*)(a0 + 0u) + 4u), *(u32*)(a0 + 4u), a2, a3);
}

void trap_obj_set_skateboard_mode(BD_VALUE* bd) {
    YS_SORA_set_skateboard_mode(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_obj_disable_occ(BD_VALUE* bd) {
    YS_OCC_disable((char*)*(void**)((char*)bd->i + 4) + 2048);
}

void trap_obj_enable_occ(BD_VALUE* bd) {
    YS_OCC_enable((char*)*(void**)((char*)bd->i + 4) + 2048);
}

void trap_obj_disable_occ_bone(BD_VALUE* bd) {
    YS_OCC_disable_bone((char*)*(void**)((char*)bd->i + 4) + 2048, bd[1].i);
}

void func_obj_control_off(BD_VALUE* bd) { YS_OBJ_ControlOff(bd->i); }

void func_obj_control_on(BD_VALUE* bd) { YS_OBJ_ControlOn(bd->i); }

void trap_obj_detach(BD_VALUE* bd) { YS_OBJ_detach(*(void**)((char*)bd->i + 4)); }

void trap_obj_act_clear(BD_VALUE* bd) {
    YS_ACT_clear((char*)*(void**)((char*)bd->i + 4) + 768);
}

u32 trap_obj_act_push(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS17trap_obj_act_pushEP8BD_VALUE");
u32 trap_obj_act_push(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001880b0(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 768u), *(u32*)(a0 + 4u), a2, a3);
}

u32 trap_obj_act_start_pri(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_obj_act_start_priEP8BD_VALUE");
u32 trap_obj_act_start_pri(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00188170(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 768u), *(u32*)(a0 + 4u), a2, a3);
}

void trap_obj_action_lightcycle(BD_VALUE* bd) {
    YS_OBJ_change_action(*(void**)((char*)bd->i + 4), 0x17);
}

u32 trap_obj_hook_stop(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS18trap_obj_hook_stopEP8BD_VALUE");
u32 trap_obj_hook_stop(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00177460(*(u32*)(*(u32*)(a0 + 0u) + 4u), 0, a2, a3);
}

u32 trap_obj_motion_capture_id(u32 a0, u32 a1, u32 a2, u32 a3)
    asm("_ZN2YS26trap_obj_motion_capture_idEP8BD_VALUE");
u32 trap_obj_motion_capture_id(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00180d40(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 320u), *(u32*)(a0 + 4u), a2, a3);
}

u32 trap_obj_effect_unbind(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_obj_effect_unbindEP8BD_VALUE");
u32 trap_obj_effect_unbind(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001de508(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 128u), *(u32*)(a0 + 4u), a2, a3);
}

}  // namespace YS

namespace gb {

void trap_obj_set_pos(BD_VALUE* bd) {
    YS_OBJ_set_pos(*(void**)((char*)bd->i + 4), bd[1].i);
}

}  // namespace gb
extern s32 ryj_EFFECT_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
extern s32 ryj_EFFECT_is_active(void*) asm("_ZN3ryj6EFFECT9is_activeEv");
extern s32 AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
extern void SOUND_SE3DDisable(void*) asm("_ZN5SOUND11SE3DDisableEv");
extern s32 YS_MENUFLAG_Check(s32) asm("_ZN2YS8MENUFLAG5CheckEi");
extern void YS_BTLOBJ_sys_dead(void*) asm("_ZN2YS6BTLOBJ8sys_deadEv");
extern void YS_PRIZE_CA_Appear(void*, s32) asm("_ZN2YS8PRIZE_CA6AppearEPNS_6BTLOBJEi");
extern void YS_MICKEY_recov_holylight(void*) asm("_ZN2YS6MICKEY15recov_holylightEv");
extern void dk_Map_setHideGroup(s32) asm("_ZN2dk3Map12setHideGroupEj");
extern void dk_Map_setVisibleGroup(s32) asm("_ZN2dk3Map15setVisibleGroupEj");
extern void YS_OBJ_set_dir(void*, s32) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
extern void YS_OBJ_texanm_start(void*, s32) asm("_ZN2YS3OBJ12texanm_startEi");
extern void YS_OBJ_texanm_stop(void*, s32) asm("_ZN2YS3OBJ11texanm_stopEi");
extern void YS_OBJ_show_part(void*, s32) asm("_ZN2YS3OBJ9show_partEi");
extern void YS_OBJ_hide_part(void*, s32) asm("_ZN2YS3OBJ9hide_partEi");
extern void YS_STATUS_CageOn(void) asm("_ZN2YS6STATUS6CageOnEv");
extern void YS_EVENT_ControlOff(void) asm("_ZN2YS5EVENT10ControlOffEv");
extern void dk_ScopeCamera_destroy(void) asm("_ZN2dk11ScopeCamera7destroyEv");
extern void YS_UNIT_GROUP_Disable(s32) asm("_ZN2YS10UNIT_GROUP7DisableEi");
extern void YS_UNIT_GROUP_Enable(s32) asm("_ZN2YS10UNIT_GROUP6EnableEi");
extern void YS_PRIZE_TR_GetAll(void*) asm("_ZN2YS8PRIZE_TR6GetAllEPNS_6BTLOBJE");
extern void YS_PIERROT_set_sheet(void*, s32) asm("_ZN2YS7PIERROT9set_sheetEi");
extern void YS_ATTACK_destroy(s32) asm("_ZN2YS6ATTACK7destroyEv");
extern void YS_LIMIT_close_gauge(s32) asm("_ZN2YS5LIMIT11close_gaugeEv");
extern void YS_BONUSLEVEL_Up(s32) asm("_ZN2YS10BONUSLEVEL2UpEi");
extern s32 YS_EVENT_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
extern void YS_MISSION_Complete(s32) asm("_ZN2YS7MISSION8CompleteEi");
extern void YS_MISSION_DeadBoss(s32) asm("_ZN2YS7MISSION8DeadBossEi");
extern void YS_MISSION_Failed(void) asm("_ZN2YS7MISSION6FailedEv");
extern void YS_MISSION_Activate2d(void) asm("_ZN2YS7MISSION10Activate2dEv");
extern void YS_MISSION_Return(void) asm("_ZN2YS7MISSION6ReturnEv");
extern void YS_MISSION_RestartTimer(s32, s32) asm("_ZN2YS7MISSION12RestartTimerEii");
extern void dk_Timer_pauseOn(s32) asm("_ZN2dk5Timer7pauseOnEj");
extern void dk_Timer_pauseOff(s32) asm("_ZN2dk5Timer8pauseOffEj");
extern void YS_MISSION_WarningTimer(s32) asm("_ZN2YS7MISSION12WarningTimerEi");
extern void YS_MISSION_DisableTimer(s32) asm("_ZN2YS7MISSION12DisableTimerEi");
extern void YS_MISSION_SetWatch(s32, s32) asm("_ZN2YS7MISSION8SetWatchEii");
extern void YS_MISSION_SetCount(s32, s32) asm("_ZN2YS7MISSION8SetCountEii");
extern void YS_MISSION_AddCount(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
extern void YS_MISSION_DisableCount(s32, s32) asm("_ZN2YS7MISSION12DisableCountEi");
extern void YS_MISSION_ResetComboCounter(s32) asm("_ZN2YS7MISSION17ResetComboCounterEi");
extern void YS_MISSION_SetMaxComboCounter(s32, s32) asm("_ZN2YS7MISSION18SetMaxComboCounterEii");
extern void YS_MISSION_WarningComboCounter(s32) asm("_ZN2YS7MISSION19WarningComboCounterEi");
extern void Ti_MG_EHSidecar_MoveToBeforePoint(void*) asm("_ZN2Ti12MG_EHSidecar17MoveToBeforePointEv");
extern void dk_LockOn_show(void*) asm("_ZN2dk6LockOn4showEv");
extern void Ts_FLARE_Init(void*) asm("_ZN2Ts5FLARE4InitEv");
extern void Ts_TRINITY_SHOT_OBJ_Init(void*) asm("_ZN2Ts16TRINITY_SHOT_OBJ4InitEv");

namespace YS {

void trap_effect_set_pos(BD_VALUE* bd) { func_001d97c8(bd); }

void trap_effect_is_alive(BD_VALUE* bd) { bd->i = ryj_EFFECT_is_alive((void*)bd->i); }

void trap_effect_is_active(BD_VALUE* bd) { bd->i = ryj_EFFECT_is_active((void*)bd->i); }

void trap_memory_alloc(BD_VALUE* bd) { bd->i = AREA_Alloc((u32)bd->i); }

void trap_sound_disable(BD_VALUE* bd) { SOUND_SE3DDisable(bd); }

void trap_menuflag_check(BD_VALUE* bd) { bd->i = YS_MENUFLAG_Check(bd->i); }

void trap_obj_dead_mark(BD_VALUE* bd) { YS_BTLOBJ_sys_dead(*(void**)((char*)bd->i + 4)); }

void trap_obj_scatter_medal(BD_VALUE* bd) {
    YS_PRIZE_CA_Appear(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_obj_recov_holylight(BD_VALUE* bd) { YS_MICKEY_recov_holylight(*(void**)((char*)bd->i + 4)); }

void trap_obj_motion_is_hook(BD_VALUE* bd) {
    YS_OBJ_set_dir(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_obj_sheet(BD_VALUE* bd) { YS_OBJ_texanm_start(*(void**)((char*)bd->i + 4), bd[1].i); }

void trap_obj_texanm_stop(BD_VALUE* bd) {
    YS_OBJ_texanm_stop(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_obj_motion_speed(BD_VALUE* bd) {
    YS_OBJ_show_part(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_command_cage_off(BD_VALUE* bd) {
    (void)bd;
    YS_STATUS_CageOn();
}

void trap_event_control_off(BD_VALUE* bd) {
    (void)bd;
    YS_EVENT_ControlOff();
}

void trap_camera_end_scope(BD_VALUE* bd) {
    (void)bd;
    dk_ScopeCamera_destroy();
}

void trap_unit_disable(BD_VALUE* bd) { YS_UNIT_GROUP_Disable(bd->i); }

void trap_unit_enable(BD_VALUE* bd) { YS_UNIT_GROUP_Enable(bd->i); }

void trap_prize_get_all_tr(BD_VALUE* bd) { YS_PRIZE_TR_GetAll(*(void**)((char*)bd->i + 4)); }

void trap_btlobj_set_sheet(BD_VALUE* bd) {
    YS_PIERROT_set_sheet(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_attack_free(BD_VALUE* bd) { YS_ATTACK_destroy(bd->i); }

void trap_limit_reference(BD_VALUE* bd) { func_001b57f8(bd->i); }

void trap_limit_close_gauge(BD_VALUE* bd) { YS_LIMIT_close_gauge(bd->i); }

void trap_bonuslevel_up(BD_VALUE* bd) { YS_BONUSLEVEL_Up(bd->i); }

void trap_event_is_exec(BD_VALUE* bd) { bd->i = YS_EVENT_IsExec(); }

void trap_mission_complete(BD_VALUE* bd) { YS_MISSION_Complete(bd->i); }

void trap_mission_dead_boss(BD_VALUE* bd) { YS_MISSION_DeadBoss(bd->i); }

void trap_mission_failed(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_Failed();
}

void trap_mission_activate2d(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_Activate2d();
}

void trap_mission_is_activate2d(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_Return();
}

void trap_mission_restart_timer(BD_VALUE* bd) { YS_MISSION_RestartTimer(bd->i, bd[1].i); }

void trap_mission_pause_timer(BD_VALUE* bd) {
    (void)bd;
    dk_Timer_pauseOn(2);
}

void trap_mission_cancel_pause_timer(BD_VALUE* bd) {
    (void)bd;
    dk_Timer_pauseOff(2);
}

void trap_mission_warning_timer(BD_VALUE* bd) { YS_MISSION_WarningTimer(bd->i); }

void trap_mission_disable_timer(BD_VALUE* bd) { YS_MISSION_DisableTimer(bd->i); }

void trap_mission_set_watch(BD_VALUE* bd) { YS_MISSION_SetWatch(bd->i, bd[1].i); }

void trap_mission_decrement_count(BD_VALUE* bd) { YS_MISSION_SetCount(bd->i, bd[1].i); }

void trap_mission_add_count(BD_VALUE* bd) { YS_MISSION_AddCount(bd->i, bd[1].i); }

void trap_mission_disable_count(BD_VALUE* bd) { YS_MISSION_DisableCount(bd->i, bd[1].i); }

void trap_mission_start_combo_counter(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_ResetComboCounter(0);
}

void trap_mission_set_combo_counter_param(BD_VALUE* bd) {
    YS_MISSION_SetMaxComboCounter(bd->i, bd[1].i);
}

void trap_mission_warning_combo_counter(BD_VALUE* bd) { YS_MISSION_WarningComboCounter(bd->i); }

}  // namespace YS

namespace gb {

void trap_bg_hide(BD_VALUE* bd) { dk_Map_setHideGroup(bd->i); }

void trap_bg_show(BD_VALUE* bd) { dk_Map_setVisibleGroup(bd->i); }

void trap_obj_hide_part(BD_VALUE* bd) {
    YS_OBJ_hide_part(*(void**)((char*)bd->i + 4), bd[1].i);
}

}  // namespace gb

namespace ryj {

void trap_player_push_ability_button(BD_VALUE* bd) {
    func_001e29e0(*(void**)((char*)bd->i + 4));
}

}  // namespace ryj

namespace Ti {

void trap_eh22_path_move_before(BD_VALUE* bd) { Ti_MG_EHSidecar_MoveToBeforePoint(bd); }

}  // namespace Ti

namespace Ts {

void trap_lockon_hide(BD_VALUE* bd) { dk_LockOn_show(bd); }

void trap_attack_set_reaction_offset(BD_VALUE* bd) { Ts_FLARE_Init(bd); }

void trap_trinity_shot_init(BD_VALUE* bd) { Ts_TRINITY_SHOT_OBJ_Init(bd); }

}  // namespace Ts
extern s32 YS_OBJ_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
extern s32 YS_CHANGEFORM_CanCaptureForm(BD_VALUE*) asm("_ZN2YS10CHANGEFORM14CanCaptureFormEv");
extern f32 YS_EVENT_GetRestTime(void) asm("_ZN2YS5EVENT11GetRestTimeEv");
extern s32 YS_STATUS_IsBattleMode(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
extern s32 Tz_Munny_Get(void) asm("_ZN2Tz5Munny3GetEv");
extern s32 YS_PRIZE_GetAppearNum(void) asm("_ZN2YS5PRIZE12GetAppearNumEv");
extern s32 YS_PRIZE_CA_GetAppearNum(void) asm("_ZN2YS8PRIZE_CA12GetAppearNumEv");
extern s32 YS_WINDOW_SYSTEM_TUTORIAL_IsOpen(void) asm("_ZN2YS22WINDOW_SYSTEM_TUTORIAL6IsOpenEv");
extern s32 YS_ATTACK_CHECK_NewComboGroup(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
extern s32 YS_SUMMON_IsTinkExist(void) asm("_ZN2YS6SUMMON11IsTinkExistEv");
extern s32 Ti_MG_EHSidecar_GetCurrentPoint(void) asm("_ZN2Ti12MG_EHSidecar15GetCurrentPointEv");
extern s32 Ts_FLARE_IsEmpty(void) asm("_ZN2Ts5FLARE7IsEmptyEv");
extern f32 YS_MATH_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
extern s32 YS_OBJ_CountEntry(s32) asm("_ZN2YS3OBJ10CountEntryEj");
extern s32 YS_PARTY_Get(s32) asm("_ZN2YS5PARTY3GetEi");
extern s32 YS_TARGET_dup(s32) asm("_ZN2YS6TARGET3dupEv");
extern s32 YS_TARGET_is_exist(s32) asm("_ZNK2YS6TARGET8is_existEv");
extern s32 Tz_Munny_Add(u32) asm("_ZN2Tz5Munny3AddEj");
extern s32 YS_DAMAGE_GetReactionType(s32) asm("_ZN2YS6DAMAGE15GetReactionTypeEi");
extern s32 YS_DAMAGE_is_finish(s32) asm("_ZNK2YS6DAMAGE9is_finishEv");
extern s32 YS_DAMAGE_is_normal(s32) asm("_ZNK2YS6DAMAGE9is_normalEv");
extern s32 YS_ATTACK_is_hit(s32) asm("_ZN2YS6ATTACK6is_hitEv");
extern s32 YS_MAGIC_CanAddCost(f32) asm("_ZN2YS5MAGIC10CanAddCostEf");
extern s32 YS_MISSION_GetTimer(s32) asm("_ZN2YS7MISSION8GetTimerEi");
extern s32 YS_MISSION_GetTimerSecond(s32) asm("_ZN2YS7MISSION14GetTimerSecondEi");
extern s32 YS_MISSION_GetCount(s32) asm("_ZN2YS7MISSION8GetCountEi");
extern s32 YS_MISSION_IsExec(void) asm("_ZN2YS7MISSION6IsExecEv");
extern f32 YS_MISSION_GetGaugeRatio(s32) asm("_ZN2YS7MISSION13GetGaugeRatioEi");
extern f32 YS_MISSION_GetGaugeWarningRatio(s32) asm("_ZN2YS7MISSION20GetGaugeWarningRatioEi");
extern s32 YS_MISSION_IsGaugeWarning(s32) asm("_ZN2YS7MISSION14IsGaugeWarningEi");
extern s32 YS_MINIGAME_GetScore(s32) asm("_ZN2YS8MINIGAME8GetScoreEi");
extern void YS_MISSION_SetComboCounterWarningSe(s32, s32) asm("_ZN2YS7MISSION24SetComboCounterWarningSeEii");
extern s32 YS_SUMMON_GetMode(void) asm("_ZN2YS6SUMMON7GetModeEv");
extern s32 YS_LIMIT_reset_hit_counter(s32) asm("_ZN2YS5LIMIT17reset_hit_counterEv");
extern s32 YS_ATTACK_is_finish(s32) asm("_ZNK2YS6ATTACK9is_finishEv");
extern void YS_EVENT_ContinueControlOff(void) asm("_ZN2YS5EVENT18ContinueControlOffEv");
extern void YS_EFFECT_AddDeadEffect(s32) asm("_ZN2YS6EFFECT13AddDeadEffectEPN3ryj6EFFECTE");
extern void YS_TARGET_free(s32) asm("_ZN2YS6TARGET4freeEv");
extern void YS_STATUS_SetPrizeRatio(f32) asm("_ZN2YS6STATUS13SetPrizeRatioEf");
extern s32 YS_LIGHT_Create(s32) asm("_ZN2YS5LIGHT6CreateEi");
extern void YS_LIGHT_fadeout(f32) asm("_ZN2YS5LIGHT7fadeoutEf");
extern void YS_LIGHT_fadein(f32) asm("_ZN2YS5LIGHT6fadeinEf");
extern void YS_BLUR_start(s32, f32) asm("_ZN2YS4BLUR5startEf");
extern void YS_BTLOBJ_dead(void*) asm("_ZN2YS6BTLOBJ4deadEv");
extern void dk_Map_setAnimationSpeedRatio(s32, f32) asm("_ZN2dk3Map22setAnimationSpeedRatioEN2kn13AnimationWork4TYPEEf");
extern void YS_OBJ_fly_to_jump(void*) asm("_ZN2YS3OBJ11fly_to_jumpEv");
extern void YS_JIGSAW_Get(s32, s32) asm("_ZN2YS6JIGSAW3GetEii");

namespace YS {

void func_system_set_game_speed(BD_VALUE* bd) { func_0014ce50(bd->f); }

void method_blur_start(BD_VALUE* bd) { YS_BLUR_start(bd->i, 0.0f); }

void trap_effect_add_dead_block(BD_VALUE* bd) { YS_EFFECT_AddDeadEffect(bd->i); }

void trap_effect_set_type(BD_VALUE* bd) { bd->f = YS_MATH_FixRadian(bd->f); }

void trap_sysobj_is_exist(BD_VALUE* bd) {
    (void)bd;
    func_00170ee8(1, 0xffff);
}

void trap_sysobj_moveto(BD_VALUE* bd) { bd->i = YS_OBJ_GetPlayer(); }

void trap_obj_dead(BD_VALUE* bd) { YS_BTLOBJ_dead(*(void**)((char*)bd->i + 4)); }

void trap_obj_count_entry(BD_VALUE* bd) { bd->i = YS_OBJ_CountEntry(bd->i); }

void trap_bg_set_animation_speed(BD_VALUE* bd) { dk_Map_setAnimationSpeedRatio(2, bd->f); }

void trap_obj_star(BD_VALUE* bd) { bd->i = YS_PARTY_Get(bd->i); }

void trap_obj_fly_to_jump(BD_VALUE* bd) { YS_OBJ_fly_to_jump(*(void**)((char*)bd->i + 4)); }

u32 func_area_activate_unit(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS23func_area_activate_unitEP8BD_VALUE");
u32 func_area_activate_unit(u32 a0, u32 a1, u32 a2, u32 a3) { return func_0019eb60(a0, a1, a2, a3); }

u32 trap_obj_check_flag(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_obj_check_flagEP8BD_VALUE");
u32 trap_obj_check_flag(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0017ec30(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 320u), *(u32*)(a0 + 4u), a2, a3);
}

void trap_player_can_capture_form(BD_VALUE* bd) { bd->i = YS_CHANGEFORM_CanCaptureForm(bd); }

void trap_player_set_exec_rc(BD_VALUE* bd) {
    YS_PLAYER_set_exec_rc(*(void**)((char*)bd->i + 4), bd[1].i);
}

void trap_target_dup(BD_VALUE* bd) { bd->i = YS_TARGET_dup(bd->i); }

void trap_target_free(BD_VALUE* bd) { YS_TARGET_free(bd->i); }

void trap_target_is_exist(BD_VALUE* bd) { bd->i = YS_TARGET_is_exist(bd->i); }

u32 trap_target_set_obj(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_target_set_objEP8BD_VALUE");
u32 trap_target_set_obj(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00190878(*(u32*)(a0 + 0u), *(u32*)(*(u32*)(a0 + 4u) + 4u), 0, a3);
}

void trap_target_clear_before_player(BD_VALUE* bd) {
    (void)bd;
    YS_TARGET_ClearBeforePlayer();
}

void trap_event_get_rest_time(BD_VALUE* bd) { bd->f = YS_EVENT_GetRestTime(); }

void trap_event_continue_control_off(BD_VALUE* bd) {
    (void)bd;
    YS_EVENT_ContinueControlOff();
}

void trap_status_is_mission(BD_VALUE* bd) { bd->i = YS_MISSION_IsExec(); }

void trap_status_force_leave_end(BD_VALUE* bd) { bd->i = YS_STATUS_IsBattleMode(); }

void trap_status_set_prize_ratio(BD_VALUE* bd) { YS_STATUS_SetPrizeRatio(bd->f); }

void trap_camera_apply_pos(BD_VALUE* bd) { func_00226e60((s32)(bd->i != 0)); }

void trap_light_fadeout(BD_VALUE* bd) { YS_LIGHT_fadeout(bd->f); }

void trap_light_fadein(BD_VALUE* bd) { YS_LIGHT_fadein(bd->f); }

void trap_light_create(BD_VALUE* bd) { bd->i = YS_LIGHT_Create(bd->i); }

void trap_sheet_munny(BD_VALUE* bd) { bd->i = Tz_Munny_Get(); }

void trap_sheet_add_munny(BD_VALUE* bd) { bd->i = Tz_Munny_Add((u32)bd->i); }

u32 trap_sheet_attack_level(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS23trap_sheet_attack_levelEP8BD_VALUE");
u32 trap_sheet_attack_level(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r16 = a0;
    u32 r2 = func_001a27d8(*(u32*)(a0 + 0u), a1, a2, a3);
    *(u32*)(r16 + 0) = r2;
    return r2;
}

void trap_prize_num(BD_VALUE* bd) { bd->i = YS_PRIZE_GetAppearNum(); }

void trap_prize_num_ca(BD_VALUE* bd) { bd->i = YS_PRIZE_CA_GetAppearNum(); }

void trap_tutorial_is_open(BD_VALUE* bd) { bd->i = YS_WINDOW_SYSTEM_TUTORIAL_IsOpen(); }

u32 trap_picture_change(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_picture_changeEP8BD_VALUE");
u32 trap_picture_change(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0023f070(*(u32*)(a0 + 0u), *(u32*)(a0 + 4u), 0xffffffffu, a3);
}

void trap_jigsaw_get(BD_VALUE* bd) { YS_JIGSAW_Get(bd->i, bd[1].i); }

void trap_btlobj_target(BD_VALUE* bd) {
    (void)bd;
    func_0018f0b0(1, 0xffff);
}

void trap_attack_is_hit_bg(BD_VALUE* bd) { func_0018e040(bd->i); }

void trap_attack_exec_reflect(BD_VALUE* bd) { bd->i = YS_ATTACK_CHECK_NewComboGroup(); }

void trap_summon_is_tink_exist(BD_VALUE* bd) { bd->i = YS_SUMMON_IsTinkExist(); }

void trap_damage_element(BD_VALUE* bd) { bd->f = func_0018cb30(bd->i); }

void trap_damage_get_reaction_type(BD_VALUE* bd) { bd->i = YS_DAMAGE_GetReactionType(bd->i); }

void trap_damage_is_finish(BD_VALUE* bd) { bd->i = YS_DAMAGE_is_finish(bd->i); }

void trap_damage_is_normal(BD_VALUE* bd) { bd->i = YS_DAMAGE_is_normal(bd->i); }

void trap_magic_can_add_cost(BD_VALUE* bd) { bd->i = YS_MAGIC_CanAddCost(bd->f); }

void trap_mission_get_timer(BD_VALUE* bd) { bd->i = YS_MISSION_GetTimer(bd->i); }

void trap_mission_get_timer_second(BD_VALUE* bd) { bd->i = YS_MISSION_GetTimerSecond(bd->i); }

void trap_mission_get_count(BD_VALUE* bd) { bd->i = YS_MISSION_GetCount(bd->i); }

void trap_mission_get_gauge_ratio(BD_VALUE* bd) { bd->f = YS_MISSION_GetGaugeRatio(bd->i); }

void trap_mission_get_gauge_warning_ratio(BD_VALUE* bd) { bd->f = YS_MISSION_GetGaugeWarningRatio(bd->i); }

void trap_mission_is_gauge_warning(BD_VALUE* bd) { bd->i = YS_MISSION_IsGaugeWarning(bd->i); }

void trap_mission_set_combo_counter_warning_se(BD_VALUE* bd) {
    YS_MISSION_SetComboCounterWarningSe(bd->i, bd[1].i);
}

void trap_score_get(BD_VALUE* bd) { bd->i = YS_MINIGAME_GetScore(bd->i); }

}  // namespace YS

namespace Ti {

void trap_eh22_path_get_point(BD_VALUE* bd) { bd->i = Ti_MG_EHSidecar_GetCurrentPoint(); }

}  // namespace Ti

namespace Ts {

void trap_flare_is_empty(BD_VALUE* bd) { bd->i = Ts_FLARE_IsEmpty(); }

void trap_friend_call(BD_VALUE* bd) {
    (void)bd;
    bd->i = func_001b5af0();
}

void trap_bghit_get_cross_pos(BD_VALUE* bd) { bd->i = func_001d36e8(bd->i); }

void trap_attack_set_rc_owner(BD_VALUE* bd) { bd->i = (YS_SUMMON_GetMode() != 0); }

void trap_limit_reset_hit_counter(BD_VALUE* bd) { bd->i = YS_LIMIT_reset_hit_counter(bd->i); }

}  // namespace Ts

namespace kn {

void trap_attack_is_finish(BD_VALUE* bd) { bd->i = YS_ATTACK_is_finish(bd->i); }

}  // namespace kn
namespace YS {

class PROGRESS {
   public:
    static int CheckFlag(int flag);
    static int IsSecond();
};

class BATTLE_REPORT {
   public:
    static int IsSecretMovie();
    static int IsFMSecretMovie();
};

class ATTACK {
   public:
    int is_hit();
};

void trap_progress_check_flag(BD_VALUE* bd) {
    bd->i = PROGRESS::CheckFlag(bd->i);
}

void trap_progress_is_second(BD_VALUE* bd) { bd->i = PROGRESS::IsSecond(); }

void trap_progress_is_secret_movie(BD_VALUE* bd) {
    bd->i = BATTLE_REPORT::IsSecretMovie();
}

void trap_progress_is_fm_secret_movie(BD_VALUE* bd) {
    bd->i = BATTLE_REPORT::IsFMSecretMovie();
}

void trap_camera_set_scope_zoom(BD_VALUE* bd) { YS_LIGHT_fadeout(bd->f); }

void trap_camera_set_scope_closeup_distance(BD_VALUE* bd) { YS_LIGHT_fadein(bd->f); }

void trap_attack_is_hit(BD_VALUE* bd) { bd->i = ((ATTACK*)bd->i)->is_hit(); }

}  // namespace YS
