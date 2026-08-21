/* Specification: scratchpad specs/func_80000450.md (boot image copy and bss clear). */
#include "podcruise/types.h"

extern u32 D_1120[];
extern u32 D_AF4B0[];
extern u32 func_80000520[];
extern void func_8002F4D0(void);

#define ADDRESS_OF(pointer) ((u32)(unsigned long)(void *)(pointer))
#define POINTER_TO(value) ((u32 *)(unsigned long)(u32)(value))

void func_80000450(void) {
    u32 *source;
    u32 *destination;
    s32 length;
    s32 index;

    *POINTER_TO(0xA4400024) = 0;
    length = (s32)(ADDRESS_OF(D_AF4B0) - ADDRESS_OF(D_1120));
    source = POINTER_TO((ADDRESS_OF(D_1120) - 0xC00) | 0x80000000);
    destination = func_80000520;
    index = 0;
    if (length / 4 > 0) {
        do {
            *destination = *source;
            source++;
            destination++;
            index++;
        } while (index < length / 4);
    }
    while (destination < POINTER_TO(0x80400000)) {
        *destination++ = 0;
    }
    func_8002F4D0();
}
