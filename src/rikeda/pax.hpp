#pragma once

#include "../common/types.h"
#include "../common/task.hpp"

class ALLOCATOR;
class EFFECT;
class PAX;
class USER_BIND_ARGS;

namespace ryj {

    class PAX {
    public:
     PAX();
     void kill_all(void);
     ~PAX();
     void init(void* a0);
     u64 start(s32 a0, s32 a1, s32 a2, s32 a3, void* a4);
     u64 start(s32 a0, USER_BIND_ARGS* a1, s32 a2, s32 a3, s32 a4);
     void start_group(s32 a0, s32 a1, s32 a2, s32 a3, void* a4);
     u64 search_id(u64 a0);
     void kill_group(s32 a0);
     u32 each_group(s32 a0, EFFECT* a1);
     void unbind(EFFECT* a0);
     void dup(PAX* a0);
     s32 get_elem(s32 a0);
     void watch(void);
     void ReadRequest(void);
     void ReadRequest(bool a0);
     void TaskStart(void);
     void Init(ALLOCATOR* a0, s32 a1, s32 a2);
     void exec(void);
     void ExecTask(TASK* a0);
     void Ensure(void);
     void Setup(void* a0);
     void Shift(void* a0, void* a1);
     u64 ThisIsValid(PAX* a0);
     void ErrorHook(void);
     void PushMode(s32 a0);
     void PopMode(void);
     void Dispose(void* a0);
     void WatchTask(TASK* a0);
     void WatchTaskFinalizer(TASK* a0);
    };

}  // namespace ryj

