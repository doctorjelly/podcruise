/* Independently written from scratchpad spec specs/func_8008FF98.md. */

#include "podcruise/types.h"

typedef struct Command {
    s32 unk_00;
    s32 unk_04;
    s16 unk_08;
    s16 unk_0A;
    s32 unk_0C;
    s32 unk_10;
} Command;

typedef struct Emitter {
    char unk_00[0x8];
    void (*unk_08)(struct Emitter *emitter, s32 kind, Command *command);
} Emitter;

typedef struct Slot {
    char unk_00[0x8];
    s32 unk_08;
} Slot;

typedef struct Entry {
    char unk_00[0x8];
    void *unk_08;
    Emitter *unk_0C;
    char unk_10[0xC8];
    s32 unk_D8;
} Entry;

typedef struct Link {
    char unk_00[0x8];
    void *unk_08;
    s32 unk_0C;
    char unk_10[0x4];
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
} Link;

typedef struct Owner {
    char unk_00[0x1C];
    s32 unk_1C;
} Owner;

typedef struct Request {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04;
} Request;

extern s32 func_8008FEB0(Owner *owner, Entry **out, s32 key);
extern Command *func_80088500(void);

s32 func_8008FF98(Owner *owner, Link *link, Request *request) {
    Entry *entry;
    Command *command;
    s32 found;
    Emitter *emitter[1];

    entry = 0;
    link->unk_16 = request->unk_00;
    link->unk_0C = 0;
    link->unk_1A = request->unk_04;
    link->unk_14 = 0;
    link->unk_08 = 0;
    link->unk_18 = request->unk_02;
    found = func_8008FEB0(owner, &entry, request->unk_00);
    if (entry) {
        if (found != 0) {
            entry->unk_D8 = 0x200;
            emitter[0] = entry->unk_0C;
            ((Slot *)entry->unk_08)->unk_08 = 0;
            command = func_80088500();
            command->unk_08 = 0xB;
            command->unk_0C = 0;
            command->unk_04 = owner->unk_1C;
            command->unk_10 = entry->unk_D8 - 0x40;
            emitter[0]->unk_08(emitter[0], 3, command);
            command = func_80088500();
            if (command != 0) {
                command->unk_08 = 0xF;
                command->unk_00 = 0;
                command->unk_04 = owner->unk_1C + entry->unk_D8;
                emitter[0]->unk_08(emitter[0], 3, command);
            }
        } else {
            entry->unk_D8 = 0;
        }
        entry->unk_08 = link;
        link->unk_08 = entry;
    }
    return entry != 0;
}
