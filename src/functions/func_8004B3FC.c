/* Implements specs/func_8004B3FC.md (bulk resource binding pass). */
#include "podcruise/types.h"

/* Regional builds select the alternate slot and resource identifiers below by
   defining the PC_* names onto the corresponding PC_*_JP / PC_*_EU constant. */
#define PC_SLOT_HI_FIRST_JP 0x81
#define PC_SLOT_HI_SPLIT_JP 0x8F
#define PC_SLOT_HI_END_JP 0xA1
#define PC_SLOT_A_JP 0x56
#define PC_SLOT_B_JP 0x57
#define PC_SLOT_C_JP 0x5E
#define PC_SLOT_D_JP 0x5F
#define PC_SLOT_E_JP 0x60
#define PC_SLOT_F_JP 0x61
#define PC_RES_A_ALT 0xAD
#define PC_RES_B_ALT 0xAB
#define PC_RES_E_ALT 0xAC

#ifndef PC_SLOT_HI_FIRST
#define PC_SLOT_HI_FIRST 0x7F
#endif
#ifndef PC_SLOT_HI_SPLIT
#define PC_SLOT_HI_SPLIT 0x8D
#endif
#ifndef PC_SLOT_HI_END
#define PC_SLOT_HI_END 0x9F
#endif
#ifndef PC_SLOT_A
#define PC_SLOT_A 0x54
#endif
#ifndef PC_SLOT_B
#define PC_SLOT_B 0x55
#endif
#ifndef PC_SLOT_C
#define PC_SLOT_C 0x5C
#endif
#ifndef PC_SLOT_D
#define PC_SLOT_D 0x5D
#endif
#ifndef PC_SLOT_E
#define PC_SLOT_E 0x5E
#endif
#ifndef PC_SLOT_F
#define PC_SLOT_F 0x5F
#endif
#ifndef PC_RES_A
#define PC_RES_A 0x91
#endif
#ifndef PC_RES_B
#define PC_RES_B 0x93
#endif
#ifndef PC_RES_C
#define PC_RES_C 0x94
#endif
#ifndef PC_RES_D
#define PC_RES_D 0x8A
#endif
#ifndef PC_RES_E
#define PC_RES_E 0x92
#endif

extern void *func_80030154(s32 id);
extern void func_8000A44C(s16 slot, void *resource);
extern void func_8000AC34(s16 slot, u32 flags);

void func_8004B3FC(void) {
    s16 slot;
    void *resource;

    resource = func_80030154(0x1A);
    for (slot = PC_SLOT_HI_FIRST; slot < PC_SLOT_HI_SPLIT; slot++) {
        func_8000A44C(slot, resource);
    }
    resource = func_80030154(0x1A);
    for (slot = PC_SLOT_HI_SPLIT; slot < PC_SLOT_HI_END; slot++) {
        func_8000A44C(slot, resource);
        func_8000AC34(slot, 0x2000);
    }
    func_8000A44C(PC_SLOT_A, func_80030154(PC_RES_A));
    resource = func_80030154(PC_RES_B);
    for (slot = PC_SLOT_B; slot < PC_SLOT_C; slot++) {
        func_8000A44C(slot, resource);
    }
    func_8000A44C(PC_SLOT_C, func_80030154(PC_RES_C));
    func_8000A44C(PC_SLOT_D, func_80030154(PC_RES_D));
    func_8000A44C(PC_SLOT_E, func_80030154(PC_RES_E));
    for (slot = PC_SLOT_A; slot < PC_SLOT_F; slot++) {
        func_8000AC34(slot, 0x8000);
    }
}
