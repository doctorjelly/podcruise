/* Recovered from specification specs/func_800396E0.md (record load and validate). */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    u8 unk04;
} Rec800396E0;

extern Rec800396E0 D_80113680;

extern s32 func_80039340(Rec800396E0 *, void *, s32);
extern s32 func_8003931C(Rec800396E0 *);

s32 func_800396E0(void *arg0) {
    s32 result = 1;

    if (func_80039340(&D_80113680, arg0, 0x3F0) != 0) {
        result = 0;
    } else if (D_80113680.unk04 != 1) {
        result = 0;
    } else if (func_8003931C(&D_80113680) != D_80113680.unk00) {
        result = 0;
    }
    return result;
}
