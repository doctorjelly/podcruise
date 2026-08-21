/* Independently written from scratchpad spec specs/func_80010EA0.md. */

#include "podcruise/types.h"

typedef struct Unk80010EA0 {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 pad16[0x1C - 0x16];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ u8 pad1E[0x70 - 0x1E];
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;
    /* 0x78 */ f32 unk78;
    /* 0x7C */ u8 pad7C[0x4];
    /* 0x80 */ f32 unk80;
    /* 0x84 */ f32 unk84;
    /* 0x88 */ f32 unk88;
    /* 0x8C */ u8 pad8C[0x4];
    /* 0x90 */ f32 unk90;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ f32 unk98;
} Unk80010EA0;

typedef struct Unk800D6140 {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
} Unk800D6140;

extern u8 D_8009B870;
extern u8 D_8009B874[];
extern f32 D_8009B878;
extern f32 D_8009B87C;
extern f32 D_8009B880;
extern s32 D_8009B884;
extern f32 D_800A3FDC[];
extern f32 D_800A86B4;
extern f32 D_800A86B8;
extern f32 D_800A86BC;
extern f32 D_800A86C0;
extern f32 D_800A86C4;
extern f32 D_800A86C8;
extern f32 D_800A86CC;
extern f32 D_800A86D0;
extern f32 D_800A86D4;
extern f32 D_800A86D8;
extern Unk800D6140 D_800D6140[];
extern f32 D_800D6280[];
extern f32 D_800D6640[];
extern u8 D_800D68C0[];
extern s16 D_80114470[];
extern u16 *D_80114528;
extern f64 D_80120BF0;

extern void func_8000A920(s16, s32);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, s32, s32, s32, s32);
extern void func_8000AC34(s16, s32);
extern void func_8000AC60(s16, s32);
extern void func_8000E680(s16, s16, s16);
extern void func_8000E738(s16, s16, s16);
extern void func_8000EBE8(s16 *, f32 *, f32 *, f32 *, f32 *, f32 *, s32);
extern s32 func_8001004C(s32);
extern s32 func_8002F054(void);
extern s32 func_80082BE0(void);

