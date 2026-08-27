/* Specification: specs/func_80090200.md (worker-authored) */
#include "podcruise/types.h"

typedef struct Node {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s16 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Node;

typedef struct Sink {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ void (*unk8)(struct Sink *, s32);
} Sink;

typedef struct Device {
    /* 0x000 */ u8 pad0[0xC];
    /* 0x00C */ Sink *unkC;
    /* 0x010 */ u8 pad10[0xC8];
    /* 0x0D8 */ s32 unkD8;
} Device;

typedef struct Host {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ Device *unk8;
} Host;

typedef struct Stream {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
} Stream;

extern Node *func_80088500(void);
extern s32 func_800883F8(Stream *, s32);

void func_80090200(Stream *arg0, Host *arg1, s16 arg2, s32 arg3) {
    Node *node;
    Sink *sink;

    if (arg1->unk8) {
        node = func_80088500();
        if (node) {
            node->unk4 = arg0->unk1C + arg1->unk8->unkD8;
            node->unk8 = 0xB;
            node->unkC = arg2;
            node->unk10 = func_800883F8(arg0, arg3);
            node->unk0 = 0;
            sink = arg1->unk8->unkC;
            sink->unk8(sink, 3);
        }
    }
}
