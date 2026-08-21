/* Independently written from $S/specs/func_80089290.md (merged -O3 unit: func_80089290, func_8008937C, func_80089384). */
#include "podcruise/types.h"

typedef struct PcGeoSurface {
    /* 0x00 */ void *unk00;
    /* 0x04 */ u8 unk04[4];
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A[2];
    /* 0x0C */ void *unk0C;
    /* 0x10 */ void *unk10;
} PcGeoSurface;

typedef struct PcGeoObject {
    /* 0x00 */ void *unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ PcGeoSurface *unk08;
    /* 0x0C */ u8 unk0C[2];
    /* 0x0E */ u8 unk0E;
    /* 0x0F */ u8 unk0F;
} PcGeoObject;

typedef struct PcGeoTable {
    /* 0x00 */ u8 unk00[3];
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04[0xA];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ PcGeoObject *unk10[1];
} PcGeoTable;

static void func_80089290();

typedef struct PcGeoGroup {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 pad03[5];
    /* 0x08 */ PcGeoTable *unk08;
    /* 0x0C */ PcGeoTable *unk0C[1];
} PcGeoGroup;

typedef struct PcGeoArchive {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ PcGeoGroup *unk04[1];
} PcGeoArchive;

void func_80089384(PcGeoArchive *arg0, s32 arg1) {
    PcGeoGroup *group;
    s32 i;
    s32 j;

    if (arg0->unk00 != 0x4231) {
        return;
    }
    for (i = 0; i < arg0->unk02; i++) {
        arg0->unk04[i] = (PcGeoGroup *)((u8 *)arg0->unk04[i] + (u32)(unsigned long)arg0);
        if (arg0->unk04[i] == 0) {
            continue;
        }
        group = arg0->unk04[i];
        if (group->unk02 != 0) {
            continue;
        }
        group->unk02 = 1;
        if (group->unk08 != 0) {
            group->unk08 = (PcGeoTable *)((u8 *)group->unk08 + (u32)(unsigned long)arg0);
            func_80089290(group->unk08, (s32)(unsigned long)arg0, arg1);
        }
        for (j = 0; j < group->unk00; j++) {
            group->unk0C[j] = (PcGeoTable *)((u8 *)group->unk0C[j] + (u32)(unsigned long)arg0);
            if (group->unk0C[j] != 0) {
                func_80089290(group->unk0C[j], (s32)(unsigned long)arg0, arg1);
            }
        }
    }
}

void func_8008937C(void) {
    if (0) {
        func_80089290((PcGeoTable *)0, 0, 0);
    }
}

static void func_80089290(PcGeoTable *table, s32 delta, s32 dataDelta) {
    PcGeoObject *object;
    s32 dd;
    PcGeoSurface *surface;
    s32 i;

    if (table->unk03 != 0) {
        return;
    }
    table->unk03 = 1;

    for (i = 0; i < table->unk0E; i++) {
        table->unk10[i] = (PcGeoObject *)((u8 *)table->unk10[i] + delta);
        object = table->unk10[i];
        dd = dataDelta;
        if (object->unk0E != 0) {
            continue;
        }
        object->unk0E = 1;
        object->unk00 = (void *)((u8 *)object->unk00 + delta);
        object->unk04 = (void *)((u8 *)object->unk04 + delta);
        object->unk08 = (PcGeoSurface *)((u8 *)object->unk08 + delta);
        surface = object->unk08;
        if (surface->unk09 != 0) {
            continue;
        }
        surface->unk09 = 1;
        surface->unk00 = (void *)((u8 *)surface->unk00 + dd);
        if (surface->unk08 == 0) {
            surface->unk10 = (void *)((u8 *)surface->unk10 + delta);
            if (surface->unk0C != 0) {
                surface->unk0C = (void *)((u8 *)surface->unk0C + delta);
            }
        } else if (surface->unk08 == 1) {
            if (surface->unk0C != 0) {
                surface->unk0C = (void *)((u8 *)surface->unk0C + delta);
            }
        }
    }
}

