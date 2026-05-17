#ifndef KH2_SRC_WORLDMAP_ROOTWINDOW_HPP
#define KH2_SRC_WORLDMAP_ROOTWINDOW_HPP

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

#endif
