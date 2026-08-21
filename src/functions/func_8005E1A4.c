/* Independently written from scratchpad spec specs/func_8005E1A4.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
} PcClip8005E1A4;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ u8 unk10[0x10];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} PcMover8005E1A4; /* 0x30 */

typedef struct PcStage8005E1A4 {
    /* 0x000 */ u8 unk000[0x108];
    /* 0x108 */ f32 unk108;
    /* 0x10C */ u8 unk10C[0x18];
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8 unk128[0x8];
    /* 0x130 */ s32 unk130;
    /* 0x134 */ PcMover8005E1A4 unk134;
    /* 0x164 */ u8 unk164[0x40];
    /* 0x1A4 */ s32 unk1A4;
    /* 0x1A8 */ struct PcStage8005E1A4 *unk1A8;
    /* 0x1AC */ s32 unk1AC;
    /* 0x1B0 */ u8 unk1B0[0x8];
    /* 0x1B8 */ s32 unk1B8;
    /* 0x1BC */ u8 unk1BC[0x4];
    /* 0x1C0 */ s32 unk1C0;
} PcStage8005E1A4;

typedef struct {
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} PcChoice8005E1A4;

typedef struct {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ s16 unk20;
} PcFlags8005E1A4;

extern f32 D_800A52C8;
extern f32 D_800A52CC;
extern f32 D_800AD058;
extern f32 D_800AD05C;
extern f32 D_800AD060;
extern f32 D_800AD064;
extern f32 D_800AD068;
extern f32 D_800AD06C;
extern f32 D_800AD070;
extern f32 D_800AD074;
extern f32 D_800AD078;
extern f32 D_800AD07C;
extern f32 D_800AD080;
extern f32 D_800AD084;
extern f32 D_800AD088;
extern f32 D_800AD08C;
extern PcFlags8005E1A4 D_800D6960;
extern void *D_8011AC80;
extern s32 D_8011B1E4;

extern void func_80006E60(void *object, u32 kind);
extern void func_8000AEFC(s16 index, s16 second, u32 third, s16 fourth);
extern void func_8000B02C(s16 arg0, s32 arg1, s16 arg2);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern s32 func_8002FAFC(void);
extern s32 func_80030274(s32 argument);
extern void func_80038DBC(s32 arg0);
extern void func_80038DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_8003B184(void *source, void *context, f32 offset);
extern void func_8003B250(void *holder, s32 index);
extern void func_80086CC8(s32 first, s32 second, s32 third);

