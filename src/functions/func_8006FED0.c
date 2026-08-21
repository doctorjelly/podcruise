/* Independently written from the specification for func_8006FED0. */
/* Behavior-recovered only: this is a no-op guard whose 24 original bytes the
   accepted IDO 5.3 -O2 profile cannot reproduce (it deletes the empty guard
   entirely). See the specification for the shapes that were ruled out. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ u32 unk60;
} Func8006FED0Target;

void func_8006FED0(Func8006FED0Target *arg0) {
    if (arg0->unk60 & 0x80) {
    }
}
