#ifndef KH2_SRC_HARATA_LIBDK_MAPFILE_HPP
#define KH2_SRC_HARATA_LIBDK_MAPFILE_HPP

#include "../../common/types.h"

class AREA;
class MapFile;

namespace dk {

    class MapFile {
    public:
     MapFile();
     u32 getMapModelAddress(void);
     u32 getMapTexAddress(void);
     u32 getOcdAddress(void);
     u32 getOccAddress(void);
     u32 getOchAddress(void);
     u32 getOclAddress(void);
     u32 getOwaAddress(void);
     u32 getMonAddress(void);
     u32 getBopAddress(void);
     u32 getPlxAddress(void);
     u32 getTelopImdAddress(void);
     u32 getTelopSqdAddress(void);
     u32 getPaxAddress(void);
     u32 getRadarAddress(s32 a0);
     u32 getMclAddress(void);
     s32 getBgObjModelAddress(s32 a0);
     u32 getBgObjTexAddress(s32 a0);
     u32 getBgObjMotionSetAddress(s32 a0);
     void buildMapFileName(AREA* a0, char* a1);
     void setMapFile(void);
     void readRequest(void);
     void init(void);
     void exit(void);
    };

}  // namespace dk

#endif
