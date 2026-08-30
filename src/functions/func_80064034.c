/* Independently written from specs/functions/recovered/func_80064034.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef f32 Matrix80064034[4][4];

typedef struct {
    u8 unk00[0x30];
    void **nodes;
    u8 unk34[0x60];
    f32 scale94;
} Resource80064034;

extern f32 D_800A5B40;
extern s32 D_800A5B3C;
extern PcVec3f D_800A5080;
extern f32 D_800AD428;
extern f32 D_800AD42C;
extern f32 D_800AD430;
extern PcVec3f D_80118D90;
extern PcVec3f D_80118E50;
extern f32 D_8011A240;
extern s32 D_8011A244;
extern s32 D_8011A248;
extern f32 D_8011A24C;
extern PcVec3f D_8011C800;
extern PcVec3f D_8011C810;
extern PcVec3f D_8011C820;
extern PcVec3f D_8011C830;
extern f32 D_80120BF8;

extern void func_8000EA4C(void *, s32, s32, s32, s32, s32, s32);
extern void *func_8000E8C4(void *);
extern void func_8001745C(Matrix80064034, f32, f32, f32);
extern void func_80017874(Matrix80064034);
extern void func_80017918(Matrix80064034, f32, f32, f32,
                          Matrix80064034);
extern void func_80017BA8(void *, Matrix80064034);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_80033780(void *, f32, f32);
extern void func_80033878(void *, PcVec3f *);
extern void func_8003E0A0(void *, f32, f32);
extern Resource80064034 *func_8003F800(u32, s32);
extern void func_80064A48(PcVec3f *, Resource80064034 *, s32);
extern s32 func_80082BE0(void);
extern void func_80082C80(void *, Matrix80064034 *, void *,
                          Matrix80064034 *);
extern void func_80086A20(s32, PcVec3f *, PcVec3f *, PcVec3f *);

void func_80064034(s32 selection) {
    PcVec3f lightAmbient;
    PcVec3f lightDiffuse;
    PcVec3f lightDirection;
    PcVec3f direction;
    PcVec3f ambientStart;
    PcVec3f diffuseStart;
    PcVec3f directionStart;
    PcVec3f ambientEnd;
    PcVec3f diffuseEnd;
    Matrix80064034 transform;
    Matrix80064034 markerTransform;
    Resource80064034 *resource;
    Resource80064034 *marker;
    void **nodes;
    void *node;
    void *effect;
    void *scroll;
    f32 phase;
    f32 firstScale;
    f32 angle;
    f32 progress;
    f32 modelProgress;
    f32 finalProgress;
    f32 scale;
    s32 randomValue;

    phase = D_8011A240;
    modelProgress = 0.0f;
    if (D_8011A244 == 0) {
        phase = 0.0f;
    }

    ambientStart.x = 80.0f;
    ambientStart.y = 75.0f;
    ambientStart.z = 50.0f;
    diffuseStart.x = 235.0f;
    diffuseStart.y = 100.0f;
    diffuseStart.z = 0.0f;
    directionStart.x = 0.0f;
    directionStart.y = -100.0f;
    directionStart.z = 400.0f;
    ambientEnd.x = 20.0f;
    ambientEnd.y = 65.0f;
    ambientEnd.z = 40.0f;
    diffuseEnd.x = 255.0f;
    diffuseEnd.y = 255.0f;
    diffuseEnd.z = 200.0f;

    func_8001535C(&direction, &D_80118E50, &D_80118D90);
    firstScale = (f32)(1.0 - (f64)phase);
    func_80015630(&lightAmbient, firstScale, &ambientStart, phase,
                  &ambientEnd);
    func_80015630(&lightDiffuse, firstScale, &diffuseStart, phase,
                  &diffuseEnd);
    func_80015630(&lightDirection, firstScale, &directionStart, phase,
                  &direction);
    func_80086A20(-1, &lightAmbient, &lightDiffuse, &lightDirection);

    progress = D_8011A240;
    resource = func_8003F800(0x456C6D6F, 4);
    if (D_800A5B3C == -1) {
        D_800A5B3C = selection;
        func_80064A48(&D_8011C800, resource, 2);
        func_80064A48(&D_8011C810, resource, 8);
        func_80064A48(&D_8011C830, resource, 4);
        func_80064A48(&D_8011C820, resource, 5);
    }

    angle = D_800A5B40 + 9.0f * D_80120BF8;
    if (angle > 360.0f) {
        angle -= 360.0f;
    }
    if (progress == 0.0f) {
        angle = 0.0f;
    }
    D_800A5B40 = angle;
    nodes = resource->nodes;

    node = nodes[2];
    if (node != 0) {
        if (D_8011A244 == 0) {
            progress = 0.0f;
        }
        func_8001745C(transform, angle, 0.0f, 0.0f);
        func_80017918(transform, 1.5f, 1.5f, 1.5f, transform);
        if (progress < 0.5f) {
            func_80017918(transform, D_800AD428, D_800AD428,
                          progress + progress, transform);
        } else {
            scale = (progress - 0.5f) + (progress - 0.5f);
            func_80017918(transform, scale, scale, 1.0f, transform);
        }
        func_80015288((PcVec3f *)transform[3], &D_8011C800);
        func_80017BA8(node, transform);
        randomValue = (s32)((f32)func_80082BE0() / 2147483648.0f * 24.0f
                            + 8.0f);
        func_8000EA4C(node, 0, 0, 0, 0xFF, 0, randomValue);
        scroll = func_8000E8C4(node);
        if (scroll != 0) {
            func_8003E0A0(scroll, D_800AD42C, D_800AD42C);
        }
        if (progress > 0.0f) {
            func_800181BC(node, 2, 3, 0x10, 2);
        } else {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
    }

    node = nodes[8];
    if (node != 0) {
        if (D_8011A248 == 0) {
            progress = 0.0f;
        }
        func_8001745C(transform, angle, 0.0f, 0.0f);
        func_80017918(transform, 1.5f, 1.5f, 1.5f, transform);
        if (progress < 0.5f) {
            func_80017918(transform, 0.1f, 0.1f, progress + progress,
                          transform);
        } else {
            scale = (progress - 0.5f) + (progress - 0.5f);
            func_80017918(transform, scale, scale, 1.0f, transform);
        }
        func_80015288((PcVec3f *)transform[3], &D_8011C810);
        func_80017BA8(node, transform);
        randomValue = (s32)((f32)func_80082BE0() / 2147483648.0f * 24.0f
                            + 8.0f);
        func_8000EA4C(node, 0, 0, 0, 0xFF, 0, randomValue);
        scroll = func_8000E8C4(node);
        if (scroll != 0) {
            func_8003E0A0(scroll, D_800AD430, D_800AD430);
        }
        if (progress > 0.0f) {
            func_800181BC(node, 2, 3, 0x10, 2);
        } else {
            func_800181BC(node, 2, -4, 0x10, 3);
        }
    }

    if (D_8011A248 != 0) {
        modelProgress = D_8011A240;
    }
    node = nodes[5];
    if (node != 0) {
        func_80017874(transform);
        func_80015288((PcVec3f *)transform[3], &D_8011C820);
        transform[3][2] -= 117.0f * (1.0f - modelProgress);
        func_80017BA8(node, transform);

        effect = nodes[6];
        if (effect != 0) {
            if (modelProgress > 0.0f) {
                randomValue = (s32)((f32)func_80082BE0() /
                                    2147483648.0f * 24.0f + 8.0f);
                func_8000EA4C(effect, 0, 0, 0, 0xFF, 0, randomValue);
                scroll = func_8000E8C4(effect);
                if (scroll != 0) {
                    func_8003E0A0(scroll, 0.11f, 0.11f);
                }
                func_800181BC(effect, 2, 3, 0x10, 2);
            } else {
                func_800181BC(effect, 2, -4, 0x10, 3);
            }
        }

        marker = func_8003F800(0x456C6D6F, 0x1C);
        func_80017874(markerTransform);
        func_80082C80(nodes[5], &markerTransform, nodes[0],
                      &markerTransform);
        markerTransform[3][2] += 10.0f;
        if (modelProgress == 1.0f) {
            func_80015630((PcVec3f *)markerTransform[3], 0.75f,
                          &D_800A5080, 0.25f,
                          (PcVec3f *)markerTransform[3]);
            modelProgress *= 0.25f;
        }
        func_80033878(marker->nodes, (PcVec3f *)markerTransform[3]);
        func_80033780(marker->nodes, marker->scale94 * modelProgress,
                      angle * 4.0f);
    }

    finalProgress = D_8011A24C;
    node = nodes[4];
    if (node != 0) {
        func_80017874(transform);
        func_80015288((PcVec3f *)transform[3], &D_8011C830);
        transform[3][2] -= 117.0f * (1.0f - finalProgress);
        func_80017BA8(node, transform);

        effect = nodes[7];
        if (effect != 0) {
            if (finalProgress > 0.0f) {
                randomValue = (s32)((f32)func_80082BE0() /
                                    2147483648.0f * 24.0f + 8.0f);
                func_8000EA4C(effect, 0, 0, 0, 0xFF, 0, randomValue);
                scroll = func_8000E8C4(effect);
                if (scroll != 0) {
                    func_8003E0A0(scroll, 0.11f, 0.11f);
                }
                func_800181BC(effect, 2, 3, 0x10, 2);
            } else {
                func_800181BC(effect, 2, -4, 0x10, 3);
            }
        }
    }
}
