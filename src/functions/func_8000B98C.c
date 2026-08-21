/* Recovered per specification scratchpad/specs/func_8000B98C.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x14];
    f32 unk14[4][4];
    u8 unk54[0x28];
} Entry8000B98C;

extern Entry8000B98C *D_8009B790;

extern void func_800156DC(void *dst, f32 (*src)[4]);
extern void func_80017874(void *arg0);
extern s32 func_80017EE4(s32 object);
extern s32 func_80017EF4(s32 object);
extern s32 func_80017F28(s32 slot);

void func_8000B98C(void *arg0, f32 *p) {
    s32 flags1;
    s32 flags2;
    s32 index1;
    s32 index2;
    s32 object1;
    s32 object2;
    f32 dist1;
    f32 dist2;

    dist1 = -1.0f;
    dist2 = -1.0f;

    object1 = func_80017F28(1);
    object2 = func_80017F28(2);
    flags1 = func_80017EF4(object1);
    flags2 = func_80017EF4(object2);

    if (flags1 & 1) {
        index1 = func_80017EE4(object1);
        dist1 = (p[0] - D_8009B790[index1].unk14[3][0]) * (p[0] - D_8009B790[index1].unk14[3][0]) +
                (p[1] - D_8009B790[index1].unk14[3][1]) * (p[1] - D_8009B790[index1].unk14[3][1]) +
                (p[2] - D_8009B790[index1].unk14[3][2]) * (p[2] - D_8009B790[index1].unk14[3][2]);
    }

    if (flags2 & 1) {
        index2 = func_80017EE4(object2);
        dist2 = (p[0] - D_8009B790[index2].unk14[3][0]) * (p[0] - D_8009B790[index2].unk14[3][0]) +
                (p[1] - D_8009B790[index2].unk14[3][1]) * (p[1] - D_8009B790[index2].unk14[3][1]) +
                (p[2] - D_8009B790[index2].unk14[3][2]) * (p[2] - D_8009B790[index2].unk14[3][2]);
    }

    if (dist2 < 0.0f || dist1 < dist2) {
        if (dist1 < 0.0f) {
            func_80017874(arg0);
        } else {
            func_800156DC(arg0, D_8009B790[index1].unk14);
        }
    } else {
        func_800156DC(arg0, D_8009B790[index2].unk14);
    }
}
