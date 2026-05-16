#include "types.h"


namespace dk {

} // namespace dk

class MapFile;
class Radar;

class Radar {
public:
 void create(void* a0);
 void update(void);
 void draw(void);
 ~Radar();
 void on(void);
 void off(void);
 s32 init(MapFile* a0);
 void exit(void);
 void debugOn(void);
};
