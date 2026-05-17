#pragma once

#include "../../common/types.h"

class WIDGET;

namespace YS {

class CONFIG {
public:
 void GetReportNo(s32 a0, void* a1);
 void ChangeMoveSpeed(s32 a0, void* a1);
 void ChangeAttackRate(s32 a0, void* a1);
 void ChangeExpRate(s32 a0, void* a1);
 void ChangeFlag(bool a0, void* a1);
 void ChangeFlag2(bool a0, void* a1);
 void ChangeFlag2_1(bool a0, void* a1);
 void ChangeRegion(s32 a0, void* a1);
 void ChangePauseMode(s32 a0, void* a1);
 s32 save(void);
 s32 Save(s32 a0);
 s32 Save(void* a0);
 void Edit2Open(s32 a0);
 void Open(s32 a0);
 void Finalizer(WIDGET* a0);
 s32 SetStartArea(s32 a0);
 CONFIG();
 void Init(void);
 void SetStartArea(void);
};

} // namespace YS

