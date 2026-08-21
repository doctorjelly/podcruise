/* Specification: $S/specs/func_8008AE30.md */
#include "podcruise/types.h"

struct Func8008AE30Entry {
    s32 unk0;
    s32 unk4;
};

extern struct Func8008AE30Entry D_80149D00[];
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);

void func_8008AE30(s32 arg0, s32 arg1, s32 arg2) {
    register s32 token;
    struct Func8008AE30Entry *entry;

    token = func_8008CA80();
    entry = &D_80149D00[arg0];
    entry->unk0 = arg1;
    entry->unk4 = arg2;
    func_8008CAA0(token);
}
