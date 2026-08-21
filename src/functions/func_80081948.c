/* Implements the specification in specs/func_80081948.md */
#include "podcruise/types.h"

extern void func_800156DC(void *, void *);
extern void func_80015328(void *, void *, void *);
extern void func_80017918(void *, f32, f32, f32, void *);

void func_80081948(void *arg0, void *arg1, void *arg2, f32 *arg3) {
    func_800156DC(arg0, arg2);
    func_80015328((u8 *)arg0 + 0x30, (u8 *)arg0 + 0x30, arg1);
    func_80017918(arg0, arg3[0], arg3[1], arg3[2], arg0);
}
