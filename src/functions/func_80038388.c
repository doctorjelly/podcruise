/* Independently written from scratchpad spec specs/func_80038388.md (scene node traversal). */

#include "podcruise/types.h"

typedef struct Node80038388 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ struct Node80038388 **unk18;
    /* 0x1C */ union {
        s32 index;
        f32 matrix[4][3];
    } unk1C;
    /* 0x4C */ f32 unk4C[4][3];
} Node80038388;

typedef struct Mask80038388 {
    u8 pad00[0x158];
    u32 required;
    u32 wanted;
} Mask80038388;

extern Mask80038388 *D_80112C94;
extern s32 D_80112DD8;
extern s32 D_800A3FE8;
extern s32 D_800A3FF4;
extern s32 D_800A4008;

extern s32 func_80017DA4(Node80038388 *node);
extern s32 func_80017DAC(Node80038388 *node);
extern u32 func_800182FC(void *object, s32 selector);
extern void func_8002E2FC(void);
extern void func_800349C4(void);
extern void func_80034DA8(void);
extern s32 func_80035354(s32 request, s16 index);
extern void func_80035598(s32 token);
extern void func_800374C4(Node80038388 *node);
extern void func_80037BF8(f32 *result, f32 *source, f32 *offset);
extern void func_80037C8C(s32 mode, f32 matrix[4][3], Node80038388 *node);
extern void func_80037E9C(Node80038388 *node);
extern s32 func_80038294(Node80038388 *node);

void func_80038388(Node80038388 *node) {
    s32 n;
    s32 count[1];
    f32 matrix[4][3];
    s32 token;
    Node80038388 *child;
    s32 kind;
    s32 ticks;
    s32 none;
    s32 index;
    s32 i;

    if (node == 0) {
        return;
    }
    if ((func_800182FC(node, 2) & D_80112C94->required) != D_80112C94->required) {
        return;
    }
    if ((func_800182FC(node, 2) & D_80112C94->wanted) == 0) {
        return;
    }

    ticks = D_800A4008;
    D_800A4008 = ticks + 1;
    if (ticks >= 11) {
        D_800A4008 = 0;
        func_8002E2FC();
    }

    none = -1;
    kind = func_80017DA4(node);
    if (kind != 0x3064) {
        if (D_800A3FE8 == 0) {
            if (node->unk0C & 0x20) {
                none = -1;
                D_80112DD8 = none;
                if (D_800A3FE8 != 0) {
                    if (D_800A3FF4 != 0) {
                        func_800349C4();
                        func_80034DA8();
                    }
                }
            }
        }
    }

    token = func_80035354(node->unk10, node->unk0E);

    switch (kind) {
        case 0xD066:
            func_80037E9C(node);
            break;
        case 0xD065:
            if (func_80017DAC(node) > 0) {
                if (node->unk0C & 0x10) {
                    matrix[0][0] = node->unk1C.matrix[0][0];
                    matrix[0][1] = node->unk1C.matrix[0][1];
                    matrix[0][2] = node->unk1C.matrix[0][2];
                    matrix[1][0] = node->unk1C.matrix[1][0];
                    matrix[1][1] = node->unk1C.matrix[1][1];
                    matrix[1][2] = node->unk1C.matrix[1][2];
                    matrix[2][0] = node->unk1C.matrix[2][0];
                    matrix[2][1] = node->unk1C.matrix[2][1];
                    matrix[2][2] = node->unk1C.matrix[2][2];
                    matrix[3][0] = node->unk1C.matrix[3][0];
                    matrix[3][1] = node->unk1C.matrix[3][1];
                    matrix[3][2] = node->unk1C.matrix[3][2];
                    func_80037BF8(&matrix[0][0], (f32 *)&node->unk1C,
                                  &node->unk4C[0][0]);
                    func_80037C8C(1, matrix, node);
                } else {
                    func_80037C8C(1, node->unk1C.matrix, node);
                }
            }
            break;
        case 0xD064:
            func_80037C8C(0, node->unk1C.matrix, node);
            break;
        case 0x5066:
            index = func_80038294(node);
            if (index != none) {
                child = node->unk18[index];
                if (child != 0) {
                    if ((func_800182FC(child, 2) & D_80112C94->required) ==
                        D_80112C94->required) {
                        if ((func_800182FC(child, 2) & D_80112C94->wanted) !=
                            0) {
                            func_80038388(child);
                        }
                    }
                }
            }
            break;
        case 0x5065:
            count[0] = func_80017DAC(node);
            if (node->unk1C.index != -2) {
                if (node->unk1C.index == none) {
                    if (count[0] > 0) {
                        i = 0;
                        do {
                            child = node->unk18[i];
                            if (child != 0) {
                                if ((func_800182FC(child, 2) &
                                     D_80112C94->required) ==
                                    D_80112C94->required) {
                                    if ((func_800182FC(child, 2) &
                                         D_80112C94->wanted) != 0) {
                                        func_80038388(child);
                                    }
                                }
                            }
                            i++;
                        } while (i != count[0]);
                    }
                } else if (node->unk1C.index >= 0 && node->unk1C.index < count[0]) {
                    child = node->unk18[node->unk1C.index];
                    if (child != 0) {
                        if ((func_800182FC(child, 2) & D_80112C94->required) ==
                            D_80112C94->required) {
                            if ((func_800182FC(child, 2) &
                                 D_80112C94->wanted) != 0) {
                                func_80038388(child);
                            }
                        }
                    }
                }
            }
            break;
        case 0x5064:
            n = func_80017DAC(node);
            count[0] = n;
            {
                for (i = 0; i < n; i++) {
                    child = node->unk18[i];
                    if (child != 0) {
                        if ((func_800182FC(child, 2) & D_80112C94->required) ==
                            D_80112C94->required) {
                            if ((func_800182FC(child, 2) &
                                 D_80112C94->wanted) != 0) {
                                func_80038388(child);
                            }
                        }
                    }
                }
            }
            break;
        case 0x3064:
            func_800374C4(node);
            break;
    }

    func_80035598(token);
}
