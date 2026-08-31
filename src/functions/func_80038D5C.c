/* Implements specs/functions/recovered/func_80038D5C.md. */
#include "podcruise/types.h"
extern u32 *func_80033E08(void);
extern void func_800344F4(u32 *, void *);
extern u8 D_80112E20[];
u32 *func_80038D5C(u32 **arg0) {
    u32 *data;
    u32 *list;
    u32 *result;
    list = *arg0;
    data = func_80033E08();
    func_800344F4(data, D_80112E20);
    list[0] = 0xDA380007;
    list[1] = (u32)(unsigned long)data;
    result = list;
    list += 2;
    *arg0 = list;
    return result;
}
