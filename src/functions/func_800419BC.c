/* Specification: $S/specs/func_800419BC.md */
#include "podcruise/types.h"

typedef struct {
    u8 pad[0x70];
    f32 unk70;
} Obj800419B4;

extern void func_80041258(Obj800419B4 *);
extern void func_80040050(Obj800419B4 *, f32);

void func_800419B4(Obj800419B4 *arg0) {
    arg0->unk70 = 8.0f;
    func_80041258(arg0);
    func_80040050(arg0, 1000.0f);
}
