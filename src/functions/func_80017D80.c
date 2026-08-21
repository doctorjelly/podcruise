/* Independently written from the specification for func_80017D80. */
#include "podcruise/types.h"

f32 func_80017D80(f32 *arg0, s32 arg1) {
    if (arg1 < 8) {
        if (arg1 >= 0) {
            return arg0[arg1 + 7];
        }
    }
}
