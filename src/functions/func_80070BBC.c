/* Independently written from the specification in specs/func_80070BBC.md. */
#include "podcruise/types.h"

typedef struct Vec70BBC {
    f32 x;
    f32 y;
    f32 z;
} Vec70BBC;

typedef struct Probe70BBC {
    /* 0x00 */ f32 origin[3];
    /* 0x0C */ f32 heading[3];
    /* 0x18 */ f32 reach;
} Probe70BBC;

typedef struct Track70BBC {
    /* 0x00 */ void *unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ f32 unk08;
} Track70BBC;

typedef struct Object70BBC {
    /* 0x000 */ u8 pad000[0xAC];
    /* 0x0AC */ Track70BBC track;
    /* 0x0B8 */ u8 pad0B8[0x84];
    /* 0x13C */ void *unk13C;
} Object70BBC;

typedef struct Info70BBC {
    /* 0x00 */ u8 pad00[0x2C];
    /* 0x2C */ s32 unk2C;
} Info70BBC;

extern f32 D_800AD838;
extern f32 D_800AD83C;
extern f32 D_800AD840;
extern f32 D_800AD844;
extern f32 D_800AD848;
extern f32 D_800AD84C;

extern void *func_80005134(void *arg0, Probe70BBC *arg1);
extern Info70BBC *func_800183A8(const void *object);
extern void func_8003ABA0(void *owner, s16 mode, Track70BBC *track);
extern void func_8003B02C(Track70BBC *track, void *matrix);
extern s32 func_8003FDCC(s32 tag, Vec70BBC *origin, f32 limit, void *exclude, s32 capacity,
                         f32 *distances, Vec70BBC *offsets, void **results);
extern void *func_80080408(Track70BBC *track);

void func_80070BBC(Object70BBC *object, Vec70BBC *frame, s32 flag) {
    Vec70BBC offset;
    f32 distance;
    void *result;
    Probe70BBC probe;
    Info70BBC *hit;
    s32 active;
    s32 rewinding;
    s32 done;
    s32 whole;
    f32 scaled;

    active = flag;
    rewinding = flag;

    if (flag == 0) {
        scaled = object->track.unk08 * -10.0f;
        if (scaled < 0) {
            whole = (s32)(scaled - D_800AD838);
        } else {
            whole = (s32)scaled;
        }
        object->track.unk08 = (f32)(-whole) / 10.0f;
        if (1.0f <= object->track.unk08) {
            object->track.unk08 = 0.0f;
            func_8003ABA0(object->track.unk00, 1, &object->track);
        }
    }

    probe.heading[0] = 0.0f;
    probe.heading[1] = 0.0f;
    probe.heading[2] = -1.0f;
    probe.reach = D_800AD83C;

    do {
        done = 1;
        if (active != 0) {
            probe.origin[0] = frame[3].x;
            probe.origin[1] = frame[3].y;
            probe.origin[2] = frame[3].z;
            hit = func_80005134(object->unk13C, &probe);
        } else {
            hit = func_80080408(&object->track);
        }

        if (hit == 0) {
            done = 0;
        } else {
            hit = func_800183A8(hit);
            if (hit != 0) {
                if ((hit->unk2C & 0x16000) != 0) {
                    done = 0;
                }
            }
        }

        if (done != 0) {
            if (func_8003FDCC(0x54657374, &frame[3], 900.0f, object, 1,
                              &distance, &offset, &result) > 0) {
                done = 0;
            }
        }

        if (done == 0) {
            if (rewinding != 0) {
                rewinding = 0;
                active = 0;
                scaled = object->track.unk08 * -10.0f;
                if (scaled < 0) {
                    whole = (s32)(scaled - D_800AD840);
                } else {
                    whole = (s32)scaled;
                }
                object->track.unk08 = (f32)(-whole) / 10.0f;
            } else if (active != 0) {
                object->track.unk08 = object->track.unk08 + D_800AD844;
            } else {
                object->track.unk08 = object->track.unk08 + D_800AD848;
            }
            func_8003B02C(&object->track, frame);
        } else if (active == 0) {
            if (flag != 0) {
                object->track.unk08 = object->track.unk08 - D_800AD84C;
                active = 1;
                done = 0;
                func_8003B02C(&object->track, frame);
            }
        }
    } while (done == 0);
}
