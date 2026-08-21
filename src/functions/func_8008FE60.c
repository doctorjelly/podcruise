/* Independently written from scratchpad spec specs/func_8008FE60.md. */

#include "podcruise/types.h"

typedef struct Link8008FE60 {
    struct Link8008FE60 *unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
} Link8008FE60;

extern u32 func_80090500(u32 mask);

void func_8008FE60(Link8008FE60 *arg0, Link8008FE60 *arg1) {
    u32 saved;

    saved = func_80090500(1);
    arg1->unk10 = arg0->unk20;
    arg1->unk00 = arg0->unk00;
    arg0->unk00 = arg1;
    func_80090500(saved);
}
