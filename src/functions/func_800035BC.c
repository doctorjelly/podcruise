/* Specification: scratchpad specs/func_800035BC.md */
#include "podcruise/types.h"

typedef struct {
    u16 unk[3];
} PrimRecord;

extern void *D_800AE938;
extern void (*D_800AE93C)();
extern void (*D_800AE940)();

extern s32 func_80017DDC(void *);
extern s32 func_80017DE4(void *);
extern s32 *func_80017DEC(void *);
extern void func_80017DF4(void *, s32, PrimRecord **, u16 **);

f32 func_800035BC(void *arg) {
    PrimRecord *records;
    u16 *indices;
    s32 *counts;
    s32 mode;
    s32 count;
    s32 i;
    s32 j;
    s32 index;
    s32 flag;

    D_800AE938 = arg;
    mode = func_80017DE4(arg);
    count = func_80017DDC(arg);
    func_80017DF4(arg, 0, &records, &indices);
    if (records != 0) {
        if (indices != 0) {
            index = 0;
            switch (mode) {
            case 5:
            case 7:
                counts = func_80017DEC(arg);
                for (i = 0; i < count; i++) {
                    flag = 0;
                    for (j = 0; j < counts[i] - 2; j++) {
                        D_800AE940(records, (s16)flag, &indices[index]);
                        flag = (s16)(1 - flag);
                        index++;
                    }
                    index += 2;
                }
                break;
            case 4:
                for (i = 0; i < count; i++) {
                    D_800AE940(records, 2, &indices[index]);
                    index += 4;
                }
                break;
            case 3:
                for (i = 0; i < count; i++) {
                    D_800AE940(records, 0, &indices[index]);
                    index += 3;
                }
                break;
            }
        } else {
            index = 0;
            switch (mode) {
            case 5:
            case 7:
                counts = func_80017DEC(arg);
                for (i = 0; i < count; i++) {
                    flag = 0;
                    for (j = 0; j < counts[i] - 2; j++) {
                        D_800AE93C(&records[index], (s16)flag);
                        flag = (s16)(1 - flag);
                        index++;
                    }
                    index += 2;
                }
                break;
            case 4:
                for (i = 0; i < count; i++) {
                    D_800AE93C(&records[index], 2);
                    index += 4;
                }
                break;
            case 3:
                for (i = 0; i < count; i++) {
                    D_800AE93C(&records[index], 0);
                    index += 3;
                }
                break;
            }
        }
    }
    return 0.0f;
}
