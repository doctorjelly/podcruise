/* Specification: $S/specs/func_80063E4C.md */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0xB8];
    s32 unkB8;
} Obj80063E4C;

extern s32 func_80063D0C(Obj80063E4C *);
extern void func_80063E08(Obj80063E4C *, s32);
extern void func_80060DE4(Obj80063E4C *, s32);

s32 func_80063E4C(Obj80063E4C *obj) {
    s32 mode;

    mode = func_80063D0C(obj);
    if (mode == -1) {
        return 0;
    }
    switch (mode) {
    case 0:
        func_80063E08(obj, 1);
        break;
    case 1:
        func_80063E08(obj, 2);
        break;
    case 2:
        func_80060DE4(obj, 0);
        break;
    default:
        return 0;
    }
    obj->unkB8 = mode;
    return 1;
}
