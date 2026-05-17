#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class OBJ;
class VOICE;

namespace YS {

    class VOICE {
    public:
     u64 is_play(void);
     void stop(void);
     ~VOICE();
     void request(s32 a0, s32 a1, OBJ* a2);
     void exec(void);
     void TransferCallback(void* a0);
     void ReadCallback(void* a0, u32 a1, void* a2);
     void ReadEntryId(u32 a0, void* a1);
     void Clear(void);
     void Init(void* a0);
     void ReadEnd(void);
     void Read(TASK* a0);
     s32 GetBank(s32 a0);
     s32 GetPartyNum(s32 a0, s32 a1);
     u64 GetTableNum(s32 a0, s32 a1, s32 a2, int* a3);
    };

}  // namespace YS

