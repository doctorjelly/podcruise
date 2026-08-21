/* Independently written from specs/functions/func_800600A0.md. */

#include "podcruise/types.h"

typedef struct Info600A0 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 *unk14;
} Info600A0;

typedef struct Slot600A0 {
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x18 - 0x0C];
    /* 0x18 */ Info600A0 *unk18;
    /* 0x1C */ u8 pad1C[0x88 - 0x1C];
} Slot600A0;

typedef struct Root600A0 {
    /* 0x000 */ u8 pad000[8];
    /* 0x008 */ s32 unk08;
    /* 0x00C */ u8 pad00C[0x1BC - 0x0C];
    /* 0x1BC */ s32 unk1BC;
} Root600A0;

typedef struct Pair600A0 {
    /* 0x00 */ void *unk00;
    /* 0x04 */ s32 unk04;
} Pair600A0;

extern s32 func_8002FAFC(void);
extern void func_80030298(s32 tag, s32 count);
extern void *func_800305E8(s32 index);
extern void func_80030A7C(void *displayList, void *patchList);
extern void func_8003FC94(s32 tag);
extern void func_8005F4D8(void *root, void *slot, s32 arg2, void *owner,
                          void *arg4, void *arg5, s32 arg6, s32 arg7);
extern s32 func_80082BE0(void);

extern s32 D_800A52BC;
extern s32 D_800A52C0;
extern s32 D_800A52D8;
extern void *D_8011B1B8;
extern s32 D_8011B1E8;
extern s32 D_8011B1F0[16];
extern u8 D_8011B230[12][4];

void func_800600A0(Root600A0 *root, Slot600A0 *slots) {
    s32 i;
    s32 j;
    s32 k;
    s32 order[12];
    s32 slotIndex[12];
    s32 mode;
    void *owners[12];
    void *records[12];
    s32 label;
    void *values[12];
    s32 extras[12];
    s32 index;
    Pair600A0 *pair;
    s32 duplicate;

    D_8011B1E8 = func_8002FAFC();
    func_80030298(0x54657374, root->unk1BC);
    func_8003FC94(0x54657374);
    D_8011B1E8 = func_8002FAFC() - D_8011B1E8;

    for (k = 0; k < 12; k++) {
        D_8011B1F0[k] = 0;
        D_8011B230[k][0] = 0;
    }

    duplicate = 0;
    for (i = 0; i < root->unk1BC; i++) {
        for (j = 0; j < root->unk1BC; j++) {
            if (i != j) {
                if (slots[i].unk18->unk00 == slots[j].unk18->unk00) {
                    duplicate = 1;
                }
            }
        }
    }
    D_800A52C0 = duplicate;

    for (i = 0; i < root->unk1BC; i++) {
        mode = 3;
        D_8011B1F0[i] = func_8002FAFC();
        D_8011B230[i][0] = slots[i].unk18->unk14[2];
        D_8011B230[i][1] = slots[i].unk18->unk14[3];
        D_8011B230[i][2] = slots[i].unk18->unk14[4];
        D_8011B230[i][3] = 0;

        if (slots[i].unk04 == 0x4C6F636C) {
            if (D_800A52BC < 2) {
                mode = 1;
            } else {
                mode = 2;
            }
        }
        if (root->unk08 & 0x20) {
            mode = 1;
        } else if (D_800A52BC == 0) {
            mode = 3;
        }

        if (mode == 2 || mode == 1) {
            values[i] = 0;
            extras[i] = 0;
            owners[i] = func_800305E8(slots[i].unk18->unk04);
            if (owners[i] == 0) {
                root->unk1BC = i;
                D_800A52D8 = i;
            } else if (mode == 1) {
                if (slots[i].unk18->unk08 >= 0) {
                    records[i] = func_800305E8(slots[i].unk18->unk08);
                    if (records[i] == 0) {
                        root->unk1BC = i;
                        D_800A52D8 = i;
                    } else {
                        func_80030A7C(owners[i], records[i]);
                    }
                }
            }
        } else if (mode == 3) {
            owners[i] = 0;
            values[i] = 0;
            extras[i] = 0;
            pair = func_800305E8(slots[i].unk18->unk0C);
            if (pair != 0) {
                values[i] = pair->unk00;
                extras[i] = pair->unk04;
            }
        } else if (mode == 4) {
            owners[i] = 0;
            values[i] = 0;
            extras[i] = 0;
            pair = func_800305E8(slots[i].unk18->unk10);
            if (pair != 0) {
                values[i] = pair->unk00;
                extras[i] = 0;
            }
        }

        D_8011B1F0[i] = func_8002FAFC() - D_8011B1F0[i];
    }

    D_8011B1B8 = slots;

    for (j = 0; j < root->unk1BC; j++) {
        order[j] = -1;
    }

    for (j = 0; j < root->unk1BC; j++) {
        index = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) *
                     (f32)(root->unk1BC - j));
        i = -1;
        while (index >= 0) {
            i++;
            if (order[i] == -1) {
                index--;
            }
        }
        order[i] = j;
    }

    label = 1;
    for (j = 0; j < root->unk1BC; j++) {
        if ((slots[j].unk08 & 0x20) != 0 || slots[j].unk04 == 0x4C6F636C) {
            slotIndex[j] = -1;
        } else {
            slotIndex[j] = label;
            label++;
        }
    }

    for (j = 0; j < root->unk1BC; j++) {
        func_8005F4D8(root, &slots[order[j]], slotIndex[order[j]], owners[order[j]],
                      records[order[j]], values[order[j]], extras[order[j]], duplicate);
    }
}
