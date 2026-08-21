/* Independently written from scratchpad spec specs/func_80038ED0.md. */

#include "podcruise/types.h"

/* Twelve 40-byte lighting records. Each record keeps an ambient colour at
 * bytes 0-2 with a duplicate copy at bytes 4-6, a diffuse colour at bytes
 * 8-10 with a duplicate copy at bytes 12-14, and a packed direction at
 * bytes 16-18. */
extern u8 D_800A3DC8[12][40];

void func_80038ED0(s32 slot, u8 *ambient, u8 *diffuse, s16 *direction) {
    u8 component;

    if ((slot >= 0) && (slot < 12)) {
        component = ambient[1];
        D_800A3DC8[slot][0] = component;
        D_800A3DC8[slot][4] = component;
        component = ambient[3];
        D_800A3DC8[slot][1] = component;
        D_800A3DC8[slot][5] = component;
        component = ambient[5];
        D_800A3DC8[slot][2] = component;
        D_800A3DC8[slot][6] = component;

        component = diffuse[1];
        D_800A3DC8[slot][8] = component;
        D_800A3DC8[slot][12] = component;
        component = diffuse[3];
        D_800A3DC8[slot][9] = component;
        D_800A3DC8[slot][13] = component;
        component = diffuse[5];
        D_800A3DC8[slot][10] = component;
        D_800A3DC8[slot][14] = component;

        D_800A3DC8[slot][16] = -direction[0];
        D_800A3DC8[slot][17] = -direction[1];
        D_800A3DC8[slot][18] = -direction[2];
    }
}
