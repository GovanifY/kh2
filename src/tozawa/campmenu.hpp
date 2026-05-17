#ifndef KH2_SRC_TOZAWA_CAMPMENU_HPP
#define KH2_SRC_TOZAWA_CAMPMENU_HPP

#include "types.h"

namespace Tz {

class ARGS;
class SELECTOR;

class CampMenu {
public:
    static u32 StartJiminy(s32, s32);
    static void SetJmStartMenu(s32);
    void InitPriority(void);
    void Init(s32 a0);
    void StartBasic(s32 a0);
    void Start(s32 a0, s32 a1);
    void Dummy(void);
    void StartParty(s32 a0, void* a1);
    void StartHelpGra(void* a0, void* a1);
    void Exit(s32 a0);
    void StartSelector(SELECTOR* a0, ARGS* a1);
    void RestartSelector(SELECTOR* a0, ARGS* a1);
    void SetWorldMapType(s32 a0);
    u32 GetWorldMapType(void);
    u64 GetChangein(void);
    u32 GetJmStartMenu(void);
};

}  // namespace Tz

#endif