void func_80010EA0(Unk80010EA0 *arg0) {
    s32 by;
    s32 alpha;
    s32 index;
    f32 padA[5];
    f32 spD4;
    f32 spD0;
    f32 padB[4];
    f32 spBC;
    f32 spB8;
    Unk800D6140 *entry;
    f32 *point;
    f32 *last;
    f32 scale;
    s32 value;
    s32 word;
    s32 limit;
    s32 i;

    (void)padA;
    (void)padB;

    if (D_8009B870 != 0) {
    entry = D_800D6140;
    for (i = 0; i < D_8009B884; i++, entry++) {
        word = *(s32 *)entry;
        if (word == -1) {
            continue;
        }
        value = D_800D68C0[i];
        if (value == 0) {
            func_8000A920((s16)word, 0);
            point = &D_800D6280[i * 3];
            last = &D_800D6640[i * 2];
            if (D_800A86B4 < (f32)func_80082BE0() / (f32)2147483648.0) {
                D_800D68C0[i] = 1;
                point[0] = D_800A3FDC[0];
                point[1] = D_800A3FDC[1];
                point[2] = D_800A3FDC[2];
                point[0] = arg0->unk70 *
                               (-400.0f + 800.0f * ((f32)func_80082BE0() / (f32)2147483648.0)) +
                           point[0];
                point[1] = arg0->unk74 *
                               (-400.0f + 800.0f * ((f32)func_80082BE0() / (f32)2147483648.0)) +
                           point[1];
                point[2] = arg0->unk78 *
                               (-400.0f + 800.0f * ((f32)func_80082BE0() / (f32)2147483648.0)) +
                           point[2];
                scale = ((f32)func_80082BE0() / (f32)2147483648.0) * 340.0f + 10.0f;
                point[0] = arg0->unk80 * scale + point[0];
                point[1] = arg0->unk84 * scale + point[1];
                point[2] = arg0->unk88 * scale + point[2];
                point[0] = arg0->unk90 *
                               (10.0f + 190.0f * ((f32)func_80082BE0() / (f32)2147483648.0)) +
                           point[0];
                point[1] = arg0->unk94 *
                               (10.0f + 190.0f * ((f32)func_80082BE0() / (f32)2147483648.0)) +
                           point[1];
                point[2] = arg0->unk98 *
                               (10.0f + 190.0f * ((f32)func_80082BE0() / (f32)2147483648.0)) +
                           point[2];
                last[0] = -1.0f;
                last[1] = -1.0f;
            }
            value = D_800D68C0[i];
        } else {
            scale = (f32)D_80120BF0;
            point = &D_800D6280[i * 3];
            point[2] = point[2] - D_8009B87C * scale;
            point[0] = point[0] - D_8009B878 * scale;
        }

        if (value == 0) {
            continue;
        }

        point = &D_800D6280[i * 3];
        last = &D_800D6640[i * 2];
        if (value == 2) {
            D_800D68C0[i] = 0;
        }
        func_8000EBE8((s16 *)arg0, point, &spD4, &spD0, &spBC, &spB8, 0);

        if (0.0f < spD4 && 0.0f < spD0 && spD4 < (f32)D_80114470[0] &&
            spD0 < (f32)D_80114470[1]) {
            index = D_80114470[0] * (s32)spD0 + (s32)spD4;
            limit = (s32)(((f32)arg0->unk1C + spBC * (f32)arg0->unk14) * 256.0f);
            value = func_8001004C(D_80114528[index]);
            if (limit > 0 && value < limit) {
                D_800D68C0[i] = 2;
            }
        }

        if (spD4 < (f32)-D_80114470[0]) {
            D_800D68C0[i] = 0;
        } else if ((f32)(D_80114470[0] * 2) < spD4) {
            D_800D68C0[i] = 0;
        } else if ((f32)(D_80114470[1] * 2) < spD0) {
            D_800D68C0[i] = 0;
        }

        if (spB8 <= D_800A86B8) {
            scale = 100.0f;
        } else {
            scale = 100.0f / spB8;
        }
        if (scale < D_800A86BC) {
            scale = D_800A86BC;
        }
        scale = scale * D_800A86C0;
        if (100.0f < D_8009B87C) {
            if (D_800A86C4 < scale) {
                scale = D_800A86C8;
            }
        } else if (300.0f < D_8009B87C) {
            if (D_800A86CC < scale) {
                scale = D_800A86D0;
            }
        } else {
            if (D_800A86D4 < scale) {
                scale = D_800A86D8;
            }
        }
        alpha = D_8009B874[3];

        func_8000A920(entry->unk2, 1);
        func_8000E680(entry->unk2, (s16)(s32)spD4, (s16)(s32)spD0);

        if (last[0] < 0.0f) {
            func_8000A920(entry->unk2, 0);
        } else {
            word = (s32)(last[0] * D_8009B880 + (1.0f - D_8009B880) * spD4);
            by = (s32)(last[1] * D_8009B880 + (1.0f - D_8009B880) * spD0);
            if ((f32)word < spD4) {
                value = (s32)-((f32)word - spD4);
            } else {
                value = (s32)((f32)word - spD4);
            }
            if ((f32)by < spD0) {
                limit = (s32)-((f32)by - spD0);
            } else {
                limit = (s32)((f32)by - spD0);
            }
            if (value < 3 && limit < 3) {
                func_8000AC60(entry->unk2, 0x4000);
            } else {
                func_8000E738(entry->unk2, (s16)word, (s16)by);
                func_8000AC34(entry->unk2, 0x4000);
            }
        }
        func_8000AAC0(entry->unk2, scale, scale);
        if (func_8002F054() != 0) {
            alpha = (s16)(s32)((f32)alpha * 0.5f);
        }
        func_8000AB24(entry->unk2, D_8009B874[0], D_8009B874[1], D_8009B874[2], alpha);
        last[0] = spD4;
        last[1] = spD0;
    }
    }
}
