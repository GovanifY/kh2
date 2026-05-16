#include "types.h"


namespace dk {

} // namespace dk

class ALIGN;

class INFO_BASE {
public:
 void update(void);
 void destroy(void);
 void create(s32 a0, s32 a1, s32 a2, s32 a3, ALIGN a4);
 void init(void);
};
