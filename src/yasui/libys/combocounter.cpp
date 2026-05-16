#include "types.h"


namespace YS {

} // namespace YS

class COMBOCOUNTER;

class COMBOCOUNTER {
public:
 COMBOCOUNTER();
 ~COMBOCOUNTER();
 void set_combo_max(s32 a0);
 void add(s32 a0, f32 a1);
 void reset(void);
 u64 exec(void);
 void activate(void);
 void reset_warning(void);
};
