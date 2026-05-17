#ifndef KH2_SRC_TAITO_MAP_PATH_OPT_HPP
#define KH2_SRC_TAITO_MAP_PATH_OPT_HPP

#include "../common/types.h"

class MapPathOpt;

namespace Ti {

    class MapPathOpt {
    public:
     MapPathOpt();
     void set(void* a0);
     u32 get_course_count(void);
     void get_course_info(s32 a0);
    };

}  // namespace Ti

#endif
