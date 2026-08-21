/* Spec: $S/specs/func_8000BB78.md */
#include "podcruise/types.h"

extern s32 func_80017F20(void);
extern void *func_80017F28(s32);
extern s32 func_80017EF4(void *);
extern s32 func_80017EE4(void *);

s32 func_8000BB78(s32 arg0) {
    void *entry;
    s32 count;
    s32 index;

    count = func_80017F20();
    for (index = 0; index < count; index++) {
        entry = func_80017F28(index);
        if (entry != 0) {
            if ((func_80017EF4(entry) & 1) != 0) {
                if (func_80017EE4(entry) == arg0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
