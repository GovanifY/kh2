#pragma once

#include "../../common/types.h"

class AREA;

namespace dk {

class Area {
public:
    void setMapFile(char* a0);
    void readData(void);
    void initMap(u64 a0);
    void init(void);
    void start(void);
    void exit(void);
    void cacheBuffDestroy(AREA* a0);
    void finalizer(AREA* a0);
};

}  // namespace dk

