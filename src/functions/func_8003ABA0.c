/* Recovered from specification $S/specs/func_8003ABA0.md */
#include "podcruise/types.h"

typedef struct Rec {
    s16 unk0;
    s16 unk2;
    s16 unk4[40];
} Rec;

typedef struct Owner {
    s16 unk0;
    s16 pad2;
    s32 pad4[2];
    Rec *unkC;
} Owner;

typedef struct Track {
    s32 pad0[2];
    f32 unk8;
    s32 padC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} Track;

void func_8003ABA0(owner, mode, track)
Owner *owner;
short mode;
Track *track;
{
    Rec *rec;
    s32 value;

    if (mode == 1) {
        track->unk24 = 0;
        if (track->unk20 == 0) {
            s16 count;
            if (owner->unk0 == 0) {
                rec = track->unk1C + owner->unkC;
            } else {
                rec = track->unk14 + owner->unkC;
            }
            count = rec->unk0;
            if (count == 0) {
                value = -1;
                track->unk20 = 1;
                track->unk8 = 1.0f;
            } else {
                s16 index;
                if (track->unk28 < count) {
                    index = (s16)track->unk28;
                } else {
                    index = (s16)(track->unk28 % count);
                }
                value = rec->unk4[index];
                if (owner->unk0 == 0) {
                    track->unk2C = (track->unk2C >> 1) | (index << 2);
                } else {
                    track->unk2C = (track->unk2C >> 1) | index;
                }
            }
        }
        if (track->unk20 == 0) {
            track->unk10 = track->unk14;
            if (owner->unk0 == 0) {
                track->unk14 = track->unk18;
                track->unk18 = track->unk1C;
                track->unk1C = value;
            } else {
                track->unk14 = value;
            }
        }
    } else {
        track->unk20 = 0;
        if (track->unk24 == 0) {
            s16 count;
            rec = track->unk10 + owner->unkC;
            count = rec->unk2;
            if (count == 0) {
                value = -1;
                track->unk24 = 1;
                track->unk8 = 0.0f;
            } else {
                if (track->unk28 < count) {
                    value = rec->unk4[track->unk28 + 2];
                } else {
                    value = rec->unk4[(track->unk28 % count) + 2];
                }
                if (owner->unk0 == 0) {
                    track->unk2C = (track->unk2C << 1) & 7;
                } else {
                    track->unk2C = (track->unk2C << 1) & 1;
                }
                if (track->unk10 != owner->unkC[value].unk4[0]) {
                    track->unk2C |= 1;
                }
            }
        }
        if (track->unk24 == 0) {
            if (owner->unk0 == 0) {
                track->unk1C = track->unk18;
                track->unk18 = track->unk14;
            }
            track->unk14 = track->unk10;
            track->unk10 = value;
        }
    }
}
