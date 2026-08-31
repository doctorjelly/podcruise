/* Independently written from specs/functions/recovered/func_80018480.md. */

#include "podcruise/vector_math.h"

typedef f32 Matrix80018480[4][4];

typedef struct TypeGeometry80018480 {
    /* 0x00 */ PcVec3f center;
    /* 0x0C */ PcVec3f attachment;
    /* 0x18 */ u8 pad18[0x0C];
    /* 0x24 */ PcVec3f firstEndpoint;
    /* 0x30 */ PcVec3f secondEndpoint;
    /* 0x3C */ u8 pad3C[0x30];
} TypeGeometry80018480;

typedef struct Object80018480 {
    /* 0x000 */ void *primary[6];
    /* 0x018 */ void *beam[8];
    /* 0x038 */ u8 pad038[0xB4];
    /* 0x0EC */ void *overlay;
    /* 0x0F0 */ s32 type;
    /* 0x0F4 */ u8 pad0F4[4];
    /* 0x0F8 */ void *primaryF8;
    /* 0x0FC */ void *primaryFC;
    /* 0x100 */ void *primary100;
    /* 0x104 */ u8 pad104[0x24];
    /* 0x128 */ void *primary128;
} Object80018480;

extern s32 D_8009B7D8;
extern s32 D_800A21AC;
extern f32 D_800A2358[];
extern f32 D_800A2368[];
extern f32 D_800A31FC[];
extern u8 D_800A3204[];
extern TypeGeometry80018480 D_800A5CA0[];
extern PcVec3f D_800A6654;
extern f64 D_800A9AD0;
extern f64 D_800A9AD8;
extern f64 D_800A9AE0;
extern f64 D_800A9AE8;
extern f32 D_800A9AF0;
extern f32 D_800A9AF4;
extern f32 D_800A9AF8;
extern f32 D_800A9AFC;
extern f32 D_800A9B00;
extern f32 D_800A9B04;
extern f32 D_800A9B08;
extern f32 D_800A9B0C;
extern f32 D_800A9B10;
extern f32 D_800A9B14;
extern f32 D_800A9B18;
extern f32 D_800A9B1C;
extern f32 D_800A9B20;
extern f32 D_800A9B24;
extern f32 D_800A9B28;
extern f32 D_800A9B2C;
extern f32 D_800A9B30;
extern f32 D_800A9B34;
extern f32 D_800A9B38;
extern f32 D_800A9B3C;
extern s32 D_800D76F4;
extern f64 D_80120C00;

extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);
extern f32 func_800154D0(PcVec3f *vector);
extern void func_80015538(PcVec3f *output, const PcVec3f *left,
                          const PcVec3f *right);
extern void func_800155EC(PcVec3f *output, const PcVec3f *base, f32 scale,
                          const PcVec3f *offset);
extern void func_80016BF4(PcVec3f *output, const PcVec3f *vector,
                          Matrix80018480 transform);
extern void func_80017520(Matrix80018480 matrix, f32 x, f32 y, f32 z);
extern void func_80017580(Matrix80018480 matrix, f32 x, f32 y, f32 z);
extern void func_80017824(Matrix80018480 matrix, f32 amount, f32 x, f32 y,
                          f32 z, s32 mode);
extern void func_80017918(Matrix80018480 destination, f32 x, f32 y, f32 z,
                          Matrix80018480 source);
extern void func_80017BA8(void *destination, const void *source);
extern void func_80017C18(const void *source, Matrix80018480 destination);
extern void func_80017D48(void *object, s32 value);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags,
                         s32 mode);
extern void func_80029494(void);
extern void func_80076180(void *owner, Object80018480 *object, f32 requestX,
                          f32 requestY);
extern void func_800833B4(void *object, f32 *values);
extern void func_800834F0(void *node, void *first, void *second, f32 phase,
                          f32 scale, f32 offset, f32 length, s32 mode);

