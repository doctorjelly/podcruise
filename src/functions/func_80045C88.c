/* Recovered from specification specs/func_80045C88.md (worker batch_15). */

#include "podcruise/types.h"

typedef struct PcNode {
    u8 unk00[0x14];
    s32 count;      /* 0x14 */
    void *children; /* 0x18 */
    u8 unk1C[0x3C];
} PcNode;           /* 0x58 */

typedef struct PcGroup {
    u8 unk00[0x14];
    s32 count;      /* 0x14 */
    void *children; /* 0x18 */
} PcGroup;          /* 0x1C */

typedef struct PcScene {
    u8 unk000[0xBC0];
    PcGroup *unkBC0;   /* 0xBC0 */
    s32 unkBC4;
    PcNode *unkBC8[6]; /* 0xBC8 */
    PcNode *unkBE0[6]; /* 0xBE0 */
    s32 unkBF8[6];     /* 0xBF8 */
    PcGroup unkC10;    /* 0xC10 */
    PcNode unkC2C[6];  /* 0xC2C */
    PcNode unkE3C[6];  /* 0xE3C */
} PcScene;

extern s32 *func_800305E8(s32 index);
extern void *func_80030964(s32 *stream);
extern void func_80018324(void *object, u32 flags);

void func_80045C88(PcScene *scene) {
    PcNode *first;
    PcNode *second;
    s32 *data;
    s32 i;

    data = func_800305E8(0x92);
    func_80030964(data);

    func_80018324(&scene->unkC10, 0x5064);
    scene->unkC10.count = 6;
    scene->unkC10.children = scene->unkBC8;
    scene->unkBC0 = &scene->unkC10;

    for (i = 0; i < 6; i++) {
        first = &scene->unkC2C[i];
        second = &scene->unkE3C[i];
        func_80018324(first, 0xD065);
        func_80018324(second, 0xD065);
        first->count = 1;
        second->count = 1;
        first->children = &scene->unkBE0[i];
        second->children = &scene->unkBF8[i];
        scene->unkBC8[i] = first;
        scene->unkBE0[i] = second;
        scene->unkBF8[i] = *data;
    }
}
