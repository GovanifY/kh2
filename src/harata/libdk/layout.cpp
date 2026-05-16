#include "types.h"


namespace dk {

} // namespace dk

class Layout;

class Layout {
public:
 void destroy(void);
 void setPos(f32 a0, f32 a1);
 void init(void);
 void exit(void);
 ~Layout();
};
