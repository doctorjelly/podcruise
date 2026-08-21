/* Independently written from scratchpad spec specs/func_80066144.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct Record80066144 {
    PcVec3f first;
    PcVec3f second;
    u8 rest[108 - 24];
} Record80066144;

typedef struct Table80066144 {
    u8 head[0x18];
    s32 *entries;
} Table80066144;

typedef struct Obj80066144 {
    u8 pad000[0x20];
    PcVec3f unk020;
    f32 pad02C;
    PcVec3f unk030;
    f32 pad03C;
    PcVec3f unk040;
    u8 pad04C[0x1290 - 0x4C];
    f32 unk1290[4][4][4];
    u8 pad1390[0x1998 - 0x1390];
    s32 unk1998;
    u8 pad199C[0x1E70 - 0x199C];
    Table80066144 *unk1E70;
} Obj80066144;

extern void func_80015538(PcVec3f *output, const PcVec3f *left, const PcVec3f *right);
extern void func_80017874(f32 *matrix);
extern void func_80017918(f32 dest[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);

extern Record80066144 D_800A5CA0[];
extern f32 D_800AD48C;
extern f32 D_800AD490;
extern f32 D_800AD494;
extern f32 D_800AD498;
extern f32 D_800AD49C;
extern f32 D_800AD4A0;

f32 func_80066144(Obj80066144 *object, PcVec3f *origin, s32 unused, f32 offset, PcVec3f *plane) {
    f32 matrix[4][4];
    PcVec3f list[9];
    f32 depths[8];
    PcVec3f hits[6];
    PcVec3f points[6];
    PcVec3f direction;
    Record80066144 *record;
    f32 lower;
    f32 upper;
    f32 best;
    f32 result;
    f32 travel;
    s32 count;
    s32 i;

    (void)unused;

    func_80015268(&list[0], 0.0f, 0.0f, 0.0f);
    record = &D_800A5CA0[object->unk1E70->entries[0]];
    count = 2;
    func_80015288(&list[1], &record->second);
    func_80015288(&list[count], &record->second);
    list[count].x = -list[count].x;
    func_80015288(&list[count + 1], &record->first);
    count += 2;

    if (count > 0) {
        for (i = 0; i != count; i++) {
            func_800155C0(&direction, list[i].x, &object->unk020);
            func_800155EC(&direction, &direction, list[i].y, &object->unk030);
            func_800155EC(&direction, &direction, list[i].z, &object->unk040);
            func_80015328(&hits[i], origin, &direction);
            if (plane->z < D_800AD490 && D_800AD48C < plane->z) {
                hits[i].z = hits[i].z - offset;
                points[i].x = plane->x;
                points[i].y = plane->y;
                points[i].z = plane->z;
                depths[i] = offset;
            } else {
                travel = ((-plane->x * direction.x) - (plane->y * direction.y)) / plane->z - direction.z;
                hits[i].z = hits[i].z + travel;
                hits[i].z = hits[i].z - offset;
                points[i].x = plane->x;
                points[i].y = plane->y;
                points[i].z = plane->z;
                depths[i] = offset - travel;
            }
        }
    }

    if ((f64)(((f32)object->unk1998 - 40.0f) / 60.0f) < 1.0) {
        lower = D_800AD494;
        upper = D_800AD498;
        for (i = 0; i != 4; i++) {
            if (0.0f < depths[i]) {
                func_80017874(&matrix[0][0]);
                matrix[2][0] = points[i].x;
                matrix[2][1] = points[i].y;
                matrix[2][2] = points[i].z;
                matrix[1][0] = object->unk030.x;
                matrix[1][1] = object->unk030.y;
                matrix[1][2] = object->unk030.z;
                func_80015538((PcVec3f *)&matrix[0][0], (PcVec3f *)&matrix[1][0], (PcVec3f *)&matrix[2][0]);
                func_80015538((PcVec3f *)&matrix[1][0], (PcVec3f *)&matrix[2][0], (PcVec3f *)&matrix[0][0]);
                matrix[3][0] = hits[i].x;
                matrix[3][1] = hits[i].y;
                matrix[3][2] = hits[i].z;
                func_800156DC((PcVec3fSlot *)object->unk1290[i], (const PcVec3fSlot *)matrix);
                func_80017918(object->unk1290[i], upper, upper, upper, object->unk1290[i]);
            } else {
                object->unk1290[i][3][2] = lower;
            }
        }
    } else {
        object->unk1290[1][3][2] = D_800AD49C;
        object->unk1290[2][3][2] = D_800AD49C;
        object->unk1290[3][3][2] = D_800AD49C;
        object->unk1290[0][3][2] = D_800AD49C;
    }

    best = depths[1];
    if (0.0f < depths[2] && depths[2] < depths[1]) {
        best = depths[2];
    }
    if (best < 0.0f) {
        if (offset < 0.0f) {
            result = D_800AD4A0;
        } else {
            result = offset;
        }
    } else {
        result = best - 2.0f;
    }
    return result;
}
