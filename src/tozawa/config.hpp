#ifndef KH2_SRC_TOZAWA_CONFIG_HPP
#define KH2_SRC_TOZAWA_CONFIG_HPP

#include "types.h"

namespace Tz {

class Config {
public:
    static u32 isEventViewer();
    static u32 isChapterAll();
    static u32 isVibration();
    static u32 isNaviOn();
    static u32 isCameraAuto();
    static u32 isCommandKH2();
    static u32 isRightStickCamera();
};

}  // namespace Tz

#endif
