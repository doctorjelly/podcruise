/* Implements the specification in specs/func_8008A360.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ void *unk04;
} Struct8008A360;

extern Struct8008A360 *D_800A7F54;
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);

void func_8008A360(void *arg0) {
    s32 temp;

    temp = func_8008CA80();
    D_800A7F54->unk04 = arg0;
    D_800A7F54->unk00 |= 0x10;
    func_8008CAA0(temp);
}
