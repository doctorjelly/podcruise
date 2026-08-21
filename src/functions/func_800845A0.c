/* spec: specs/func_800845A0.md */
#include "podcruise/types.h"

typedef struct Node800845A0 {
    u8 pad00[0xC];
    u16 unk0C;
    u8 pad0E[0x18 - 0xE];
    struct Node800845A0 **children;
    union {
        s32 selector;
        f32 matrix[12];
    } u;
} Node800845A0;

typedef struct {
    u8 pad00[0x4C];
    f32 offset[3];
} Owner800845A0;

extern void func_800156DC(f32 (*)[4], f32 (*)[4]);
extern void func_80015724(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
extern s32 func_80017DA4(Node800845A0 *);
extern s32 func_80017DAC(Node800845A0 *);
extern s32 func_800182FC(Node800845A0 *, s32);
extern void func_80084324(void *, f32 (*)[4], s32, f32 *, f32 *, f32 *, s32);
extern s32 func_800844C8(Node800845A0 *);

extern s32 D_800A6894;
extern s32 D_800A6898;
extern Node800845A0 *D_80120DA0[];

void func_800845A0(Node800845A0 *root, Node800845A0 *node, f32 (*mtx)[4], s32 flag,
                   s32 mode, f32 *best, f32 *reference, f32 *outPoint, s32 extra) {
    s32 dead[4];
    Owner800845A0 *dummy;
    Owner800845A0 *owner;
    f32 local[4][4];
    f32 work[4][4];
    s32 type;
    s32 count;
    s32 i;

    (void)dead;
    if (node == 0) {
        return;
    }
#if defined(__GNUC__)
    dummy = (Owner800845A0 *)node;
#endif
    if (func_800182FC(node, 2) == 0) {
        return;
    }
    type = func_80017DA4(node);
    if (node == root) {
        flag = 1;
    }
    func_800156DC(local, mtx);
    switch (type) {
    case 0x5064:
    case 0xD064:
    case 0xD065:
        if ((type & 0x8000) != 0) {
            if (D_800A6898 >= 0) {
                if (D_800A6898 < D_800A6894 - 1) {
                    D_80120DA0[D_800A6898] = node;
                }
                D_800A6898 = D_800A6898 + 1;
            }
            if (type == 0xD065) {
                owner = (Owner800845A0 *)node;
            } else {
                owner = dummy;
            }
            work[0][0] = node->u.matrix[0];
            work[0][1] = node->u.matrix[1];
            work[0][2] = node->u.matrix[2];
            work[1][0] = node->u.matrix[3];
            work[1][1] = node->u.matrix[4];
            work[1][2] = node->u.matrix[5];
            work[2][0] = node->u.matrix[6];
            work[2][1] = node->u.matrix[7];
            work[2][2] = node->u.matrix[8];
            work[3][0] = node->u.matrix[9];
            work[3][1] = node->u.matrix[10];
            work[3][2] = node->u.matrix[11];
            work[0][3] = 0.0f;
            work[1][3] = 0.0f;
            work[2][3] = 0.0f;
            work[3][3] = 1.0f;
            if ((node->unk0C & 0x10) != 0) {
                for (i = 0; i < 3; i++) {
                    work[3][i] += -owner->offset[0] * node->u.matrix[i];
                    work[3][i] += -owner->offset[1] * node->u.matrix[i + 3];
                    work[3][i] += -owner->offset[2] * node->u.matrix[i + 6];
                    work[3][i] += owner->offset[i];
                }
            }
            func_80015724(local, work, mtx);
        }
        count = func_80017DAC(node);
        for (i = 0; i < count; i++) {
            if (node->children[i] != 0) {
                func_800845A0(root, node->children[i], local, flag, mode, best, reference, outPoint, extra);
            }
        }
        if ((type & 0x8000) != 0) {
            if (D_800A6898 >= 0) {
                D_800A6898 = D_800A6898 - 1;
            }
        }
        break;
    case 0x5066:
        count = func_800844C8(node);
        if (count == -1) {
            break;
        }
        if (node->children[count] != 0) {
            func_800845A0(root, node->children[count], local, flag, mode, best, reference, outPoint, extra);
        }
        break;
    case 0x5065:
        count = func_80017DAC(node);
        if (node->u.selector == -2) {
            break;
        }
        if (node->u.selector == -1) {
            for (i = 0; i < count; i++) {
                if (node->children[i] != 0) {
                    func_800845A0(root, node->children[i], local, flag, mode, best, reference, outPoint, extra);
                }
            }
            break;
        }
        if (node->children[node->u.selector] != 0) {
            func_800845A0(root, node->children[node->u.selector], local, flag, mode, best, reference, outPoint, extra);
        }
        break;
    case 0x3064:
        if (flag != 0) {
            func_80084324(node, local, mode, best, reference, outPoint, extra);
        }
        break;
    case 0xD066:
        break;
    }
}
