/* Independently written from specs/functions/recovered/func_8002F750.md. */

#include "podcruise/types.h"

extern s16 D_800A2836;
extern s32 D_8009A294;
extern f32 D_800A9FC0;
extern u32 D_800D76F0;
extern u32 D_800D7700;
extern f64 D_80120BF0;

extern void func_80006C00(void);
extern void func_80008548(void);
extern void func_80008610(void);
extern void func_800086F8(void);
extern void func_80008F28(void);
extern void func_80009580(void);
extern void func_80009820(void);
extern void func_8000BC10(void);
extern void func_8000C530(void);
extern void func_80018440(void);
extern void func_80018448(void);
extern void func_8002E4B4(void);
extern void func_8002E82C(s32 arg0);
extern void func_8002E8E8(void);
extern void func_8002ECA0(void);
extern void func_8002F024(void);
extern s32 func_8002F054(void);
extern void func_8002F2D0(void);
extern void func_8002FCD8(void);
extern s32 func_8002FDBC(void);
extern void func_80031324(s16 arg0, s16 arg1);
extern void func_80031640(s32 arg0);
extern void func_80039D34(void);
extern void func_8003F388(void);
extern void func_8003F474(void);
extern void func_8003F560(void);
extern void func_8003F64C(void);
extern void func_80081360(void);
extern void func_80084CC4(void);
extern void func_80085D44(void);
extern void func_80085E20(void);
extern void func_800865E8(void);
extern void func_80087198(void);

void func_8002F750(void *arg0) {
    s32 dirty;
    s32 firstPass;
    f32 remaining;

    (void)arg0;
    dirty = 0;
    func_8002FCD8();
    if (func_8002FDBC() != 0) {
        dirty = 1;
    }
    func_8002E8E8();
    func_80018448();
    if (func_8002FDBC() != 0) {
        dirty = 1;
    }
    func_800865E8();
    func_8002E4B4();
    func_80008610();
    if (func_8002FDBC() != 0) {
        dirty = 1;
    }
    func_80031324(0, D_800A2836);
    if (func_8002FDBC() != 0) {
        dirty = 1;
    }

    firstPass = 1;
    if (dirty == 0) {
        do {
            func_80008548();
            func_80008F28();
            func_80018440();
            func_8002ECA0();
            func_8000C530();
            if ((D_800D7700 & 2) != 0) {
                if ((D_800D76F0 & 0x100) != 0) {
                    D_8009A294 = 1;
                }
            }
            func_80081360();
            func_80008F28();
            func_80009580();
            func_80009820();
            func_8002F024();
            if (func_8002F054() == 0) {
                func_80006C00();
                func_8003F388();
                func_80008F28();
                func_8003F474();
                func_8003F560();
                func_80008F28();
                func_8003F64C();
            } else {
                func_8002F2D0();
            }
            func_8000BC10();
            D_8009A294 = 0;
            func_80008F28();
            func_80087198();
            if (firstPass == 0) {
                func_80085E20();
                func_80084CC4();
            }
            func_80085D44();
            firstPass = 0;
            func_80008F28();
            if (func_8002FDBC() != 0) {
                dirty = 1;
            }
        } while (dirty == 0);
    }

    func_80039D34();
    remaining = D_800A9FC0;
    func_800086F8();
    func_8002E82C(-1);
    for (;;) {
        func_80031640(-1);
        func_80081360();
        if (remaining > 0.0f) {
            remaining = (f32)((f64)remaining - D_80120BF0);
            func_80008F28();
        } else {
            remaining = 0.0f;
        }
    }
}
