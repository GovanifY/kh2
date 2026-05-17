#pragma once

#include "../common/types.h"
#include "../common/task.hpp"


namespace worldmap {

class RootWindow {
public:
    static void* get();
    RootWindow();
    ~RootWindow();
    void execTask(TASK*);
};

}  // namespace worldmap

