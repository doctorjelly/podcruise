/* Specification: specs/func_8008C280.md (worker scratchpad) */
#include "podcruise/types.h"

extern void func_800905F0(void);
extern void func_80090634(void);
extern s32 func_800950F4(s32, u16 *);

s32 func_8008C280(s32 arg0) {
    s32 result;
    u16 value[4];
    s32 status;

    func_800905F0();
    status = func_800950F4(arg0, value);
    if (status != 0) {
        result = 0;
    } else {
        switch (value[0] & 0xC000) {
            case 0x8000:
                result = 1;
                break;
            case 0xC000:
                result = 2;
                break;
            default:
                result = 0;
                break;
        }
    }
    func_80090634();
    return result;
}
