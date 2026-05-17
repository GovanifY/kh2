#ifndef KH2_SRC_TOZAWA_JM_SYNTHE_HPP
#define KH2_SRC_TOZAWA_JM_SYNTHE_HPP

#include "types.h"

namespace Tz {

class JmSynthe {
public:
    u64 isEnableMaterial(void);
    bool isEnableRecipe(void);
    void CreateList(void);
    void Init(void);
    void Exit(void);
    void FadeOutAll(void);
    void LeaveAll(void);
    void Setup(void);
    void Control(void);
    u64 isEnable(void);
    void ReadMixData(void);
    void GetMixData(void);
};

}  // namespace Tz

#endif
