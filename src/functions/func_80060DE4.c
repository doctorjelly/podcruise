/* Recovered per specs/functions/recovered/func_80060DE4.md. */
#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct {
    u8 unk000[0x100];
    u32 unk100;
} Node80060DE4;

typedef struct {
    /* 0x00 */ u8 unk00[0x08];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ u8 unk10[0x04];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ u8 unk20[0x10];
    /* 0x30 */ void *unk30;
    /* 0x34 */ Node80060DE4 **unk34;
    /* 0x38 */ u8 unk38[0x0C];
    /* 0x44 */ PcVec3f unk44;
    /* 0x50 */ PcVec3f unk50;
    /* 0x5C */ u8 unk5C[0x0C];
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ u8 unk70[0x08];
    /* 0x78 */ f32 unk78;
    /* 0x7C */ u8 unk7C[0x0C];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ u8 unk8C[0x14];
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
} Object80060DE4;

typedef struct {
    u8 unk00[0x2C];
    f32 unk2C;
    f32 unk30;
} Reference80060DE4;

extern Reference80060DE4 D_800A4C00;
extern f32 D_800AD0B0;
extern f32 D_800AD0B4;
extern f64 D_800AD1D8;
extern f32 D_800AD1E0;
extern f32 D_800AD1E4;
extern f32 D_800AD1E8;
extern f32 D_800AD1EC;
extern f32 D_800AD204;
extern f32 D_800AD208;
extern f32 D_800AD20C;
extern f32 D_800AD210;
extern f32 D_800AD214;
extern s8 D_80113E67;
extern s32 D_80118EF8;

extern void func_80008B14(s32, s16, f32, f32, s32);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);
extern u32 func_80009524(s32, u32);
extern f32 func_80014F54(f32, f32);
extern void func_8001535C(PcVec3f *, const PcVec3f *, const PcVec3f *);
extern void func_80033928(Node80060DE4 **, f32);
extern void func_8003398C(Node80060DE4 **, f32, f32, f32, s32, f32,
                          f32);
extern Object80060DE4 *func_8003F800(u32, s32);
extern void func_80060D70(s32, s32, s32, s32, s32);
extern void func_80063344(Object80060DE4 *, f32 *, f32 *);
extern s32 func_800636D0(Object80060DE4 *);
extern s32 func_80082BE0(void);

#define RANDOM_UNIT() ((f32)func_80082BE0() / 2147483648.0f)

