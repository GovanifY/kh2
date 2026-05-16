#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class TEST_ITEM;

class TEST_ITEM {
public:
 void make_list(s32 a0, s32 a1);
 TEST_ITEM(TEST_ITEM* a0, s32 a1);
 void ChangeType(s32 a0, void* a1);
 void ChangeAbilityType(s32 a0, void* a1);
 void GetAll(void* a0);
 void OpenWindow(s32 a0);
 void OpenObjWindow(s32 a0);
 void Init(void);
 ~TEST_ITEM();
};
