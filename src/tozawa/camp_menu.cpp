#include "types.h"


namespace Tz {

} // namespace Tz

class ARGS;
class SELECTOR;

class CampMenu {
public:
 void InitPriority(void);
 void Init(s32 a0);
 void StartBasic(s32 a0);
 void Start(s32 a0, s32 a1);
 void Dummy(void);
 void StartParty(s32 a0, void* a1);
 void StartJiminy(s32 a0, s32 a1);
 void StartHelpGra(void* a0, void* a1);
 void Exit(s32 a0);
 void StartSelector(SELECTOR* a0, ARGS* a1);
 void RestartSelector(SELECTOR* a0, ARGS* a1);
 void SetWorldMapType(s32 a0);
 u32 GetWorldMapType(void);
 u64 GetChangein(void);
 void SetJmStartMenu(s32 a0);
 u32 GetJmStartMenu(void);
};
