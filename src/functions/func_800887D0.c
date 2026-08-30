/* Recovered per specs: func_800887D0 (see scratchpad specs/func_800887D0.md). */
#include "podcruise/types.h"

typedef struct Entry {
    /* 0x00 */ struct Entry *unk00;
    /* 0x04 */ struct Entry *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ void *unk0C;
    /* 0x10 */ u8 unk10[0x48];
    /* 0x58 */ u8 unk58[0x34];
    /* 0x8C */ u8 unk8C[0x50];
} Entry;

typedef struct Node {
    /* 0x00 */ struct Node *unk00;
    /* 0x04 */ u8 unk04[0x18];
} Node;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ Entry *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ void *unk24;
    /* 0x28 */ void *unk28;
    /* 0x2C */ Node *unk2C;
    /* 0x30 */ void *unk30;
    /* 0x34 */ void *unk34;
    /* 0x38 */ void *unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
} Obj;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ void *unk10;
    /* 0x14 */ void *unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 unk1C;
} Config;

extern void *func_80087FC0(s32, s32, void *, s32, s32);
extern void func_80088050(void *, void *);
extern void func_8008D510(void *);
extern void func_8008D554(void *, void *, s32);
extern void func_8008D5A8(void *, void *, s32);
extern void func_8008D5FC(void *, void *);
extern void func_8008D684(void *, void *, void *);
extern void func_8008D72C(void *, void *);
extern void *func_8008DCB0(void *, s16, void *, void *);
extern s32 func_8008DD50(void *, s32, void *);
extern void func_8008DEA0(void *, s32, void *);
extern s32 func_8008E9F0(void *, s32, void *);
extern s32 func_8008EE04(void *, s32, void *);
extern s32 func_8008F950(void *, s32, void *);
extern void func_8008FA60(void *, s32, void *);

void func_800887D0(Obj *obj, Config *cfg) {
    void *spare;
    Entry *base;
    Entry *cur;
    Node *node;
    void *region;
    void *slots;
    void *first;
    void *nodes;
    void *bound;
    s32 i;

    region = cfg->unk14;
    spare = region;
    (void)spare;
    obj->unk00 = 0;
    obj->unk3C = cfg->unk04;
    obj->unk20 = 0;
    obj->unk1C = 0;
    obj->unk44 = cfg->unk18;
    obj->unk48 = 0xA0;
    obj->unk24 = cfg->unk10;

    first = func_80087FC0(0, 0, region, 1, 0x1C);
    func_8008D510(first);
    obj->unk38 = first;
    obj->unk34 = func_80087FC0(0, 0, region, 1, 0x4C);
    obj->unk40 = 1;
    slots = func_80087FC0(0, 0, region, cfg->unk04, 4);
    func_8008D5A8(obj->unk34, slots, cfg->unk04);
    obj->unk30 = func_80087FC0(0, 0, region, 1, 0x20);
    nodes = func_80087FC0(0, 0, region, cfg->unk04, 4);
    func_8008D554(obj->unk30, nodes, cfg->unk04);

    if (cfg->unk1C != 0) {
        bound = func_8008DCB0(obj, 0, cfg, region);
        (void)bound;
    } else {
        func_8008DD50(obj->unk30, 2, obj->unk34);
    }
    obj->unk04 = 0;
    obj->unk08 = 0;
    obj->unk14 = 0;
    obj->unk18 = 0;
    obj->unk0C = 0;
    obj->unk10 = 0;

    base = (Entry *)func_80087FC0(0, 0, region, cfg->unk04, 0xDC);
    for (i = 0; i < cfg->unk04; i++) {
        cur = &base[i];
        func_80088050(cur, &obj->unk04);
        cur->unk08 = 0;
        func_8008D684(cur->unk10, obj->unk24, region);
        func_8008DEA0(cur->unk10, 1, 0);
        func_8008D5FC(cur->unk58, region);
        func_8008E9F0(cur->unk58, 1, cur->unk10);
        func_8008D72C(cur->unk8C, region);
        func_8008EE04(cur->unk8C, 1, cur->unk58);
        func_8008F950(obj->unk34, 2, cur->unk8C);
        cur->unk0C = cur->unk8C;
    }

    func_8008FA60(first, 1, obj->unk30);
    node = (Node *)func_80087FC0(0, 0, region, cfg->unk08, 0x1C);
    obj->unk2C = 0;
    for (i = 0; i < cfg->unk08; i++) {
        node->unk00 = obj->unk2C;
        obj->unk2C = node;
        node++;
    }
    obj->unk28 = region;
}
