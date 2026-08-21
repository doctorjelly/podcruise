/* Implements the specification in specs/func_8002F1EC.md (pause-input poll). */
#include "podcruise/types.h"

extern s32 D_800A26F4;
extern s32 D_8009B7D8;
extern s32 D_800D76F0;
extern s32 D_800D7700[];

extern s16 *func_8003F800(s32, s32);
extern void func_8002F06C(void);
extern s32 func_8005B764(void);

void func_8002F1EC(void) {
    if (D_800A26F4 == 0) {
        if (func_8003F800(0x4A646765, 0) != 0) {
            if ((func_8003F800(0x4A646765, 0)[3] & 0x1000) != 0) {
                if ((D_8009B7D8 & 1) != 0) {
                    if (((D_800D7700[0] & 0x200) != 0) || ((D_800D7700[1] & 0x200) != 0)) {
                        if ((D_800A26F4 == 1) || ((D_800D76F0 & 0x400) != 0)) {
                            func_8002F06C();
                        }
                    }
                }
            } else if (func_8005B764() != 0) {
                func_8002F06C();
            }
        }
    }
}
