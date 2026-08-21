/* Independently written from scratchpad spec specs/func_8003F388.md. */

#include "podcruise/types.h"

typedef struct Element8003F388 {
    u8 unk00[0x6];
    s16 unk06;
} Element8003F388;

typedef struct Group8003F388 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    Element8003F388 *unk10;
    void (*unk14)(Element8003F388 *element);
    void (*unk18)(Element8003F388 *element);
} Group8003F388;

extern Group8003F388 **D_800A2170;
extern s16 D_800A4AA0;
extern void func_80008F28(void);

void func_8003F388(void) {
    Group8003F388 **list;
    Group8003F388 *group;
    Element8003F388 *element;
    void (*handler)(Element8003F388 *element);
    s16 index;

    for (list = D_800A2170; *list != 0; list++) {
        group = *list;
        if (group->unk14 != 0) {
            handler = group->unk14;
            if ((group->unk04 & D_800A4AA0) == 0) {
                element = group->unk10;
                for (index = 0; index < group->unk08; index++) {
                    if ((element->unk06 & 0x1100) == 0) {
                        handler(element);
                    }
                    element = (Element8003F388 *)((u8 *)element + group->unk0C);
                    func_80008F28();
                }
            }
        }
    }
}
