#pragma once

#include "../common/types.h"

class ALLOCATOR;
class COLOR;
class Camera;
class FMatrix;
class FVector;
class PAX;
class Projection;
struct TASK;
class uchar;

namespace ryj {

class EFFECT {
public:
 u32 is_alive();
 void set_no_draw();
 void PaxInit(void);
 void Load(void);
 void Ensure(void);
 u64 AttackNoToPaxCategory(s32 a0, u64 a1);
 void AttackNoToPaxID(PAX* a0, s32 a1, u64 a2);
 void SetRelativeControl(EFFECT* a0);
 u64 start(f32 a0);
 bool is_valid(void);
 u64 is_active(void);
 void pos(void);
 u32 data(void);
 void SortEffect(void);
 EFFECT(EFFECT* a0, u32 a1, u32 a2);
 ~EFFECT();
 void scale(void);
 void angle(void);
 void color(void);
 void stop(bool a0);
 void stop_onoff(void);
 void bind_stop(bool a0);
 u64 is_stop(void);
 u64 is_loop(void);
 void loop_end(void);
 void loop_end_kill(void);
 void free(void);
 void fadeout_free(f32 a0);
 void kill(void);
 void fadeout_kill(f32 a0);
 u64 is_waiting(void);
 u64 is_delete(void);
 void set_reference_pos(FVector* a0, s32 a1);
 void set_reference_matrix(FMatrix* a0, s32 a1);
 void fade(void);
 void set_color(COLOR* a0);
 void set_draw_first(u32 a0);
 void reset_no_draw(void);
 u64 is_draw(void);
 void set_no_viewclip(void);
 void InitOnce(void);
 void ReadRequestTexCommon(void);
 void TexCommonLoaded(void);
 void Init(ALLOCATOR* a0, s32 a1, s32 a2);
 void Monochrome(bool a0);
 void Free(u32 a0);
 void SetFogRange(f32 a0, f32 a1);
 void SetFogColor(uchar a0, uchar a1, uchar a2);
 void SetFogClamp(uchar a0, uchar a1);
 u32 GetEffectNum(void);
 void Prev(EFFECT* a0);
 void CheckWorkMemory(void);
 void Calc(Projection* a0, Camera* a1, bool a2);
 void CalcTask(TASK* a0);
 void DrawTask(TASK* a0);
 void DestroyTask(TASK* a0);
 void StopTask(void);
 void StartTask(void);
 void MenuStart(void);
 void MenuEnd(void);
 void PrintPerformance(void);
 s32 GetEffectIndex(EFFECT* a0);
 void Read(void);
 void Init(void);
 void Exec(void);
 void AddDeadEffect(EFFECT* a0);
};

} // namespace ryj

