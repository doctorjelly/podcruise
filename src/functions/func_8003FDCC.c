/* Independently written from $S/specs/func_8003FDCC.md (nearest-object gather into a sorted list). */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ u8 unk00[6];
    /* 0x06 */ s16 unk06;
    /* 0x08 */ u8 unk08[0x48];
    /* 0x50 */ f32 x;
    /* 0x54 */ f32 y;
    /* 0x58 */ f32 z;
} Entity;

typedef struct {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 flags;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 stride;
    /* 0x10 */ Entity *items;
} Group;

extern Group **D_800A2170;

s32 func_8003FDCC(s32 tag, Vec3f *origin, f32 limit, Entity *exclude, s32 capacity,
                  f32 *distances, Vec3f *offsets, Entity **results) {
    Group **cursor;
    Group *group;
    Entity *entity;
    f32 delta[3];
    f32 distance;
    s32 found;
    s32 index;
    s32 slot;
    s32 last;

    found = 0;
    cursor = D_800A2170;
    while (*cursor != 0) {
        group = *cursor;
        if (tag == group->tag || tag == 0x416C6C21) {
            if ((group->flags & 1) != 0) {
                entity = group->items;
                for (index = 0; index < group->count; index++) {
                    if ((entity->unk06 & 0x100) == 0 && entity != exclude) {
                        delta[0] = entity->x - origin->x;
                        delta[1] = entity->y - origin->y;
                        delta[2] = entity->z - origin->z;
                        distance = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
                        if (distance < limit) {
                            for (slot = 0; slot < found; slot++) {
                                if (!(distances[slot] < distance)) {
                                    break;
                                }
                            }
                            if (slot < capacity) {
                                if (found < capacity) {
                                    last = found;
                                    found++;
                                } else {
                                    last = capacity - 1;
                                }
                                for (; last > slot; last--) {
                                    results[last] = results[last - 1];
                                    distances[last] = distances[last - 1];
                                    offsets[last].x = offsets[last - 1].x;
                                    offsets[last].y = offsets[last - 1].y;
                                    offsets[last].z = offsets[last - 1].z;
                                }
                                distances[slot] = distance;
                                results[slot] = entity;
                                offsets[slot].x = delta[0];
                                offsets[slot].y = delta[1];
                                offsets[slot].z = delta[2];
                            }
                        }
                    }
                    entity = (Entity *)((u8 *)entity + group->stride);
                }
            }
        }
        cursor++;
    }
    return found;
}
