/* Recovered from the specification in scratchpad specs/func_80048F74.md */
#include "podcruise/types.h"

typedef struct {
    f32 value[5];
} KeyBlock;

extern KeyBlock D_800A51DC;
extern s32 D_800D6DD8[][23];
extern f32 D_80119670[][6];
extern s32 D_8011A2A8[151];
extern s32 *D_8011A508[];

extern void func_80014CC0(f32 degrees, f32 *sine, f32 *cosine);

void func_80048F74(s32 arg0) {
    s32 order[5];
    s32 count;
    s32 limit;
    s32 taken;
    s32 inner;
    s32 head;
    s32 outer;
    s32 tail;
    f32 sine;
    f32 cosine;
    s32 last;
    KeyBlock key;

    key = D_800A51DC;
    for (outer = 0; outer < 5; outer++) {
        order[outer] = -1;
    }

    last = D_800D6DD8[arg0][1];
    count = last - D_800D6DD8[arg0][0] + 1;
    limit = count + 2;
    tail = count + 1;
    head = 0;

    for (outer = D_800D6DD8[arg0][0]; outer <= D_800D6DD8[arg0][1]; outer++) {
        func_80014CC0(D_80119670[outer][3], &sine, &cosine);
        if ((D_80119670[outer][1] * cosine) > 0.0f) {
            key.value[head] = D_80119670[outer][5];
            order[head] = (outer - D_800D6DD8[arg0][0]) + 0x46;
            head++;
        } else {
            key.value[tail] = D_80119670[outer][5];
            order[tail] = (outer - D_800D6DD8[arg0][0]) + 0x46;
            tail--;
        }
    }

    order[head] = arg0 + 0x3D;
    head++;
    order[head++] = 0x45;

    for (outer = 0; outer < head - 3; outer++) {
        for (inner = outer + 1; inner < head - 2; inner++) {
            if (key.value[outer] < key.value[inner]) {
                taken = order[outer];
                order[outer] = order[inner];
                order[inner] = taken;
            }
        }
    }

    for (outer = tail; outer < count + 1; outer++) {
        for (inner = outer + 1; inner < count + 2; inner++) {
            if (key.value[inner] < key.value[outer]) {
                taken = order[outer];
                order[outer] = order[inner];
                order[inner] = taken;
            }
        }
    }

    taken = 0;
    for (outer = 0; outer < 151; outer++) {
        for (inner = 0; inner < limit; inner++) {
            if (*D_8011A508[order[inner]] == D_8011A2A8[outer]) {
                D_8011A2A8[outer] = *D_8011A508[order[taken]];
                taken++;
                inner = limit + 1;
            }
        }
    }
}
