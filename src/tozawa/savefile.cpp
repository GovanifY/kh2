#include "types.h"


namespace Tz {

} // namespace Tz

class SaveFile;

class SaveFile {
public:
 SaveFile();
 ~SaveFile();
 s32 getIcoAddress(void);
 s32 getSysIcoAddress(void);
 void buildData(void* a0);
};
