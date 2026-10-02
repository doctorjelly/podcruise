#include <assert.h>

#include "../src/functions/func_800129E4.c"
#include "../src/functions/func_800129B8.c"

u8 D_800A1CD8[256][2];
u8 D_800A1D1C[256];
struct PcFont *D_800D6940[2];

int main(void) {
    static Glyph firstGlyphs[2];
    static Glyph secondGlyphs[2];
    static Font firstFont;
    static Font secondFont;
    static u8 empty[] = "";
    static u8 text[] = "AB";
    static u8 lower[] = "ab";
    static u8 newline[] = "A~nB";

    firstGlyphs[0].unk02 = 3;
    firstGlyphs[1].unk02 = 7;
    secondGlyphs[0].unk02 = 5;
    secondGlyphs[1].unk02 = 9;
    firstFont.unk5A = secondFont.unk5A = 'A';
    firstFont.unk5B = secondFont.unk5B = 'B';
    firstFont.unk5C = (u8 *)firstGlyphs;
    secondFont.unk5C = (u8 *)secondGlyphs;
    D_800D6940[0] = &firstFont;
    D_800D6940[1] = &secondFont;

    assert(func_800129B8(empty, 0) == 0);
    assert(func_800129B8(text, 0) == 10);
    assert(func_800129B8(text, 1) == 14);
    assert(func_800129B8(lower, 0) == 10);
    assert(func_800129B8(newline, 1) == 5);
    return 0;
}
