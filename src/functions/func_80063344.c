/* Specification: scratchpad specs/func_80063344.md */
#include "podcruise/types.h"

typedef struct {
    s16 first;
    s16 second;
} RangePair;

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 kind;
    s32 padding[31];
    s32 selector;
} RangeOwner;

static const s32 rodataFiller[3] = {0, 0, 0};

extern RangePair D_800A3090[];
extern RangePair D_800A3104[];
extern RangePair D_800A313C[];
extern RangePair D_800A317C[];
extern RangePair D_800A318C[];
extern RangePair D_800A319C[];
extern RangePair D_800A31B0[];
extern RangePair D_800A31C4[];
extern f32 D_800AD3EC;
extern f32 D_800AD3F0;
extern f32 D_800AD3F4;
extern f32 D_800AD3F8;
extern f32 D_800AD3FC;
extern f32 D_800AD400;
extern f32 D_800AD404;
extern f32 D_800AD408;
extern f32 D_800AD40C;
extern f32 D_800AD410;
extern f32 D_800AD414;
extern f32 D_800AD418;
extern f32 D_800AD41C;
extern f32 D_800AD420;

void func_80063344(RangeOwner *owner, f32 *low, f32 *high) {
    s32 index;
    f32 scale;

    index = owner->selector;
    if (index == -1) {
        if ((owner->kind == 1) || (owner->kind == 2) || (owner->kind == 6) || (owner->kind == 3)) {
            return;
        }
    }

    switch (owner->kind) {
    case 1:
        scale = D_800AD3EC;
        *low = D_800A3090[index].first * scale;
        *high = D_800A3090[owner->selector].second * scale;
        break;
    case 2:
        scale = D_800AD3F0;
        *low = D_800A3104[index].first * scale;
        *high = D_800A3104[owner->selector].second * scale;
        break;
    case 3:
        scale = D_800AD3F4;
        *low = D_800A313C[index].first * scale;
        *high = D_800A313C[owner->selector].second * scale;
        break;
    case 4:
        *low = D_800AD3F8;
        *high = D_800AD3FC;
        break;
    case 5:
        *low = D_800AD400;
        *high = D_800AD404;
        break;
    case 7:
        *low = D_800AD408;
        *high = D_800AD40C;
        break;
    case 10:
        scale = D_800AD410;
        *low = D_800A317C[index].first * scale;
        *high = D_800A317C[owner->selector].second * scale;
        break;
    case 12:
        scale = D_800AD414;
        *low = D_800A318C[index].first * scale;
        *high = D_800A318C[owner->selector].second * scale;
        break;
    case 11:
        scale = D_800AD418;
        *low = D_800A319C[index].first * scale;
        *high = D_800A319C[owner->selector].second * scale;
        break;
    case 8:
        scale = D_800AD41C;
        *low = D_800A31B0[index].first * scale;
        *high = D_800A31B0[owner->selector].second * scale;
        break;
    case 9:
        scale = D_800AD420;
        *low = D_800A31C4[index].first * scale;
        *high = D_800A31C4[owner->selector].second * scale;
        break;
    case 6:
    default:
        *low = 0.0f;
        *high = 0.0f;
        break;
    }
}
