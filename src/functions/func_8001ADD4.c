/* Independently written from specs/functions/recovered/func_8001ADD4.md. */

#include "podcruise/vector_math.h"

typedef f32 Matrix8001ADD4[4][4];

typedef struct Controller8001ADD4 {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ s32 mode;
    /* 0x10 */ s32 state;
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8 pad18[0x38];
    /* 0x50 */ u8 tableIndex;
    /* 0x51 */ u8 pad51[3];
    /* 0x54 */ f32 offsetX;
    /* 0x58 */ f32 offsetY;
    /* 0x5C */ u8 resetOffsets;
    /* 0x5D */ u8 pad5D[0x0F];
    /* 0x6C */ u8 locked;
    /* 0x6D */ u8 pad6D[2];
    /* 0x6F */ s8 currentStage;
    /* 0x70 */ s8 stageCount;
    /* 0x71 */ u8 pad71;
    /* 0x72 */ s8 chosenEntries[16];
} Controller8001ADD4;

typedef struct Session8001ADD4 {
    /* 0x00 */ f32 progress;
    /* 0x04 */ u8 pad04[8];
    /* 0x0C */ f32 panelFade;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x0C];
    /* 0x2C */ s32 entryCount;
    /* 0x30 */ s32 currentEntry;
    /* 0x34 */ s32 previousEntry;
    /* 0x38 */ u8 pad38[4];
    /* 0x3C */ s32 entryTransition;
} Session8001ADD4;

typedef struct Option8001ADD4 {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ u8 label[3];
    /* 0x17 */ u8 pad17[4];
    /* 0x1B */ s8 assignedEntry;
    /* 0x1C */ u8 pad1C[0x10];
} Option8001ADD4;

typedef struct Stage8001ADD4 {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 pad01[3];
    /* 0x04 */ u8 usesOption;
    /* 0x05 */ u8 option;
    /* 0x06 */ u8 pad06;
    /* 0x07 */ s8 entry;
    /* 0x08 */ u8 pad08[0x10];
    /* 0x18 */ s32 amount;
    /* 0x1C */ u8 fixedAmount;
    /* 0x1D */ u8 pad1D[0x0F];
} Stage8001ADD4;

typedef struct Entry8001ADD4 {
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ s32 resourceA;
    /* 0x08 */ s32 resourceB;
    /* 0x0C */ u8 pad0C[8];
    /* 0x14 */ s32 labelA;
    /* 0x18 */ s32 labelB;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ f32 panelOffset;
    /* 0x24 */ u8 pad24[0x0C];
    /* 0x30 */ s32 resourceC;
} Entry8001ADD4;

typedef struct EntryIndex8001ADD4 {
    s32 value;
    s32 pad04;
} EntryIndex8001ADD4;

typedef struct DisplayObject8001ADD4 {
    u8 pad000[0xEC];
    void *overlay;
    s32 type;
} DisplayObject8001ADD4;

extern s32 D_800A2198;
extern s32 D_800A239C;
extern s32 D_800A23A0;
extern s32 D_800A23A4;
extern f32 D_800A23A8;
extern s32 D_800A23AC;
extern f32 D_800A23B0;
extern s32 D_800A23B4;
extern s32 D_800A23B8;
extern Entry8001ADD4 D_800A31E0[];
extern f32 D_800A3200[];
extern u32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern PcVec3f D_800A5080;
extern PcVec3f D_800A508C;
extern u8 D_800A5100[];
extern u8 D_800A8A60[];
extern u8 D_800A8A74[];
extern u8 D_800A8A80[];
extern u8 D_800A8A90[];
extern u8 D_800A8AA0[];
extern u8 D_800A8AB4[];
extern u8 D_800A8AC0[];
extern f64 D_800A9B70;
extern f64 D_800A9B78;
extern f64 D_800A9B80;
extern f64 D_800A9B88;
extern f64 D_800A9B90;
extern f64 D_800A9B98;
extern f32 D_800A9BA0;
extern f32 D_800A9BA4;
extern f32 D_800A9BA8;
extern f32 D_800A9BAC;
extern f64 D_800A9BB0;
extern f32 D_800A9BB8;
extern f32 D_800A9BBC;
extern f64 D_800A9BC0;
extern f32 D_800A9BC8;
extern f32 D_800A9BCC;
extern f32 D_800A9BD0;
extern f32 D_800A9BD4;
extern f32 D_800D6C44;
extern EntryIndex8001ADD4 D_800D6CD8[];
extern s32 D_800D73A4;
extern Option8001ADD4 D_80113680[];
extern Stage8001ADD4 D_80113E60[];
extern Session8001ADD4 D_8011A240;
extern DisplayObject8001ADD4 *D_8011A544;
extern void **D_8011A780;
extern f32 D_80120BF8;

