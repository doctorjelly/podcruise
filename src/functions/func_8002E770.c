/* Independently written from specs/functions/runtime_wrappers.md. */

#include "podcruise/types.h"

extern u8 D_800D7540[];
extern u8 D_800D9C28[];
extern void func_80031944(s32 index, void *value);
extern s32 func_8008B424(void *owner, void *record, s32 index);
extern void func_8008B1B0(void *record, s32 value);

void func_8002E770(void) {
    s32 index;

    for (index = 0; index < 4; index++) {
        func_80031944(index, 0);
    }
    for (index = 0; index < 4; index++) {
        u8 *record = &D_800D7540[index * 104];

        if (func_8008B424(D_800D9C28, record, index) == 0) {
            func_80031944(index, record);
            func_8008B1B0(record, 0);
            func_8008B1B0(record, 0);
            func_8008B1B0(record, 0);
        }
    }
}