void func_8005E1A4(PcStage8005E1A4 *stage, PcStage8005E1A4 **list, PcChoice8005E1A4 *choice) {
    PcStage8005E1A4 **cursor;
    PcStage8005E1A4 *entry;
    PcStage8005E1A4 *found;
    s32 target;
    s32 ended;
    s32 started;
    s32 sound;
    s32 red;
    s32 green;
    s32 blue;
    PcMover8005E1A4 *mover;
    void *context;

    stage->unk1B8 = -1;
    if (stage->unk1AC == 0) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x19;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x2D;
        }
    }
    if (stage->unk1AC == 1) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x11;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x1E;
        }
        if (stage->unk1C0 == 2) {
            stage->unk1B8 = 0x1F;
        }
        if (stage->unk1C0 == 3) {
            stage->unk1B8 = 0x2E;
        }
    }
    if (stage->unk1AC == 2) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x22;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x52;
        }
        if (stage->unk1C0 == 2) {
            stage->unk1B8 = 0x30;
        }
    }
    if (stage->unk1AC == 3) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x24;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x26;
        }
        if (stage->unk1C0 == 2) {
            stage->unk1B8 = 0x28;
        }
    }
    if (stage->unk1AC == 4) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x53;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x58;
        }
        if (stage->unk1C0 == 2) {
            stage->unk1B8 = 0x59;
        }
        if (stage->unk1C0 == 3) {
            stage->unk1B8 = 0x2F;
        }
    }
    if (stage->unk1AC == 5) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x38;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x39;
        }
        if (stage->unk1C0 == 2) {
            stage->unk1B8 = 0x54;
        }
    }
    if (stage->unk1AC == 6) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x29;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x2A;
        }
        if (stage->unk1C0 == 2) {
            stage->unk1B8 = 0x2B;
        }
    }
    if (stage->unk1AC == 7) {
        if (stage->unk1C0 == 0) {
            stage->unk1B8 = 0x23;
        }
        if (stage->unk1C0 == 1) {
            stage->unk1B8 = 0x3B;
        }
        if (stage->unk1C0 == 2) {
            stage->unk1B8 = 0x3E;
        }
    }

    stage->unk130 = 0;
    if (stage->unk1B8 < 0) {
        return;
    }

    started = func_8002FAFC();
    stage->unk1A4 = func_80030274(stage->unk1B8);
    ended = func_8002FAFC();
    D_8011B1E4 = D_8011B1E4 + ended - started;

    if (stage->unk1C0 == 0) {
        target = choice->unk0C;
    }
    if (stage->unk1C0 == 1) {
        target = choice->unk10;
    }
    if (stage->unk1C0 == 2) {
        target = choice->unk14;
    }
    if (stage->unk1C0 == 3) {
        target = choice->unk0C;
    }

    if (stage->unk1A4 == 0) {
        return;
    }
    if (target == 0) {
        return;
    }

    stage->unk130 = 1;
    stage->unk134.unk00 = stage->unk1A4;
    stage->unk134.unk20 = 0;
    stage->unk134.unk24 = 0;
    stage->unk134.unk28 = 0;
    stage->unk134.unk2C = 0;
    stage->unk134.unk04 = 0.0f;
    stage->unk134.unk08 = 0.0f;
    stage->unk134.unk0C = 0.0f;
    if (stage->unk134.unk00 != 0) {
        func_8003B250(&stage->unk134, 0);
    }
    mover = &stage->unk134;
    context = &stage->unk164;
    func_8003B184(mover, context, 0.0f);

    found = 0;
    if (list != 0) {
        cursor = list;
        while (*cursor != 0) {
            entry = *cursor;
            if (target == entry->unk124) {
                func_80006E60(entry, 0x30);
                found = entry;
            }
            cursor++;
        }
    }

    if (found == 0) {
        mover->unk04 = 1.0f;
        func_8000AEFC(5, 2, (u32)(unsigned long)context, 0);
        func_8000B02C(5, target, 2);
    } else {
        mover->unk04 =
            ((f32)((PcClip8005E1A4 *)(unsigned long)stage->unk1A4)->unk04 - 1.0f) / found->unk108;
        func_8000AEFC(5, 2, (u32)(unsigned long)context, 0);
        func_8000B02C(5, target, 2);
    }

    stage->unk1A8 = found;
    D_800A52C8 = 100.0f;
    D_800A52CC = D_800AD058;

    sound = 0;
    if (stage->unk1AC == 0) {
        red = 0xDC;
        green = 0xEA;
        blue = 0xE5;
        D_800A52CC = D_800AD05C;
        sound = 0x3E4;
    }
    if (stage->unk1AC == 1) {
        sound = 0x3E4;
        if (stage->unk1C0 == 3) {
            red = 0xAD;
            green = 0xB9;
            blue = 0xC6;
            D_800A52CC = D_800AD060;
        } else {
            red = 0xD2;
            green = 0xD7;
            blue = 0xE1;
            D_800A52CC = D_800AD064;
        }
    }
    if (stage->unk1AC == 2) {
        if (stage->unk1C0 == 0) {
            D_800A52CC = D_800AD068;
        } else if (stage->unk1C0 == 1) {
            red = 0x78;
            green = 0x64;
            blue = 0x78;
            D_800A52CC = D_800AD06C;
            sound = 0x3E4;
        } else if (stage->unk1C0 == 2) {
            D_800A52CC = D_800AD070;
        }
    }
    if (stage->unk1AC == 3) {
        red = 0x9A;
        green = 0x81;
        blue = 0x81;
        D_800A52CC = D_800AD074;
        sound = 0x3E2;
    }
    if (stage->unk1AC == 4) {
        if (stage->unk1C0 == 3) {
            D_800A52CC = D_800AD058;
        } else if (stage->unk1C0 == 0) {
            red = 0xCA;
            green = 0xB7;
            blue = 0xC3;
            D_800A52CC = D_800AD058;
            sound = 0x3E4;
        } else if (stage->unk1C0 == 1) {
            red = 0x9B;
            green = 0x9A;
            blue = 0xA7;
            D_800A52CC = 1200.0f;
            sound = 0x3E0;
            if (D_8011AC80 != 0) {
                func_800181BC(D_8011AC80, 2, 0xFFFFFFFC, 0x10, 3);
            }
        } else if (stage->unk1C0 == 2) {
            red = 0x5A;
            green = 0x36;
            blue = 0x28;
            D_800A52CC = D_800AD078;
            sound = 0x3DE;
            if (D_8011AC80 != 0) {
                func_800181BC(D_8011AC80, 2, 0xFFFFFFFC, 0x10, 3);
            }
        }
    }
    if (stage->unk1AC == 5) {
        red = 0xBE;
        green = 0x37;
        blue = 0xA;
        if (stage->unk1C0 == 0) {
            D_800A52CC = 8000.0f;
            sound = 0x3DE;
        } else if (stage->unk1C0 == 1) {
            D_800A52CC = D_800AD07C;
            sound = 0x3E4;
        } else if (stage->unk1C0 == 2) {
            D_800A52CC = 4000.0f;
            sound = 0x3E4;
        }
    }
    if (stage->unk1AC == 6) {
        D_800A52CC = D_800AD080;
    }
    if (stage->unk1AC == 7) {
        if (stage->unk1C0 == 0) {
            D_800A52CC = D_800AD084;
        } else if (stage->unk1C0 == 1) {
            D_800A52CC = D_800AD088;
        } else if (stage->unk1C0 == 2) {
            D_800A52CC = D_800AD08C;
        }
    }

    if (sound != 0) {
        func_80038DBC(1);
        func_80038DF8(sound, 0x3E8, red, green, blue, 0xFF);
        func_80086CC8(red, green, blue);
    } else {
        func_80038DBC(0);
    }
    D_800D6960.unk20 |= 2;
}
