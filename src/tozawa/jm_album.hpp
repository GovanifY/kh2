#ifndef KH2_SRC_TOZAWA_JM_ALBUM_HPP
#define KH2_SRC_TOZAWA_JM_ALBUM_HPP

#include "../common/types.h"

namespace Tz {

class JmAlbum {
public:
    static void RequestGraLoad(s32);
    static u32 GetAlbumData(u32);
    static u32 GetImageName(u32);
    static void RequestLoad(u32, void*, u32);
};

}  // namespace Tz

#endif
