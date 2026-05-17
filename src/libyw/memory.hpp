#ifndef KH2_SRC_LIBYW_MEMORY_HPP
#define KH2_SRC_LIBYW_MEMORY_HPP

#include "types.h"

class Space;
class anonymous_namespace;

class MEMORY {
public:
    s32 alloc(u32 a0);
    void free(void* a0);
    void Init(void);
    void Ensure(void);
    u32 GetAllocator(void);
    void Alloc(u32 a0);
    void Alloc(u32 a0, u32 a1, void** a2, void** a3);
    void Free(void* a0);
    void MemInit(void);
    void MemEnsure(void);
};

class Memory {
public:
    void DeleteSpace(Space* a0);
    void (anonymous_namespace)::System::Malloc(uint a0, u32 a1);
    void (anonymous_namespace)::System::Free(void* a0);
    u64 (anonymous_namespace a0);
};

#endif
