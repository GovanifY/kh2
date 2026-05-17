#pragma once

#include "../common/types.h"

namespace worldmap {

class Manager {
public:
    void readPackDisable();
    void readPackEnable();
    void readPack();
    void read();
    void initialize();
    void exit();
    u8 isExec();
};

}  // namespace worldmap

