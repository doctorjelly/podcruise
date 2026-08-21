/* Independently written from specs/functions/object_global_initializer.md. */

#include "podcruise/object_accessors.h"

typedef struct ObjectGlobalState {
    f32 values[6];
    s32 field_18;
    u32 flags_1C;
    s16 field_20;
    s16 field_22;
    f32 field_24;
    f32 field_28;
    s32 field_2C;
    s32 field_30;
    s16 field_34;
    s16 field_36;
    s32 field_38;
} ObjectGlobalState;

extern ObjectGlobalState D_800D6960;

void func_800183C0(void) {
    D_800D6960.flags_1C = 0;
    D_800D6960.field_18 = 0;
    D_800D6960.field_20 = 0;
    D_800D6960.field_22 = 2;
    D_800D6960.flags_1C |= 1;
    D_800D6960.flags_1C |= 8;
    D_800D6960.field_2C = 0;
    D_800D6960.field_30 = 1;
    D_800D6960.field_34 = 30;
    D_800D6960.field_36 = 0;
    D_800D6960.field_38 = 0;
    D_800D6960.values[0] = 0.0f;
    D_800D6960.values[1] = 0.0f;
    D_800D6960.values[2] = 0.0f;
    D_800D6960.values[3] = 0.0f;
    D_800D6960.values[4] = 0.0f;
    D_800D6960.values[5] = 0.0f;
    D_800D6960.field_28 = 1.0f;
    D_800D6960.field_24 = 1.0f;
}
