#pragma once

#include "../common/types.h"

namespace Tz {

class MenuFile;

class SyntheData {
public:
    static void LeadData(MenuFile*);
    static u32 GetMixDataFname();
};

}  // namespace Tz

