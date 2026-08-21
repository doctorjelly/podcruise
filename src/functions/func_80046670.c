/* Independently written from scratchpad spec specs/func_80046670.md. */

#include "podcruise/types.h"

extern u32 *func_800305E8(s32 id);
extern u32 *func_80030964(u32 *data);
extern void func_80030A7C(u32 *displayList, u32 *patchList);
extern void func_80087754(void *arg);
extern void func_80018470(void);

extern u32 D_8011A2A8[];
extern u32 *D_8011A508[];
extern u32 *D_8011A768[];
extern u32 D_8011A288;
extern u32 *D_8011A9C4;

void func_80046670(s32 arg0, s32 arg1, s32 slot, s32 arg3) {
    u32 *data;

    D_8011A508[slot] = 0;
    D_8011A2A8[slot] = 0;
    D_8011A768[slot] = 0;

    data = func_800305E8(arg0);
    if (arg1 >= 0) {
        func_80030A7C(data, func_800305E8(arg1));
    }

    if (data != 0) {
        if (&D_8011A768[slot] >= &D_8011A9C4) {
            while (1) {
            }
        }
        D_8011A508[slot] = data;
        D_8011A2A8[slot] = data[0];
        if (arg3 != 0) {
            D_8011A768[slot] = func_80030964(D_8011A508[slot]);
        }
    }

    func_80087754(&D_8011A288);
    func_80018470();
}
