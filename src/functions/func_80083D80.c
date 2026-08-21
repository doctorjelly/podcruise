/* Recovered from specification specs/func_80083D80.md (worker batch 12). */
#include "podcruise/types.h"

typedef struct Node80083D80 {
    /* 0x00 */ u8 unk00[0x18];
    /* 0x18 */ struct Node80083D80 **unk18;
} Node80083D80;

extern f32 D_80120D40[4][4];

extern void func_80017874(f32 (*)[4]);
extern s32 func_80017DA4(Node80083D80 *);
extern void func_80017C18(Node80083D80 *, f32 (*)[4]);
extern void func_80017C98(Node80083D80 *, f32 (*)[4]);
extern void func_80015C30(f32 (*)[4], f32 (*)[4]);
extern s32 func_80017DAC(Node80083D80 *);
extern void func_80017E20(Node80083D80 *, f32 *);
extern void func_80016CAC(f32 *, f32 *, f32 (*)[4]);

s32 func_80083D80(Node80083D80 *node, f32 *arg1, s32 flags) {
    s32 type;
    s32 count;
    s32 index;
    s32 extra[2];
    f32 matrix[4][4];

    (void)extra;
    if (node == 0) {
        return 0;
    }
    {
        if (!(flags & 1)) {
            func_80017874(D_80120D40);
        }
        flags |= 1;
        type = func_80017DA4(node);
        if (type & 0x4000) {
            if (type == 0xD065) {
                func_80017C18(node, matrix);
                func_80015C30(D_80120D40, matrix);
            } else if (type == 0xD064) {
                func_80017C98(node, matrix);
                func_80015C30(D_80120D40, matrix);
            }
            count = func_80017DAC(node);
            for (index = 0; index < count; index++) {
                if (func_80083D80(node->unk18[index], arg1, flags)) {
                    return 1;
                }
            }
            return 0;
        } else if (type == 0x3064) {
            func_80017E20(node->unk18[0], arg1);
            func_80016CAC(arg1, arg1, D_80120D40);
            func_80016CAC(&arg1[3], &arg1[3], D_80120D40);
            return 1;
        }
    }
    return 0;
}
