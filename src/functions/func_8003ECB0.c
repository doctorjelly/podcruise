/* Recovered from specification specs/func_8003ECB0.md (worker tier2_18). */
#include "podcruise/types.h"

extern void func_8003EA84(s16 column, s16 row, u8 red, u8 green, u8 blue,
                          u8 alpha, const char *text, s32 limit, s32 bank);

void func_8003ECB0(s16 column, s16 row, const char *text) {
    func_8003EA84(column, row, 0xFF, 0xFF, 0xFF, 0xFF, text, -1, 0);
}
