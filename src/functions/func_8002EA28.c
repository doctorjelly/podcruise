/* Recovered from specification: specs/func_8002EA28.md (worker batch_01) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 unk4[16];
    /* 0x14 */ s32 unk14;
} Entry8002EA28; /* 0x18 */

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s8 unk2;
    /* 0x03 */ s8 unk3;
    /* 0x04 */ s16 unk4;
} Source8002EA28; /* 0x06 */

extern u32 D_800D697C;
extern s32 D_800D7490;
extern s32 D_800A26D8;
extern s32 D_800D7498[4];
extern u16 D_800D74A8;
extern Source8002EA28 D_800D74C0[4];
extern Entry8002EA28 D_800D74D8[4];

Entry8002EA28 *func_8002EA28(void) {
    s32 i;
    s32 j;
    s32 mask;
    f32 temp;

    if (D_800D697C & 0x1000) {
        D_800D74D8[0].unk14 = 0;
        D_800D74D8[0].unk0 = 0;
        D_800D74D8[0].unk2 = 0;
        for (j = 0; j < 16; j++) {
            D_800D74D8[0].unk4[j] = 0;
        }
    }
    if (D_800D7490 != -1 && D_800A26D8 == 0) {
        for (i = 0; i < 4; i++) {
            if (D_800D7498[i] != 0) {
                D_800D74A8 = D_800D74C0[i].unk0;
                mask = D_800D74C0[i].unk0;
                temp = (f32)D_800D74C0[i].unk2;
                D_800D74D8[i].unk0 = (s16)(temp >= -100.0f ? (temp <= 100.0f ? temp : 100.0f) : -100.0f);
                temp = (f32)D_800D74C0[i].unk3;
                D_800D74D8[i].unk2 = (s16)(temp >= -100.0f ? (temp <= 100.0f ? temp : 100.0f) : -100.0f);
                D_800D74D8[i].unk14 = D_800D74C0[i].unk0;
                for (j = 0; j < 16; j++) {
                    D_800D74D8[i].unk4[j] = (mask & (1 << j)) != 0;
                }
            } else {
                D_800D74D8[i].unk0 = 0;
                D_800D74D8[i].unk2 = 0;
                for (j = 0; j < 16; j++) {
                    D_800D74D8[i].unk4[j] = 0;
                }
            }
        }
    }
    D_800A26D8 = 0;
    return D_800D74D8;
}
