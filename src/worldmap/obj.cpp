#include "types.h"


namespace worldmap {

} // namespace worldmap

class FVector;
class OBJENTRY;
class Obj;

class Obj {
public:
 Obj(Obj* a0, OBJENTRY* a1, FVector* a2, f32 a3);
 u64 appear(OBJENTRY* a0, FVector* a1, f32 a2);
 void applyStateAll(void);
 void checkStateAll(void);
};
