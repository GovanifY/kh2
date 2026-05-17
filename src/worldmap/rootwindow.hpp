#pragma once

#include "../common/types.h"

struct TASK;

namespace worldmap {

class RootWindow {
public:
    static void* get();
    RootWindow();
    ~RootWindow();
    void execTask(TASK*);
};

}  // namespace worldmap

