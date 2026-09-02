/* Independently written from specs/functions/recovered/func_8005CBD8.md. */
#include "podcruise/types.h"

typedef union PcWord5C {
    s32 s;
    u32 u;
    f32 f;
    s16 h[2];
} PcWord5C;

typedef struct Msg5CBD8 {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
} Msg5CBD8;

typedef struct Entry5CBD8 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 pad04[0x80];
    /* 0x84 */ s32 unk84;
} Entry5CBD8;

typedef struct Note5CBD8 {
    /* 0x00 */ s32 id;
    /* 0x04 */ u8 pad04[292];
} Note5CBD8;

extern s32 func_80009B8C(s32);
extern void func_8000AB24(s32, s32, s32, s32, s32);
extern void func_8000AEFC(s32, s32, f32 *, s32);
extern void func_8002F1E4(void);
extern void func_80031560(s32);
extern void func_8003F974(s32, Note5CBD8 *);
extern void func_8003F99C(s32, Msg5CBD8 *);
extern void func_8003FA24(s32, Note5CBD8 *);
extern void func_80051C80(PcWord5C *, s32);
extern void func_80052A08(PcWord5C *, s32);
extern void func_80060880(PcWord5C *, s32);
extern void func_800811CC(void);

extern f32 D_8009B8C8;
extern s32 D_800A533C;
extern s32 D_800A5340;
extern s32 D_800A5998;
extern s32 D_800A599C;
extern s32 D_800A59A0;
extern f32 D_800A59A4;
extern f32 D_800AD004;
extern s32 D_800D6960[];
extern Entry5CBD8 *D_8011B1B8;
extern s32 D_8011B1BC;

