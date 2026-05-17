#include "../../common/types.h"


namespace YS {

} // namespace YS

void SetGameLevel(s32 a0);
u64 GetHeaderId(void);
s32 new_game(void);
s32 GetGameLevel(void);
bool isGameComplete(void);
void SAVERAM(void);
void mc_endian_write_conv(void);
void mc_endian_read_conv(void);
