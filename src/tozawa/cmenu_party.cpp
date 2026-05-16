#include "types.h"

extern void Tz_CmParty_FadeOutList(void) asm("_ZN2Tz7CmParty11FadeOutListEv");
extern void Tz_CmParty_LeaveList(void) asm("_ZN2Tz7CmParty9LeaveListEv");

namespace Tz {
class CmParty {
public:
    static void FadeOutAll();
    static void LeaveAll();
};

void CmParty::FadeOutAll() { Tz_CmParty_FadeOutList(); }
void CmParty::LeaveAll() { Tz_CmParty_LeaveList(); }
}  // namespace Tz
