/* Independently written from the specification scratchpad/specs/func_80035BF0.md. */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx80035BF0;

typedef struct {
    u32 unk00;
    s16 unk04;
    u8 mux[16];
    u8 pad16[2];
    u32 unk18;
    u32 unk1C;
    u8 unk20[6];
    u8 unk26[4];
    u8 unk2A[4];
    u8 unk2E[4];
} Obj80035BF0;

extern s16 D_800A3D44[4];
extern Gfx80035BF0 *D_80112C90;
extern s16 D_80112DE4;
extern u8 D_80112DE6[8];
extern u8 D_80112DEE[8];
extern u32 D_80112DF8;
extern u32 D_80112DFC;
extern u8 D_80112E00[6];
extern u8 D_80112E06[4];
extern u8 D_80112E0A[4];
extern u8 D_80112E0E[4];

extern s32 func_80081530(u8 *, u8 *, s32);

void func_80035BF0(Obj80035BF0 *obj, s32 force) {
    if ((force != 0) || (obj->unk04 != D_80112DE4)) {
        if (obj->unk04 == 1) {
            {
                Gfx80035BF0 *g;
                g = D_80112C90++;
                g->w1 = 0;
                g->w0 = 0xE3000A01;
            }
        } else {
            {
                Gfx80035BF0 *g;
                g = D_80112C90++;
                g->w0 = 0xE3000A01;
                g->w1 = 0x00100000;
            }
        }
    }

    if ((force != 0) || (func_80081530(&obj->mux[0], D_80112DE6, 8) == 0) ||
        (func_80081530(&obj->mux[8], D_80112DEE, 8) == 0)) {
        {
            Gfx80035BF0 *g;
            g = D_80112C90++;
            g->w0 = 0xFC000000 |
                    (((((obj->mux[0] & 0xF) << 20) | ((obj->mux[2] & 0x1F) << 15) |
                       ((obj->mux[4] & 7) << 12) | ((obj->mux[6] & 7) << 9)) |
                      (((obj->mux[8] & 0xF) << 5) | (obj->mux[10] & 0x1F))) & 0xFFFFFF);
            g->w1 = (((obj->mux[1] & 0xF) << 28) | ((obj->mux[3] & 7) << 15)) |
                    (((obj->mux[5] & 7) << 12) | ((obj->mux[7] & 7) << 9)) |
                    (((obj->mux[9] & 0xF) << 24) | ((obj->mux[12] & 7) << 21) | ((obj->mux[14] & 7) << 18) | ((obj->mux[11] & 7) << 6) | ((obj->mux[13] & 7) << 3) | (obj->mux[15] & 7));
        }
    }

    if ((force != 0) || (D_80112DF8 != obj->unk18) || (D_80112DFC != obj->unk1C)) {
        {
            Gfx80035BF0 *g;
            g = D_80112C90++;
            g->w0 = 0xE200001C;
            g->w1 = obj->unk18 | obj->unk1C;
            g = D_80112C90++;
            g->w0 = 0xE2001E01;
            g->w1 = (obj->unk18 | obj->unk1C) & 3;
        }
    }

    if (obj->unk00 & 1) {
        if ((force != 0) || (func_80081530(obj->unk20, D_80112E00, 6) == 0)) {
            {
                Gfx80035BF0 *g;
                g = D_80112C90++;
                g->w0 = 0xFA000000 | (obj->unk20[0] << 8) | obj->unk20[1];
                g->w1 = (obj->unk20[2] << 24) | (obj->unk20[3] << 16) |
                        (obj->unk20[4] << 8) | obj->unk20[5];
            }
        }
    }

    if (obj->unk00 & 2) {
        if ((force != 0) || (func_80081530(obj->unk26, D_80112E06, 4) == 0)) {
            {
                Gfx80035BF0 *g;
                g = D_80112C90++;
                g->w0 = 0xFB000000;
                g->w1 = (obj->unk26[0] << 24) | (obj->unk26[1] << 16) |
                        (obj->unk26[2] << 8) | obj->unk26[3];
            }
        }
    }

    if (!(obj->unk00 & 4)) {
        obj->unk2A[0] = D_800A3D44[0];
        obj->unk2A[1] = D_800A3D44[1];
        obj->unk2A[2] = D_800A3D44[2];
        obj->unk2A[3] = D_800A3D44[3];
    }

    if ((force != 0) || (func_80081530(obj->unk2A, D_80112E0A, 4) == 0)) {
        {
            Gfx80035BF0 *g;
            g = D_80112C90++;
            g->w0 = 0xF8000000;
            g->w1 = (obj->unk2A[0] << 24) | (obj->unk2A[1] << 16) |
                    (obj->unk2A[2] << 8) | obj->unk2A[3];
        }
    }

    if (obj->unk00 & 8) {
        if ((force != 0) || (func_80081530(obj->unk2E, D_80112E0E, 4) == 0)) {
            {
                Gfx80035BF0 *g;
                g = D_80112C90++;
                g->w0 = 0xF9000000;
                g->w1 = (obj->unk2E[0] << 24) | (obj->unk2E[1] << 16) |
                        (obj->unk2E[2] << 8) | obj->unk2E[3];
            }
        }
    }
}
