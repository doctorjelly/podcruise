/* Implements the specification in specs/func_8008AEA0.md (copy a record and relocate its pointer fields). */
#include "podcruise/types.h"

extern void *D_80149D80[0x10];

extern void func_80092250(void *, void *, s32);
extern void *func_80088360(void *);

void **func_8008AEA0(void *arg0) {
    void **record;

    record = D_80149D80;
    func_80092250(arg0, record, 0x40);
    if (record[4] != 0) {
        record[4] = func_80088360(record[4]);
    }
    if (record[6] != 0) {
        record[6] = func_80088360(record[6]);
    }
    if (record[8] != 0) {
        record[8] = func_80088360(record[8]);
    }
    if (record[10] != 0) {
        record[10] = func_80088360(record[10]);
    }
    if (record[11] != 0) {
        record[11] = func_80088360(record[11]);
    }
    if (record[12] != 0) {
        record[12] = func_80088360(record[12]);
    }
    if (record[14] != 0) {
        record[14] = func_80088360(record[14]);
    }
    return record;
}
