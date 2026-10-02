/* Independently written from the specification for func_8006FED0. */
/* No-op flag guard: nested empty tests keep IDO -O2 from deleting the branch. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ u32 unk60;
} Func8006FED0Target;

void func_8006FED0(Func8006FED0Target *arg0) {
    if (arg0->unk60 & 0x80) {
        if (arg0->unk60 & 0x40) {
            if (arg0 != 0) {
            }
        }
    }
}