#define NODE_WORD(node, offset) (*(u32 *)((u8 *)(node) + (offset)))
#define STRIDED_FLOAT(base, index) (*(f32 *)((u8 *)(base) + (index) * 0x34))
#define STRIDED_BYTE(base, index) (*(u8 *)((u8 *)(base) + (index) * 0x34))

void func_80018480(Object80018480 *object, Matrix80018480 source, s32 scaleByType,
                   f32 scaleX, f32 scaleY, f32 scaleZ, f32 depth, s32 animate,
                   f32 requestX, f32 requestY) {
    Matrix80018480 base;
    Matrix80018480 work;
    Matrix80018480 firstMatrix;
    Matrix80018480 secondMatrix;
    Matrix80018480 beamMatrix;
    PcVec3f firstVector;
    PcVec3f secondVector;
    PcVec3f firstPoint;
    PcVec3f secondPoint;
    PcVec3f firstOffset;
    PcVec3f secondOffset;
    PcVec3f direction;
    PcVec3f firstZero;
    PcVec3f secondZero;
    f32 sine[8];
    f32 cosine[8];
    f32 typeScale;
    f32 length;
    f32 phase;
    TypeGeometry80018480 *geometry;
    void *node;
    s32 index;
    s32 type;

    if (object == 0) {
        return;
    }

    type = object->type;
    geometry = &D_800A5CA0[type];

    if (animate != 0) {
        for (index = 0; index < 8; index++) {
            func_80014CC0(
                (f32)((f64)(f32)D_80120C00 * D_800A9AD0
                      * (D_800A9AE0 + D_800A9AD8 * (f64)index)),
                &sine[index], &cosine[index]);
        }
    }

    if (scaleByType != 0) {
        typeScale = STRIDED_FLOAT(D_800A31FC, type);
        if ((f64)typeScale < D_800A9AE8 || typeScale > 5.0f) {
            typeScale = 1.0f;
        }
        scaleX *= typeScale;
        scaleY *= typeScale;
        scaleZ *= typeScale;
    }

    func_800833B4(object->primary[5], D_800A2358);
    func_800833B4(object->primary[1], D_800A2368);
    func_800833B4(object->primary[2], D_800A2368);
    func_800833B4(object->primary[3], D_800A2368);
    func_800833B4(object->primary[4], D_800A2368);

    if (object->primaryF8 != 0) {
        NODE_WORD(object->primaryF8, 0x10) |= 1;
    }
    if (object->primary[2] != 0) {
        NODE_WORD(object->primary[2], 0x10) |= 1;
    }
    if (object->primary[4] != 0) {
        NODE_WORD(object->primary[4], 0x10) |= 1;
    }

    func_800156DC((PcVec3fSlot *)base, (PcVec3fSlot *)source);
    func_80017918(work, scaleX, scaleY, scaleZ, base);

    node = object->primary[0];
    if (node != 0) {
        func_80017D48(node, 0);
        func_800181BC(node, 2, 3, 0x10, 2);
    }

    if ((D_8009B7D8 & 0x80) != 0 && (D_800D76F4 & 0x400) != 0) {
        node = object->primary[0];
        if (node != 0) {
            func_80017D48(node, 1);
            func_800181BC(node, 2, 3, 0x10, 2);
        }

        node = object->primary128;
        if (node != 0) {
            func_800156DC((PcVec3fSlot *)work, (PcVec3fSlot *)base);
            func_80017918(work, D_800A9AF0, D_800A9AF0, D_800A9AF0, work);
            if (animate != 0) {
                func_800155EC((PcVec3f *)work[3], (PcVec3f *)work[3],
                              sine[3] * D_800A9AF4, (PcVec3f *)work[2]);
            }
            func_80017BA8(node, work);
            func_800181BC(node, 2, 3, 0x10, 2);
        }
    } else {
        node = object->primary[1];
        if (node != 0) {
            func_800156DC((PcVec3fSlot *)work, (PcVec3fSlot *)base);
            func_80015288(&firstVector, &geometry->attachment);
            func_80016BF4(&secondVector, &firstVector, work);
            func_80015328((PcVec3f *)work[3], (PcVec3f *)work[3], &secondVector);
            if (animate != 0) {
                func_800155EC((PcVec3f *)work[3], (PcVec3f *)work[3],
                              sine[3] * D_800A9AF8, (PcVec3f *)work[2]);
                func_80015288(&secondVector, (PcVec3f *)work[1]);
                func_800154D0(&secondVector);
                func_80017824(work, sine[1] * 5.0f, secondVector.x,
                              secondVector.y, secondVector.z, 0);
            }
            func_80017BA8(node, work);
            func_800181BC(node, 2, 3, 0x10, 2);

            node = object->primary[3];
            if (node != 0) {
                func_80015288(&firstVector, &D_800A6654);
                func_80016BF4(&secondVector, &firstVector, base);
                func_80015328((PcVec3f *)work[3], (PcVec3f *)work[3],
                              &secondVector);
                if (animate != 0) {
                    func_800155EC((PcVec3f *)work[3], (PcVec3f *)work[3],
                                  sine[3] * D_800A9AFC, (PcVec3f *)work[2]);
                    func_80015288(&secondVector, (PcVec3f *)work[1]);
                    func_800154D0(&secondVector);
                    func_80017824(work, sine[1] * 5.0f, secondVector.x,
                                  secondVector.y, secondVector.z, 0);
                }
                func_80017BA8(node, work);
                func_800181BC(node, 2, 3, 0x10, 2);
            }

            node = object->primaryF8;
            if (node != 0) {
                func_80015288(&secondVector, (PcVec3f *)work[3]);
                func_80017520(work, scaleX, scaleY, scaleZ);
                func_80015288((PcVec3f *)work[3], &secondVector);
                work[3][2] = depth;
                func_80017918(work, D_800A9B00, D_800A9B00, D_800A9B00,
                              work);
                func_80017BA8(node, work);
                func_800181BC(node, 2, 3, 0x10, 2);
            }
        }

        node = object->primary[2];
        if (node != 0) {
            func_800156DC((PcVec3fSlot *)work, (PcVec3fSlot *)base);
            func_80015288(&firstVector, &geometry->attachment);
            firstVector.x = -firstVector.x;
            func_80016BF4(&secondVector, &firstVector, work);
            func_80015328((PcVec3f *)work[3], (PcVec3f *)work[3], &secondVector);
            if (animate != 0) {
                func_800155EC((PcVec3f *)work[3], (PcVec3f *)work[3],
                              sine[4] * D_800A9B04, (PcVec3f *)work[2]);
                func_80015288(&secondVector, (PcVec3f *)work[1]);
                func_800154D0(&secondVector);
                func_80017824(work, sine[2] * 5.0f, secondVector.x,
                              secondVector.y, secondVector.z, 0);
            }
            func_80017BA8(node, work);
            func_800181BC(node, 2, 3, 0x10, 2);

            node = object->primary[4];
            if (node != 0) {
                func_80015288(&firstVector, &D_800A6654);
                firstVector.x = -firstVector.x;
                func_80016BF4(&secondVector, &firstVector, base);
                func_80015328((PcVec3f *)work[3], (PcVec3f *)work[3],
                              &secondVector);
                if (animate != 0) {
                    func_800155EC((PcVec3f *)work[3], (PcVec3f *)work[3],
                                  sine[2] * D_800A9B08, (PcVec3f *)work[2]);
                    func_80015288(&secondVector, (PcVec3f *)work[1]);
                    func_800154D0(&secondVector);
                    func_80017824(work, sine[0] * 5.0f, secondVector.x,
                                  secondVector.y, secondVector.z, 0);
                }
                func_80017BA8(node, work);
                func_800181BC(node, 2, 3, 0x10, 2);
            }

            node = object->primaryFC;
            if (node != 0) {
                func_80015288(&secondVector, (PcVec3f *)work[3]);
                func_80017520(work, scaleX, scaleY, scaleZ);
                func_80015288((PcVec3f *)work[3], &secondVector);
                work[3][2] = depth;
                func_80017918(work, D_800A9B0C, D_800A9B0C, D_800A9B0C,
                              work);
                func_80017BA8(node, work);
                func_800181BC(node, 2, 3, 0x10, 2);
            }
        }

        node = object->primary[5];
        if (node != 0) {
            func_800156DC((PcVec3fSlot *)work, (PcVec3fSlot *)base);
            func_80015288(&firstVector, &geometry->center);
            func_80016BF4(&secondVector, &firstVector, work);
            func_80015328((PcVec3f *)work[3], (PcVec3f *)work[3], &secondVector);
            if (animate != 0) {
                work[3][2] = (f32)STRIDED_BYTE(D_800A3204, type) * 10.0f
                             + depth + 1.5f * scaleZ;
                func_800155EC((PcVec3f *)work[3], (PcVec3f *)work[3],
                              sine[5] * D_800A9B10, (PcVec3f *)work[2]);
                func_80015288(&secondVector, (PcVec3f *)work[1]);
                func_800154D0(&secondVector);
                func_80017824(work, sine[1] * 10.0f, secondVector.x,
                              secondVector.y, secondVector.z, 0);
            }
            func_80017BA8(node, work);
            func_800181BC(node, 2, 3, 0x10, 2);

            if (firstVector.y == 0.0f) {
                if (object->primary[1] != 0) {
                    func_80017BA8(object->primary[1], work);
                }
                if (object->primary[2] != 0) {
                    func_80017BA8(object->primary[2], work);
                }
            }

            node = object->primary100;
            if (node != 0) {
                func_80015288(&secondVector, (PcVec3f *)work[3]);
                func_80017520(work, scaleX, scaleY, scaleZ);
                func_80015288((PcVec3f *)work[3], &secondVector);
                work[3][2] = depth;
                func_80017918(work, 0.004f, 0.004f, 0.004f, work);
                func_80017BA8(node, work);
                func_800181BC(node, 2, 3, 0x10, 2);
            }
        }

        func_80076180(0, object, requestX, requestY);

        if (object->beam[0] != 0) {
            func_800181BC(object->beam[0], 2, 0xFFFFFFFC, 0x10, 3);
        }
        if (object->beam[1] != 0) {
            func_800181BC(object->beam[1], 2, 0xFFFFFFFC, 0x10, 3);
        }
        if (object->beam[2] != 0) {
            func_800181BC(object->beam[2], 2, 0xFFFFFFFC, 0x10, 3);
        }
        if (object->beam[3] != 0) {
            func_800181BC(object->beam[3], 2, 0xFFFFFFFC, 0x10, 3);
        }
        if (object->beam[4] != 0) {
            func_800181BC(object->beam[4], 2, 0xFFFFFFFC, 0x10, 3);
        }
        if (object->beam[5] != 0) {
            func_800181BC(object->beam[5], 2, 0xFFFFFFFC, 0x10, 3);
        }
        if (object->beam[6] != 0) {
            func_800181BC(object->beam[6], 2, 0xFFFFFFFC, 0x10, 3);
        }
        if (object->beam[7] != 0) {
            func_800181BC(object->beam[7], 2, 0xFFFFFFFC, 0x10, 3);
        }

        if (D_800A21AC > 0) {
            D_800A21AC--;
        }

        node = object->beam[4];
        if (node != 0) {
            func_80017C18(object->primary[5], secondMatrix);
            func_80015288(&firstPoint, (PcVec3f *)secondMatrix[3]);
            func_80017C18(object->primary[1], firstMatrix);
            func_80015288(&secondPoint, (PcVec3f *)firstMatrix[3]);
            func_80015288(&firstOffset, &geometry->firstEndpoint);
            func_80016BF4(&firstOffset, &firstOffset, secondMatrix);
            func_80015328(&firstPoint, &firstOffset, &firstPoint);
            func_80015288(&secondOffset, &geometry->secondEndpoint);
            func_80016BF4(&secondOffset, &secondOffset, firstMatrix);
            func_80015328(&secondPoint, &secondOffset, &secondPoint);
            func_8001535C(&direction, &firstPoint, &secondPoint);
            length = func_800153C0(&direction);
            func_800154D0(&direction);
            func_80017580(beamMatrix, firstPoint.x, firstPoint.y, firstPoint.z);
            func_80015288((PcVec3f *)beamMatrix[1], &direction);
            func_80015268((PcVec3f *)beamMatrix[2], 0.0f, 0.0f, 1.0f);
            func_80015538((PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1],
                          (PcVec3f *)beamMatrix[2]);
            func_80015538((PcVec3f *)beamMatrix[2],
                          (PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1]);
            func_80017918(beamMatrix, D_800A9B14 * scaleX, length / 100.0f,
                          D_800A9B14 * scaleZ, beamMatrix);
            func_80017BA8(node, beamMatrix);
            if (D_800A21AC > 0) {
                func_80015268(&secondZero, 0.0f, 0.0f, 0.0f);
                func_80015268(&firstZero, 0.0f, 0.0f, 0.0f);
                phase = animate != 0 ? D_800A9B18 : 0.5f;
                func_800834F0(node, &secondZero, &firstZero, phase, 1.0f,
                              0.0f, 50.0f, 0);
            }
            func_800181BC(node, 2, 3, 0x10, 2);
        }

        node = object->beam[5];
        if (node != 0) {
            func_80017C18(object->primary[5], secondMatrix);
            func_80015288(&firstPoint, (PcVec3f *)secondMatrix[3]);
            func_80017C18(object->primary[2], firstMatrix);
            func_80015288(&secondPoint, (PcVec3f *)firstMatrix[3]);
            func_80015288(&firstOffset, &geometry->firstEndpoint);
            firstOffset.x = -firstOffset.x;
            func_80016BF4(&firstOffset, &firstOffset, secondMatrix);
            func_80015328(&firstPoint, &firstOffset, &firstPoint);
            func_80015288(&secondOffset, &geometry->secondEndpoint);
            secondOffset.x = -secondOffset.x;
            func_80016BF4(&secondOffset, &secondOffset, firstMatrix);
            func_80015328(&secondPoint, &secondOffset, &secondPoint);
            func_8001535C(&direction, &firstPoint, &secondPoint);
            length = func_800153C0(&direction);
            func_800154D0(&direction);
            func_80017580(beamMatrix, firstPoint.x, firstPoint.y, firstPoint.z);
            func_80015288((PcVec3f *)beamMatrix[1], &direction);
            func_80015268((PcVec3f *)beamMatrix[2], 0.0f, 0.0f, 1.0f);
            func_80015538((PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1],
                          (PcVec3f *)beamMatrix[2]);
            func_80015538((PcVec3f *)beamMatrix[2],
                          (PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1]);
            func_80017918(beamMatrix, D_800A9B1C * scaleX, length / 100.0f,
                          D_800A9B20 * scaleZ, beamMatrix);
            func_80017BA8(node, beamMatrix);
            if (D_800A21AC > 0) {
                func_80015268(&secondZero, 0.0f, 0.0f, 0.0f);
                func_80015268(&firstZero, 0.0f, 0.0f, 0.0f);
                phase = animate != 0 ? D_800A9B24 : 0.5f;
                func_800834F0(node, &secondZero, &firstZero, phase, 1.0f,
                              0.0f, 50.0f, 0);
            }
            func_800181BC(node, 2, 3, 0x10, 2);
        }

        node = object->beam[6];
        if (node != 0) {
            func_80017C18(object->primary[5], secondMatrix);
            func_80015288(&firstPoint, (PcVec3f *)secondMatrix[3]);
            func_80017C18(object->primary[3], firstMatrix);
            func_80015288(&secondPoint, (PcVec3f *)firstMatrix[3]);
            func_80015288(&firstOffset, &geometry->firstEndpoint);
            func_80016BF4(&firstOffset, &firstOffset, secondMatrix);
            func_80015328(&firstPoint, &firstOffset, &firstPoint);
            func_80015288(&secondOffset, &geometry->secondEndpoint);
            func_80016BF4(&secondOffset, &secondOffset, firstMatrix);
            func_80015328(&secondPoint, &secondOffset, &secondPoint);
            func_8001535C(&direction, &firstPoint, &secondPoint);
            length = func_800153C0(&direction);
            func_800154D0(&direction);
            func_80017580(beamMatrix, firstPoint.x, firstPoint.y, firstPoint.z);
            func_80015288((PcVec3f *)beamMatrix[1], &direction);
            func_80015268((PcVec3f *)beamMatrix[2], 0.0f, 0.0f, 1.0f);
            func_80015538((PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1],
                          (PcVec3f *)beamMatrix[2]);
            func_80015538((PcVec3f *)beamMatrix[2],
                          (PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1]);
            func_80017918(beamMatrix, D_800A9B28 * scaleX, length / 100.0f,
                          D_800A9B2C * scaleZ, beamMatrix);
            func_80017BA8(node, beamMatrix);
            if (D_800A21AC > 0) {
                func_80015268(&secondZero, 0.0f, 0.0f, 0.0f);
                func_80015268(&firstZero, 0.0f, 0.0f, 0.0f);
                phase = animate != 0 ? D_800A9B30 : 0.5f;
                func_800834F0(node, &secondZero, &firstZero, phase, 1.0f,
                              0.0f, 50.0f, 0);
            }
            func_800181BC(node, 2, 3, 0x10, 2);
        }

        node = object->beam[7];
        if (node != 0) {
            func_80017C18(object->primary[5], secondMatrix);
            func_80015288(&firstPoint, (PcVec3f *)secondMatrix[3]);
            func_80017C18(object->primary[4], firstMatrix);
            func_80015288(&secondPoint, (PcVec3f *)firstMatrix[3]);
            func_80015288(&firstOffset, &geometry->firstEndpoint);
            firstOffset.x = -firstOffset.x;
            func_80016BF4(&firstOffset, &firstOffset, secondMatrix);
            func_80015328(&firstPoint, &firstOffset, &firstPoint);
            func_80015288(&secondOffset, &geometry->secondEndpoint);
            secondOffset.x = -secondOffset.x;
            func_80016BF4(&secondOffset, &secondOffset, firstMatrix);
            func_80015328(&secondPoint, &secondOffset, &secondPoint);
            func_8001535C(&direction, &firstPoint, &secondPoint);
            length = func_800153C0(&direction);
            func_800154D0(&direction);
            func_80017580(beamMatrix, firstPoint.x, firstPoint.y, firstPoint.z);
            func_80015288((PcVec3f *)beamMatrix[1], &direction);
            func_80015268((PcVec3f *)beamMatrix[2], 0.0f, 0.0f, 1.0f);
            func_80015538((PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1],
                          (PcVec3f *)beamMatrix[2]);
            func_80015538((PcVec3f *)beamMatrix[2],
                          (PcVec3f *)beamMatrix[0],
                          (PcVec3f *)beamMatrix[1]);
            func_80017918(beamMatrix, D_800A9B34 * scaleX, length / 100.0f,
                          D_800A9B38 * scaleZ, beamMatrix);
            func_80017BA8(node, beamMatrix);
            if (D_800A21AC > 0) {
                func_80015268(&secondZero, 0.0f, 0.0f, 0.0f);
                func_80015268(&firstZero, 0.0f, 0.0f, 0.0f);
                phase = animate != 0 ? D_800A9B3C : 0.5f;
                func_800834F0(node, &secondZero, &firstZero, phase, 1.0f,
                              0.0f, 50.0f, 0);
            }
            func_800181BC(node, 2, 3, 0x10, 2);
        }

        if (D_800A21AC == 4) {
            func_80029494();
        }

        if (object->overlay != 0) {
            func_800181BC(object->overlay, 2, 0xFFFFFFFC, 0x10, 3);
        }
        if ((D_8009B7D8 & 0x80) != 0 && (D_800D76F4 & 0x1000) != 0
            && object->overlay != 0) {
            func_800181BC(object->overlay, 2, 3, 0x10, 2);
        }
    }
}

#undef STRIDED_FLOAT
#undef STRIDED_BYTE
#undef NODE_WORD
