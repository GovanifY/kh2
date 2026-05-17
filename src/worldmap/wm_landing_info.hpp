#pragma once

#include "../common/types.h"

namespace dk {

class WM_LANDING {
public:
    bool isListType();
    bool isEpisodeType();
};

class WM_LANDING_INFO {
public:
    void fadeout();
    void exit();
};

}  // namespace dk

