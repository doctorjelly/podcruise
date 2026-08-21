/* Recovered from specification $S/specs/func_8002E2FC.md */
#include "podcruise/types.h"

extern u8 D_800D7420[];
extern void *D_801488C0;
extern s32 D_800A2670;
extern s32 D_800A2674;
extern s32 D_800A2678;
extern s32 D_800A267C;
extern s32 D_800A2680;
extern s32 D_800A2684;
extern s32 D_800A2688;

extern void func_8002DFB0(s32, s32);
extern void func_8002E028(void);
extern void func_8002E0A8(void);
extern s32 func_80087E80(void *, s32 *, s32);
extern s32 func_8008ADB0(void *);

void func_8002E2FC(void) {
    s32 message;
    register u8 *object;
    register s32 *messagePointer;

    object = D_800D7420;
    messagePointer = &message;
    while (func_80087E80(object, messagePointer, 0) != -1) {
        switch (message) {
        case 1:
        case 4:
            func_8002DFB0(5, 0);
            if (D_800A2680 != 0) {
                D_800A2684 = 1;
                func_8002DFB0(100, 0);
            } else if (D_800A2678 != 0) {
                D_800A2678 = 0;
                if (func_8008ADB0(D_801488C0) == 1) {
                    D_800A267C = 1;
                    D_800A2674 = 0;
                    func_8002DFB0(200, 0);
                } else {
                    func_8002DFB0(300, 0);
                }
                D_800A2688 = 1;
            } else if (D_800A2674 != 0) {
                D_800A2670 = 1;
                D_800A2674 = 0;
                func_8002E028();
                func_8002DFB0(400, 0);
            } else {
                func_8002DFB0(500, 0);
            }
            break;
        case 2:
            func_8002E0A8();
            func_8002DFB0(2000, 0);
            break;
        }
    }
}
