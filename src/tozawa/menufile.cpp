#include "menufile.hpp"
#include "file_address_layout.hpp"

namespace Tz {
s32 MenuFile::getFileAddress() const {
    return reinterpret_cast<const FileAddressLayout*>(this)->fileAddress;
}

}  // namespace Tz
