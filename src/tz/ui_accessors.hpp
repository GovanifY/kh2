#pragma once

#include "../common/types.h"

namespace Tz {

class PartyInfo;

struct PartyInfoLayout {
    s32 partyMax;
};

struct ItemInfoLayout {
    s32 infoMax;
    char _pad0[4096];
    PartyInfo* partyInfo;
};

struct MultiSeqLayout {
    char _pad0[52];
    s32 exMode;
};

struct HelpGraLayout {
    char _pad0[408];
    s32 pri;
};

class CmComm {
public:
    s64 GetIconMsgSize();
};

}  // namespace Tz

