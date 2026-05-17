#ifndef KH2_SRC_RIKEDA_SAVERAM_GUMIBATTLE_HPP
#define KH2_SRC_RIKEDA_SAVERAM_GUMIBATTLE_HPP

#include "../common/types.h"

class SAVERAM_GUMIBATTLE;

namespace ryj {

    class SAVERAM_GUMIBATTLE {
    public:
     SAVERAM_GUMIBATTLE();
     void new_game(void);
     s32 get_record(s32 a0, s32 a1, bool a2);
     double get_all_treasure_complete(void);
     u64 is_treasure_complete(void);
    };

}  // namespace ryj

#endif
