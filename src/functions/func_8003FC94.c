/* Independently written from scratchpad spec specs/func_8003FC94.md. */

#include "podcruise/types.h"

typedef struct Element8003FC94 {
    u8 unk00[0x6];
    s16 unk06;
} Element8003FC94;

typedef struct Notice8003FC94 {
    u32 unk00;
    u32 unk04;
} Notice8003FC94;

typedef struct Group8003FC94 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    Element8003FC94 *unk10;
} Group8003FC94;

extern Group8003FC94 **D_800A2170;
extern void func_8003F99C(Element8003FC94 *element, Notice8003FC94 *notice);

void func_8003FC94(s32 arg0) {
    Group8003FC94 **list;
    Group8003FC94 *group;
    Element8003FC94 *element;
    s16 index;
    Notice8003FC94 notice;

    notice.unk00 = 0x46726565;
    for (list = D_800A2170; *list != 0; list++) {
        group = *list;
        if (arg0 == group->unk00) {
            element = group->unk10;
            for (index = 0; index < group->unk08; index++) {
                if ((element->unk06 & 0x100) == 0) {
                    func_8003F99C(element, &notice);
                    element->unk06 |= 0x100;
                }
                element = (Element8003FC94 *)((u8 *)element + group->unk0C);
            }
        }
    }
}
