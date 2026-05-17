#pragma once

#include "../../common/types.h"

class HEADER;
struct TASK;

namespace YS {

    class CACHE_BUFF {
    public:
     void Link(HEADER* a0);
     s32 SearchByName(char* a0, s32 a1);
     void clearLink(void);
     u64 GetSize(void);
     s32 Dump(void);
     void FlushCompaction(void);
     void checkBrokenMemory(HEADER* a0);
     void FlushRead(void);
     void Init(void);
     void InitThread(void);
     void SetBlockSize(s32 a0, s32 a1);
     void SetPlayerBlockSize(s32 a0, s32 a1);
     void Clear(s32 a0);
     void ReadRequest(char* a0, s32 a1, u32 a2);
     void ReadRequestApdx(char* a0, s32 a1, s32 a2, u32 a3);
     void ReadRequestPack(char* a0, char** a1, u32 a2);
     u64 IsFlushingList(void);
     u64 IsFlushing(void);
     void WaitFlush(TASK* a0);
     void Flush(TASK* a0);
     u32 Alloc(char* a0, s32 a1);
     s32 Free(void* a0);
     void Destroy(s32 a0);
     void DestroyAll(void);
     void DestroyUnuse(char* a0);
     void DestroyPriority(s32 a0);
     void FixFree(void* a0);
     u64 GetStatus(char* a0);
     u32 GetPriority(char* a0);
     s32 GetFreeSize(void);
     s32 GetFree(void);
    };

}  // namespace YS

