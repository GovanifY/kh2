#pragma once

#include "../common/types.h"
#include "../common/task.hpp"

class BTLOBJ;
class FVector;
class LAST_XEMNUS_LASER;

namespace ryj {

    class LAST_XEMNUS_LASER {
    public:
     void init(void);
     LAST_XEMNUS_LASER();
     void setup(void);
     void exec_attack(void);
     void sort_pos_list(FVector* a0, s32 a1);
     void exec(void);
     void Start(BTLOBJ* a0);
     void Optimize(void);
     void OptimizeEnd(void);
     void Attack(void);
     void End(void);
     void ExecTask(TASK* a0);
     void ExecTaskFinalizer(TASK* a0);
    };

}  // namespace ryj

