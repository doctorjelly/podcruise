/* Recovered from specification specs/functions/recovered/func_80096790.md */
#include "podcruise/types.h"

typedef struct Rec80096790 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Rec80096790;

extern u8 D_80149CB1;
extern void *D_8014D720;

extern void func_800905F0(void);
extern void func_80090634(void);
extern void func_80096930(s32);
extern s32 func_800907D0(s32, void *);
extern void func_80087E80(void *, s32 *, s32);
extern void func_80096A00(u8 *, Rec80096790 *);

s32 func_80096790(void *arg0, u8 *arg1) {
    s32 result;
    s32 scratch;
    u8 flag;
    Rec80096790 records[4];
    s32 index;
    u8 mask;
    s32 remaining;

    result = 0;
    mask = 0;
    remaining = 3;
    func_800905F0();
    do {
        func_80096930(0);
        result = func_800907D0(1, &D_8014D720);
        func_80087E80(arg0, &scratch, 1);
        result = func_800907D0(0, &D_8014D720);
        func_80087E80(arg0, &scratch, 1);
        func_80096A00(&flag, records);
        for (index = 0; index < D_80149CB1; index++) {
            if ((records[index].unk2 & 4) == 0) {
                remaining--;
                break;
            }
        }
        if (D_80149CB1 == index) {
            remaining = 0;
        }
    } while (remaining > 0);
    for (index = 0; index < D_80149CB1; index++) {
        if (records[index].unk3 == 0 && (records[index].unk2 & 1)) {
            mask |= 1 << index;
        }
    }
    func_80090634();
    *arg1 = mask;
    return result;
}
