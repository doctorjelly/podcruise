/* Independently written from the specification in specs/func_80060880.md
   (race session start-up). */

#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 tag;
    s32 rest[32];
} Entrant;

typedef struct {
    s32 pad0[76];
    s32 unk130;
    s32 pad1[30];
    s32 unk1AC;
    s32 pad2[3];
    s32 unk1BC;
    s32 unk1C0;
} Session;

extern s32 D_8009B80C;
extern s32 D_800A26B8;
extern s32 D_800A52B8;
extern s32 D_800A52BC;
extern s32 D_800A52D8;
extern s32 D_800A5B5C;
extern s32 D_800A6950;
extern s32 D_800A6954[2];
extern s32 D_800A695C[2];
extern s32 D_800D74C0[];
extern s32 D_800D9C28[];
extern Entrant *D_8011B1BC;
extern Entrant *D_8011B1C0;
extern Entrant *D_8011B1C4;
extern Entrant *D_8011B1C8;
extern s32 D_8011B1CC;
extern s32 D_8011B1D0;
extern s32 D_8011B1E0;
extern s32 D_8011B1E4;
extern s32 D_8011B1E8;
extern s32 D_8011B1F0[12];
extern s32 D_8011B220;
extern s32 D_8011B224;
extern s32 D_8011B228;
extern s16 D_8011C7E8[12];

extern s32 func_80005B80(void);
extern void func_8000955C(s32 index, s32 colour);
extern void func_80009F6C(void);
extern void func_8000FE1C(void);
extern void func_8000FE78(void);
extern void func_8000FEF0(void);
extern void func_80011838(void);
extern void func_8002E770(void);
extern void func_8002FA00(s32 arg0);
extern s32 func_8002FAFC(void);
extern void func_8002FB90(void);
extern s32 func_8002FC58(void);
extern void func_80036F7C(void);
extern void func_8005DBAC(s32 arg0, s32 arg1);
extern void func_8005EF08(Session *session);
extern void func_8005F9CC(Session *session);
extern void func_8005FA38(Session *session);
extern void func_80060030(Session *session);
extern void func_800600A0(Session *session, Entrant *entrants);
extern void func_80060668(Session *session);
extern s32 func_80087E80(s32 *queue, void **out, s32 blocking);
extern s32 func_80089BB0(s32 *arg0);
extern void func_80089C34(s32 *entry);

void func_80060880(Session *session, Entrant *entrants) {
    s16 *dst;
    s32 slot;
    s32 i;

    if (D_800A26B8 == 0) {
        func_80087E80(D_800D9C28, 0, 1);
        func_80089C34(D_800D74C0);
    }

    func_8002E770();
    func_80089BB0(D_800D9C28);

    dst = D_8011C7E8;
    for (slot = 0; slot != 12; slot++) {
        *dst = slot;
        dst++;
    }

    func_8002FA00(1);
    D_8011B1CC = func_8002FAFC();
    D_8011B1E4 = 0;
    D_800A52D8 = 0;
    func_80036F7C();
    func_80005B80();
    func_80011838();
    func_8000FEF0();
    func_8000FE1C();
    func_8000FE78();

    session->unk130 = 0;
    D_8011B1BC = 0;
    D_8011B1C0 = 0;
    D_8011B1C4 = 0;
    D_8011B1C8 = 0;
    D_800A52BC = 0;

    for (i = 0; i < session->unk1BC; i++) {
        if (entrants[i].tag == 0x4C6F636C) {
            D_800A52BC++;
            if (D_8011B1BC == 0) {
                D_8011B1BC = &entrants[i];
            } else if (D_8011B1C0 == 0) {
                D_8011B1C0 = &entrants[i];
            } else if (D_8011B1C4 == 0) {
                D_8011B1C4 = &entrants[i];
            } else if (D_8011B1C8 == 0) {
                D_8011B1C8 = &entrants[i];
            }
        }
    }

    D_800A6954[0] = 0;
    D_800A695C[0] = 0;
    D_800A6954[1] = 0;
    D_800A695C[1] = 0;
    D_800A6950 = 0;
    D_800A52B8 = 0;

    if (D_800A52BC >= 2) {
        D_8009B80C = 0;
        D_800A6950 = 1;
        if (session->unk1AC == 6) {
            D_800A52B8 = 1;
        }
    }

    if (session->unk1AC == 3 && session->unk1C0 == 2) {
        D_800A5B5C = 1;
    } else if (session->unk1AC == 1 && session->unk1C0 == 0) {
        D_800A5B5C = 2;
    } else {
        D_800A5B5C = 0;
    }

    func_8005EF08(session);
    func_8005DBAC(session->unk1AC, session->unk1C0);
    func_8005F9CC(session);
    func_8005FA38(session);
    func_80060030(session);
    func_80060668(session);
    func_800600A0(session, entrants);
    func_80009F6C();

    for (i = 0; i != 12; i++) {
        func_8000955C(i, 0xFF0000);
    }

    D_8011B1D0 = func_8002FAFC();
    D_8011B224 = func_8002FC58();

    D_8011B220 = D_8011B1D0 - D_8011B1CC;
    D_8011B228 = 0x400000;
    D_8011B228 -= D_8011B220;
    D_8011B228 -= D_8011B224;

    for (slot = 0; slot != 12; slot++) {
        D_8011B220 -= D_8011B1F0[slot];
    }
    D_8011B220 -= D_8011B1E0;
    D_8011B220 -= D_8011B1E4;
    D_8011B220 -= D_8011B1E8;

    func_8002FB90();
}
