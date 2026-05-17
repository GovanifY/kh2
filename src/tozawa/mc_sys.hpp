#ifndef KH2_SRC_TOZAWA_MC_SYS_HPP
#define KH2_SRC_TOZAWA_MC_SYS_HPP

#include "../common/types.h"

class ALLOCATOR;

namespace Tz {

class McSys {
public:
    McSys(McSys* a0, ALLOCATOR* a1);
    ~McSys();
    u32 GetDataBuff(void);
    void SetGameClear(bool a0);
    u64 isGameClearKH2(void);
    void Update(void);
    void isEnableDataKH2(void);
    void InitKH2(void);
    void MergeProgress(void* a0);
    void endian_read_KH2(void);
    void endian_write_KH2(void);
};

}  // namespace Tz

#endif
