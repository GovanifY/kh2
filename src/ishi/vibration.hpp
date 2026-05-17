#pragma once

#include "../common/types.h"

struct TASK;

namespace YI {

class VIBRATION {
public:
 VIBRATION();
 ~VIBRATION();
 void Reset(void);
 u64 Create(char* a0);
 void Enable(void);
 void Disable(void);
 void Stop(void);
 u64 IsBusy(void);
 void Management(void);
 void Run(TASK* a0);
};

} // namespace YI

