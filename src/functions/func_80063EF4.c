/* Independently written from scratchpad spec specs/func_80063EF4.md. */

#include "podcruise/types.h"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct Tracker {
    /* 0x00 */ u8 pad00[0x44];
    /* 0x44 */ Vec3f unk44;
    /* 0x50 */ Vec3f unk50;
    /* 0x5C */ u8 pad5C[0xC];
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
} Tracker;

extern f32 D_80120BF8;

extern void func_8001535C(Vec3f *, Vec3f *, Vec3f *);
extern f32 func_800153C0(Vec3f *);
extern f32 func_80014F54(f32, f32);

void func_80063EF4(Tracker *tracker) {
    Vec3f offset;
    f32 delta;

    func_8001535C(&offset, &tracker->unk50, &tracker->unk44);
    offset.z = 0.0f;
    func_800153C0(&offset);

    tracker->unk6C = func_80014F54(-offset.x, offset.y);
    delta = tracker->unk6C - tracker->unk68;

    if (delta < -180.0f) {
        delta = delta + 360.0f;
    }
    if (delta > 180.0f) {
        delta = delta - 360.0f;
    }

    if (delta > 5.0f || delta < -5.0f) {
        if (delta < 0.0f) {
            tracker->unk68 = tracker->unk68 - 90.0f * D_80120BF8;
        } else {
            tracker->unk68 = tracker->unk68 + 90.0f * D_80120BF8;
        }
    } else {
        tracker->unk68 = tracker->unk6C;
    }
}
