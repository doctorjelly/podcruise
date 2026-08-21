/* Independently written from specs/functions/func_8003FA24.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
} Member;

typedef s32 (*MemberProc)(void *, void *, void *);

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ Member *unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ MemberProc unk24;
} Group;

extern Group **D_800A2170;

void func_8003FA24(u32 arg0, void *arg1) {
    Group **list;
    Group *group;
    MemberProc proc;
    Member *member;
    s32 index;

    for (list = D_800A2170; *list != 0; list++) {
        group = *list;
        if (arg0 == group->unk00 || arg0 == 0x416C6C21) {
            if (group->unk24 != 0) {
                proc = group->unk24;
                member = group->unk10;
                for (index = 0; index < group->unk08; index++) {
                    if ((member->unk06 & 0x100) == 0) {
                        if (proc(member, arg1, arg1) == 2) {
                            return;
                        }
                    }
                    member = (Member *)((u8 *)member + group->unk0C);
                }
            }
            if (arg0 != 0x416C6C21) {
                return;
            }
        }
    }
}
