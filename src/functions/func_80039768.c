/* Recovered from the specification in specs/func_80039768.md (worker notes). */
#include "podcruise/types.h"

extern void func_800393DC(s32 *source, s32 destination, s32 length);

extern s32 D_80113680[];
extern s32 D_80113A70[];

void func_80039768(s32 destination) {
    s32 *current;
    s32 *shadow;
    s32 index;
    s32 word;
    s32 same;

    current = D_80113680;
    shadow = D_80113A70;
    for (index = 0; index < 63; index++) {
        same = 1;
        for (word = 0; word < 4; word++) {
            if (current[word] != shadow[word]) {
                same = 0;
            }
        }
        if (!same) {
            func_800393DC(current, destination, 16);
        }
        current += 4;
        shadow += 4;
        destination += 16;
    }
}
