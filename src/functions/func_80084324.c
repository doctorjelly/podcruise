/* Independently written from scratchpad spec specs/func_80084324.md. */
#include "podcruise/types.h"

typedef struct Unk80084324Node {
    u8 pad00[0x30];
    void *unk30;
    s16 *unk34;
    u8 pad38[2];
    s16 unk3A;
} Unk80084324Node;

typedef struct Unk80084324Owner {
    u8 pad00[0x14];
    s32 count;
    Unk80084324Node **items;
} Unk80084324Owner;

extern void func_80016CAC(f32 *destination, f32 *source, f32 (*transform)[4]);
extern f32 func_800153EC(f32 *a, f32 *b);
extern void func_80084148(void *shape, f32 (*transform)[4], f32 *best, f32 *reference, f32 *outPoint, s32 extra);

void func_80084324(Unk80084324Owner *owner, f32 (*transform)[4], s32 mode, f32 *best,
                   f32 *reference, f32 *outPoint, s32 extra) {
    s32 i;
    s32 j;
    Unk80084324Node *node;
    s16 *vertex;
    f32 distance;

    for (i = 0; i < owner->count; i++) {
        node = owner->items[i];
        if (mode != 0) {
            f32 source[3];
            f32 transformed[3];
            vertex = node->unk34;
            for (j = 0; j < node->unk3A; j++) {
                source[0] = (f32)vertex[0];
                source[1] = (f32)vertex[1];
                source[2] = (f32)vertex[2];
                func_80016CAC(transformed, source, transform);
                distance = func_800153EC(transformed, reference);
                if (distance < *best) {
                    outPoint[0] = transformed[0];
                    outPoint[1] = transformed[1];
                    outPoint[2] = transformed[2];
                    *best = distance;
                }
                vertex += 8;
            }
        } else {
            func_80084148(node->unk30, transform, best, reference, outPoint, extra);
        }
    }
}
