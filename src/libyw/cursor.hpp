#pragma once

#include "../common/types.h"
#include "../common/task.hpp"

class BOX;
class COST;
class CURSOR;
class FMatrix;
class FVector;
class FuncDef37;
class GUMI;
class PAD;
class STATUSWINDOW;
class WINDOW;
class WORKAREACAMERA;
class WORKBLOCK;

class CURSOR {
public:
    void select_difference_level(void);
    u64 move_cursor_block(FVector* a0);
    u64 move_cursor_center(FVector* a0);
    void move_cursor_prev(void);
    void move_cursor_normal(void);
    u64 move_cursor(void);
    u64 rot_has_gumi_lump(void);
    u64 rot_has_gumi(void);
    void calc_range_box(void);
    void create_copy(FVector* a0);
    u64 rot_copy_mirror(void);
    void gumi_mirror(GUMI* a0);
    void mirror(void);
    void calc_range_select_draw(void);
    void range_select_clear(void);
    void snap(BOX* a0, FVector* a1);
    CURSOR(CURSOR* a0, WORKAREACAMERA* a1, COST* a2, s32 a3, s32 a4);
    ~CURSOR();
    void calc_move_area(void);
    u64 calc_out_block(s32 a0);
    void init(s32 a0, void* a1);
    void start(s32 a0, s32 a1, void* a2, STATUSWINDOW* a3);
    void end(void);
    void update_mode(void);
    void snap(void);
    void move(void);
    void set_difference_level_cancel(s32 a0);
    void force_exit(void);
    void redo(void);
    void undo(void);
    void range_select(void);
    void delete_gumi(WORKBLOCK* a0);
    void delete_range_select_gumi(void);
    void delete_gumi(void);
    void cancel(void);
    void copy_select_gumi(void);
    void range_add_list(void);
    u32 get_select_direction(void);
    void has_multi_gumi(void);
    void has_select_gumi(void);
    void set_difference_level_decide(s32 a0);
    void paint_texture(WORKBLOCK* a0);
    void decide(void);
    void key(void);
    void adjust_gumi(void);
    void update(void);
    void draw(void);
    void draw_range_select_area(void);
    void draw_cursor_box(void);
    void get_move_plane_position(FVector* a0, FMatrix* a1);
    void get_move_plane_position(FMatrix* a0, bool a1);
    void get_move_plane_position(void);
    u64 get_move_plane_mode(void);
    void DrawRangeSelect(TASK* a0);
    void DrawCursorBox(TASK* a0);
    void update_xy(int* a0, int* a1);
    void set(s32 a0, s32 a1);
    s32 exec(TASK* a0);
    s32 get_select(void);
    void set_select_callback(FuncDef37* a0);
    void exec(WINDOW* a0, PAD* a1);
    void draw(void);
    void update(f32 a0, f32 a1, u32 a2, s32 a3, s32 a4);
    void start(s32 a0, s32 a1);
    void move(FVector* a0);
};

