/* Independently written from specs/functions/recovered/func_80007594.md. */

#include "podcruise/types.h"

typedef struct Entry80007594 {
    /* 0x00 */ struct Entry80007594 *next;
    /* 0x04 */ struct Entry80007594 *previous;
    /* 0x08 */ u32 start;
    /* 0x0C */ u32 stamp;
    /* 0x10 */ u32 buffer;
} Entry80007594;

typedef struct {
    /* 0x00 */ Entry80007594 *active;
    /* 0x04 */ Entry80007594 *free;
} Lists80007594;

extern Lists80007594 D_800AFAC0;
extern u32 D_800AFE88;
extern s32 D_8009A2C8;
extern u8 D_800AFE98[];
extern u8 D_800B0498[];

extern s32 func_80087D70(void *, s32, s32, u32, u32, s32, void *);
extern void func_80088020(Entry80007594 *);
extern void func_80088050(Entry80007594 *, Entry80007594 *);
extern u32 func_80088360(u32);

u32 func_80007594(u32 address, u32 size, s32 unused) {
    Entry80007594 *entry;
    Entry80007594 *old_head;
    Entry80007594 *previous;
    Lists80007594 *lists;
    u32 buffer;
    u32 low_bit;

    (void)unused;
    lists = &D_800AFAC0;
    entry = lists->active;
    previous = 0;
    while (entry != 0) {
        if (address < entry->start) {
            break;
        }
        if ((s32)(address + size) <= (s32)(entry->start + 0x400)) {
            entry->stamp = D_800AFE88;
            return func_80088360(entry->buffer + address - entry->start);
        }
        previous = entry;
        entry = entry->next;
    }

    entry = lists->free;
    lists->free = entry->next;
    func_80088020(entry);
    if (previous != 0) {
        func_80088050(entry, previous);
    } else if (lists->active != 0) {
        old_head = lists->active;
        lists->active = entry;
        entry->next = old_head;
        entry->previous = 0;
        old_head->previous = entry;
    } else {
        lists->active = entry;
        entry->next = 0;
        entry->previous = 0;
    }

    low_bit = address & 1;
    buffer = entry->buffer;
    address -= low_bit;
    entry->start = address;
    entry->stamp = D_800AFE88;
    func_80087D70(D_800AFE98 + D_8009A2C8++ * 0x18, 0, 0, address,
                  buffer, 0x400, D_800B0498);
    return func_80088360(buffer) + low_bit;
}
