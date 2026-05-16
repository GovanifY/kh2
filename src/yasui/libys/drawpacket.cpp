#include "types.h"


namespace YS {

} // namespace YS

class DRAWPACKET {
public:
 void Flush(void);
 void free(void);
 void alloc(u32 a0);
 s32 inc_pt(u32 a0);
 void set_regs(s32 a0, u64 a1, u64 a2, u64 a3);
 void set_regs(s32 a0, u64 a1, u64 a2, u64 a3, u64 a4, u64 a5);
 void send0(void);
 u32 AllocScratchPad(void);
 void FreeScratchPad(void);
 void unUsedScratchPad(void);
 void usedScratchPad(void);
};
