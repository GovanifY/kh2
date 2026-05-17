#pragma once

#include "../common/types.h"
#include "../common/task.hpp"

class BINARC;
class MODEL_GUMI;
class MemoryAllocator;
class PLAN;

namespace gm {

    class CONVERT {
    public:
     u32 GetGumiAttachmentData(char* a0);
     u32 GetBaseKntFile(s32 a0);
     u32 GetBaseKntFileSize(s32 a0);
     u32 GetPxlFile(s32 a0);
     u32 GetPxlFileSize(s32 a0);
     u32 GetBasePxlFile(void);
     u32 GetBasePxlFileSize(void);
     u32 GetCltFileSize(s32 a0);
     u32 GetCltFile(s32 a0);
     u32 GetBaseCltFile(void);
     u32 GetBaseCltFileSize(void);
     s32 CreateTexture(MemoryAllocator* a0, void* a1, void* a2, PLAN* a3);
     s32 GetTextureSize(PLAN* a0);
     u64 CreateModel(MemoryAllocator* a0, PLAN* a1);
     void DestroyModel(MemoryAllocator* a0, MODEL_GUMI* a1);
     u32 GetUserKntFile(void);
     u32 GetUserKntFileSize(void);
     void Init(MemoryAllocator* a0);
     void SetPxlData(BINARC* a0);
     void SetCltData(BINARC* a0);
     void SetKntData(BINARC* a0);
     void Load(TASK* a0);
     void Ensure(void);
    };

}  // namespace gm

