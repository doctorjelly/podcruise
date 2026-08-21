/* Recovered from specification $S/specs/func_8000B0E0.md */
#include "podcruise/types.h"

typedef struct {
    s32 unk0;
    u8 pad[120];
} Entry8000B0E0;

extern Entry8000B0E0 *D_8009B790;
extern s32 D_8009B798;
extern s32 D_8009B79C;

extern s32 func_80017EE4(void *);
extern void func_80017EEC(void *, s32);

void func_8000B0E0(slot, object)
s16 slot;
void *object;
{
    if (object != 0) {
        if (func_80017EE4(object) != -1) {
            D_8009B790[func_80017EE4(object)].unk0 &= ~1;
        }
        if (slot == -1) {
            D_8009B798 = slot;
        } else {
            func_80017EEC(object, slot);
            D_8009B790[D_8009B798].unk0 |= 1;
            D_8009B79C = 0;
        }
    }
}
