/* Recovered from specification $S/specs/func_800396E0.md */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    u8 unk04;
} Rec800396E0;

extern Rec800396E0 D_80113680;

extern s32 func_80039340(Rec800396E0 *, void *, s32);
/* Defined void, but its callee's result survives in the return register
   and this comparison reads it: an unprototyped-C inconsistency that the
   original source relied on. The argument is this function's own, which
   is why the call site sets up no argument register. */
extern s32 func_8003931C(void *buffer);

s32 func_800396E0(void *arg0) {
    f64 pad;
    s32 result = 1;

    if (func_80039340(&D_80113680, arg0, 0x3F0) != 0) {
        result = 0;
    } else if (D_80113680.unk04 != 1) {
        result = 0;
    } else if (func_8003931C(arg0) != D_80113680.unk00) {
        result = 0;
    }
    (void)&pad;
    return result;
}
