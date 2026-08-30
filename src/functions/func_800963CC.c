/* Independently written from specs/functions/recovered/func_800963CC.md. */

#include "podcruise/types.h"

typedef struct Command800963CC {
    /* 0x00 */ u32 w0;
    /* 0x04 */ u32 w1;
} Command800963CC;

typedef struct Channel800963CC Channel800963CC;
typedef struct Envelope800963CC Envelope800963CC;

typedef struct Voice800963CC {
    /* 0x00 */ u32 start;
    /* 0x04 */ u32 end;
    /* 0x08 */ s16 firstCommand;
    /* 0x0A */ s16 secondCommand;
    /* 0x0C */ s16 finalCommand;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ Channel800963CC *channel;
    /* 0x24 */ Envelope800963CC *envelope;
} Voice800963CC;

typedef struct OutputSource800963CC OutputSource800963CC;

typedef Command800963CC *(*BeginOutput800963CC)(
    OutputSource800963CC *, void *, s32, s32, void *);

struct OutputSource800963CC {
    /* 0x00 */ void *unk00;
    /* 0x04 */ BeginOutput800963CC beginOutput;
};

typedef struct Sequence800963CC {
    /* 0x00 */ OutputSource800963CC *outputSource;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s16 *ringBase;
    /* 0x18 */ s16 *cursor;
    /* 0x1C */ u32 ringLength;
    /* 0x20 */ Voice800963CC *voices;
    /* 0x24 */ u8 voiceCount;
} Sequence800963CC;

extern Command800963CC *func_80095B68(
    Channel800963CC *, s32, s32, Command800963CC *);
extern Command800963CC *func_80095C20(
    Sequence800963CC *, s16 *, s32, s32, Command800963CC *);
extern Command800963CC *func_80095DA8(
    Sequence800963CC *, s16 *, u32, u32, Command800963CC *);
extern Command800963CC *func_80095F34(
    Sequence800963CC *, Voice800963CC *, u32, s32,
    Command800963CC *);

Command800963CC *func_800963CC(
    Sequence800963CC *sequence, void *arg1, s32 sampleCount, s32 arg3,
    void *arg4) {
    Command800963CC *out;
    Voice800963CC *voice;
    s16 *start;
    s16 *mirrorEnd;
    s16 *previousBoundary;
    s16 *newCursor;
    s16 *ringEnd;
    s32 doubledCount;
    u16 shortDoubledCount;
    s32 rightOffset;
    s32 leftOffset;
    s32 swap;
    s16 index;

    previousBoundary = 0;
    out = sequence->outputSource->beginOutput(
        sequence->outputSource, arg1, sampleCount, arg3, arg4);

    doubledCount = sampleCount * 2;
    shortDoubledCount = (u16)doubledCount;
    out[0].w0 = 0x08000000;
    out[0].w1 = shortDoubledCount;
    out[1].w0 = 0x0C00DA83;
    out[1].w1 = 0x06C006C0;
    out[2].w0 = 0x0C005A82;
    out[2].w1 = 0x080006C0;

    rightOffset = 0x140;
    leftOffset = 0;
    out = func_80095C20(
        sequence, sequence->cursor, 0x6C0, sampleCount, out + 3);
    out->w0 = 0x02000800;
    out->w1 = doubledCount;
    out++;

    for (index = 0; index < sequence->voiceCount; index++) {
        voice = &sequence->voices[index];
        start = sequence->cursor - voice->start;
        mirrorEnd = sequence->cursor - voice->end;

        if (start == previousBoundary) {
            swap = rightOffset;
            rightOffset = (s16)leftOffset;
            leftOffset = (s16)swap;
        } else {
            out = func_80095DA8(
                sequence, start, leftOffset, sampleCount, out);
        }

        out = func_80095F34(
            sequence, voice, rightOffset, sampleCount, out);

        if (voice->firstCommand != 0) {
            out->w0 = 0x0C000000 | (u16)voice->firstCommand;
            out->w1 = ((u16)leftOffset << 16) | (u16)rightOffset;
            out++;
            if ((voice->envelope == 0) && (voice->channel == 0)) {
                out = func_80095C20(
                    sequence, mirrorEnd, rightOffset, sampleCount, out);
            }
        }

        if (voice->secondCommand != 0) {
            out->w0 = 0x0C000000 | (u16)voice->secondCommand;
            out->w1 = ((u16)rightOffset << 16) | (u16)leftOffset;
            out++;
            out = func_80095C20(
                sequence, start, leftOffset, sampleCount, out);
        }

        if (voice->channel != 0) {
            out = func_80095B68(
                voice->channel, rightOffset, sampleCount, out);
        }

        if (voice->envelope == 0) {
            out = func_80095C20(
                sequence, mirrorEnd, rightOffset, sampleCount, out);
        }

        if (voice->finalCommand != 0) {
            out->w0 = 0x0C000000 | (u16)voice->finalCommand;
            out->w1 = ((u16)rightOffset << 16) | 0x0800;
            out++;
        }

        previousBoundary = sequence->cursor + voice->end;
    }

    newCursor = sequence->cursor + sampleCount;
    ringEnd = sequence->ringBase + sequence->ringLength;
    sequence->cursor = newCursor;
    if (ringEnd < newCursor) {
        sequence->cursor = newCursor - sequence->ringLength;
    }

    out->w0 = 0x0A000800;
    out->w1 = 0x06C00000 | shortDoubledCount;
    return out + 1;
}
