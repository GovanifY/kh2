#include "types.h"


namespace worldmap {

} // namespace worldmap

class Player;
class TARGET;

class Warp {
public:
 void start(Player* a0, TARGET* a1);
 void exec(Player* a0);
};
