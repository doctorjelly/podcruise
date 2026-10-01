/* Recovered per specs/func_800718DC.md (racer object message handler). */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x18];
    s32 *unk18;
    u8 pad1C[0x5C - 0x1C];
    s16 unk5C;
} Owner;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Lod;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} HitInfo;

typedef struct {
    u8 pad0[8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x50 - 0x20];
    s32 unk50;
    u8 pad54[0x60 - 0x54];
    s32 unk60;
    u8 pad64[0x1A0 - 0x64];
    f32 unk1A0;
    u8 pad1A4[0x2B8 - 0x1A4];
    f32 unk2B8;
    u8 pad2BC[0x308 - 0x2BC];
    f32 unk308;
    u8 pad30C[0x324 - 0x30C];
    s32 unk324;
    u8 pad328[0x344 - 0x328];
    Lod *unk344;
    u8 pad348[0x1998 - 0x348];
    s32 unk1998;
    u8 pad199C[0x1E70 - 0x199C];
    Owner *unk1E70;
    s32 unk1E74;
    f32 unk1E78;
    f32 unk1E7C;
    s32 unk1E80;
    u8 pad1E84[4];
    f32 unk1E88;
    s32 unk1E8C;
    s32 unk1E90;
    s32 unk1E94;
    s32 unk1E98;
    s32 unk1E9C;
    s32 unk1EA0;
} Racer;

extern u32 D_80000318;
extern f32 D_800A5B70[8];
extern u8 D_800A5B90[8];
extern s32 D_800A5B98;
extern u8 D_800A5B9C[];
extern u8 D_800A5C1C[];
extern f64 D_800AD8C0;
extern f32 D_800AD8C8;
extern f32 D_800AD8CC;
extern f32 D_800AD8D0;
extern f32 D_800AD8D4;
extern f64 D_800AD8D8;
extern f32 D_800AD8E0;
extern f32 D_800AD8E4;
extern f32 D_800AD8E8;
extern f32 D_800AD8EC;
extern f64 D_800AD8F0;
extern f32 D_800AD8FC;
extern f64 D_800AD900;
extern f32 D_800AD908;
extern f32 D_800AD90C;
extern f32 D_800AD910;
extern f32 D_800AD914;

