#include "../common/types.h"


namespace Ti {

} // namespace Ti

class FMatrix;
class FVector;
class MGObj;
class OBJ;
class OBJENTRY;
class UNIT_DATA_OBJ;

class MGObj {
public:
 void _OVR_initialize(void);
 void _OVR__destroy(void);
 void _OVR_leave_req(void);
 void alloc_work(s32 a0);
 void release_work(void);
 void reset_all_members(bool a0);
 void exec_prepare(void);
 void awake_from_hibernation(void);
 void exec_appear(void);
 s32 find_free_member_buffer(s32 a0);
 u64 IsInitAppear(OBJENTRY* a0);
 u32 get_prize_count(s32 a0);
 MGObj(MGObj* a0, OBJENTRY* a1, u32 a2, FVector* a3, f32 a4);
 void hibernate(void);
 void hibernate_req(void);
 ~MGObj();
 void _OVR_begin(void);
 void MatrixToRotation(FVector* a0, FMatrix* a1);
 void set_matrix(FMatrix* a0);
 void check_all_leave(void);
 void set_matrix(OBJ* a0, FMatrix* a1);
 void get_bbox_for_appear_check(UNIT_DATA_OBJ* a0);
 void get_po06_obj_count(int* a0);
};

class MGObj> {
public:
 void begin(MGObj* a0);
};
