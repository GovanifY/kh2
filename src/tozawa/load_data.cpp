#include "load_data.hpp"

extern void YS_CACHE_BUFF_Clear(s32) asm("_ZN2YS10CACHE_BUFF5ClearEi");
extern void YS_CACHE_BUFF_Flush(TASK*) asm("_ZN2YS10CACHE_BUFF5FlushEP4TASK");
extern void* YS_CACHE_BUFF_Alloc(char const*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");

namespace Tz {

extern "C" u32 func_00170cd0(...);
extern "C" void func_00170518(...);
extern u8 D_00360000 asm("D_00360000");

void LoadData::Request(const char* a0, s32 a1, bool a2) {
    u32 s16 = (u32)a0;
    u32 s17 = (u32)a1;
    if (((u32)a2 & 0xff) == 0) {
        func_00170cd0();
    }
    func_00170518(s16, s17, 0);
    u8* base = (u8*)&D_00360000;
    base[-2888] = 1;
}

void LoadData::FlushTask(TASK* task) { YS_CACHE_BUFF_Flush(task); }
void LoadData::Clear(s32 priority) { YS_CACHE_BUFF_Clear(priority); }
void* LoadData::CacheAlloc(const char* path) {
    return YS_CACHE_BUFF_Alloc(path, -1);
}
}  // namespace Tz
