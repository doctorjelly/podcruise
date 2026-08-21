/* Implements specification specs/func_8008C770.md (recovered behavior). */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
} Func8008C770Context;

extern Func8008C770Context *D_800A7F50;
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32 arg0);

s32 func_8008C770(void) {
    register s32 handle;
    s32 saved;

    handle = func_8008CA80();
    saved = D_800A7F50->unk04;
    func_8008CAA0(handle);
    return saved;
}
