/* Independently written from specs/functions/func_80046870.md. */

#include "podcruise/types.h"

extern void func_80005B80(void);

extern u32 D_8011A2A8[151];
extern u32 *D_8011A508[151];

void func_80046870(void) {
    u32 *entry;
    s32 index;
    s32 slot;

    for (index = 5; index < 151; index++) {
        entry = D_8011A508[index];
        if (entry != 0) {
            for (slot = 0; slot < 151; slot++) {
                if (D_8011A2A8[slot] == *entry) {
                    D_8011A2A8[slot] = 0;
                }
            }
            D_8011A508[index] = 0;
        }
    }
    func_80005B80();
}
