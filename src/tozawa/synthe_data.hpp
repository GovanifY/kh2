#ifndef KH2_SRC_TOZAWA_SYNTHE_DATA_HPP
#define KH2_SRC_TOZAWA_SYNTHE_DATA_HPP

#include "types.h"

namespace Tz {

class MenuFile;

class SyntheData {
public:
    static void LeadData(MenuFile*);
    static u32 GetMixDataFname();
};

}  // namespace Tz

#endif
