/* Specification: specs/func_8008A3B0.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u16 unk00;
} Struct8008A3B0;

extern Struct8008A3B0 *D_800A7F54;
extern void *func_8008CA80(void);
extern void func_8008CAA0(void *);

void func_8008A3B0(u8 arg0) {
    register void *sp;

    sp = func_8008CA80();
    if (arg0 != 0) {
        D_800A7F54->unk00 |= 0x20;
    } else {
        D_800A7F54->unk00 &= ~0x20;
    }
    func_8008CAA0(sp);
}
