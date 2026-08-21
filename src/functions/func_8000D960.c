/* Independently written from scratchpad spec specs/func_8000D960.md. */
#include "podcruise/types.h"

extern s32 D_8009B800;
extern void func_8000D7DC(s32 arg0);
extern void func_8000D818(s32 arg0);

void func_8000D960(s32 arg0) {
    if (D_8009B800 == 0) {
        func_8000D7DC(arg0);
    } else if (D_8009B800 == 2) {
        func_8000D818(arg0);
    }
}
