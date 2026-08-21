/* Recovered from specification specs/functions/func_80091630.md (batch_07). */
#include "podcruise/types.h"

typedef union Entry80091630 {
    u16 half;
    struct {
        u8 hi;
        u8 lo;
    } b;
} Entry80091630;

typedef struct Dev80091630 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x50 - 0x0C];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 pad54[0x5C - 0x54];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ union {
        s32 word;
        struct {
            u16 hi;
            u16 lo;
        } h;
    } unk60;
    /* 0x64 */ u8 unk64;
    /* 0x65 */ u8 unk65;
} Dev80091630;

typedef struct Page80091630 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ Entry80091630 unk06;
    /* 0x08 */ u8 pad08[0x20 - 0x08];
} Page80091630;

typedef struct Out80091630 {
    /* 0x000 */ u8 pad0[0x100];
    /* 0x100 */ u8 unk100;
    /* 0x101 */ u8 flags[0x100];
} Out80091630;

extern s32 func_800910D4(Dev80091630 *device);
extern s32 func_80091280(Dev80091630 *device);
extern s32 func_80091354(Dev80091630 *device, Entry80091630 *table, u8 mode, u8 key);
extern s32 func_80091B68(Dev80091630 *device, Out80091630 *out);
extern s32 func_80091E34(Dev80091630 *device, Entry80091630 key, Out80091630 *out);
extern s32 func_80091FD0(Dev80091630 *device, u8 value);
extern s32 func_80092050(s32 handleA, s32 handleB, u16 selector, Page80091630 *page);
extern void func_80092850(Page80091630 *page, s32 length);
extern s32 func_800928F0(s32 handleA, s32 handleB, u16 selector, Page80091630 *page, s32 flag);

s32 func_80091630(Dev80091630 *device) {
    s32 status;
    s32 index;
    Entry80091630 entry;
    Entry80091630 table3[128];
    Entry80091630 table2[128];
    Page80091630 page;
    Entry80091630 slots[16];
    Out80091630 out;
    s32 repaired;
    s32 mismatch;
    s32 chain;
    u8 curKey;
    u8 iteration;
    u8 lastLoaded;
    s32 status2;
    Entry80091630 temp;

    repaired = 0;
    lastLoaded = 0xFE;
    status = func_80091280(device);
    if (status == 2) {
        status = func_800910D4(device);
    }
    if (status != 0) {
        return status;
    }

    status = func_80091B68(device, &out);
    if (status != 0) {
        return status;
    }

    for (index = 0; index < device->unk50; index++) {
        status = func_80092050(device->unk04, device->unk08, (u16)(device->unk5C + index), &page);
        if (status != 0) {
            return status;
        }
        if (page.unk04 != 0 || page.unk00 != 0) {
            if (page.unk04 == 0 || page.unk00 == 0) {
                mismatch = -1;
            } else {
                mismatch = 0;
                chain = 0;
                entry = page.unk06;
                iteration = 0xFF;
                curKey = iteration;
                if (entry.half >= device->unk60.word && entry.b.hi < device->unk64 &&
                    entry.b.lo > 0 && entry.b.lo < 0x80) {
                    do {
                        iteration = entry.b.hi;
                        if (curKey != entry.b.hi) {
                            curKey = entry.b.hi;
                            if (lastLoaded != entry.b.hi) {
                                status = func_80091354(device, table2, 0, curKey);
                                lastLoaded = iteration;
                            }
                            if (status != 0 && status != 3) {
                                return status;
                            }
                        }
                        mismatch = func_80091E34(device, entry, &out) - chain;
                        if (mismatch != 0) {
                            break;
                        }
                        entry = table2[entry.b.lo];
                        chain = 1;
                    } while (entry.half >= device->unk60.word && entry.b.hi < device->unk64 &&
                             entry.b.lo > 0 && entry.b.lo < 0x80);
                }
            }
            if (mismatch != 0 || entry.half != 1) {
                func_80092850(&page, 0x20);
                if (device->unk65 != 0) {
                    status = func_80091FD0(device, 0);
                    if (status != 0) {
                        return status;
                    }
                }
                status = func_800928F0(device->unk04, device->unk08,
                                       (u16)(device->unk5C + index), &page, 0);
                if (status != 0) {
                    return status;
                }
                repaired++;
            }
        }
    }

    for (index = 0; index < device->unk50; index++) {
        status = func_80092050(device->unk04, device->unk08, (u16)(device->unk5C + index), &page);
        if (status != 0) {
            return status;
        }
        if (page.unk04 != 0 && page.unk00 != 0 && page.unk06.half >= device->unk60.h.lo) {
            slots[index].half = page.unk06.half;
        } else {
            slots[index].half = 0;
        }
    }

    for (iteration = 0; iteration < device->unk64; iteration++) {
        status2 = func_80091354(device, table2, 0, iteration);
        if (status2 != 0 && status2 != 3) {
            return status2;
        }
        curKey = iteration;
        if (iteration > 0) {
            mismatch = 1;
        } else {
            mismatch = device->unk60.word;
        }
        for (index = 0; index < mismatch; index++) {
            table3[index].half = table2[index].half;
        }
        for (; index < 128; index++) {
            table3[index].half = 3;
        }
        for (index = 0; index < device->unk50; index++) {
            while (slots[index].b.hi == curKey && slots[index].half >= device->unk60.h.lo) {
                temp = table2[slots[index].b.lo];
                table3[slots[index].b.lo] = temp;
                slots[index] = temp;
            }
        }
        status2 = func_80091354(device, table3, 1, iteration);
        if (status2 != 0) {
            return status2;
        }
    }

    if (repaired != 0) {
        device->unk00 |= 2;
    } else {
        device->unk00 &= ~2;
    }
    return 0;
}
