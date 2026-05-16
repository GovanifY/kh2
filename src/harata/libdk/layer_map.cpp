#include "types.h"


namespace dk {

} // namespace dk

class MapFile;

class LAYER_MAP {
public:
 void init(MapFile* a0);
 void finalizer(void);
 void on(void);
 void off(void);
};
