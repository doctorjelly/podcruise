/* Independently written from specs/functions/runtime_wrappers.md. */

#include "podcruise/types.h"

extern u8 D_800D7540[];
extern u8 D_800D9C28[];
extern void func_8008B424(void *owner, void *record, s32 channel);
extern void func_8008B1B0(void *record, s32 value);

void func_8002E82C(s32 index) {
    void *record;
    s32 slot;

    if (index == -1) {
        for (slot = 0; slot < 4; slot++) {
            func_8002E82C(slot);
        }
        return;
    }
    record = D_800D7540 + index * 104;
    func_8008B424(D_800D9C28, record, index);
    func_8008B1B0(record, 0);
    func_8008B1B0(record, 0);
    func_8008B1B0(record, 0);
}
