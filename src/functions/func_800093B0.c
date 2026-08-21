/* Specification: $S/specs/func_800093B0.md */
#include "podcruise/types.h"

extern s32 func_80008F6C(s32 owner, s32 handle, s32 detail);
extern void func_800092EC(s32 owner, s32 handle, s32 detail);
extern s32 func_80082BE0(void);

void func_800093B0(s32 owner, s32 handle, s32 first, s32 second, s32 third,
                   s32 fourth, s32 fifth) {
    s32 choices[14];
    s32 count;
    s32 index;

    count = 0;
    choices[count] = first;
    if (func_80008F6C(owner, handle, first) != -1) {
        count++;
    }
    choices[count] = second;
    if (func_80008F6C(owner, handle, second) != -1) {
        count++;
    }
    choices[count] = third;
    if (func_80008F6C(owner, handle, third) != -1) {
        count++;
    }
    choices[count] = fourth;
    if (func_80008F6C(owner, handle, fourth) != -1) {
        count++;
    }
    choices[count] = fifth;
    if (func_80008F6C(owner, handle, fifth) != -1) {
        count++;
    }

    if (count != 0) {
        index = (s32)((f32)func_80082BE0() / 2147483648.0f * (f32)(count + 1));
        if (index < 0) {
            index = 0;
        }
        index = index % count;
        func_800092EC(owner, handle, choices[index]);
    }
}
