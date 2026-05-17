#ifndef KH2_SRC_NAKA_LIBKN_EFFECT_OBSERVER_HPP
#define KH2_SRC_NAKA_LIBKN_EFFECT_OBSERVER_HPP

#include "../../common/types.h"

class EFFECT;
class EffectObserver;

namespace kn {

    class EffectObserver {
    public:
     void Init(void);
     void Update(void);
     void Create(EffectObserver** a0);
     ~EffectObserver();
     void removeEntry(EFFECT* a0);
     void addEntry(EFFECT* a0);
     s32 getIndex(EFFECT* a0);
    };

}  // namespace kn

#endif
