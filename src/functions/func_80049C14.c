/* Independently written from specs/functions/recovered/func_80049C14.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct {
    /* 0x00 */ PcVec3f first;
    /* 0x0C */ f32 pad0C;
    /* 0x10 */ PcVec3f second;
} AnglePair80049C14;

static const f32 D_800AAFD0[1] = { 0.0f };

extern PcVec3f D_800A51F4;
extern PcVec3f D_80118D90;
extern PcVec3f D_80118E50;
extern AnglePair80049C14 D_80118D60;
extern void **D_8011A690[];
extern s32 D_800A5200;
extern s16 D_800A4BC0;
extern PcVec3f D_8011AC48;
extern PcVec3f D_8011AC54;

extern void func_80017874(f32 *matrix);
extern void func_800178C4(void *arg0, void *arg1, f32 a, f32 b, f32 c, f32 d);
extern s32 func_80082BE0(void);
extern void func_8000EA4C(void *node, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f);
extern void func_80017918(f32 dest[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_80083D80(void *node, f32 *arg1, s32 flags);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);

void func_80049C14(s32 arg0, s32 index, f32 amount) {
    PcVec3f axis;
    f32 matrix[4][4];
    void *object;
    f32 scale;
    PcVec3f offset;

    (void)arg0;
    scale = 0.0018f * amount;
    offset = D_800A51F4;
    object = D_8011A690[index][0];
    if (object == 0) {
        return;
    }

    func_80017874(&matrix[0][0]);
    func_80015630(&axis, 0.6667f, &D_80118D90, 0.3333f, &D_80118E50);
    func_800178C4(matrix, matrix, 90.0f, D_80118D60.first.x, D_80118D60.first.y,
                  D_80118D60.first.z);
    func_800178C4(matrix, matrix, 160.0f, D_80118D60.second.x,
                  D_80118D60.second.y, D_80118D60.second.z);

    switch (index) {
    case 0:  scale = (0.0018f * amount) * 1.5f; break;
    case 1:  scale = (0.0018f * amount) * 1.5f; break;
    case 2:  scale = (0.0018f * amount) * 1.2f; break;
    case 4:  scale = (0.0018f * amount) * 0.8f; break;
    case 5:  scale = (0.0018f * amount) * 1.2f; break;
    case 6:  scale = (0.0018f * amount) * 1.5f; break;
    case 7:  scale = (0.0018f * amount) * 1.5f; break;
    case 8:  scale = (0.0018f * amount) * 1.3f; break;
    case 9:  scale = (0.0018f * amount) * 1.5f; break;
    case 10: scale = (0.0018f * amount) * 1.5f; break;
    case 11: scale = (0.0018f * amount) * 1.7f; break;
    case 12: scale = (0.0018f * amount) * 1.5f; break;
    case 13: scale = (0.0018f * amount) * 2.2f; break;
    case 14: scale = (0.0018f * amount) * 1.8f; break;
    case 15: scale = (0.0018f * amount) * 2.3f; break;
    case 16: scale = (0.0018f * amount) * 5.0f; break;
    case 17: scale = (0.0018f * amount) * 1.2f; break;
    case 18: scale = (0.0018f * amount) * 1.2f; break;
    case 19: scale = (0.0018f * amount) * 1.3f; break;
    case 22: scale = (0.0018f * amount) * 2.3f; break;
    case 23: scale = (0.0018f * amount) * 2.5f; break;
    case 24: scale = (0.0018f * amount) * 2.5f; break;
    }

    func_8000EA4C(object, 0, 0, 0, 0xFF, 0,
                  (s16)((f32)func_80082BE0() / (f32)2147483648.0 * 60.0f + 170.0f));
    func_80017918(matrix, scale, scale, scale, matrix);
    func_80015288((PcVec3f *)&matrix[3][0], &axis);
    func_80017BA8(object, matrix);

    if (*(s32 *)0x800A5200 != index || D_800A4BC0 != 0) {
        D_800A5200 = index;
        if (func_80083D80(object, &D_8011AC48.x, 0) == 0) {
            func_80015268(&D_8011AC48, 0.0f, 0.0f, 0.0f);
            func_80015268(&D_8011AC54, -10.0f, -10.0f, -10.0f);
        }
    }

    switch (index) {
    case 0:  func_80015268(&offset, 0.0f, 0.0f, 0.0f); break;
    case 1:  func_80015268(&offset, 0.0f, 0.0f, 0.0f); break;
    case 2:  func_80015268(&offset, 0.0f, 0.0f, 0.0f); break;
    case 3:  func_80015268(&offset, 0.0f, 0.0f, 0.0f); break;
    case 4:  func_80015268(&offset, 0.0f, 0.0f, 2.0f); break;
    case 5:  func_80015268(&offset, 0.0f, 0.0f, 0.0f); break;
    case 6:  func_80015268(&offset, -4.0f, 0.0f, -2.0f); break;
    case 7:  func_80015268(&offset, -4.0f, 0.0f, 0.0f); break;
    case 8:  func_80015268(&offset, 0.0f, 0.0f, -1.0f); break;
    case 9:  func_80015268(&offset, -4.0f, 0.0f, 0.0f); break;
    case 10: func_80015268(&offset, -2.0f, 0.0f, 2.0f); break;
    case 11: func_80015268(&offset, -2.0f, 0.0f, 4.0f); break;
    case 12: func_80015268(&offset, 0.0f, 0.0f, 0.0f); break;
    case 13: func_80015268(&offset, 0.0f, 0.0f, 0.0f); break;
    case 14: func_80015268(&offset, -1.0f, 0.0f, 1.0f); break;
    case 15: func_80015268(&offset, 0.0f, 0.0f, -12.0f); break;
    case 16: func_80015268(&offset, -4.0f, 0.0f, 1.0f); break;
    case 17: func_80015268(&offset, 0.0f, 0.0f, 2.0f); break;
    case 18: func_80015268(&offset, 0.0f, 0.0f, 2.0f); break;
    case 19: func_80015268(&offset, -4.0f, 0.0f, -2.0f); break;
    case 20: func_80015268(&offset, 0.0f, 0.0f, -5.0f); break;
    case 21: func_80015268(&offset, 0.0f, 0.0f, -6.0f); break;
    case 22: func_80015268(&offset, -4.0f, 0.0f, -6.0f); break;
    case 23: func_80015268(&offset, 16.0f, 0.0f, 2.0f); break;
    case 24: func_80015268(&offset, -6.0f, 0.0f, 12.0f); break;
    }

    func_80015328((PcVec3f *)&matrix[3][0], (PcVec3f *)&matrix[3][0], &offset);
    func_80017BA8(object, matrix);
    if (object != 0) {
        func_800181BC(object, 2, 3, 0x10, 2);
    }
}
