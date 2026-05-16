#include "types.h"


class FMatrix;
class MemoryAllocator;
struct TASK;

namespace gm {

class GUMIBLOCKDATA {
public:
 u16 get_parameter(char a0);
 void Init(MemoryAllocator* a0);
 void Load(TASK* a0);
 void MsetReadRequest(TASK* a0);
 void Ensure(void);
 u32 GetIdx(u32 a0);
 s32 Get(u32 a0);
 void get_dl_pos(s32 a0);
 void GetGlobalSize(s32 a0, FMatrix* a1);
 u64 IsUnitSize(s32 a0);
 u64 GetBattleItemNum(s32 a0);
 void GetItemNum(s32 a0);
 void GetTextureset(s32 a0);
 u64 GetTinyshipSystem(void);
 void GetMaterial(void);
 u64 is_material(void);
};


} // namespace gm