extern void func_80005B80(void);
extern s32 func_800129B8(const u8 *, s32);
extern void func_80015288(PcVec3f *, const PcVec3f *);
extern void func_80015630(PcVec3f *, f32, const PcVec3f *, f32,
                          const PcVec3f *);
extern void func_8001745C(Matrix8001ADD4, f32, f32, f32);
extern s32 func_800181BC(void *, s32, u32, s32, s32);
extern void func_80018470(void);
extern void func_80018480(DisplayObject8001ADD4 *, Matrix8001ADD4, s32, f32,
                          f32, f32, f32, s32, f32, f32);
extern s32 func_8001CCC4(Controller8001ADD4 *, s32);
extern void func_800281F0(Controller8001ADD4 *);
extern void func_80028D60(void);
extern void func_80029298(f32);
extern void func_8002932C(Controller8001ADD4 *);
extern void func_80029A3C(s32, s32);
extern void func_8002BBA4(Controller8001ADD4 *, s32, s32, s32, s32, s32,
                          const u8 *);
extern void func_8002CC28(s32, s32, s32);
extern void func_8002D4C4(s32);
extern s32 func_8002DCF4(void);
extern void func_8003398C(void **, f32, f32, f32, s32, f32, f32);
extern void func_80039914(s32, s32);
extern void func_800399F0(void);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, const u8 *);
extern void func_8003ECB0(s32, s32, const u8 *);
extern void func_80046670(s32, s32, s32, s32);
extern void func_800467F8(void);
extern void func_800469B4(Controller8001ADD4 *, s32);
extern void func_80046DC4(Controller8001ADD4 *, f32, f32);
extern void func_8004A5B4(s32);
extern f32 func_8004E034(f32, f32);
extern void func_800503E8(Controller8001ADD4 *, s32, s32, s32);
extern void func_8005163C(Controller8001ADD4 *);
extern void func_800517D8(s32, s32, s32, f32);
extern void func_80051898(s32);
extern void func_800519C0(s32, s32, s32, s32);
extern void func_80063AA0(s32, s32);
extern f32 func_80064A88(f32);
extern void func_80064B44(s32, f32, s32);
extern void func_80082BE0(void);
extern s32 func_8008A6B4(u8 *, const u8 *, ...);

#define ENTRY_OFFSET(index) (*(f32 *)((u8 *)D_800A3200 + (index) * 0x34))

