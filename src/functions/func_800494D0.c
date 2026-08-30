/* Independently written from specs/functions/recovered/func_800494D0.md. */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s32 unk1C[16];
} Course;

extern Course D_800D6DD8[];
extern f32 D_80119670[][6];
extern void **D_8011A508[];
extern f32 D_80120BF8;
extern f32 D_800A508C[3];
extern f32 D_800A51F0;
extern f32 D_800AAFC8;
extern f32 D_800AAFCC;
extern f32 D_800AAFD0;
extern f32 D_80118D60[4][4];
extern f32 D_80118E20[4][4];

extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void func_800156DC(f32 output[4][4], const f32 source[4][4]);
extern void func_80015288(f32 *output, const f32 *source);
extern void func_800155EC(f32 *output, f32 *base, f32 scale, f32 *direction);
extern void func_80014CC0(f32 angle, f32 *outB, f32 *outA);
extern void func_800178C4(void *output, void *source, f32 angle, f32 x, f32 y, f32 z);
extern void func_80017918(f32 output[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);
extern void func_80017BA8(void *object, f32 source[4][4]);
extern void func_80028D60(void);
extern void func_80048F74(s32 arg0);

#define SHOW(object) if ((object) != 0) func_800181BC((object), 2, -4, 0x10, 3)
#define HIDE(object) if ((object) != 0) func_800181BC((object), 2, 3, 0x10, 2)

void func_800494D0(void *arg0, s32 arg1, f32 arg2) {
    f32 vector[3];
    f32 matrix[4][4];
    void *object;
    void **entry;
    f32 sine;
    f32 cosine;
    register s32 which;
    s32 index;
    s32 slot;
    f32 amount;

    which = arg1;
    for (index = 0; index < 8; index++) {
        D_800D6DD8[index].unk0C += D_80120BF8 * D_800D6DD8[index].unk10;
        if (D_800D6DD8[index].unk0C > 360.0f) { D_800D6DD8[index].unk0C -= 360.0f; }
        if (D_800D6DD8[index].unk0C < 0.0f) { D_800D6DD8[index].unk0C += 360.0f; }
        D_800D6DD8[index].unk14 += D_80120BF8 * D_800D6DD8[index].unk18;
        if (D_800D6DD8[index].unk14 > 360.0f) { D_800D6DD8[index].unk14 -= 360.0f; }
        if (D_800D6DD8[index].unk14 < 0.0f) { D_800D6DD8[index].unk14 += 360.0f; }
        entry = D_8011A508[index + 61];
        if (entry != 0) {
            object = *entry;
            if (object != 0) {
                SHOW(object);
            }
        }
    }

    for (index = 0; D_80119670[index] < D_80119670[19]; index++) {
        D_80119670[index][3] += D_80120BF8 * D_80119670[index][4];
        if (D_80119670[index][3] > 360.0f) { D_80119670[index][3] -= 360.0f; }
        if (D_80119670[index][3] < 0.0f) { D_80119670[index][3] += 360.0f; }
        D_80119670[index][3] += D_80120BF8 * D_80119670[index][4];
        if (D_80119670[index][3] > 360.0f) { D_80119670[index][3] -= 360.0f; }
        if (D_80119670[index][3] < 0.0f) { D_80119670[index][3] += 360.0f; }
    }

    func_80048F74(which);
    func_80028D60();

    object = *D_8011A508[which + 61];
    if (object != 0) {
        SHOW(object);
        func_800156DC(matrix, D_80118E20);
        func_80015288(vector, D_800A508C);
        func_800178C4(matrix, matrix, D_800D6DD8[which].unk0C, D_80118D60[2][0], D_80118D60[2][1], D_80118D60[2][2]);
        func_800178C4(matrix, matrix, D_800D6DD8[which].unk08, D_80118D60[1][0], D_80118D60[1][1], D_80118D60[1][2]);
        if (which == 6) {
            amount = D_800AAFC8 * arg2 * 1.5;
        } else {
            amount = D_800AAFCC * arg2 * D_800A51F0;
        }
        func_80017918(matrix, amount, amount, amount, matrix);
        func_80015288(matrix[3], vector);
        func_80017BA8(object, matrix);
        HIDE(object);
    }

    object = *D_8011A508[69];
    if (object != 0) {
        SHOW(object);
        amount = D_800AAFD0 * arg2;
        func_800156DC(matrix, D_80118E20);
        func_80015288(vector, D_800A508C);
        func_800178C4(matrix, matrix, D_800D6DD8[which].unk14, D_80118D60[2][0], D_80118D60[2][1], D_80118D60[2][2]);
        func_800178C4(matrix, matrix, D_800D6DD8[which].unk08, D_80118D60[1][0], D_80118D60[1][1], D_80118D60[1][2]);
        func_80017918(matrix, amount, amount, amount, matrix);
        func_80015288(matrix[3], vector);
        func_80017BA8(object, matrix);
        HIDE(object);
        if (which == 6) {
            SHOW(object);
        }
    }

    for (slot = D_800D6DD8[which].unk00; slot <= D_800D6DD8[which].unk04; slot++) {
        object = *D_8011A508[(slot - D_800D6DD8[which].unk00) + 70];
        if (object != 0) {
            SHOW(object);
            func_800156DC(matrix, D_80118E20);
            func_80015288(vector, D_800A508C);
            func_80014CC0(D_80119670[slot][3], &sine, &cosine);
            func_800155EC(vector, vector, D_80119670[slot][0] * sine * arg2, D_80118D60[0]);
            func_800155EC(vector, vector, D_80119670[slot][1] * cosine * arg2, D_80118D60[1]);
            func_800155EC(vector, vector, D_80119670[slot][2] * cosine * arg2, D_80118D60[2]);
            func_800178C4(matrix, matrix, D_80119670[slot][3], D_80118D60[2][0], D_80118D60[2][1], D_80118D60[2][2]);
            func_800178C4(matrix, matrix, D_800D6DD8[which].unk08, D_80118D60[1][0], D_80118D60[1][1], D_80118D60[1][2]);
            func_80017918(matrix, D_80119670[slot][5] * arg2, D_80119670[slot][5] * arg2, D_80119670[slot][5] * arg2, matrix);
            func_80015288(matrix[3], vector);
            func_80017BA8(object, matrix);
            HIDE(object);
        }
    }
    (void)arg0;
}
