#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace kn {

} // namespace kn

class OBJ;
class TexanmSelector;

class TexanmSelector {
public:
 void readHeader(void);
 TexanmSelector(TexanmSelector* a0, OBJ* a1);
 ~TexanmSelector();
 void init(void);
};
