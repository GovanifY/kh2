#pragma once

#include "../common/types.h"
#include "../common/task.hpp"

class DrawParam;
class FILTER;
class FMatrix;
class GUMISHIP;
class MODEL_GUMI;
class MemoryAllocator;

namespace gm {

class PLAN {
public:
 void ensure(void);
 void get_decogumi_num(void);
 void get_material_num(void);
 void get_hp(void);
 void get_power(void);
 void get_speed(void);
 void get_dash(void);
 void get_search(void);
 void get_decogumi_position(s32 a0);
 void get_material_position(s32 a0);
 void get_size(void);
 void get_ability_num(void);
 void get_ability_item_id(s32 a0);
 u32 get_decogumi_entry_id(s32 a0);
 void set_plan(PLAN* a0, TASK* a1);
 void create_decogumi(GUMISHIP* a0, s32 a1);
 void draw(FMatrix* a0, DrawParam* a1);
 u64 is_exist(void);
 s32 dump_cost(bool a0);
 u32 GetRecommendPlanItemIdNewGet(u32 a0);
 u32 GetRecommendPlanItemIdNewGetNum(void);
 u64 RecommendPlanGet(void);
 void LoadRecommendPlan(TASK* a0);
 void InitRecommendPlan(void);
 void EnsureRecommendPlan(void);
 u16 get_material_num(void);
 u16 get_decogumi_entry_id(s32 a0);
 u16 get_decogumi_num(void);
 s32 get_search(void);
 s32 get_dash(void);
 s32 get_speed(void);
 s32 get_power(void);
 s32 get_attack(void);
 u64 is_equep_crown(void);
 s32 get_hp(void);
 s32 dump(void);
 u16 get_name_size(void);
 s32 get_data_size(void);
 s32 copy(PLAN* a0);
 s32 write(char* a0, MemoryAllocator* a1);
 void get_ability_max(void);
 u64 check_block_num(FILTER* a0, int* a1, s32 a2, s32 a3);
 u8 get_material_texture_no(s32 a0);
 s32 get_texture(s32 a0);
 u8 get_decogumi_texture_slot_number(s32 a0);
 void get_decogumi_texture(s32 a0, MODEL_GUMI* a1);
 u8 get_material_texture_slot_number(s32 a0);
 void get_matrix(s32 a0, FMatrix* a1);
 void get_position(s32 a0);
 void get_material_position(s32 a0);
 void get_decogumi_position(s32 a0);
 void get_matrix(s32 a0, bool a1);
 void get_decogumi_matrix(s32 a0, bool a1);
 s32 get_ap(void);
 void get_gumiship_size(void);
 s32 get_gumiship_max_size(void);
 s32 get_gumiship_min_size(void);
 s32 get_name_code(void);
 u64 get_name(char* a0);
 void set_name(s32 a0, ushort* a1);
 u64 is_mirror(s32 a0);
 u64 is_decogumi_mirror(s32 a0);
 void remove(void);
 u16 get_ability_id(s32 a0);
 s32 get_can_tiny_set_num(void);
 s32 get_max_cost(void);
 s32 get_cost(void);
 s32 get_tiny_max_cost(void);
 u64 can_create(PLAN* a0, PLAN* a1, s32 a2);
 void can_create_tiny(void);
 void InitPlanInfoData(void);
 void ReadPlanInfoData(TASK* a0);
 u32 GetPlanInfoData(void);
 void EnsurePlanInfoData(void);
 void SetupPlanInfo(void);
 u64 GetDefaultData(s32 a0, PLAN** a1, PLAN** a2, PLAN** a3);
 u64 is_create(void);
 s32 get_arrange_data(void);
};

} // namespace gm

