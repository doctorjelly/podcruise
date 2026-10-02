#include <assert.h>

#include "../src/functions/func_8003B860.c"

u8 D_800A4920[1];

int main(void) {
    static const struct {
        s32 x, y;
        u32 vertices[4];
    } cases[] = {
        {9, 19, {0x00090013, 0x001E0014, 0x001E0028, 0x000A0028}},
        {10, 19, {0x000A0014, 0x000A0013, 0x001E0028, 0x000A0028}},
        {10, 20, {0x000A0014, 0x001E0014, 0x000A0014, 0x000A0028}},
        {9, 20, {0x000A0014, 0x001E0014, 0x001E0028, 0x00090014}},
        {-1, -1, {0xFFFFFFFF, 0x001E0014, 0x001E0028, 0x000A0028}},
        {32768, 19, {0x000A0014, 0x80000013, 0x001E0028, 0x000A0028}},
        {2147483647, 20, {0x000A0014, 0x001E0014, 0xFFFF0014, 0x000A0028}},
        {-1, 20, {0x000A0014, 0x001E0014, 0x001E0028, 0xFFFF0014}},
        {(-2147483647 - 1), 20, {0x000A0014, 0x001E0014, 0x001E0028, 0x00000014}}
    };
    static const u32 textureWords[4] = {
        0x8000FFFF, 0xFFFFFFFF, 0xFFFF8000, 0x80008000
    };
    unsigned i, j;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++) {
        PcGfx storage[16];
        PcGfx *output = storage + 1;
        PcGfx *cursor = output;
        for (j = 0; j < 16; j++) {
            storage[j].w0 = 0xDEADBEEF;
            storage[j].w1 = 0xCAFEBABE;
        }
        func_8003B860(&cursor, 10, 30, 20, 40, cases[i].x, cases[i].y,
                     32768, -1, -1, 32768);
        assert(cursor == output + 14);
        assert(storage[0].w0 == 0xDEADBEEF && storage[0].w1 == 0xCAFEBABE);
        assert(storage[15].w0 == 0xDEADBEEF && storage[15].w1 == 0xCAFEBABE);
        assert(output[0].w0 == 0x01004008);
        assert(output[0].w1 == (u32)(unsigned long)D_800A4920);
        for (j = 0; j < 4; j++) {
            assert(output[1 + j].w0 == 0x021C0000 + 2 * j);
            assert(output[1 + j].w1 == 0);
            assert(output[5 + j].w0 == 0x02180000 + 2 * j);
            assert(output[5 + j].w1 == cases[i].vertices[j]);
            assert(output[9 + j].w0 == 0x02140000 + 2 * j);
            assert(output[9 + j].w1 == textureWords[j]);
        }
        assert(output[13].w0 == 0x06000402 && output[13].w1 == 0x604);
    }
    return 0;
}
