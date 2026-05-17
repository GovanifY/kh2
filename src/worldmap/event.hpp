#ifndef KH2_SRC_WORLDMAP_EVENT_HPP
#define KH2_SRC_WORLDMAP_EVENT_HPP

#include "../common/types.h"

struct TASK;

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

#endif
