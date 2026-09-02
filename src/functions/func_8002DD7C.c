/* Recovered from specs/functions/recovered/medium_service_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x14];
    u32 unk14;
    u8 pad18[0x45];
    s8 unk5D;
} Obj8002DD7C;

extern s32 D_800A5998;
extern s32 D_800A4B94;
extern u8 D_800A9ACC[];
extern u8 D_800A21B4[];
extern s32 D_800A22E8[][7];
extern s8 D_80119668[];
extern u8 D_80113E60[];
extern u8 D_80113680[];

extern s32 func_8002D968(u8 *, u8 *);
extern s32 func_80082BE0(void);

void func_8002DD7C(Obj8002DD7C *arg0) {
    s8 *scan;
    u8 total;
    s32 useA;
    s32 index;
    s32 bit;
    s32 i;
    s32 mask;
    s32 found;

    D_800A5998 = 1;
    *(u32 *)(D_80113680 + 8) |= 0x40;
    arg0->unk14 |= 8;
    total = 0;
    useA = 0;

    if (func_8002D968(D_80113E60, D_800A9ACC) != 0) {
        if ((D_800A4B94 & 4) != 0) {
            D_80119668[0] = arg0->unk5D;
            total = 1;
            useA = 1;
        }
    }

    while (total < 5) {
        index = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 5.0f);
        bit = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * (f32)(s32)D_800A21B4[index]);
        mask = D_80113E60[index + 8];
        if (useA != 0) {
            mask = D_80113680[index + 12];
        }
        found = 0;
        if ((mask & (1 << bit)) != 0) {
            i = 0;
            if (total > 0) {
                scan = D_80119668;
                do {
                    i++;
                    if (D_800A22E8[index][bit] == *scan++) {
                        found = 1;
                        break;
                    }
                } while (i != total);
            }
            if (found == 0) {
                D_80119668[total] = D_800A22E8[index][bit];
                total++;
            }
        }
    }
}
