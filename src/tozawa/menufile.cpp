#include "types.h"

namespace Tz {
class MenuFile {
public:
    s32 getFileAddress() const;
};

struct FileAddressLayout {
    char _pad0[4];
    s32 fileAddress;
};

s32 MenuFile::getFileAddress() const {
    return reinterpret_cast<const FileAddressLayout*>(this)->fileAddress;
}

}  // namespace Tz
