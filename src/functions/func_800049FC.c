/* Recovered from specification $S/specs/func_800049FC.md */
#include "podcruise/types.h"

typedef struct Node800049FC {
    u8 pad00[0x18];
    void **unk18;
    f32 unk1C[6];
} Node800049FC;

extern f32 D_800AE8B0;
extern f32 D_800AE8E8[7];
extern f32 D_800AE918[3];
extern f32 D_800AE928[3];
extern s32 D_800AEC78;
extern s32 D_800AEC7C;
extern s32 D_8009A270;
extern s32 D_8009A274;
extern s32 D_8009A278;

extern void func_800035BC(void *object);
extern void func_80003B44(s32 flags);
extern void func_80004704(s32 flags, s32 count, f32 (*out)[7], f32 (*in)[7]);
extern void func_800155EC(f32 *out, f32 *src, f32 scale, f32 *axis);
extern s32 func_80017E54(Node800049FC *node);
extern s32 func_80017E88(void *object, s32 selector);
extern void *func_80017EDC(void *object);

void func_800049FC(Node800049FC *node, f32 (*arg1)[7], s32 arg2) {
    s32 count;
    f32 unused[22];
    f32 vec[3];
    f32 zero;
    s32 i;
    s32 mode;
    f32 *box;
    void *child;

    (void)unused;
    if (node == 0) {
        D_800AE8B0 = -1.0f;
        return;
    }

    if (D_800AEC78 != 0) {
        D_800AEC78 = 0;
        func_80004704(arg2, 1, &D_800AE8E8, arg1);
    }

    func_800155EC(vec, D_800AE8E8, D_800AE8E8[6], &D_800AE8E8[3]);

    zero = 0.0f;
    if (D_800AE8E8[3] < zero) {
        D_800AE918[0] = D_800AE8E8[0] + zero;
        D_800AE928[0] = vec[0] - zero;
    } else {
        D_800AE928[0] = D_800AE8E8[0] - zero;
        D_800AE918[0] = vec[0] + zero;
    }
    if (D_800AE8E8[4] < zero) {
        D_800AE918[1] = D_800AE8E8[1] + zero;
        D_800AE928[1] = vec[1] - zero;
    } else {
        D_800AE928[1] = D_800AE8E8[1] - zero;
        D_800AE918[1] = vec[1] + zero;
    }
    if (D_800AE8E8[5] < zero) {
        D_800AE918[2] = D_800AE8E8[2] + zero;
        D_800AE928[2] = vec[2] - zero;
    } else {
        D_800AE928[2] = D_800AE8E8[2] - zero;
        D_800AE918[2] = vec[2] + zero;
    }

    box = node->unk1C;
    if (box != 0) {
        if (D_800AE918[0] < box[0]) {
            return;
        }
        if (box[3] < D_800AE928[0]) {
            return;
        }
        if (D_800AE918[1] < box[1]) {
            return;
        }
        if (box[4] < D_800AE928[1]) {
            return;
        }
        if (D_800AE918[2] < box[2]) {
            return;
        }
        if (box[5] < D_800AE928[2]) {
            return;
        }
    }

    count = func_80017E54(node);
    for (i = 0; i < count; i++) {
        child = node->unk18[i];
        box = (f32 *)((u8 *)child + 8);
        if (D_800AE918[0] < box[0]) {
            continue;
        }
        if (box[3] < D_800AE928[0]) {
            continue;
        }
        if (D_800AE918[1] < box[1]) {
            continue;
        }
        if (box[4] < D_800AE928[1]) {
            continue;
        }
        if (D_800AE918[2] < box[2]) {
            continue;
        }
        if (box[5] < D_800AE928[2]) {
            continue;
        }
        if (D_8009A270 != 0) {
            D_8009A278 = 1;
            D_8009A274 = 1;
        } else {
            mode = func_80017E88(func_80017EDC(child), 1);
            if (mode == 1 || mode == 3) {
                D_8009A278 = 0;
            } else {
                D_8009A278 = 1;
            }
            if (mode == 2 || mode == 3) {
                D_8009A274 = 0;
            } else {
                D_8009A274 = 1;
            }
        }
        func_800035BC(child);
    }

    if (D_800AEC7C != 0) {
        func_80003B44(arg2);
        D_800AEC7C = 0;
    }
}
