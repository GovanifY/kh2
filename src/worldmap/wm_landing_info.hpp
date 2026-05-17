#ifndef KH2_SRC_WORLDMAP_WM_LANDING_INFO_HPP
#define KH2_SRC_WORLDMAP_WM_LANDING_INFO_HPP

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

#endif
