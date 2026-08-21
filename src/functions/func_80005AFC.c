/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern s32 D_8009A29C;

void func_80005AFC(void) {
    if (D_8009A29C > 0) {
        D_8009A29C--;
    }
}
