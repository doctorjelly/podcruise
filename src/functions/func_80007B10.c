/* Implements specification $S/specs/func_80007B18.md (entry corrected to 0x80007B10). */
#include "podcruise/types.h"

typedef struct Record80007B10 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
} Record80007B10;

typedef struct Descriptor80007B10 {
    /* 0x00 */ s32 count0;
    /* 0x04 */ s32 count1;
    /* 0x08 */ void *data;
} Descriptor80007B10;

typedef struct Archive80007B10 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
} Archive80007B10;

extern u8 D_AF4B0[];
extern u8 D_B8960[];
extern void *D_8009A2BC;
extern s32 D_800A81B8;
extern Descriptor80007B10 D_800AFA48;
extern s32 D_800AFA54;
extern Archive80007B10 *D_800AFA58;
extern u8 D_800D1D28[];
extern Record80007B10 D_800D1F38[8];
extern Record80007B10 D_800D2038[8];

extern s32 func_80006FE4(s32, s32, s32, s32);
extern void func_80006F60(s32, s32, s32);
extern void func_80089144(void *, Descriptor80007B10 *);
extern void func_80089384(void *, s32);

void func_80007B10(void) {
    s32 i;
    s32 size;
    u8 unused[0x14];

    (void)unused;
    size = D_B8960 - D_AF4B0;
    D_800AFA58 = (Archive80007B10 *)(unsigned long)func_80006FE4((s32)(unsigned long)&D_800A81B8,
                                                  (s32)(unsigned long)D_800D1D28, 1, size);
    func_80006F60((s32)(unsigned long)D_AF4B0, (s32)(unsigned long)D_800AFA58, size);
    D_800AFA48.count0 = 8;
    D_800AFA48.count1 = 0x40;
    D_800AFA48.data = D_800D1D28;
    func_80089144(D_8009A2BC, &D_800AFA48);
    func_80089384(D_800AFA58, (s32)(unsigned long)D_B8960);
    D_800AFA54 = D_800AFA58->unk04;
    for (i = 0; i < 8; i++) {
        D_800D1F38[i].unk00 = -1;
        D_800D1F38[i].unk04 = -1;
        D_800D1F38[i].unk08 = 0;
        D_800D1F38[i].unk0C = -1;
        D_800D1F38[i].unk10 = 0;
        D_800D1F38[i].unk14 = 1.0f;
        D_800D1F38[i].unk1C = 0x40;
        D_800D2038[i].unk00 = -1;
        D_800D2038[i].unk04 = -1;
        D_800D2038[i].unk08 = 0;
        D_800D2038[i].unk0C = -1;
        D_800D2038[i].unk10 = 0;
        D_800D2038[i].unk14 = 1.0f;
        D_800D2038[i].unk1C = 0x40;
    }
}
