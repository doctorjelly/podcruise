/* Recovered per scratchpad spec specs/func_80030C98.md (boundary corrected from 0x80030CA0). */
#include "podcruise/types.h"

extern s32 D_800A284C;
extern s32 D_800A2850;
extern s32 D_800A2854;
extern u32 D_8011AC60[];
extern s32 D_8011AC74;
extern void **D_8011AC78;
extern void *D_8011AC80;
extern void *D_8011AC84;

extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void func_80018324(void *object, u32 flags);
extern void *func_800305E8(s32 index);
extern s32 **func_80030964(s32 *stream);
extern void func_80030A7C(u32 *displayList, u32 *patchList);
extern void func_800862D8(s32 index, s32 left, s32 top, s32 right, s32 bottom);
extern void func_8008635C(s32 slot, s32 value);
extern void func_80087754(void *arg);

void func_80030C98(void) {
    void **stream;

    if (D_800A2854 < 0) {
        stream = func_800305E8(D_800A284C);
        if (D_800A2850 >= 0) {
            func_80030A7C((u32 *)stream, (u32 *)func_800305E8(D_800A2850));
        }
        if (stream[0] != 0) {
            func_800181BC(stream[0], 2, 3, 0x10, 2);
        }
        func_800862D8(0, 8, 8, 0x138, 0xE8);
        func_800862D8(1, 8, 8, 0x138, 0xE8);
        func_8008635C(1, 0);
        func_80087754(stream[0]);
        func_80030964((s32 *)stream);
    } else {
        func_80018324(D_8011AC60, 0x5064);
        D_8011AC74 = 2;
        D_8011AC78 = &D_8011AC80;
        stream = func_800305E8(D_800A284C);
        if (D_800A2850 >= 0) {
            func_80030A7C((u32 *)stream, (u32 *)func_800305E8(D_800A2850));
        }
        if (stream[0] != 0) {
            func_800181BC(stream[0], 2, 3, 0x10, 2);
        }
        func_80030964((s32 *)stream);
        D_8011AC80 = stream[0];
        stream = func_800305E8(D_800A2854);
        if (stream[0] != 0) {
            func_800181BC(stream[0], 2, 3, 0x10, 2);
        }
        func_80030964((s32 *)stream);
        D_8011AC84 = stream[0];
        func_800862D8(0, 8, 8, 0x138, 0xE8);
        func_800862D8(1, 8, 8, 0x138, 0xE8);
        func_8008635C(1, 0);
        func_80087754(D_8011AC60);
    }
}
