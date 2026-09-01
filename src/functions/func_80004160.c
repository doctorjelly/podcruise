/* Recovered from specification specs/func_80004160.md. */

#include "podcruise/vector_math.h"

extern f32 func_800154D0(f32 *vector);
extern void func_80015538(PcVec3f *output, const PcVec3f *left,
                          const PcVec3f *right);

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern f32 D_800A813C;
extern s32 D_8009A280;
extern f32 D_800AE8B0;
extern PcVec3f D_800AE8B8;
extern PcVec3f D_800AE8C8;
extern s32 D_800AE8D8;
extern f32 D_800AE8DC;

s32 func_80004160(PcVec3f *a, f32 b, PcVec3f *c, f32 d, f32 e, PcVec3f *f,
                  PcVec3f *g, PcVec3f *h) {
    PcVec3f t;
    PcVec3f r;
    PcVec3f pad0;
    PcVec3f v;
    PcVec3f w;
    PcVec3f y;
    PcVec3f u;
    f32 dot;
    f32 pad1;
    PcVec3f x;
    PcVec3f z;
    PcVec3f p;
    PcVec3f q;
    f32 len;

    (void)pad0;
    (void)pad1;

    if (D_800AE8B0 < D_800AE8DC) {
        f->x = D_800AE8C8.x; f->y = D_800AE8C8.y; f->z = D_800AE8C8.z;
        t.x = a->x - D_800AE8B8.x;
        t.y = a->y - D_800AE8B8.y;
        t.z = a->z - D_800AE8B8.z;
        func_800154D0(&t.x);
        func_80015538(&u, &t, c);
        func_80015538(&v, &u, c);
        len = func_800153C0(&v);
        if (len < D_800A813C) {
            dot = c->z * t.z + (t.x * c->x + t.y * c->y);
            if (dot < 0.0f) {
                func_800155C0(&t, -(d - sqrtf(D_800AE8B0)), f);
            } else {
                func_800155C0(&t, -e - sqrtf(D_800AE8B0), f);
            }
            a->x = a->x + t.x;
            a->y = a->y + t.y;
            a->z = a->z + t.z;
            g->x = -f->x;
            g->y = -f->y;
            g->z = -f->z;
        } else {
            func_800155C0(&v, 1.0f / len, &v);
            func_800155C0(&w, sqrtf(D_800AE8DC - d * d), &v);
            func_800155EC(&x, &w, d, c);
            func_800155C0(&y, sqrtf(D_800AE8DC - e * e), &v);
            func_800155EC(&z, &y, e, c);
            func_80015538(&p, &x, &t);
            func_80015538(&q, &z, &t);
            dot = q.z * p.z + (p.x * q.x + p.y * q.y);
            if (dot < 0.0f) {
                func_800155C0(&t, b - sqrtf(D_800AE8B0), &t);
                a->x = a->x + t.x;
                a->y = a->y + t.y;
                a->z = a->z + t.z;
                g->x = -f->x;
                g->y = -f->y;
                g->z = -f->z;
            } else {
                dot = f->z * c->z + (c->x * f->x + c->y * f->y);
                if (0.0f < dot) {
                    r.x = z.x + a->x;
                    r.y = z.y + a->y;
                    r.z = z.z + a->z;
                    g->x = z.x;
                    g->y = z.y;
                    g->z = z.z;
                } else {
                    r.x = x.x + a->x;
                    r.y = x.y + a->y;
                    r.z = x.z + a->z;
                    g->x = z.x;
                    g->y = z.y;
                    g->z = z.z;
                }
                func_800154D0(&g->x);
                func_800155EC(a, a,
                              (D_800AE8B8.x * f->x + D_800AE8B8.y * f->y +
                               D_800AE8B8.z * f->z) -
                                  (f->z * r.z + (r.x * f->x + r.y * f->y)),
                              f);
            }
        }
        h->x = D_800AE8B8.x;
        h->y = D_800AE8B8.y;
        h->z = D_800AE8B8.z;
        if (D_800AE8D8 != 0) {
            D_8009A280 = D_800AE8D8;
        }
        return 1;
    }
    return 0;
}
