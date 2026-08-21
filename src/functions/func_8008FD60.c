/* Implements the specification in specs/func_8008FD60.md */
#include "podcruise/types.h"

extern s32 func_80090500(s32);
extern s32 func_80088020(s32 *);
extern void func_80088050(s32 *, s32 *);
extern void func_80096710(void *, void *, s32);

s32 func_8008FD60(s32 **arg0, s16 *arg1) {
    s32 *node;
    s32 result;
    s32 saved;

    saved = func_80090500(1);
    node = arg0[2];
    if (node != 0) {
        func_80088020(node);
        func_80096710(node + 3, arg1, 0x10);
        func_80088050(node, (s32 *)arg0);
        result = node[2];
    } else {
        *arg1 = -1;
        result = 0;
    }
    func_80090500(saved);
    return result;
}
