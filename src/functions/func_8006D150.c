/* Independently written from scratchpad spec specs/func_8006D150.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8   unk00[0x30];
    Vec3 unk30;
    u8   unk3C[0x4];
} Motion;

typedef struct {
    /* 0x0000 */ u8   pad0000[0x30];
    /* 0x0030 */ Vec3 unk0030;
    /* 0x003C */ u8   pad003C[0x14];
    /* 0x0050 */ Vec3 unk0050;
    /* 0x005C */ u8   pad005C[0x4];
    /* 0x0060 */ u32  unk0060;
    /* 0x0064 */ u32  unk0064;
    /* 0x0068 */ u8   pad0068[0xC];
    /* 0x0074 */ f32  unk0074;
    /* 0x0078 */ u8   pad0078[0x34];
    /* 0x00AC */ u8   unk00AC[0x28];
    /* 0x00D4 */ s32  unk00D4;
    /* 0x00D8 */ u8   pad00D8[0x8];
    /* 0x00E0 */ f32  unk00E0;
    /* 0x00E4 */ u8   pad00E4[0x4];
    /* 0x00E8 */ f32  unk00E8;
    /* 0x00EC */ u8   pad00EC[0x18];
    /* 0x0104 */ f32  unk0104;
    /* 0x0108 */ f32  unk0108;
    /* 0x010C */ u8   pad010C[0x80];
    /* 0x018C */ f32  unk018C;
    /* 0x0190 */ u8   pad0190[0x4];
    /* 0x0194 */ Vec3 unk0194;
    /* 0x01A0 */ u8   pad01A0[0x50];
    /* 0x01F0 */ f32  unk01F0;
    /* 0x01F4 */ u8   pad01F4[0x38];
    /* 0x022C */ f32  unk022C;
    /* 0x0230 */ u8   pad0230[0x1768];
    /* 0x1998 */ s32  unk1998;
} Racer;

extern s32 D_800A5B6C;
extern f32 D_800AD634;
extern f32 D_800AD638;
extern f32 D_800AD63C;
extern f32 D_800AD640;
extern f32 D_800AD644;
extern f32 D_800AD648;
extern f32 D_800AD64C;
extern f32 D_800AD650;
extern f32 D_800AD654;
extern f32 D_800AD658;
extern f32 D_800AD65C;
extern f32 D_800AD660;
extern f32 D_800AD664;
extern f32 D_800AD668;
extern f32 D_800AD66C;
extern f32 D_800AD670;
extern f32 D_800AD674;
extern f32 D_800AD678;
extern f32 D_800AD67C;
extern f32 D_800AD680;
extern f32 D_800AD684;
extern f32 D_800AD688;
extern f32 D_800AD68C;
extern f32 D_800AD690;
extern f32 D_800AD694;
extern f32 D_800AD698;
extern f32 D_800AD69C;
extern f32 D_800AD6A0;

extern s32 func_80082BE0(void);
extern void func_8003B184(void *source, Motion *motion, f32 offset);
extern void func_8006D0C0(Racer *racer, Vec3 *target, Vec3 *previous,
                          s32 allow);
extern void func_800155EC(Vec3 *output, const Vec3 *base, f32 scale,
                          const Vec3 *offset);
extern f32 func_800153C0(const Vec3 *vector);
extern void func_80015538(Vec3 *output, const Vec3 *left, const Vec3 *right);

