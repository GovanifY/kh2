#include "types.h"


namespace dk {

} // namespace dk

class GAUGE_DRAW {
public:
 void off(void);
 void init(void);
 void exit(void);
 void on(void);
 void drawStart(void);
 void drawEnd(void);
 s32 getImage(void);
 u32 getFriend1(void);
 u32 getEnemy(void);
 void checkAlertOff(void);
};