void func_8001ADD4(Controller8001ADD4 *controller) {
    Matrix8001ADD4 rotation;
    PcVec3f finalPosition;
    PcVec3f *position;
    u8 text[0x100];
    Entry8001ADD4 *entry;
    Stage8001ADD4 *stage;
    Option8001ADD4 *option;
    u32 buttons;
    f32 scale;
    f32 angle;
    s32 width;
    s32 index;
    s32 oldEntry;
    s32 restartDisplay;
    s32 availableSum;
    s32 displayMode;

    restartDisplay = 0;
    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        func_80029298(157.0f);
        D_800A23A0 = 0;
        D_800A239C = 0;
        D_8011A240.previousEntry = 0;
        D_800A23A4 = -1;
        D_800A23B8 = 1;
        func_800503E8(controller, 0x24, -1, 0);

        if (controller->mode == 2) {
            controller->state = D_80113E60[controller->currentStage].active != 0;
        } else if (controller->mode == 1 || controller->mode == 0x12) {
            controller->state = 0;
            controller->currentStage = 0;
        } else if (controller->mode == 9) {
            controller->state = controller->currentStage == 0;
        } else {
            controller->state = 1;
            if (controller->mode == 0xC) {
                controller->currentStage = controller->stageCount - 1;
            }
        }

        if (controller->mode != 1 && controller->mode != 0x12) {
            D_800A23AC = D_80113E60[controller->currentStage].option;
        }
        if (controller->state == 1) {
            func_800281F0(controller);
        }

        index = D_80113E60[controller->currentStage].entry;
        if (index == -1) {
            D_8011A240.currentEntry = 0;
            restartDisplay = 1;
        } else {
            for (oldEntry = 0; oldEntry < D_8011A240.entryCount; oldEntry++) {
                if (D_800D6CD8[oldEntry].value == index) {
                    D_8011A240.currentEntry = oldEntry;
                    break;
                }
            }
            func_800519C0(D_800D6CD8[D_8011A240.currentEntry].value,
                          -1, 0, 0xFF);
        }

        D_800D6C44 = 360.0f;
        D_800A23B4 = 4;
        if (controller->mode == 1 || controller->mode == 0x12) {
            D_800A23AC = 4;
            if (D_80113680[0].assignedEntry != -1
                    || D_80113680[1].assignedEntry != -1
                    || D_80113680[2].assignedEntry != -1
                    || D_80113680[3].assignedEntry != -1
                    || controller->locked != 0) {
                D_800A23AC = 0;
            }
        }
    }

    if (D_800A4BC0 != 0) {
        return;
    }

    if (controller->state == 0) {
        if (D_800A23AC < 4) {
            D_800D73A4 = D_80113680[D_800A23AC].assignedEntry;
        } else {
            D_800D73A4 = -1;
        }
    } else if (controller->state == 1) {
        D_800D73A4 = D_800D6CD8[D_8011A240.currentEntry].value;
    }

    if (D_8011A240.progress > 0.0f) {
        if (controller->state == 1) {
            scale = (f32)((f64)D_800D6CD8[D_8011A240.previousEntry].value
                          * D_800A9B70 + D_800A9B78);
        } else {
            scale = (f32)((f64)D_800A23A4 * D_800A9B80 + D_800A9B88);
        }
        func_8003398C(D_8011A780, scale, scale, scale, 0, 0.0f, 0.0f);
        func_8004A5B4(D_8011A240.previousEntry);
    } else if (D_800D73A4 != -1) {
        scale = (f32)((f64)D_800D73A4 * D_800A9B90 + D_800A9B98);
        func_8003398C(D_8011A780, scale, scale, scale, 0, 0.0f, 0.0f);
    }

    if (D_800A239C == 5 && func_80064A88(D_800A9BA0) == 0.0f) {
        func_80063AA0(0x1C, 0);
        func_800399F0();
        func_800469B4(controller, D_800A2198);
        return;
    }

    if (controller->state == 0) {
        if (D_800A239C == 0) {
            if (D_800A4BDC == -1 || D_800D73A4 == -1
                    || D_800A23A4 != D_800D73A4) {
                func_80064A88(D_800A9BA4);
            } else {
                func_80064A88(D_800A9BA8);
            }
            D_8011A240.panelFade += D_800A9BAC * D_80120BF8;
            if (D_8011A240.panelFade > 1.0f) {
                D_8011A240.panelFade = 1.0f;
            }
        }
        if (D_8011A240.panelFade == 1.0f) {
            D_800A23B0 = (f32)((f64)D_800A23B0
                               + D_800A9BB0 * (f64)D_80120BF8);
            if (D_800A23B0 > 255.0f) {
                D_800A23B0 = 255.0f;
            }
        } else if (D_8011A240.panelFade < 1.0f) {
            D_800A23B0 = 0.0f;
        }

        func_8003ECB0(0xA0, 0x19, D_800A8A60);
        for (index = 0; index < 4; index++) {
            option = &D_80113680[index];
            if (option->assignedEntry != -1) {
                func_8008A6B4(text, D_800A8A74, option->label[0],
                              option->label[1], option->label[2]);
                func_8002BBA4(controller, 0xF0, 0x96, 0xA,
                              D_800A23AC, index, text);
            } else {
                func_8002BBA4(controller, 0xF0, 0x96, 0xA,
                              D_800A23AC, index, D_800A8A80);
            }
        }
        func_8002BBA4(controller, 0xF0, 0x96, 0xA,
                      D_800A23AC, 4, D_800A8A90);
        D_8011A240.unk1C = 0;
        D_8011A240.unk18 = 0;
    } else if (controller->state == 1) {
        if (D_800A239C == 0) {
            D_8011A240.panelFade -= D_800A9BB8 * D_80120BF8;
            if (D_8011A240.panelFade < 0.0f) {
                D_8011A240.panelFade = 0.0f;
            }
            if (D_800A23B8 != 0) {
                func_80046DC4(controller, 105.0f, 135.0f);
            }
        }
        func_8003ECB0(0xA0, 0x19, D_800A8AA0);
    }

    if (D_800D73A4 != -1) {
        entry = &D_800A31E0[D_800D73A4];
        func_8008A6B4(text, D_800A8AB4, entry->labelA, entry->labelB);
        func_8003EC40(0xA0, 0x2A, 0, 0xFF, 0, 0xFF, text);
        width = func_800129B8(text, 0);
        func_8002CC28((s32)(160.0 - (f64)width * 0.5), 0x2B,
                      func_800129B8(text, 0));
        controller->flags |= 4;
    } else {
        controller->flags &= ~4;
        controller->resetOffsets = 1;
        controller->offsetX = 0.0f;
        controller->offsetY = 0.0f;
    }

    if (controller->stageCount >= 2) {
        func_8008A6B4(text, D_800A8AC0, controller->currentStage + 1);
        func_8003ECB0(0xA0, 0x37, text);
    }

    if (controller->state == 1 && D_8011A240.entryTransition == 0
            && D_800A23A4
                != D_800D6CD8[D_8011A240.previousEntry].value) {
        restartDisplay = 1;
    }
    if (controller->state == 0 && (f64)D_8011A240.progress == 0.0
            && D_800A23A4 != D_800D73A4) {
        restartDisplay = 1;
    }

    if (D_800D73A4 != -1
            && (D_8011A544 == 0 || restartDisplay != 0)) {
        func_80005B80();
        func_80051898(3);
        entry = &D_800A31E0[D_800D73A4];
        D_800D6C44 = 0.0f;
        func_80046670(entry->resourceA, entry->resourceB, 0xF, 0);
        if (D_8011A544 != 0) {
            func_80018470();
            D_8011A544->type = D_800D73A4;
            func_800517D8(entry->resourceC, 0x1C, 2, entry->panelOffset);
        }
        D_800A23A4 = D_800D73A4;
        func_800467F8();
        func_8002932C(controller);
        func_800519C0(D_800D73A4, -1, -1, 0xFF);
    }

    if (D_800A23A0 == 0) {
        D_800A23A0 = 1;
    }
    D_800D6C44 += 90.0f * D_80120BF8;
    if (D_800D6C44 > 1800.0f) {
        D_800D6C44 -= 1800.0f;
    }
    if (D_800A239C == 1 && func_80064A88(D_800A9BBC) == 0.0f) {
        D_800A239C = 2;
    }

    D_800A23A8 = D_8011A240.progress * 4.0f;
    if ((f64)D_800A23A8 < D_800A9BC0) {
        D_800A23A8 = D_800A9BC8;
    }

    if (D_8011A544 != 0 && D_8011A240.progress > 0.0f) {
        func_80028D60();
        angle = D_800D6C44;
        if (angle < 540.0f) {
            func_8001745C(rotation,
                          D_800A9BCC - func_8004E034(angle, 540.0f),
                          0.0f, 0.0f);
        } else if (angle < 900.0f) {
            func_8001745C(rotation, 100.08f, 180.0f,
                          180.0f - func_8004E034(angle - 540.0f, 360.0f));
        } else if (angle < 1440.0f) {
            func_8001745C(rotation,
                          D_800A9BD0
                              - func_8004E034(angle - 900.0f, 540.0f)
                              + 180.0f,
                          0.0f, 0.0f);
        } else {
            func_8001745C(rotation, 100.08f, 0.0f,
                          -func_8004E034(angle - 1440.0f, 360.0f));
        }

        position = (PcVec3f *)&rotation[3][0];
        func_80015288(position, &D_800A508C);
        D_800A23A8 *= 0.5f;
        func_80015630(position, 0.5f, &D_800A508C, 0.5f, &D_800A5080);
        displayMode = D_800A2198 == -1;
        func_80018480(D_8011A544, rotation, displayMode,
                      D_800A23A8, D_800A23A8, D_800A23A8, D_800A9BD4,
                      displayMode == 0, 1.0f, 1.0f);
        if (D_8011A544->overlay != 0) {
            func_800181BC(D_8011A544->overlay, 2, 3, 0x10, 2);
        }
    }

    if (D_800A239C != 0) {
        if (D_8011A240.progress == 0.0f) {
            D_800A239C++;
        }
        return;
    }
    if (controller->state == 3) {
        if (func_8001CCC4(controller, D_800A23AC) != 0) {
            controller->state = 0;
        }
        return;
    }

    index = controller->currentStage;
    buttons = D_800A4BA4[index];
    if (controller->state == 0) {
        if (buttons & 1) {
            func_8002D4C4(0x55);
            if (D_800D73A4 == -1) {
                controller->state = 1;
                func_80029A3C(0, index);
                stage = &D_80113E60[controller->currentStage];
                stage->option = D_800A23AC;
                if (D_800A23AC < 4) {
                    stage->usesOption = 1;
                    func_800469B4(controller, 2);
                    return;
                }
                stage->usesOption = 0;
                func_800281F0(controller);
                D_8011A240.currentEntry = 0;
                func_800519C0(D_800D6CD8[0].value, -1, 0, 0xFF);
            } else {
                func_80039914(index, D_800A23AC);
                func_800281F0(controller);
                controller->state = 1;
                for (oldEntry = 0; oldEntry < D_8011A240.entryCount;
                     oldEntry++) {
                    if (D_800D73A4 == D_800D6CD8[oldEntry].value) {
                        D_8011A240.currentEntry = oldEntry;
                        D_8011A240.previousEntry = oldEntry;
                        break;
                    }
                }
                func_800519C0(D_800D6CD8[D_8011A240.currentEntry].value,
                              -1, 0, 0xFF);
                return;
            }
        }

        buttons = D_800A4BA4[index];
        if ((buttons & 2) && !(buttons & 1)) {
            func_8002D4C4(0x4D);
            stage = &D_80113E60[index];
            stage->entry = -1;
            stage->option = 0xFF;
            if (controller->currentStage > 0) {
                D_800A239C = 1;
                controller->currentStage--;
                D_800A2198 = 9;
                return;
            }
            D_800A2198 = 1;
            D_800A4BDC = -1;
            return;
        }

        availableSum = D_80113680[0].assignedEntry
                     + D_80113680[1].assignedEntry
                     + D_80113680[2].assignedEntry
                     + D_80113680[3].assignedEntry;
        displayMode = 0;
        if (controller->stageCount == 1) {
            if (D_800D73A4 != -1 && D_8011A240.progress == 1.0f) {
                displayMode = 1;
            } else if (D_800A23AC == 4 && func_8002DCF4() != 0) {
                displayMode = 1;
            } else if (D_800A23AC == 4 && availableSum == -4) {
                displayMode = 1;
            }
            buttons = D_800A4BA4[index];
            if (displayMode != 0 && (buttons & 4)) {
                func_8002D4C4(0x55);
                controller->state = 3;
                return;
            }
        }

        buttons = D_800A4BA4[index];
        if (buttons & 0x8000) {
            D_800A23AC++;
            func_8002D4C4(0x57);
        }
        buttons = D_800A4BA4[index];
        if (buttons & 0x4000) {
            D_800A23AC--;
            func_8002D4C4(0x57);
        }
        if (D_800A23AC > D_800A23B4) {
            D_800A23AC = 0;
        }
        if (D_800A23AC < 0) {
            D_800A23AC = D_800A23B4;
        }
    } else if (controller->state == 1) {
        oldEntry = D_8011A240.currentEntry;
        func_80064B44(index, 1.0f, 1);
        if (oldEntry != D_8011A240.currentEntry) {
            func_800519C0(D_800D6CD8[D_8011A240.currentEntry].value,
                          -1, 0, 0xFF);
        }
        buttons = D_800A4BA4[index];
        if (D_8011A240.progress >= 1.0f && (buttons & 2)) {
            func_8002D4C4(0x4D);
            if (controller->mode == 3) {
                D_800A2198 = 3;
                D_800A239C = 1;
                return;
            }
            controller->state = 0;
            controller->resetOffsets = 1;
            controller->offsetX = 0.0f;
            controller->offsetY = 0.0f;
            return;
        }
        buttons = D_800A4BA4[index];
        if (D_8011A240.progress >= 1.0f && (buttons & 1)) {
            func_8002D4C4(0x55);
            D_800A239C = 1;
        }
        buttons = D_800A4BA4[index];
        if (buttons & 8) {
            func_8002D4C4(0x55);
            D_800A23B8 = D_800A23B8 == 0;
        }
    }

    if (D_800A239C == 1) {
        stage = &D_80113E60[controller->currentStage];
        if (controller->state == 1) {
            index = D_800D6CD8[D_8011A240.currentEntry].value;
            func_80029298(ENTRY_OFFSET(index));
            controller->chosenEntries[controller->currentStage] = index;
            stage->entry = index;
            if (D_800A23AC < 4) {
                option = &D_80113680[D_800A23AC];
                if (option->label[0] == 0) {
                    stage->fixedAmount = 1;
                    stage->amount = 0x190;
                } else {
                    option->assignedEntry = index;
                }
            }
        } else {
            controller->chosenEntries[controller->currentStage] = stage->entry;
        }

        func_8005163C(controller);
        if (controller->mode == 3) {
            D_800A2198 = 3;
            return;
        }
        if (D_80113680[D_800A23AC].label[0] == 0
                && controller->state == 1 && D_800A23AC < 4) {
            D_800A2198 = 2;
            return;
        }
        if (controller->currentStage < controller->stageCount - 1) {
            controller->currentStage++;
            D_800A2198 = 9;
            return;
        }

        D_800A2198 = 0xC;
        func_80015288(&finalPosition,
                      (PcVec3f *)&D_800A5100[controller->tableIndex * 0xC
                                           + 0x6C]);
        func_80082BE0();
        return;
    }
    if (D_800A239C == 2) {
        D_800A239C = 3;
    }
}
