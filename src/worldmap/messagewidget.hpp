#pragma once

#include "../common/types.h"

namespace worldmap {

class MessageWidget {
public:
    MessageWidget(s32, s32);
    ~MessageWidget();
    u32 isEnd();
};

}  // namespace worldmap

