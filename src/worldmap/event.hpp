#pragma once

#include "../common/types.h"
#include "../common/task.hpp"


namespace worldmap {

class Event {
public:
    void start(s32);
    u64 IsExec();
    Event(TASK*, s32);
    ~Event();
    void exec();
    void execLibretto(s32);
    void execThread(TASK*);
    void finalizeThread(TASK*);
    s64 CompareFlag(void*, void*);
};

}  // namespace worldmap

