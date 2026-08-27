/* Recovered from specification specs/func_8000D130.md (debug-option text formatter). */
#include "podcruise/types.h"

extern s32 func_8008A6B4(char *, const char *, ...);
extern void *func_8003F714(s32, s32);

extern s32 D_8009B7D0;
extern s32 D_8009B7D8;
extern s32 D_8009B7E0;
extern s32 D_800A52D0;
extern s32 D_800A52D4;
extern s32 D_800D697C;
extern f32 D_800A5B54;
extern f32 D_800A5B58;
extern f32 D_800A5B64;
extern f32 D_800A5B68;
extern f32 D_800A8630;
extern f32 D_800A8634;
extern const char D_800A83B0[];
extern const char D_800A83BC[];
extern const char D_800A83C4[];
extern const char D_800A83D8[];
extern const char D_800A83EC[];
extern const char D_800A83F4[];
extern const char D_800A8404[];
extern const char D_800A840C[];
extern const char D_800A8418[];
extern const char D_800A8420[];
extern const char D_800A8430[];
extern const char D_800A8438[];
extern const char D_800A8448[];
extern const char D_800A8450[];
extern const char D_800A8464[];
extern const char D_800A8478[];
extern const char D_800A8480[];
extern const char D_800A8494[];
extern const char D_800A84A8[];
extern const char D_800A84B0[];
extern const char D_800A84C4[];

static const f32 D_800A8600[3] = { 0.1f, 0.05f, -10000.0f };

s32 func_8000D130(s32 index, char *text, u8 *flag, s32 *value, f32 *scale) {
    s16 *entry;

    *flag = 0;
    *value = -10000;
    *scale = D_800A8600[2];

    switch (index) {
        case 0:
            func_8008A6B4(text, D_800A83B0);
            *value = D_8009B7D0;
            break;
        case 1:
            if (!(D_8009B7D8 & 4)) {
                func_8008A6B4(text, D_800A83BC);
            } else if (D_800A52D4 != 0) {
                func_8008A6B4(text, D_800A83C4);
            } else {
                func_8008A6B4(text, D_800A83D8);
            }
            break;
        case 2:
            if (!(D_8009B7D8 & 8)) {
                func_8008A6B4(text, D_800A83EC);
                break;
            }
            func_8008A6B4(text, D_800A83F4);
            *scale = D_800A5B64 * 10.0f;
            break;
        case 3:
            if (!(D_8009B7D8 & 8)) {
                func_8008A6B4(text, D_800A8404);
                break;
            }
            func_8008A6B4(text, D_800A840C);
            *scale = D_800A5B68;
            break;
        case 4:
            if (!(D_8009B7D8 & 8)) {
                func_8008A6B4(text, D_800A8418);
                break;
            }
            func_8008A6B4(text, D_800A8420);
            *scale = D_800A5B54;
            break;
        case 5:
            if (!(D_8009B7D8 & 8)) {
                func_8008A6B4(text, D_800A8430);
                break;
            }
            func_8008A6B4(text, D_800A8438);
            *scale = D_800A5B58;
            break;
        case 6:
            if (!(D_8009B7D8 & 0x10)) {
                func_8008A6B4(text, D_800A8448);
                break;
            }
            if (D_800A52D0 != 0) {
                func_8008A6B4(text, D_800A8450);
            } else {
                func_8008A6B4(text, D_800A8464);
            }
            *scale = D_800A8630;
            break;
        case 7:
            if (!(D_8009B7D8 & 0x20)) {
                func_8008A6B4(text, D_800A8478);
                break;
            }
            if (D_800D697C & 0x4000) {
                func_8008A6B4(text, D_800A8480);
            } else {
                func_8008A6B4(text, D_800A8494);
            }
            *scale = D_800A8634;
            break;
        case 8:
            if (!(D_8009B7D8 & 2)) {
                func_8008A6B4(text, D_800A84A8);
                break;
            }
            entry = (s16 *)func_8003F714(0x54657374, D_8009B7E0);
            if (entry == 0 || (entry[3] & 0x100) != 0) {
                return 0;
            }
            func_8008A6B4(text, D_800A84B0);
            break;
        default:
            func_8008A6B4(text, D_800A84C4);
            return 0;
    }
    return 1;
}