void func_8006D150(Racer *racer) {
    Motion motion;
    Vec3 axis;
    Vec3 point;
    Vec3 offset;
    Vec3 previous;
    Vec3 delta[1]; /* one-element array: the original keeps these stores live */
    f32 length;
    f32 dot;
    f32 turn;
    s32 mode;

    if (racer->unk0060 & 0x10) {
        racer->unk018C = D_800AD634;
    } else {
        racer->unk018C = D_800AD638;
    }

    if (racer->unk0104 < D_800AD63C) {
        racer->unk0104 = D_800AD63C;
    }
    if ((f32)2.0 < racer->unk0104) {
        racer->unk0104 = (f32)2.0;
    }

    if ((f32)func_80082BE0() / (f32)2147483648.0 * (f32)2.0 < 0.0f) {
        racer->unk00D4 = (s32)((f32)func_80082BE0() / (f32)2147483648.0 *
                                   (f32)2.0 -
                               D_800AD640);
    } else {
        racer->unk00D4 =
            (s32)((f32)func_80082BE0() / (f32)2147483648.0 * (f32)2.0);
    }

    mode = D_800A5B6C;
    if (mode > 0) {
        if (1 == mode) {
            if (racer->unk00E8 < D_800AD644 ||
                (D_800AD648 < racer->unk00E0 &&
                 racer->unk00E0 < D_800AD64C)) {
                racer->unk00D4 = 0;
            }
        } else if (mode == 2) {
            if ((D_800AD650 < racer->unk00E0 &&
                 racer->unk00E0 < D_800AD654) ||
                (D_800AD658 < racer->unk00E0 &&
                 racer->unk00E0 < D_800AD65C)) {
                racer->unk00D4 = 0;
            }
        } else if (mode == 3) {
            if (D_800AD660 < racer->unk00E0 && racer->unk00E0 < D_800AD664) {
                racer->unk00D4 = 0;
            }
        } else if (mode == 4) {
            if (D_800AD668 < racer->unk00E0 && racer->unk00E0 < D_800AD66C) {
                racer->unk00D4 = 0;
            }
        } else if (mode == 5) {
            if (D_800AD670 < racer->unk00E0 && racer->unk00E0 < D_800AD674) {
                racer->unk00D4 = 1;
            }
        } else if (mode == 6) {
            if (D_800AD678 < racer->unk00E0 && racer->unk00E0 < D_800AD67C) {
                racer->unk00D4 = 1;
            }
        }
    }

    func_8003B184(racer->unk00AC, &motion, 0.0f);
    point.x = motion.unk30.x;
    point.y = motion.unk30.y;
    point.z = motion.unk30.z;
    func_8003B184(racer->unk00AC, &motion, racer->unk0104);

    func_8006D0C0(racer, &motion.unk30, &point,
                  ((f32)racer->unk1998 - 400.0f) / 600.0f < 1.0 ||
                      (racer->unk0060 & 0x20) != 0 ||
                      (racer->unk0064 & 0x4000000) != 0);

    if ((point.z - motion.unk30.z) * (point.z - motion.unk30.z) +
               ((point.x - motion.unk30.x) * (point.x - motion.unk30.x) +
                (point.y - motion.unk30.y) * (point.y - motion.unk30.y)) < racer->unk0108) {
        racer->unk0104 = racer->unk0104 + D_800AD680;
    } else if (racer->unk0108 < (point.z - motion.unk30.z) * (point.z - motion.unk30.z) +
               ((point.x - motion.unk30.x) * (point.x - motion.unk30.x) +
                (point.y - motion.unk30.y) * (point.y - motion.unk30.y))) {
        racer->unk0104 = racer->unk0104 - D_800AD684;
    }

    point.x = motion.unk30.x;
    point.y = motion.unk30.y;
    point.z = motion.unk30.z;
    delta[0].x = racer->unk0050.x - motion.unk30.x;
    delta[0].y = racer->unk0050.y - motion.unk30.y;
    delta[0].z = racer->unk0050.z - motion.unk30.z;
    func_800155EC(&previous, &point,
                  racer->unk0194.z * delta[0].z +
                      (delta[0].x * racer->unk0194.x + delta[0].y * racer->unk0194.y),
                  &racer->unk0194);

    offset.x = previous.x - racer->unk0050.x;
    offset.y = previous.y - racer->unk0050.y;
    offset.z = previous.z - racer->unk0050.z;
    length = func_800153C0(&offset);
    if (D_800AD688 < length) {
        length = 1.0f / length;
        offset.x = offset.x * length;
        offset.y = offset.y * length;
        offset.z = offset.z * length;
        func_80015538(&axis, &racer->unk0030, &offset);

        dot = racer->unk0194.z * axis.z +
              (axis.x * racer->unk0194.x + axis.y * racer->unk0194.y);
        turn = 0.0f;
        if (D_800AD68C < dot) {
            turn = -dot / D_800AD690;
            if (D_800AD694 < dot) {
                racer->unk018C = racer->unk018C * ((1.0f - dot) * 0.5f);
            }
        } else if (dot < D_800AD698) {
            turn = -dot / D_800AD69C;
            if (dot < D_800AD6A0) {
                racer->unk018C = racer->unk018C * ((1.0f + dot) * 0.5f);
            }
        }
        racer->unk01F0 = racer->unk0074 * turn * racer->unk022C;
    }
}
