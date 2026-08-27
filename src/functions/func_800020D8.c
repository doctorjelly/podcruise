/* Specification: specs/func_800020D8.md */
#include "podcruise/types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Vtx3s;

extern void func_800179EC(f32 *, f32 *, f32 *, f32 *);
extern void func_80001E80(f32 *, f32 *, f32 *, f32 *, f32 *);
extern f32 D_800AE928[];
extern f32 D_800AE918[];
extern f32 D_800AE8E8[];

void func_800020D8(verts, mode, idx)
Vtx3s *verts;
s16 mode;
u16 *idx;
{
    f32 out[4];
    f32 p[4][3];

    p[0][0] = (f32)verts[idx[0]].unk0;
    p[0][1] = (f32)verts[idx[0]].unk2;
    p[0][2] = (f32)verts[idx[0]].unk4;
    p[1][0] = (f32)verts[idx[1]].unk0;
    p[1][1] = (f32)verts[idx[1]].unk2;
    p[1][2] = (f32)verts[idx[1]].unk4;
    p[2][0] = (f32)verts[idx[2]].unk0;
    p[2][1] = (f32)verts[idx[2]].unk2;
    p[2][2] = (f32)verts[idx[2]].unk4;

    if (mode == 2) {
        p[3][0] = (f32)verts[idx[3]].unk0;
        p[3][1] = (f32)verts[idx[3]].unk2;
        p[3][2] = (f32)verts[idx[3]].unk4;

        if (p[0][0] < D_800AE928[0] && p[1][0] < D_800AE928[0] && p[2][0] < D_800AE928[0] && p[3][0] < D_800AE928[0]) { return; }
        if (D_800AE918[0] < p[0][0] && D_800AE918[0] < p[1][0] && D_800AE918[0] < p[2][0] && D_800AE918[0] < p[3][0]) { return; }
        if (p[0][1] < D_800AE928[1] && p[1][1] < D_800AE928[1] && p[2][1] < D_800AE928[1] && p[3][1] < D_800AE928[1]) { return; }
        if (D_800AE918[1] < p[0][1] && D_800AE918[1] < p[1][1] && D_800AE918[1] < p[2][1] && D_800AE918[1] < p[3][1]) { return; }
        if (p[0][2] < D_800AE928[2] && p[1][2] < D_800AE928[2] && p[2][2] < D_800AE928[2] && p[3][2] < D_800AE928[2]) { return; }
        if (D_800AE918[2] < p[0][2] && D_800AE918[2] < p[1][2] && D_800AE918[2] < p[2][2] && D_800AE918[2] < p[3][2]) { return; }
        func_800179EC(out, p[0], p[1], p[3]);
        func_80001E80(out, p[0], p[1], p[3], D_800AE8E8);
        func_800179EC(out, p[1], p[2], p[3]);
        func_80001E80(out, p[1], p[2], p[3], D_800AE8E8);
    } else {
        if (p[0][0] < D_800AE928[0] && p[1][0] < D_800AE928[0] && p[2][0] < D_800AE928[0]) { return; }
        if (D_800AE918[0] < p[0][0] && D_800AE918[0] < p[1][0] && D_800AE918[0] < p[2][0]) { return; }
        if (p[0][1] < D_800AE928[1] && p[1][1] < D_800AE928[1] && p[2][1] < D_800AE928[1]) { return; }
        if (D_800AE918[1] < p[0][1] && D_800AE918[1] < p[1][1] && D_800AE918[1] < p[2][1]) { return; }
        if (p[0][2] < D_800AE928[2] && p[1][2] < D_800AE928[2] && p[2][2] < D_800AE928[2]) { return; }
        if (D_800AE918[2] < p[0][2] && D_800AE918[2] < p[1][2] && D_800AE918[2] < p[2][2]) { return; }
        if (mode == 1) {
            func_800179EC(out, p[0], p[2], p[1]);
            func_80001E80(out, p[0], p[2], p[1], D_800AE8E8);
        } else {
            func_800179EC(out, p[0], p[1], p[2]);
            func_80001E80(out, p[0], p[1], p[2], D_800AE8E8);
        }
    }
}