void func_80060DE4(Object80060DE4 *object, s32 nextState) {
    PcVec3f delta;
    Node80060DE4 **nodes;
    Node80060DE4 **scan;
    Object80060DE4 *other;
    f32 valueA;
    f32 lower;
    f32 upper;
    f32 valueB;
    f32 valueC;
    f32 speed;
    f32 angle;
    f32 angleDifference;
    f32 rangeOffset;
    s32 applyRange;
    s32 sendRange;
    s32 oldState;
    s32 choiceCount;
    s32 choice;
    s32 specialSet;
    s32 index;

    applyRange = 1;
    sendRange = 1;
    valueA = D_800AD0B0;
    lower = D_800AD0B0;
    upper = D_800AD0B4;
    valueB = D_800AD0B4;
    valueC = D_800AD0B4;

    if (object->unk0C == -1) {
        return;
    }
    oldState = object->unk14;
    object->unk14 = nextState;
    object->unk18 = 0.0f;
    if (object->unk08 == 6) {
        return;
    }

    speed = object->unk78;
    if (speed < 0.0f) {
        speed = -speed;
    }
    func_800636D0(object);

    nodes = object->unk34;
    for (index = 0; nodes[index] != 0; index++) {
        nodes[index]->unk100 |= 0x10000000;
    }

    switch (nextState) {
    case 0:
        object->unk78 = 0.0f;
        for (index = 0; nodes[index] != 0; index++) {
            nodes[index]->unk100 &= 0xEFFFFFFF;
        }
        break;
    case 1:
        applyRange = 0;
        choice = (s32)(RANDOM_UNIT() * 5.0f);
        switch (choice) {
        case 0:
            object->unk88 = 0x1B;
            break;
        case 1:
            object->unk88 = 0x1C;
            break;
        case 2:
            object->unk88 = 0xF;
            break;
        case 3:
            object->unk88 = 0x19;
            break;
        default:
            object->unk88 = 0x1A;
            break;
        }
        break;
    case 2:
        object->unk88 = 0xF;
        applyRange = 0;
        break;
    case 3:
        object->unk88 = 0xE;
        applyRange = 0;
        break;
    case 4:
    case 5:
        object->unk88 = 0x10;
        applyRange = 0;
        break;
    case 6:
        object->unk88 = 0xB;
        applyRange = 0;
        if (oldState == 6) {
            valueB = 0.0f;
        }
        break;
    case 7:
        object->unk88 = 0x13;
        applyRange = 0;
        break;
    case 8:
        if ((f64)RANDOM_UNIT() < D_800AD1D8) {
            func_80008B14(0x31, 6, 0.25f, 0.5f, 0);
        } else {
            func_80008B14(0x32, 6, 0.25f, 0.5f, 0);
        }
        object->unk88 = 0x14;
        valueB = 0.0f;
        break;
    case 9:
        object->unk88 = 0x15;
        valueB = 0.0f;
        applyRange = 0;
        break;
    case 0xA:
        object->unk88 = 8;
        applyRange = 0;
        break;
    case 0xB:
        object->unk88 = 9;
        valueB = 0.0f;
        valueC = 0.0f;
        break;
    case 0xC:
        object->unk88 = 0xA;
        valueB = 0.0f;
        applyRange = 0;
        break;
    case 0xD:
        object->unk88 = 3;
        applyRange = 0;
        break;
    case 0xE:
        object->unk88 = 4;
        valueB = 0.0f;
        object->unk1C =
            (f32)(((f64)RANDOM_UNIT() * 4.0) + 8.0);
        break;
    case 0xF:
        object->unk88 = 5;
        applyRange = 0;
        valueB = 0.0f;
        break;
    case 0x10:
        object->unk88 = 0;
        applyRange = 0;
        break;
    case 0x13:
        valueC = 0.0f;
        if (object->unk88 == 1) {
            sendRange = 0;
        }
        object->unk88 = 1;
        break;
    case 0x14:
        func_8001535C(&delta, &object->unk50, &object->unk44);
        delta.z = 0.0f;
        if (object->unkA0 != 0) {
            angle = object->unk6C;
        } else {
            angle = func_80014F54(-delta.x, delta.y);
        }
        angleDifference = angle - object->unk68;
        if (angleDifference < -180.0f) {
            angleDifference += 360.0f;
        }
        if (angleDifference > 180.0f) {
            angleDifference -= 360.0f;
        }
        object->unk88 = 1;
        if (angleDifference > 5.0f || angleDifference < -5.0f) {
            if (angleDifference > 85.0f && angleDifference < 175.0f) {
                object->unk88 = 0xB;
                applyRange = 0;
            }
            if (angleDifference < -85.0f && angleDifference > -175.0f) {
                object->unk88 = 0xB;
                applyRange = 0;
                speed = -1.0f;
            }
            if (angleDifference > 175.0f || angleDifference < -175.0f) {
                object->unk88 = 0xC;
                applyRange = 0;
            }
        }
        valueC = 0.0f;
        if (oldState == 0x13 && object->unk88 == 1) {
            sendRange = 0;
        }
        break;
    case 0x11:
        object->unk88 = 5;
        if (func_80009524(0, 0x80000000) == 0) {
            switch (D_80118EF8) {
            case 4:
            case 7:
                if (RANDOM_UNIT() < D_800AD1E0) {
                    if (RANDOM_UNIT() <= D_800AD1E4) {
                        func_800093B0(0, D_80113E67, 1, 5, 0x12, 0xE,
                                      8);
                    } else {
                        func_800093B0(0, D_80113E67, 6, 9, 6, 9, 6);
                    }
                }
                break;
            case 8:
                if (RANDOM_UNIT() < D_800AD1E8) {
                    if (RANDOM_UNIT() < 0.5f) {
                        func_800093B0(0, D_80113E67, 0xC, 7, 5, 1,
                                      0xB);
                    } else {
                        func_800093B0(0, D_80113E67, 8, 7, 5, 3, 0xC);
                    }
                } else if (RANDOM_UNIT() < D_800AD1EC) {
                    func_800093B0(0, D_80113E67, 6, 9, 6, 9, 6);
                }
                break;
            }
        }
        break;
    case 0x12:
        choiceCount = 5;
        specialSet = 0;
        if (object->unk50.x == D_800A4C00.unk2C &&
            object->unk50.y == D_800A4C00.unk30) {
            specialSet = 1;
            choiceCount = 2;
        }
        choice = (s32)(RANDOM_UNIT() * (f32)choiceCount);
        if (choice == object->unkA4) {
            choice++;
        }
        if (choice >= choiceCount) {
            choice = 0;
        }
        object->unkA4 = choice;
        switch (choice) {
        case 0:
            object->unk88 = specialSet != 0 ? 4 : 3;
            break;
        case 1:
            object->unk88 = specialSet != 0 ? 8 : 6;
            break;
        case 2:
            object->unk88 = 7;
            break;
        case 3:
            object->unk88 = 4;
            break;
        default:
            object->unk88 = 8;
            break;
        }
        applyRange = 0;
        break;
    case 0x18:
        object->unk88 = 9;
        break;
    case 0x19:
        if ((f64)RANDOM_UNIT() < 0.75) {
            func_80060D70(0xA, 0xB, 0xC, 0xD, 0x12);
        } else {
            func_800093B0(0, D_80113E67, 2, 2, 2, 2, 2);
        }
        object->unk88 = 9;
        applyRange = 0;
        other = func_8003F800(0x456C6D6F, 0x15);
        if (other->unk14 == 0x20) {
            func_80060DE4(other, 0x25);
        } else if (other->unk14 == 0x1D) {
            func_80060DE4(other, 0x23);
        }
        break;
    case 0x1A:
        if ((f64)RANDOM_UNIT() < 0.75) {
            func_80060D70(2, 0x1F, 7, 8, 9);
        } else {
            func_800093B0(0, D_80113E67, 3, 3, 3, 5, 5);
        }
        object->unk88 = 0xA;
        applyRange = 0;
        other = func_8003F800(0x456C6D6F, 0x15);
        if (other->unk14 == 0x20) {
            func_80060DE4(other, 0x26);
        } else if (other->unk14 == 0x1D) {
            func_80060DE4(other, 0x24);
        }
        break;
    case 0x1B:
        object->unk88 = 0xD;
        scan = object->unk34;
        if (*scan != 0) {
            do {
                scan++;
            } while (*scan != 0);
        }
        break;
    case 0x1C:
        object->unk88 = 0xD;
        break;
    case 0x1D:
        if (RANDOM_UNIT() < 0.5f) {
            func_80060D70(0x30, 0x31, 0x32, 0x22, 0x2B);
        } else if (RANDOM_UNIT() < 0.5f) {
            func_80060D70(0x23, 0x24, 0x25, 0x26, 0x27);
        } else if (RANDOM_UNIT() < D_800AD204 || D_80113E67 == 2) {
            func_80060D70(0x18, 0x2E, 0x13, 0x29, 0x2B);
        } else {
            func_80060D70(0x19, 0x20, 0x2C, 0x19, 0x20);
        }
        object->unk88 = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        object->unk1C = (RANDOM_UNIT() * 2.0f) + 3.0f;
        break;
    case 0x22:
    case 0x1E:
        object->unk88 = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x1F:
        object->unk88 = 0xB;
        applyRange = 0;
        valueB = 0.0f;
        break;
    case 0x20:
        object->unk88 = 0xC;
        object->unk1C =
            (f32)(((f64)RANDOM_UNIT() * 2.0) + 3.0);
        break;
    case 0x21:
        object->unk88 = 0xF;
        applyRange = 0;
        break;
    case 0x23:
        if (RANDOM_UNIT() < 0.25f) {
            func_80060D70(0xB, 0xC, 0xD, 0x2D, 0x14);
        }
        object->unk88 = 3;
        applyRange = 0;
        break;
    case 0x24:
        if (RANDOM_UNIT() < 0.25f) {
            func_80060D70(0x12, 0x28, 0x36, 0xE, 0x17);
        }
        object->unk88 = 1;
        applyRange = 0;
        break;
    case 0x25:
        if (RANDOM_UNIT() < 0.25f) {
            func_80060D70(0xB, 0xC, 0xD, 0x2D, 0x14);
        }
        object->unk88 = 0xD;
        applyRange = 0;
        break;
    case 0x26:
        if (RANDOM_UNIT() < 0.25f) {
            func_80060D70(0x12, 0x28, 0x36, 0xE, 0x17);
        }
        object->unk88 = 0xE;
        applyRange = 0;
        break;
    case 0x27:
        if (RANDOM_UNIT() < 0.25f) {
            if (RANDOM_UNIT() < D_800AD208 || D_80113E67 == 2) {
                func_80060D70(0x2A, 0x32, 0x31, 0x33, 0x13);
            } else {
                func_80060D70(0x2C, 0x19, 0x20, 0x2C, 0x19);
            }
        }
        object->unk88 = 2;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x2B:
        object->unk88 = 0;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x2C:
        object->unk88 = 1;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x2D:
        object->unk88 = 2;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x2E:
        object->unk88 = 3;
        valueC = 0.0f;
        speed = 0.5f;
        break;
    case 0x2F:
        object->unk88 = 0;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x30:
        object->unk88 = 1;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x31:
        object->unk88 = 2;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x32:
        object->unk88 = 3;
        valueC = 0.0f;
        break;
    case 0x33:
        object->unk88 = 0;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x34:
        object->unk88 = 1;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x35:
        object->unk88 = 2;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x36:
        object->unk88 = 3;
        applyRange = 0;
        break;
    case 0x37:
        object->unk88 = 4;
        valueC = 0.0f;
        break;
    case 0x38:
        object->unk88 = 0;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x39:
        object->unk88 = 1;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x3A:
        object->unk88 = 2;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x3B:
        object->unk88 = 3;
        applyRange = 0;
        break;
    case 0x3C:
        object->unk88 = 4;
        valueC = 0.0f;
        break;
    case 0x3D:
        object->unk88 = 0;
        applyRange = 0;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x3E:
        object->unk88 = 1;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x3F:
        object->unk88 = 2;
        valueC = 0.0f;
        valueB = 0.0f;
        break;
    case 0x40:
        object->unk88 = 3;
        applyRange = 0;
        break;
    case 0x41:
        object->unk88 = 4;
        valueC = 0.0f;
        break;
    case 0x42:
        object->unk88 = 5;
        break;
    }

    if (object->unk08 == 3) {
        valueC = 0.0f;
        valueB = D_800AD20C;
    }
    rangeOffset = D_800AD210;
    if (object->unk14 != 0) {
        func_80063344(object, &lower, &upper);
        rangeOffset = D_800AD214;
        valueA = lower;
    }
    if (object->unk14 == 0x1B && object->unk88 != 0xD) {
        upper = lower + rangeOffset;
    }
    if (speed < 0.0f) {
        valueA = upper - rangeOffset;
    }
    if (object->unk14 == 5) {
        valueA = upper - rangeOffset;
        lower = valueA;
    }
    if (object->unk14 == 0x2A) {
        valueC = 0.0f;
    }
    if (sendRange != 0) {
        func_8003398C(object->unk34, valueA, lower, upper, applyRange,
                      valueB, valueC);
    }
    if (speed != object->unk78) {
        object->unk78 = speed;
        func_80033928(object->unk34, speed);
    }
}

#undef RANDOM_UNIT
