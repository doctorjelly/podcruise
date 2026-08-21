/* Recovered from specification $S/specs/func_8007C64C.md (batch_04). */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x0C];
    /* 0x00C */ s32 unk00C;
    /* 0x010 */ u8 unk010[0x2C];
    /* 0x03C */ void *unk03C;
    /* 0x040 */ u8 unk040[0x08];
    /* 0x048 */ void *unk048;
    /* 0x04C */ f32 *unk04C;
} PcView;

typedef struct {
    /* 0x000 */ u8 unk000[0x50];
    /* 0x050 */ f32 unk050;
    /* 0x054 */ f32 unk054;
    /* 0x058 */ f32 unk058;
    /* 0x05C */ u8 unk05C[0x110];
    /* 0x16C */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
} PcSubject;

typedef struct {
    /* 0x00 */ u8 unk00[0x18];
    /* 0x18 */ void *unk18;
} PcNode;

extern void *D_8011C918;
extern u8 D_8011C940;
extern f32 D_800ADB64;

extern f32 func_800151E0(f32 *vector);
extern void func_80017874(f32 (*matrix)[4]);
extern void func_80017BA8(void *destination, f32 (*source)[4]);
extern s32 func_800181BC(void *object, s32 which, s32 value, s32 flags, s32 mode);
extern void func_8007B6CC(s32 index);
extern s32 func_8007B7BC(s32 index);
extern void func_8007B9E4(s32 key);
extern PcNode *func_8007BA9C(f32 *source);

void func_8007C64C(PcView *view, PcSubject *subject) {
    f32 offset[3];
    f32 distance;
    PcNode *node;
    f32 matrix[4][4];
    void *previous;

    previous = view->unk03C;
    if (previous != 0) {
        func_800181BC(previous, 2, -4, 0x10, 3);
    }

    view->unk00C |= 2;
    if (func_8007B7BC(2) == 0) {
        func_8007B9E4(0x6C);
    }
    view->unk00C |= 1;

    func_80017874(matrix);
    matrix[3][0] = view->unk04C[0];
    matrix[3][1] = view->unk04C[1];
    matrix[3][2] = view->unk04C[2];
    matrix[3][0] = matrix[3][0] + 8.0f;
    matrix[3][2] = matrix[3][2] - 24.0f;

    offset[0] = subject->unk050 - subject->unk16C;
    offset[1] = subject->unk054 - subject->unk170;
    offset[2] = subject->unk058 - subject->unk174;
    distance = func_800151E0(offset);
    if (D_800ADB64 < distance) {
        matrix[0][0] = offset[1];
        matrix[0][1] = -offset[0];
        matrix[1][0] = offset[0];
        matrix[1][1] = offset[1];
    }

    func_80017BA8(D_8011C918, matrix);
    if (D_8011C918 != 0) {
        func_800181BC(D_8011C918, 2, 3, 0x10, 2);
    }

    node = func_8007BA9C(view->unk04C);
    view->unk048 = node;
    if (node != 0) {
        if (node != 0) {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
        func_80017BA8(node, matrix);
        node->unk18 = &D_8011C940;
    }

    func_8007B6CC(2);
}