s32 func_8005CBD8(PcWord5C *self, Msg5CBD8 *message, f32 *arg2) {
    Note5CBD8 note;
    s32 index;
    s32 count;

    switch (message->id) {
        case 0x536C6570:
            self[1].h[1] |= 0x1000;
            break;

        case 0x57616B65:
            self[1].h[1] &= 0xEFFF;
            break;

        case 0x4C6F6164:
            func_8000AEFC(1, 1, &self[0x64 / 4].f, 0);
            self[0x8 / 4].s = 0;
            self[0x30 / 4].s = 0;
            self[0x2C / 4].s = 0;
            self[0x10 / 4].s = 0;
            self[0x14 / 4].s = 0;
            self[0x64 / 4].f = 1.0f;
            self[0x68 / 4].f = 0.0f;
            self[0x6C / 4].f = 0.0f;
            self[0x70 / 4].f = 0.0f;
            self[0x74 / 4].f = 0.0f;
            self[0x78 / 4].f = 1.0f;
            self[0x7C / 4].f = 0.0f;
            self[0x80 / 4].f = 0.0f;
            self[0x84 / 4].f = 0.0f;
            self[0x88 / 4].f = 0.0f;
            self[0x8C / 4].f = 1.0f;
            self[0x90 / 4].f = 0.0f;
            self[0x94 / 4].f = 0.0f;
            self[0x98 / 4].f = 0.0f;
            self[0x9C / 4].f = 0.0f;
            self[0xA0 / 4].f = 1.0f;
            self[0xC / 4].f = 0.0;
            for (index = 2; index < 6; index++) {
                self[0x10 / 4 + index].s = 0;
            }
            self[0x28 / 4].s = 0;
            self[0x130 / 4].s = 0;
            self[0x1A4 / 4].s = 0;
            self[0x1A8 / 4].s = 0;
            self[0x1E0 / 4].s = 0;
            self[0x124 / 4].s = 2;
            self[0x1A0 / 4].f = 1.0f;
            self[0x19C / 4].f = 0.0f;
            self[0x198 / 4].f = 0.0f;
            self[0x194 / 4].f = 0.0f;
            self[0x190 / 4].f = 0.0f;
            self[0x18C / 4].f = 1.0f;
            self[0x188 / 4].f = 0.0f;
            self[0x184 / 4].f = 0.0f;
            self[0x180 / 4].f = 0.0f;
            self[0x17C / 4].f = 0.0f;
            self[0x178 / 4].f = 1.0f;
            self[0x174 / 4].f = 0.0f;
            self[0x170 / 4].f = 0.0f;
            self[0x16C / 4].f = 0.0f;
            self[0x168 / 4].f = 0.0f;
            self[0x164 / 4].f = 1.0f;
            self[0x1D8 / 4].f = 0.0;
            self[0x1DC / 4].f = 0.0;
            self[0x1E4 / 4].f = 0.0;
            self[0x12C / 4].f = 0.0;
            /* fallthrough */
        case 0x52536574:
            func_8002F1E4();
            note.id = 0x536C6570;
            func_8003FA24(0x4A646765, &note);
            return 1;

        case 0x4A6F696E:
            if ((self[0x8 / 4].s & 0x10) != 0) {
                note.id = 0x4D737472;
                func_8003F974(0x4A646765, &note);
                return 1;
            }
            break;

        case 0x4D737472:
            self[0x8 / 4].s &= ~0x10;
            break;

        case 0x4A41736E:
            message->id = 0x4E41736E;
            count = self[0x1BC / 4].s;
            for (index = 0; index < count; index++) {
                if (D_8011B1B8[index].unk00 == message->unk08) {
                    message->unk08 = D_8011B1B8[index].unk84;
                    func_8003F99C(message->unk0C, message);
                    count = self[0x1BC / 4].s;
                    index = count;
                }
            }
            return 1;

        case 0x50617773:
            if (message->unk04 < 0) {
                if (message->unk08 == 1) {
                    func_80051C80(self, 0x41627274);
                    return 1;
                }
                if (message->unk08 == 2) {
                    func_80051C80(self, 0x52537472);
                    return 1;
                }
            }
            break;

        case 0x4265676E:
            D_800A5340 = 0;
            self[0x1BC / 4].s = message->unk08;
            self[0x1AC / 4].s = message->unk0C;
            self[0x1B0 / 4].s = message->unk10;
            self[0x1B4 / 4].s = message->unk14;
            self[0x1B8 / 4].s = message->unk18;
            self[0x1C0 / 4].s = message->unk1C;
            self[0x1CC / 4].f = message->unk20;
            self[0x1C8 / 4].s = message->unk24;
            self[0x1D0 / 4].f = arg2[0x28 / 4];
            self[0x1D4 / 4].f = arg2[0x2C / 4];
            self[0x1C4 / 4].s = message->unk30;
            if (message->unk34 == 1) {
                D_800D6960[0x1C / 4] |= 0x4000;
            } else {
                D_800D6960[0x1C / 4] &= ~0x4000;
            }
            self[0x8 / 4].s &= ~0x80;
            D_800A533C = message->unk38;
            if (0.0f < self[0x1CC / 4].f) {
                self[0x8 / 4].s |= 0x20;
            } else {
                self[0x8 / 4].s &= ~0x20;
            }
            func_80060880(self, message->unk04);
            if (D_8011B1BC == 0) {
                self[0x8 / 4].s |= 0x40;
            } else {
                self[0x8 / 4].s &= ~0x40;
            }
            func_800811CC();
            self[0x8 / 4].s = (self[0x8 / 4].s & ~0xF) | 4;
            self[0xC / 4].f = 0.5f;
            func_8000AB24(-0x67, 0, 0, 0, 0xFF);
            func_80009B8C(self[0x1AC / 4].s);
            func_80052A08(self, 2);
            if (self[0x1AC / 4].s == 3 && 1 == self[0x1C0 / 4].s) {
                D_8009B8C8 = D_800AD004;
            }
            func_80031560(-1);
            if (D_800A5998 != 0) {
                D_800A599C = D_800A599C + 1;
                if (D_800A599C == 6) {
                    D_800A599C = 1;
                    D_800A59A0 = 1;
                }
                self[0x124 / 4].s = 4;
                D_800A59A4 = 0.0f;
            }
            break;

        default:
            return 0;
    }
    return 1;
}
