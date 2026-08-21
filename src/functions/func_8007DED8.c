/* Recovery evidence: specs/functions/recovered/medium_system_tranche.md. */
#include "podcruise/types.h"

typedef struct Node8007DED8 {
    /* 0x00 */ u8 unk00[0x18];
    /* 0x18 */ struct Node8007DED8 **unk18;
} Node8007DED8;

typedef struct Item8007DED8 {
    /* 0x00 */ u8 unk00[0x3C];
    /* 0x3C */ s32 unk3C;
} Item8007DED8;

extern s32 D_800A5B5C;
extern s32 D_800A66DC;

extern s32 func_80017DA4(Node8007DED8 *node);
extern s32 func_80017DAC(Node8007DED8 *node);
extern s32 func_80017E54(Node8007DED8 *node);
extern void *func_80017E5C(Node8007DED8 *node, s32 index);
extern s32 func_800181BC(Node8007DED8 *node, s32 which, u32 value, s32 flags, s32 mode);
extern u32 func_800182FC(Node8007DED8 *node, s32 selector);
extern Item8007DED8 *func_800183A8(void *object);
extern void func_8007D3CC(s32 handle, u32 value);
extern s32 func_8007DBA4(Node8007DED8 *node);

s32 func_8007DED8(Node8007DED8 *node) {
    s32 pad[2];
    s32 type;
    f32 scratch[24];
    s32 saved;
    s32 count;
    s32 count2;
    s32 index;
    s32 result;
    Item8007DED8 *item;
    void *object;

    (void)scratch;
    (void)pad;
    type = func_80017DA4(node);
    result = 0;
    if (type == 0x3064) {
        if (D_800A5B5C != 0 && D_800A66DC == 0) {
            result = func_8007DBA4(node);
        }
        count = func_80017E54(node);
        for (index = 0; index < count; index++) {
            object = func_80017E5C(node, index);
            if (object != 0) {
                item = func_800183A8(object);
                if (item != 0 && item->unk3C != 0) {
                    func_8007D3CC(item->unk3C, func_800182FC(node, 2));
                }
            }
        }
    } else if (type & 0x4000) {
        if (type & 0x8000) {
            saved = D_800A66DC;
            D_800A66DC = 1;
        }
        count2 = func_80017DAC(node);
        for (index = 0; index < count2; index++) {
            if (node->unk18[index] != 0) {
                result |= func_8007DED8(node->unk18[index]);
            }
        }
        if (D_800A5B5C != 0 && D_800A66DC == 0) {
            func_800181BC(node, 0, 0xFF, 0x10, 3);
            func_800181BC(node, 0, result, 0x10, 2);
        }
        if (type & 0x8000) {
            D_800A66DC = saved;
        }
    }
    return result;
}
