#ifndef PODCRUISE_OBJECT_ACCESSORS_H
#define PODCRUISE_OBJECT_ACCESSORS_H

#include "podcruise/types.h"

void func_80017D48(void *object, s32 value);
void func_80017D58(void *object, s32 index, f32 value);
u32 func_80017DA4(const void *object);
s32 func_80017DAC(const void *object);
s16 func_80017DDC(const void *object);
s16 func_80017DE4(const void *object);
u32 func_80017DEC(const void *object);
void func_80017DF4(const void *object, s32 mode, s32 *first, s32 *second);
void func_80017E20(const void *object, f32 *output);
s32 func_80017E54(const void *object);
u32 func_80017E5C(const void *object, s32 index);
void func_80017E70(void *object, s32 selector, s32 value);
u32 func_80017EDC(const void *object);
s32 func_80017EE4(const void *object);
void func_80017EEC(void *object, s32 value);
u32 func_80017EF4(const void *object);
s32 func_80017F20(void);
u32 func_80017DB4(const void *object, s32 index);
s32 func_80017E88(const void *object, s32 selector);
void func_80017EFC(void *object, u32 mask);
void func_80017F0C(void *object, u32 mask);
void *func_80017F28(s32 index);
void func_80017F64(const void *object, f32 *first, f32 *second);
void func_80017FD0(void *object, const f32 *input);
void func_80018084(void *object, s32 selector, f32 value);
f32 func_800180C8(const void *object, s32 selector);
void func_80018114(void *object, s32 value);
void func_8001811C(void *object, s32 selector, s32 value);
s32 func_80018164(const void *object, s32 selector);
u32 func_800182FC(const void *object, s32 selector);
void func_80018324(void *object, u32 flags);
u32 func_800183A8(const void *object);
void func_800183B0(void *object, u32 value);
void func_800183C0(void);
void func_80018440(void);
void func_80018448(void);
void func_80018450(u32 first, u32 second);
void func_80018470(void);

#endif
