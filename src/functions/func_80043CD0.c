/* Independently written from specification specs/func_80043CD0.md. */
#include "podcruise/types.h"

typedef union PcWord {
    s32 s;
    u32 u;
    f32 f;
    void *p;
} PcWord;

typedef struct Sub43CD0 {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 *unk18;
} Sub43CD0;

typedef struct Actor43CD0 {
    /* 0x0000 */ u8 pad0000[0x19B4];
    /* 0x19B4 */ f32 unk19B4;
    /* 0x19B8 */ u8 pad19B8[0x1E70 - 0x19B8];
    /* 0x1E70 */ Sub43CD0 *unk1E70;
} Actor43CD0;

typedef struct Msg43CD0 {
    /* 0x00 */ u32 id;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ Actor43CD0 *unk08;
    /* 0x0C */ f32 *unk0C;
    /* 0x10 */ f32 *unk10;
    /* 0x14 */ f32 *unk14;
} Msg43CD0;

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80017874(f32 *);
extern void func_80040050(PcWord *, f32);
extern void func_8004110C(PcWord *, s32);
extern void func_800419B4(PcWord *);

extern f32 D_800A5CA0[][27];
extern f32 D_800AACF4;
extern f32 D_800AACF8;

s32 func_80043CD0(PcWord *self, Msg43CD0 *message, f32 *shake) {
    Actor43CD0 *actor;
    s32 state;
    s32 index;
    f32 scratch[30];

    (void)scratch;

    switch (message->id) {
        case 0x4C6F6164:
            func_80015268(&self[0x8 / 4].f, 0.0f, 0.0f, 0.0f);
            func_80015268(&self[0x14 / 4].f, 0.0f, 0.0f, 0.0f);
            func_80017874(&self[0x20 / 4].f);
            self[0x60 / 4].s = 0;
            self[0x64 / 4].s = 0;
            self[0x74 / 4].s = -1;
            self[0x7C / 4].s = 0;
            self[0x2A4 / 4].s = 0;
            self[0x68 / 4].f = 0.0f;
            self[0x148 / 4].f = 0.0f;
            self[0x14C / 4].f = 0.0f;
            self[0x150 / 4].f = 0.0f;
            for (index = 0; index < 2; index++) {
                self[0xF4 / 4 + index].s = 0;
            }
            func_80015268(&self[0xFC / 4].f, 0.0f, 0.0f, 0.0f);
            func_80017874(&self[0x108 / 4].f);
            self[0x154 / 4].s = 0;
            self[0x158 / 4].s = 0;
            self[0x7C / 4].s = 0;
            self[0x74 / 4].s = -1;
            break;

        case 0x52536574:
            self[0xF4 / 4].s = 0;
            self[0x7C / 4].s = 0;
            self[0x74 / 4].s = -1;
            self[0x3A4 / 4].f = 0.0f;
            self[0x3A0 / 4].f = 0.0f;
            self[0x39C / 4].f = 0.0f;
            break;

        case 0x4E41736E:
            self[0x74 / 4].s = message->unk04;
            self[0x7C / 4].s = 1;
            self[0x80 / 4].s = 1;
            actor = message->unk08;
            self[0xF4 / 4].p = actor;
            func_8004110C(self, 1);
            self[0x6C / 4].s = 0;
            self[0x70 / 4].f = -1.0f;
            func_80040050(self, -1.0f);
            if (actor != 0) {
                self[0x148 / 4].f =
                    D_800A5CA0[*actor->unk1E70->unk18][0x4C / 4];
                self[0x14C / 4].f =
                    D_800A5CA0[*actor->unk1E70->unk18][0x50 / 4];
                self[0x14C / 4].f =
                    (f32)(self[0x14C / 4].f + actor->unk19B4 * 0.75);
            }
            self[0x1B0 / 4].f = 0.0f;
            self[0x1A4 / 4].f = 0.0f;
            self[0x1A8 / 4].f = 0.0f;
            self[0x1AC / 4].f = 0.0f;
            self[0x198 / 4].f = 0.0f;
            self[0x19C / 4].f = 0.0f;
            self[0x1A0 / 4].f = 0.0f;
            self[0x2B0 / 4].f = 100.0f;
            self[0x2D4 / 4].f = D_800AACF4;
            self[0x2D8 / 4].f = -1.0f;
            self[0x2E0 / 4].f = -1.0f;
            self[0x84 / 4].s = 0;
            self[0x2A8 / 4].s = 16;
            self[0x2AC / 4].s = -256;
            self[0x2A4 / 4].s = 0;
            self[0x2E4 / 4].u = 0x80000000;
            self[0x364 / 4].s = 0;
            self[0x37C / 4].f = -1.0f;
            self[0x150 / 4].f = 0.0f;
            self[0x398 / 4].f = 0.0f;
            self[0x378 / 4].f = 0.0f;
            self[0x374 / 4].f = 0.0f;
            self[0x394 / 4].f = 0.0f;
            self[0x38C / 4].f = 0.0f;
            self[0x3A4 / 4].f = 0.0f;
            self[0x3A0 / 4].f = 0.0f;
            self[0x39C / 4].f = 0.0f;
            self[0x2DC / 4].f = D_800AACF8;
            self[0x368 / 4].f = 64.0f;
            self[0x36C / 4].f = 64.0f;
            self[0x370 / 4].f = 64.0f;
            self[0x380 / 4].f = 255.0f;
            self[0x384 / 4].f = 255.0f;
            self[0x388 / 4].f = 255.0f;
            self[0x390 / 4].f = 1.0f;
            break;

        case 0x53776565:
            if (message->unk04 == 0) {
                func_800419B4(self);
                return 1;
            }
            func_80040050(self, 0.0f);
            self[0x7C / 4].s = 7;
            self[0x6C / 4].s = 0;
            self[0x70 / 4].f = -1.0f;
            break;

        case 0x44657468:
            if (self[0xF4 / 4].s == message->unk04) {
                if (message->unk08 == 0) {
                    self[0x7C / 4].s = 8;
                } else {
                    self[0x7C / 4].s = 9;
                }
                self[0x15C / 4].f = message->unk0C[0];
                self[0x160 / 4].f = message->unk0C[1];
                self[0x168 / 4].f = self[0x50 / 4].f;
                self[0x16C / 4].f = self[0x54 / 4].f;
                self[0x170 / 4].f = self[0x58 / 4].f;
                self[0x164 / 4].f = message->unk0C[2];
                self[0x174 / 4].f = message->unk10[0];
                self[0x178 / 4].f = message->unk10[1];
                self[0x17C / 4].f = message->unk10[2];
                self[0x180 / 4].f = message->unk14[0];
                self[0x184 / 4].f = message->unk14[1];
                self[0x188 / 4].f = message->unk14[2];
                self[0x6C / 4].s = 0;
                self[0x70 / 4].f = 1.0f;
            }
            self[0x3A4 / 4].f = 0.0f;
            self[0x3A0 / 4].f = 0.0f;
            self[0x39C / 4].f = 0.0f;
            break;

        case 0x5368616B:
            self[0x3A4 / 4].f = shake[1];
            self[0x39C / 4].f = 0.0f;
            self[0x3A0 / 4].f = shake[2];
            break;

        case 0x43427574:
            if (self[0xF4 / 4].s == message->unk04) {
                state = self[0x7C / 4].s;
                self[0x84 / 4].s = 0;
                if (state == 7) {
                    func_8004110C(self, 1);
                    state = self[0x7C / 4].s;
                }
                if (1 == state) {
                    state = 4;
                    self[0x7C / 4].s = state;
                } else if (state == 3) {
                    state = 4;
                    self[0x7C / 4].s = state;
                } else if (state == 4) {
                    state = 5;
                    self[0x7C / 4].s = state;
                } else if (state == 5) {
                    func_8004110C(self, 2);
                    state = self[0x7C / 4].s;
                } else if (state == 2) {
                    func_8004110C(self, 1);
                    state = self[0x7C / 4].s;
                }
                self[0x80 / 4].s = state;
            }
            break;

        default:
            return 0;
    }
    return 1;
}
