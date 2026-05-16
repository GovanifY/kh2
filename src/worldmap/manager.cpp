#include "types.h"


namespace worldmap {

} // namespace worldmap

class Manager {
public:
 void readPackDisable(void);
 void readPackEnable(void);
 void readPack(void);
 void read(void);
 void initialize(void);
 void exit(void);
 u8 isExec(void);
};
