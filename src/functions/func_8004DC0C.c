/* Specification: scratchpad specs/func_8004DC0C.md (session command dispatcher). */
#include "podcruise/types.h"

typedef struct Session {
    u8 pad0[0x14];
    s32 flags;
    u8 pad18[0x45];
    u8 unk5D;
    s8 unk5E;
    u8 pad5F;
    s8 unk60;
    u8 pad61[3];
    s32 unk64;
    s32 unk68;
} Session;

extern s32 D_800A2198;
extern s32 D_800A2320[];
extern s32 D_800A2344;
extern u8 D_800A21B5;
extern s32 D_800A4BDC;
extern u8 D_800A4BFC;
extern s32 D_800A5998;

extern void func_8000AB24(s32, s32, s32, s32, s32);
extern void func_8000AC90(s32);
extern void func_800469B4(Session *, s32);
extern void func_8004A6A4(Session *, s32, s32);
extern void func_8004BDFC(void);
extern void func_8004EA08(Session *);
extern void func_8004FFA8(Session *, f32);
extern void func_80050208(Session *);
extern void func_80051898(s32);
extern void func_8005163C(Session *);

#ifndef PADDING_WORDS
#define PADDING_WORDS 3
#endif

static const s32 padding[PADDING_WORDS] = { 0 };

s32 func_8004DC0C(Session *session, u32 *command, s32 argument) {
    u8 retry;

    (void)argument;
    retry = 0;
    session->unk60 = 0;
    switch (command[0]) {
    case 0x4C6F6164:
        func_8000AC90(0x3800);
        session->flags &= ~1;
        func_8004EA08(session);
        session->flags |= 1;
        session->flags |= 4;
        func_8000AB24(-0x67, 0, 0, 0, 0xFF);
        D_800A4BDC = 1;
        func_800469B4(session, 0);
        func_80051898(1);
        func_8004BDFC();
        break;
    case 0x41627274:
        func_8004FFA8(session, 1.0f);
        session->flags |= 1;
        if (session->unk64 == 2) {
            session->unk64 = 0;
            func_80050208(session);
            D_800A2198 = 1;
        } else {
            D_800A2198 = 3;
        }
        func_8000AB24(-0x67, 0, 0, 0, 0xFF);
        D_800A4BDC = 1;
        if (session->unk68 >= 0) {
            switch (session->unk68) {
            case 0:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                D_800A2198 = 1;
                break;
            case 1:
                D_800A2198 = 14;
                break;
            default:
                D_800A2198 = 3;
                break;
            }
        }
        session->unk68 = -1;
        if (D_800A5998 != 0) {
            retry = 1;
        } else {
            func_800469B4(session, D_800A2198);
        }
        break;
    case 0x46696E69:
        func_8004FFA8(session, 1.0f);
        session->flags |= 1;
        D_800A2198 = 5;
        func_8005163C(session);
        func_8000AB24(-0x67, 0, 0, 0, 0xFF);
        D_800A4BDC = 1;
        if (session->unk68 >= 0) {
            switch (session->unk68) {
            case 0:
            case 15:
                D_800A2198 = 1;
                break;
            case 1:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                D_800A2198 = 14;
                break;
            default:
                D_800A2198 = 12;
                break;
            }
        }
        if (session->unk68 < 9 || session->unk68 >= 15) {
            session->unk68 = -1;
        } else {
            session->unk68 = session->unk68 + 1;
        }
        if (D_800A5998 != 0) {
            retry = 1;
        } else {
            func_800469B4(session, D_800A2198);
        }
        break;
    case 0x52537472:
        func_8004A6A4(session, 1, 0);
        break;
    case 0x53746F70:
        session->flags &= ~1;
        break;
    default:
        return 0;
    }
    if (retry != 0) {
        if ((s32)(u8)(++D_800A4BFC) < 5) {
            func_8004A6A4(session, 1, 0);
            return 1;
        }
        session->flags &= ~8;
        D_800A4BFC = 0;
        D_800A5998 = 0;
        session->unk64 = 0;
        if (session->unk5E == 3) {
            session->unk5D = D_800A2344;
        } else {
            session->unk5D = D_800A2320[D_800A21B5];
        }
        func_800469B4(session, 1);
    }
    return 1;
}
