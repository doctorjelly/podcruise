/* Recovered from specs/func_8004A780.md (behavioral specification). */
#include "podcruise/types.h"

typedef struct {
    u32 target;
} Entry8004A780;

extern Entry8004A780 *D_8011A508[151];
extern void func_800181BC(u32 target, s32 a, s32 b, s32 c, s32 d);

void func_8004A780(s32 arg0) {
    s32 i;

    (void)arg0;
    for (i = 0; i < 151; i++) {
        if (D_8011A508[i] != 0) {
            if (D_8011A508[i]->target != 0) {
                if (D_8011A508[i]->target != 0) {
                    func_800181BC(D_8011A508[i]->target, 2, -4, 0x10, 3);
                }
            }
        }
    }
}
