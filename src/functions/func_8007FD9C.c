/* Independently written from the specification for func_8007FD9C. */
#include "podcruise/types.h"

extern void func_8007F914(void *arg0, f32 arg1, s16 *arg2, s16 *arg3);

/* Behaviour-recovered, not byte-matching: the original receives its floating
   point argument already in the first floating point argument register, so the
   build here carries one extra move ahead of the frame setup. */
void func_8007FD9C(void *arg0, f32 arg1, s16 *arg2, s16 *arg3) {
    func_8007F914(arg0, arg1, arg2, arg3);
}