extern s32 func_80008BC4(s32, s32, f32, f32, s32 *, s32, s32, f32, f32);
extern s32 func_800093B0(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80031B70(Racer *, s32);
extern s32 func_8003FD7C(Racer *);
extern s32 func_800703A0(s32 *, Racer *);
extern s32 func_800704A8(Racer *, f32);
extern s32 func_80071820(Racer *, s32, f32);
extern s32 func_80082BE0(void);
extern s32 func_800833B4(s32, u8 *);

s32 func_800718DC(Racer *self, s32 *message, HitInfo *info) {
    s32 slots[5];
    s32 kind;
    s32 code;
    s32 index;
    s32 count;
    s32 *cursor;
    Racer **target;
    u8 *record;
    f32 strength;
    f32 random;
    f32 alpha;

    code = message[0];
    switch (code) {
        case 0x52536574:
            func_8003FD7C(self);
            break;

        case 0x4C6F6164:
            func_8003FD7C(self);
            break;

        case 0x416C6F63:
        case 0x46726565:
            break;

        case 0x476F2121:
            self->unk60 = (self->unk60 & ~0xF) | 2;
            break;

        case 0x526D4869:
            if ((self->unk60 & 0x40) == 0) {
                break;
            }
            if (self->unk1E74 >= 0) {
                break;
            }
            self->unk1E8C = self->unk8;
            self->unk1E90 = self->unkC;
            self->unk1E98 = self->unk14;
            self->unk1E94 = self->unk10;
            self->unk1E80 = 0;
            self->unk1E74 = message[1];
            self->unk1E7C = 0.0f;
            self->unk1E78 = 0.0f;
            self->unk1E9C = self->unk18;
            self->unk1EA0 = self->unk1C;
            return 2;

        case 0x526D5468:
            if ((self->unk60 & 0x40) == 0) {
                break;
            }
            if (self->unk1E74 != message[1]) {
                break;
            }
            self->unk1E88 = *(f32 *)&info->unkC;
            break;

        case 0x526D436E:
            if ((self->unk60 & 0x40) == 0) {
                break;
            }
            if (self->unk1E74 != message[1]) {
                break;
            }
            self->unk1E78 = *(f32 *)&info->unk8;
            self->unk1E7C = *(f32 *)&info->unkC;
            self->unk1E80 = message[4];
            break;

        case 0x526D4C63:
            if ((self->unk60 & 0x40) == 0) {
                break;
            }
            if (self->unk1E74 != message[1]) {
                break;
            }
            self->unk1E8C = info->unk8;
            self->unk1E90 = info->unkC;
            self->unk1E94 = info->unk10;
            self->unk1E98 = info->unk14;
            self->unk1E9C = info->unk18;
            self->unk1EA0 = info->unk1C;
            break;

        case 0x536E6170:
            if (message[1] < 0) {
                func_800704A8(self, -0.1f);
            } else if (message[1] > 0) {
                if (message[1] >= 2) {
                    func_800704A8(self, 0.01f);
                } else {
                    func_800704A8(self, 0.1f);
                }
            } else {
                func_800704A8(self, 0);
            }
            break;

        case 0x734C4F44:
            if (self->unk344 == 0) {
                break;
            }
            index = message[1];
            if (self->unk60 & 0x20) {
                record = &D_800A5B9C[index * 32];
                func_800833B4(self->unk344->unk14, record);
                func_800833B4(self->unk344->unk4, record + 4);
                func_800833B4(self->unk344->unk8, record + 4);
                func_800833B4(self->unk344->unkC, record + 4);
                func_800833B4(self->unk344->unk10, record + 4);
            } else {
                record = &D_800A5C1C[index * 32];
                func_800833B4(self->unk344->unk14, record);
                func_800833B4(self->unk344->unk4, record + 4);
                func_800833B4(self->unk344->unk8, record + 4);
                func_800833B4(self->unk344->unkC, record + 4);
                func_800833B4(self->unk344->unk10, record + 4);
            }
            break;

        case 0x48697474:
            if (self->unk1E70 == 0) {
                goto done;
            }
            kind = message[1];
            strength = *(f32 *)&info->unk8;
            if ((self->unk60 << 1) < 0) {
                strength = strength * 2000.0f;
            }
            strength = strength / 2000.0f;
            if (self->unk60 & 0x20) {
                index = D_800A5B98;
                D_800A5B90[index] = *(u8 *)&kind;
                D_800A5B70[index] = strength;
                D_800A5B98 = index + 1;
                if (index + 1 >= 8) {
                    D_800A5B98 = 0;
                }
            }

            count = 0;
            switch (kind) {
                case 0x42697473:
                    self->unk324 = -1;
                    goto done;

                case 0x54323031:
                    self->unk2B8 = 1.0f;
                    count = 3;
                    alpha = strength / (f32)count;
                    for (index = 0; index < count; index++) {
                        func_80071820(self, (s32)((u32)func_80082BE0() % 6U), alpha);
                    }
                    if (!((f64)self->unk1998 < D_800AD8C0)) {
                        goto done;
                    }
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    random = random * D_800AD8C8 + D_800AD8CC;
                    alpha = self->unk1A0 * D_800AD8D0 + 0.75f;
                    if (alpha > 1.0f) {
                        alpha = 1.0f;
                    }
                    func_80008BC4(0x37, 6, random, alpha,
                                  &self->unk50, 0, 0, 10.0f, 200.0f);
                    if ((self->unk60 & 0x20) == 0) {
                        goto done;
                    }
                    func_80031B70(self, 6);
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    if (!(random < D_800AD8D4)) {
                        goto done;
                    }
                    count = ((D_80000318 >= 0x800000) || (self->unk60 & 0x120)) ? self->unk1E70->unk18[0] : -1;
                    func_800093B0(1, count, 5, 6, 5, 6, 7);
                    goto done;

                case 0x426F746D:
                    count = (s32)strength;
                    if (count >= 7) {
                        count = 6;
                    }
                    if (count <= 0) {
                        count = 1;
                    }
                    self->unk2B8 = 1.0f;
                    if (count > 0) {
                        alpha = strength / (f32)count;
                        for (index = 0; index != count; index++) {
                            func_80071820(self, (s32)((u32)func_80082BE0() % 6U), alpha);
                        }
                    }
                    if (!((f64)self->unk1998 < D_800AD8D8)) {
                        goto done;
                    }
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    random = random * D_800AD8E0 + D_800AD8E4;
                    alpha = self->unk1A0 * D_800AD8E8 + 0.75f;
                    if (alpha > 1.0f) {
                        alpha = 1.0f;
                    }
                    func_80008BC4(0x37, 6, random, alpha,
                                  &self->unk50, 0, 0, 10.0f, 200.0f);
                    if ((self->unk60 & 0x20) == 0) {
                        goto done;
                    }
                    func_80031B70(self, 7);
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    if (!(random < D_800AD8EC)) {
                        goto done;
                    }
                    count = ((D_80000318 >= 0x800000) || (self->unk60 & 0x120)) ? self->unk1E70->unk18[0] : -1;
                    func_800093B0(1, count, 7, 7, 7, 8, 8);
                    goto done;

                case 0x52744674:
                case 0x4C744674:
                case 0x52745364:
                case 0x4C745364:
                case 0x56684C74:
                    self->unk2B8 = 1.0f;
                    count = 1;
                    if (kind == 0x52744674) {
                        slots[0] = 3;
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.5) {
                            slots[1] = 0;
                            count = 2;
                        }
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.25) {
                            slots[count] = 4;
                            count++;
                        }
                    } else if (kind == 0x4C744674) {
                        slots[0] = 0;
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.5) {
                            slots[1] = 3;
                            count = 2;
                        }
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.25) {
                            slots[count] = 1;
                            count++;
                        }
                    } else if (kind == 0x52745364) {
                        slots[0] = 3;
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.5) {
                            slots[1] = 4;
                            count = 2;
                        }
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.25) {
                            slots[count] = 5;
                            count++;
                        }
                    } else if (kind == 0x4C745364) {
                        slots[0] = 0;
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.5) {
                            slots[1] = 1;
                            count = 2;
                        }
                        random = (f32)func_80082BE0() / 2147483648.0f;
                        if ((f64)random < 0.25) {
                            slots[count] = 2;
                            count++;
                        }
                    } else if (kind == 0x56684C74) {
                        count = 4;
                        for (index = 0; index < 4; index++) {
                            slots[index] = (s32)((u32)func_80082BE0() % 6U);
                        }
                        self->unk308 = (f32)func_80082BE0() / 2147483648.0f * 6.0f + 2.0f;
                    }
                    if (count > 0) {
                        alpha = strength / (f32)count;
                        for (index = 0; index != count; index++) {
                            func_80071820(self, slots[index], alpha);
                        }
                    }
                    if (!((f64)self->unk1998 < D_800AD8F0)) {
                        goto done;
                    }
                    if ((self->unk60 & 0x20) == 0) {
                        goto done;
                    }
                    func_80031B70(self, 6);
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    if (!(random < D_800AD8FC)) {
                        goto done;
                    }
                    if (kind == 0x56684C74) {
 count = ((D_80000318 >= 0x800000) || (self->unk60 & 0x120)) ? self->unk1E70->unk18[0] : -1;
 func_800093B0(1, count, 1, 6, 5, 6, 5);
 } else {
 count = ((D_80000318 >= 0x800000) || (self->unk60 & 0x120)) ? self->unk1E70->unk18[0] : -1;
                        func_800093B0(1, count, 5, 6, 5, 6, 7);
                    }
                    goto done;

                case 0x4B506F77:
                    self->unk2B8 = 1.0f;
                    slots[0] = 3;
                    count = 1;
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    if ((f64)random < 0.5) {
                        slots[1] = 0;
                        count = 2;
                    }
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    if ((f64)random < 0.25) {
                        slots[count] = 4;
                        count++;
                    }
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    if ((f64)random < 0.25) {
                        slots[count] = 1;
                        count++;
                    }
                    if (count > 0) {
                        alpha = strength / (f32)count;
                        for (index = 0; index != count; index++) {
                            func_80071820(self, slots[index], alpha);
                        }
                    }
                    if (!((f64)self->unk1998 < D_800AD900)) {
                        goto done;
                    }
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    random = random * D_800AD908 + D_800AD90C;
                    alpha = self->unk1A0 * D_800AD910 + 0.75f;
                    if (alpha > 1.0f) {
                        alpha = 1.0f;
                    }
                    func_80008BC4(0x37, 6, random, alpha,
                                  &self->unk50, 0, 0, 10.0f, 200.0f);
                    if ((self->unk60 & 0x20) == 0) {
                        goto done;
                    }
                    func_80031B70(self, 6);
                    random = (f32)func_80082BE0() / 2147483648.0f;
                    if (!(random < D_800AD914)) {
                        goto done;
                    }
                    count = ((D_80000318 >= 0x800000) || (self->unk60 & 0x120)) ? self->unk1E70->unk18[0] : -1;
                    func_800093B0(1, count, 5, 6, 5, 6, 7);
                    goto done;

                default:
                    goto done;
            }
            goto done;

        case 0x51657279:
            if (message[1] == 0x51657279) {
                return 1;
            }
            cursor = &message[1];
            do {
                target = *(Racer ***)(cursor + 1);
                if ((cursor[0] == 0x3173743F) && (self->unk1E70->unk5C == 1)) {
                    *target = self;
                }
                if ((cursor[0] == 0x326E643F) && (self->unk1E70->unk5C == 2)) {
                    *target = self;
                }
                if ((cursor[0] == 0x3372643F) && (self->unk1E70->unk5C == 3)) {
                    *target = self;
                }
                if (cursor[0] == 0x43616D50) {
                    func_800703A0(*(s32 **)(cursor + 1), self);
                }
                cursor += 2;
            } while (cursor[0] != 0x51657279);
            return 1;

        default:
            return 0;
    }
done:
    return 1;
}
