/* Recovered from specs/func_800467F8.md (behavioral specification). */
#include "podcruise/types.h"

extern u32 D_8011A508[151];
extern u32 D_8011A768[151];
extern void func_80005B80(void);
extern u32 func_80030964(u32 handle);

void func_800467F8(void) {
    s32 i;

    func_80005B80();
    for (i = 0; i < 151; i++) {
        if (D_8011A508[i] != 0) {
            D_8011A768[i] = func_80030964(D_8011A508[i]);
        }
    }
}
