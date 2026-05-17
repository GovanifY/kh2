#ifndef KH2_SRC_WORLDMAP_MESSAGEWIDGET_HPP
#define KH2_SRC_WORLDMAP_MESSAGEWIDGET_HPP

#include "../common/types.h"

namespace worldmap {

class MessageWidget {
public:
    MessageWidget(s32, s32);
    ~MessageWidget();
    u32 isEnd();
};

}  // namespace worldmap

#endif
