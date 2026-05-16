#include "types.h"


namespace worldmap {

} // namespace worldmap

class Event;
struct TASK;

class Event {
public:
 void start(s32 a0);
 u64 IsExec(void);
 Event(Event* a0, TASK* a1, s32 a2);
 ~Event();
 void exec(void);
 void execLibretto(s32 a0);
 void execThread(TASK* a0);
 void finalizeThread(TASK* a0);
 s64 CompareFlag(void* a0, void* a1);
};
