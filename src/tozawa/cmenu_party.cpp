#include "cmenu_party.hpp"

extern void Tz_CmParty_FadeOutList(void) asm("_ZN2Tz7CmParty11FadeOutListEv");
extern void Tz_CmParty_LeaveList(void) asm("_ZN2Tz7CmParty9LeaveListEv");

namespace Tz {
void CmParty::FadeOutAll() { Tz_CmParty_FadeOutList(); }
void CmParty::LeaveAll() { Tz_CmParty_LeaveList(); }
}  // namespace Tz
