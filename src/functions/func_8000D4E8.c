/* Independently written from specs/functions/func_8000D4E8.md. */

#include "podcruise/types.h"

extern s32 func_8008A6B4(char *buffer, const char *format, ...);

extern s32 D_8009B7D4;
extern char D_800A84D4[];
extern char D_800A84E0[];
extern char D_800A84E8[];
extern char D_800A84F8[];
extern char D_800A8508[];
extern char D_800A8518[];
extern f32 D_800A8638;

s32 func_8000D4E8(s32 entry, char *buffer, u8 *flag, s32 *order, f32 *value) {
    *flag = 0;
    *order = -10000;
    *value = D_800A8638;
    switch (entry) {
    case 0:
        func_8008A6B4(buffer, D_800A84D4);
        break;
    case 2:
        func_8008A6B4(buffer, D_800A84E0);
        break;
    case 1:
        func_8008A6B4(buffer, D_800A84E8);
        break;
    case 3:
        if (D_8009B7D4 > 0) {
            func_8008A6B4(buffer, D_800A84F8);
            break;
        }
        func_8008A6B4(buffer, D_800A8508);
        return 0;
    default:
        func_8008A6B4(buffer, D_800A8518);
        return 0;
    }
    return 1;
}
