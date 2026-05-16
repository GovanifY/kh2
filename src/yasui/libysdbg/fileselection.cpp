#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class FILESELECTION;
class FuncDef50;

class FILESELECTION {
public:
 void set_list(void);
 FILESELECTION(FILESELECTION* a0, s32 a1, s32 a2, s32 a3, char* a4, FuncDef50* a5);
 ~FILESELECTION();
};
