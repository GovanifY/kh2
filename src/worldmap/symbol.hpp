#pragma once

#include "../common/types.h"

class ATTACK;
class ATTACKPARAM;
class BTLOBJ;
class FVector;
class OBJENTRY;
class Symbol;
class WORLDSTATE;

namespace worldmap {

    class Symbol {
    public:
     Symbol(Symbol* a0, OBJENTRY* a1, FVector* a2, f32 a3);
     void _OVR_checkState(void);
     void _OVR_applyState(void);
     void appearEpisodeAll(void);
     void _OVR_exec(void);
     void setState(WORLDSTATE* a0);
     void _OVR_attack_callback(BTLOBJ* a0, ATTACK* a1, ATTACKPARAM* a2);
     void appearEpisode(void);
    };

}  // namespace worldmap

