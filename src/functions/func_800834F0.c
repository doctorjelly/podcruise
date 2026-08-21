/* Recovered from specification specs/func_800834F0.md (scratchpad). */
#include "podcruise/types.h"

typedef struct Vertex {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
} Vertex;

typedef struct Command {
    u32 w0;
    u32 w1;
} Command;

typedef struct Mesh {
    u8 unk00[0x30];
    Command *commands;
    Vertex *vertices;
} Mesh;

typedef struct Node {
    u8 unk00[0x18];
    void **children;
} Node;

extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);
extern s32 func_80017DA4(Node *node);
extern s32 func_80017DAC(Node *node);

extern Vertex D_800A6808[6];
extern Command D_800A6868[6];
extern s32 D_800A6890;
extern f64 D_800ADD10;
extern f64 D_800ADD18;
extern f64 D_800ADD20;
extern f64 D_800ADD28;
extern f64 D_800ADD30;
extern f32 D_80120C40[64];

void func_800834F0(Node *node, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5,
                   f32 arg6, s32 arg7) {
    f32 scratch;
    s32 steps;
    Mesh *mesh;
    Vertex *vertex;
    Command *command;
    f32 factor;
    f32 ratio;
    f32 fraction;
    f32 value;
    f32 limit;
    f64 amplitude;
    s32 flags;
    s32 children;
    s32 segments;
    s32 commandCount;
    s32 total;
    s32 offset;
    s32 height;
    s32 index;
    s32 i;
    s32 j;
    s32 i0;
    s32 i1;
    s32 i2;
    s32 i3;
    s32 i4;
    s32 i5;
    s16 keep;

    if (D_800A6890 == 0) {
        steps = 0x40;
        for (i = 0; i != steps; i++) {
            func_80014CC0(((f32)i * 360.0f) / (f32)64.0, &D_80120C40[i], &scratch);
        }
        D_800A6890 = 1;
    }

    flags = func_80017DA4(node);
    if ((flags & 0x4000) != 0) {
        children = func_80017DAC(node);
        for (i = 0; i < children; i++) {
            func_800834F0((Node *)node->children[i], arg1, arg2, arg3, arg4,
                          arg5, arg6, arg7);
        }
        return;
    }
    if (flags != 0x3064) {
        return;
    }

    mesh = (Mesh *)node->children[0];
    vertex = mesh->vertices;
    command = mesh->commands;

    if (arg6 <= arg5) {
        factor = 0.0f;
    } else {
        ratio = arg5 / arg6;
        factor = 1.0f - ratio * ratio;
    }

    commandCount = 6;
    segments = 8;

    if (factor < D_800ADD10) {
        for (i = 0; i < 6; i++) {
            vertex[i] = D_800A6808[i];
        }
        command[0].w0 = 0x0100600C;
        command[0].w1 = (u32)(unsigned long)mesh->vertices;
        for (i = 1; i < commandCount; i++) {
            command[i] = D_800A6868[i];
        }
        return;
    }

    for (i = 0; i < segments; i++) {
        vertex[0] = D_800A6808[0];
        vertex[1] = D_800A6808[1];
        vertex[2] = D_800A6808[2];
        vertex += 3;
    }
    vertex[0] = D_800A6808[3];
    vertex[1] = D_800A6808[4];
    vertex[2] = D_800A6808[5];

    if (segments >= 2) {
        amplitude = (f64)(arg4 * factor) * -100.0;
        limit = (f32)segments;
        vertex = mesh->vertices + 3;
        for (i = 1; i < segments; i++) {
            fraction = (f32)i / limit;
            value = fraction;
            if (segments == 8) {
                if (D_800ADD30 < (f64)fraction && (f64)fraction < D_800ADD28) {
                    value = (fraction - 0.25f) * 0.75f + 0.25f;
                } else if (D_800ADD20 < (f64)fraction &&
                           (f64)fraction < D_800ADD18) {
                    value = (fraction - 0.75f) * 0.75f + 0.75f;
                }
            }
            index = (s32)((f64)(value * 64.0f) + 0.5);
            offset = (s32)((f64)D_80120C40[index] * amplitude);
            height = (s32)((f64)value * -100.0);
            for (j = 0; j < 3; j++) {
                keep = vertex->unk00;
                vertex->unk02 = height;
                vertex->unk04 = vertex->unk04 + offset;
                vertex->unk00 = keep;
                vertex++;
            }
        }
    }

    total = segments * 3 + 3;
    command[0].w1 = (u32)(unsigned long)mesh->vertices;
    command[0].w0 = (((u32)total & 0xFF) << 12) | 0x01000000 |
                    (((u32)total & 0x7F) << 1);
    command++;
    if (segments > 0) {
        i0 = 0;
        i1 = 2;
        i2 = 4;
        i3 = 6;
        i4 = 8;
        i5 = 10;
        for (i = 0; i < segments; i++) {
            command[0].w0 = ((((u32)i5 & 0xFF) << 16) | (((u32)i0 & 0xFF) << 8) |
                             ((u32)i2 & 0xFF)) | 0x06000000;
            command[0].w1 = (((u32)i0 & 0xFF) << 16) | (((u32)i5 & 0xFF) << 8) |
                            ((u32)i3 & 0xFF);
            command[1].w0 = ((((u32)i1 & 0xFF) << 16) | (((u32)i3 & 0xFF) << 8) |
                             ((u32)i4 & 0xFF)) | 0x06000000;
            command[1].w1 = (((u32)i3 & 0xFF) << 16) | (((u32)i1 & 0xFF) << 8) |
                            ((u32)i0 & 0xFF);
            command[2].w0 = ((((u32)i4 & 0xFF) << 16) | (((u32)i2 & 0xFF) << 8) |
                             ((u32)i1 & 0xFF)) | 0x06000000;
            command[2].w1 = (((u32)i2 & 0xFF) << 16) | (((u32)i4 & 0xFF) << 8) |
                            ((u32)i5 & 0xFF);
            command += 3;
            i0 += 6;
            i1 += 6;
            i2 += 6;
            i3 += 6;
            i4 += 6;
            i5 += 6;
        }
    }
    command[0].w0 = 0xDF000000;
    command[0].w1 = 0;
}
