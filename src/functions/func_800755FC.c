/* Implements the specification in specs/func_800755FC.md */
#include "podcruise/types.h"

extern void func_8007531C(void *);
extern void func_80075490(void *);
extern s32 D_8011C8D8;
extern s32 D_8011C8DC;

void func_800755FC(void *arg0, void *arg1) {
    D_8011C8D8 = 0;
    D_8011C8DC = 0;
    func_8007531C(arg1);
    if (D_8011C8D8 > 0) {
        func_80075490(arg0);
    }
}
