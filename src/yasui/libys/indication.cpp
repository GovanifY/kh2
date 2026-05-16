#include "types.h"


namespace YS {

} // namespace YS

class PLAYER;

class INDICATION {
public:
 void init_field(void);
 void _disable(void);
 void disable(void);
 void init_area(void);
 void enable(void);
 void start(PLAYER* a0);
 void end(void);
 void exec(void);
 void show(void);
 void hide(void);
 void Disable(void);
 void Enable(void);
};
