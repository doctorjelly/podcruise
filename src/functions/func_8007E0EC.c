/* Recovered from specification specs/func_8007E0EC.md (scratchpad). */
#include "podcruise/types.h"

typedef struct MatrixWork {
    f32 m[4][4];
    s32 unk40;
    s32 unk44;
} MatrixWork;

typedef struct Resource {
    void *unk00;
} Resource;

typedef struct Queue {
    s32 unk00[5];
    s32 count;
} Queue;

extern s32 func_8007E0AC(void);
extern void func_8007DA20(void);
extern void func_8007DED8(s32 arg0);
extern void func_8007B744(s32 arg0);
extern Resource *func_800305E8(s32 id);
extern void *func_80030964(Resource *resource);
extern s32 func_800181BC(void *object, s32 which, s32 value, s32 flags, s32 mode);
extern void func_80017520(f32 (*matrix)[4], f32 x, f32 y, f32 z);
extern void func_80017BA8(void *object, f32 (*matrix)[4]);

extern s32 D_800A5B5C;
extern s32 D_800A66D0;
extern s32 D_800A66D4;
extern s32 D_800A66D8;
extern f32 D_800ADC30;
extern void *D_8011C8F0;
extern void *D_8011C8F4;
extern void *D_8011C8F8;
extern void *D_8011C8FC;
extern void *D_8011C904;
typedef struct NodeSet {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0C;
    void *unk10;
    void *unk14;
} NodeSet;

extern NodeSet D_8011C910;
extern void *D_8011C930;
extern void *D_8011C938;
extern void *D_8011C93C;
extern void *D_8011C940;
extern Queue D_8011C950;
extern s32 D_8011C964;
extern void *D_8011C970[1];
extern s32 D_8011CA58;
extern s32 D_8011CA5C;
extern s32 D_8011CA60[48];

s32 func_8007E0EC(s32 arg0, s32 arg1, s32 arg2) {
    MatrixWork work;
    s32 result;
    Resource *resource;
    void *node;
    s32 i;

    (void)arg1;
    result = 0;
    D_8011CA58 = 0;
    D_8011CA5C = 0;
    for (i = 0; i < 48; i++) {
        D_8011CA60[i] = 0;
    }
    D_800A66D8 = arg0;
    D_800A66D4 = 0;
    D_800A66D0 = 0;
    if (D_800A5B5C != 0) {
        func_8007DA20();
    }

    if (arg0 == 1) {
        result = func_8007E0AC();
        resource = func_800305E8(0xF9);
        D_8011C8F0 = func_80030964(resource);
        func_8007B744(0);
        node = resource->unk00;
        D_8011C910.unk00 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C950.count] = resource->unk00;
        D_8011C950.count++;

        resource = func_800305E8(0xF6);
        D_8011C8F4 = func_80030964(resource);
        func_8007B744(1);
        node = resource->unk00;
        D_8011C910.unk04 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C950.count] = resource->unk00;
        D_8011C950.count++;

        resource = func_800305E8(0xBF);
        D_8011C8F8 = func_80030964(resource);
        func_8007B744(2);
        node = resource->unk00;
        D_8011C910.unk08 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C950.count] = resource->unk00;
        D_8011C950.count++;

        resource = func_800305E8(0xC0);
        D_8011C8FC = func_80030964(resource);
        D_8011C910.unk0C = ((void **)((void **)resource->unk00)[6])[1];
        D_8011C93C = D_8011C910.unk0C;
        D_8011C910.unk10 = ((void **)((void **)resource->unk00)[6])[0];
        D_8011C940 = D_8011C910.unk10;
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    if (arg0 == 2) {
        result = func_8007E0AC();
        resource = func_800305E8(0x97);
        D_8011C8F0 = func_80030964(resource);
        D_8011C910.unk00 = resource->unk00;
        D_8011C930 = resource->unk00;

        resource = func_800305E8(0x122);
        D_8011C8F4 = func_80030964(resource);
        func_8007B744(1);
        node = resource->unk00;
        D_8011C910.unk04 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C964] = resource->unk00;
        D_8011C964++;
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    if (arg0 == 3) {
        result = func_8007E0AC();
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    if (arg0 == 4) {
        result = func_8007E0AC();
        resource = func_800305E8(0x118);
        D_8011C8F0 = func_80030964(resource);
        func_8007B744(0);
        node = resource->unk00;
        D_8011C910.unk00 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C950.count] = resource->unk00;
        D_8011C950.count++;

        resource = func_800305E8(0x117);
        D_8011C8F4 = func_80030964(resource);
        func_8007B744(1);
        node = resource->unk00;
        D_8011C910.unk04 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C950.count] = resource->unk00;
        D_8011C950.count++;

        resource = func_800305E8(0x122);
        D_8011C8FC = func_80030964(resource);
        func_8007B744(3);
        node = resource->unk00;
        D_8011C910.unk0C = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C964] = resource->unk00;
        D_8011C964++;

        resource = func_800305E8(0x12D);
        D_8011C8F8 = func_80030964(resource);
        D_8011C910.unk08 = resource->unk00;
        D_8011C938 = resource->unk00;

        resource = func_800305E8(0x127);
        D_8011C904 = func_80030964(resource);
        func_8007B744(5);
        node = resource->unk00;
        D_8011C910.unk14 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C964] = resource->unk00;
        D_8011C964++;
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    if (arg0 == 5) {
        result = func_8007E0AC();
        resource = func_800305E8(0x128);
        D_8011C8F0 = func_80030964(resource);
        D_8011C910.unk00 = resource->unk00;
        D_8011C930 = resource->unk00;

        resource = func_800305E8(0x12D);
        D_8011C8F8 = func_80030964(resource);
        D_8011C910.unk08 = resource->unk00;
        D_8011C938 = resource->unk00;
        func_80017520(work.m, D_800ADC30, D_800ADC30, D_800ADC30);
        func_80017BA8(D_8011C910.unk08, work.m);
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    if (arg0 == 6) {
        result = func_8007E0AC();
        resource = func_800305E8(0x123);
        D_8011C8F0 = func_80030964(resource);
        func_8007B744(0);
        node = resource->unk00;
        D_8011C910.unk00 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C964] = resource->unk00;
        D_8011C964++;
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    if (arg0 == 7) {
        result = func_8007E0AC();
        resource = func_800305E8(0x125);
        D_8011C8F0 = func_80030964(resource);
        func_8007B744(0);
        node = resource->unk00;
        D_8011C910.unk00 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C964] = resource->unk00;
        D_8011C964++;
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    if (arg0 == 0) {
        result = func_8007E0AC();
        resource = func_800305E8(0xF7);
        D_8011C8F0 = func_80030964(resource);
        func_8007B744(0);
        node = resource->unk00;
        D_8011C910.unk00 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C964] = resource->unk00;
        D_8011C964++;

        resource = func_800305E8(0xF6);
        D_8011C8F4 = func_80030964(resource);
        func_8007B744(1);
        node = resource->unk00;
        D_8011C910.unk04 = node;
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        D_8011C970[D_8011C964] = resource->unk00;
        D_8011C964++;

        resource = func_800305E8(0x124);
        D_8011C8F8 = func_80030964(resource);
        D_8011C910.unk08 = resource->unk00;
        D_8011C938 = resource->unk00;
        if (arg2 != 0) {
            func_8007DED8(arg2);
        }
    }

    return result;
}
