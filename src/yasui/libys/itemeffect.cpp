#include "types.h"


namespace YS {

} // namespace YS

class ITEM_EFFECT;
class OBJ;
struct TASK;

class ITEM_EFFECT {
public:
 void use(void);
 u64 exec(void);
 ~ITEM_EFFECT();
 void Exec(TASK* a0);
 void Init(void);
 void ClearAll(void);
 void Cast(OBJ* a0);
};
