#include <assert.h>

#include "podcruise/global_state.h"
#include "podcruise/leaf_state.h"
#include "podcruise/object_accessors.h"
#include "podcruise/runtime_leaves.h"
#include "podcruise/runtime_stubs.h"
#include "podcruise/runtime_wrappers.h"
#include "podcruise/selector_state.h"
#include "podcruise/vector_math.h"

s32 D_8009A29C;
u8 D_8009A324;
f32 D_8009AD08;
f32 D_8009AD0C;
f32 D_8009B880;
s32 D_8009B884;
u8 D_8009B870;
u8 D_8009B874[4];
s32 D_8009B810;
s16 D_800A1CD0[2];
s32 D_800A59FC;
s32 D_800A5A00;
s32 D_8011C840;
f32 D_800A6700;
f64 D_800A6750;
s32 D_800A6758;
s32 D_800A675C;
s16 D_801488B8[3];
u8 D_80120DF0[4][0x170];
extern s32 D_800A21AC;
s32 D_800A21AC;
union {
    double alignment;
    u8 bytes[0x3C];
} D_800D6960;
u32 D_800D2140[256];
f32 D_8009B878;
f32 D_8009B87C;
s32 D_800D6140[256];
s32 D_8011AC8C;
s32 D_800A268C;
s32 D_800A2690;
s32 D_800A26F4;
f32 D_800D7740;
s32 D_800A26F8;
u8 D_800A26FC;
s32 D_800DB910[256];
s32 *D_800A2DD4;
u32 D_800A48D4;
s32 D_8009A290;
s32 D_8009A28C;
s32 D_8009A2A0;
s32 D_800AF4C0[75][4];
s32 D_800D9DBC;
u8 D_800D9C70[32];
u8 D_8014C3B8[32];
u8 D_8014C4D8[32];

static s32 calls_80007218;
static s32 calls_8000F5A0;

void func_80007218(void) { calls_80007218++; }
void func_8000F5A0(void) { calls_8000F5A0++; }

/* Recovered dependencies observed through their own state instead of a double. */
extern s32 D_8009A2B8;
extern s32 D_800D2038[];
extern s32 D_800A2868;
extern s32 D_800D9DD8[];
extern s32 D_800A1D88;
extern void *D_800A1D8C;
extern void *D_800D6940[];
extern s32 D_800A290C[];
extern u8 D_800D68C0[];

static f32 result_80014D4C;
static s32 calls_8002FF38;
static void *argument_8002FF38;

f32 func_80014D4C(void) { return result_80014D4C; }
void func_8002FF38(void *argument) {
    calls_8002FF38++;
    argument_8002FF38 = argument;
}

static s32 result_80030174;
static s32 calls_8003FB78;
static s32 argument_8003FB78;
static s32 second_8003FB78;
static s32 third_8003FB78;
static s32 calls_80038F68;
static s32 argument_80038F68;
static s32 result_80087E80;
static void *argument_80087E80;
static s32 second_80087E80;
static s32 third_80087E80;
static void *argument_80039178;
static s32 size_80039178;
static s32 calls_8008C930;
static void *argument_8008C930[2];
static s32 second_8008C930;
static s32 third_8008C930;
static f32 argument_80014CC0;

void func_80030174(s32 argument, s32 *output) {
    *output = argument + result_80030174;
}
void func_8003FB78(s32 argument, s32 second, s32 third) {
    calls_8003FB78++;
    argument_8003FB78 = argument;
    second_8003FB78 = second;
    third_8003FB78 = third;
}
void func_80038F68(s32 argument) {
    calls_80038F68++;
    argument_80038F68 = argument;
}
s32 func_80087E80(void *argument, s32 second, s32 third) {
    argument_80087E80 = argument;
    second_80087E80 = second;
    third_80087E80 = third;
    return result_80087E80;
}
void func_80039178(void *argument, s32 size) {
    argument_80039178 = argument;
    size_80039178 = size;
}
void func_8008C930(void *argument, s32 second, s32 third) {
    argument_8008C930[calls_8008C930++] = argument;
    second_8008C930 = second;
    third_8008C930 = third;
}

void func_80014CC0(f32 argument, f32 *numerator, f32 *denominator) {
    argument_80014CC0 = argument;
    *numerator = 15.0f;
    *denominator = 3.0f;
}


int main(void) {
    union {
        double alignment;
        u8 bytes[0x200];
    } object = {0};
    s16 first;
    s16 second;
    s32 first_word;
    s32 second_word;
    f32 copied[6];
    u32 items[3] = {10, 20, 30};
    s32 pointer_words[2] = {17, 23};
    s32 output;
    void *tail = 0;
    void *head = &tail;
    PcVec2f vec2_left = {3.0f, 4.0f};
    PcVec2f vec2_right = {1.0f, -2.0f};
    PcVec2f vec2_output;
    PcVec3f vec3_left = {1.0f, 2.0f, 3.0f};
    PcVec3f vec3_right = {4.0f, -1.0f, 2.0f};
    PcVec3f vec3_output;
    PcVec3fSlot vec3_slots[4] = {0};
    PcVec3fSlot source_slots[4] = {
        {{1.0f, 2.0f, 3.0f}, 4.0f},
        {{5.0f, 6.0f, 7.0f}, 8.0f},
        {{9.0f, 10.0f, 11.0f}, 12.0f},
        {{13.0f, 14.0f, 15.0f}, 16.0f},
    };
    PcVec3fSlot output_slots[4] = {0};

    func_8001514C(&vec2_output, &vec2_left, &vec2_right);
    assert(vec2_output.x == 4.0f && vec2_output.y == 2.0f);
    func_80015170(&vec2_output, 2.0f, &vec2_left);
    assert(vec2_output.x == 6.0f && vec2_output.y == 8.0f);
    func_80015190(&vec2_output, &vec2_left, 2.0f, &vec2_right);
    assert(vec2_output.x == 5.0f && vec2_output.y == 0.0f);
    assert(func_800151C0(&vec2_left) == 5.0f);

    func_80015268(&vec3_output, -2.0f, 5.0f, 7.0f);
    assert(vec3_output.x == -2.0f && vec3_output.y == 5.0f && vec3_output.z == 7.0f);
    func_80015288(&vec3_output, &vec3_left);
    assert(vec3_output.x == 1.0f && vec3_output.y == 2.0f && vec3_output.z == 3.0f);
    func_80015328(&vec3_output, &vec3_left, &vec3_right);
    assert(vec3_output.x == 5.0f && vec3_output.y == 1.0f && vec3_output.z == 5.0f);
    func_8001535C(&vec3_output, &vec3_left, &vec3_right);
    assert(vec3_output.x == -3.0f && vec3_output.y == 3.0f && vec3_output.z == 1.0f);
    assert(func_80015390(&vec3_left, &vec3_right) == 8.0f);
    vec3_output.x = 2.0f;
    vec3_output.y = 3.0f;
    vec3_output.z = 6.0f;
    assert(func_800153C0(&vec3_output) == 7.0f);
    assert(func_800153EC(&vec3_left, &vec3_right) == 19.0f);
    func_800155C0(&vec3_output, 2.0f, &vec3_left);
    assert(vec3_output.x == 2.0f && vec3_output.y == 4.0f && vec3_output.z == 6.0f);
    func_800155EC(&vec3_output, &vec3_left, 2.0f, &vec3_right);
    assert(vec3_output.x == 9.0f && vec3_output.y == 0.0f && vec3_output.z == 7.0f);
    func_80015694(vec3_slots, 3, &vec3_left);
    func_800156B8(vec3_slots, 3, &vec3_output);
    assert(vec3_output.x == 1.0f && vec3_output.y == 2.0f && vec3_output.z == 3.0f);
    func_800156DC(output_slots, source_slots);
    assert(output_slots[0].value.x == 1.0f && output_slots[0].padding == 4.0f);
    assert(output_slots[3].value.z == 15.0f && output_slots[3].padding == 16.0f);

    D_8009A290 = 0;
    D_8009A28C = 0;
    func_80005B1C(3, 7);
    func_80005B1C(5, -2);
    func_80005B1C(4, 99);
    assert(D_8009A290 == 7 && D_8009A28C == -2);
    assert(func_80005B44(3) == 7);
    assert(func_80005B44(5) == -2);
    assert(func_80005B44(4) == -1);
    D_8009A2A0 = 23;
    for (s32 index = 0; index < 75; index++) {
        D_800AF4C0[index][0] = index + 1;
        D_800AF4C0[index][1] = index + 2;
        D_800AF4C0[index][2] = index + 3;
        D_800AF4C0[index][3] = index + 4;
    }
    func_80005B80();
    assert(D_8009A2A0 == 0);
    assert(D_800AF4C0[0][0] == 0 && D_800AF4C0[74][3] == 0);

    D_8009A2B8 = 1;
    for (s32 record = 0; record < 8; record++) {
        D_800D2038[record * 8 + 6] = 5;
    }
    func_80008610();
    func_800086F8();
    func_800118F8();
    assert(calls_80007218 == 1 && calls_8000F5A0 == 1);
    /* func_800086F8 reaches the recovered func_80007A44, which clears the
       counter field of all eight records when the enable flag is set. */
    assert(D_800D2038[6] == 0 && D_800D2038[7 * 8 + 6] == 0);
    D_8009B870 = 1;
    /* func_800117F0 reaches the recovered func_800116E8, which clears all
       eighty flag bytes, so the effect is observable directly. */
    D_800D68C0[0] = 1;
    D_800D68C0[79] = 1;
    func_800117F0();
    assert(D_8009B870 == 0);
    assert(D_800D68C0[0] == 0 && D_800D68C0[79] == 0);

    result_80014D4C = 12.5f;
    assert(func_80014F2C() == 77.5f);
    D_800D9DBC = 100;
    D_800A2868 = 1;
    D_800D9DD8[1] = 37;
    assert(func_8002FC58() == 63);
    /* func_80030154 forwards its argument untouched to func_8002FF38. */
    func_80030154(&object);
    /* func_80031924 forwards its index untouched to func_80031BBC, which marks
       the slot and then clears the matching record; both are recovered source
       now, so the effect is observable directly. */
    func_80031924(0);
    assert(calls_8002FF38 == 1 && argument_8002FF38 == &object);
    assert(D_800A290C[0] == -1);
    result_80030174 = 9;
    assert(func_80030274(13) == 22);
    func_80030304(-7);
    assert(calls_8003FB78 == 1 && argument_8003FB78 == -7);
    assert(second_8003FB78 == 0 && third_8003FB78 == 0);
    /* func_80031BBC is recovered source now; its own slot table is exercised
       by its own unit rather than by a call counter here. */
    func_800319CC(4);

    func_80065C50(object.bytes, &vec3_left);
    func_80065C74(object.bytes, &vec3_right);
    assert(((PcVec3f *)(object.bytes + 0x50))->x == 1.0f);
    assert(((PcVec3f *)(object.bytes + 0x74))->z == 2.0f);
    func_80065C50(0, &vec3_right);
    func_80065C74(0, &vec3_left);
    func_80086CA0(-1);
    assert(calls_80038F68 == 0);
    func_80086CA0(42);
    assert(calls_80038F68 == 1 && argument_80038F68 == 42);
    /* func_8008B190 reaches func_80093980, which is now recovered source and
       writes a memory-mapped hardware register. That address is unmapped in a
       host process, so this path is exercised by the byte-match verifier
       rather than here. */

    D_800D9DD8[1] = 10;
    assert(func_8002FB18(9) == 1 && func_8002FB18(10) == 0);
    result_80087E80 = -1;
    assert(func_8002FDBC() == 0);
    result_80087E80 = 0;
    assert(func_8002FDBC() == 1);
    assert(argument_80087E80 == D_800D9C70);
    assert(second_80087E80 == 0 && third_80087E80 == 0);
    func_8003931C(object.bytes);
    assert(argument_80039178 == object.bytes + 4 && size_80039178 == 0x3EC);
    /* func_80039768 forwards only the records that differ from their shadow
       copy. With both tables zeroed nothing is forwarded, which is what makes
       this call safe: its callee func_800393DC is now recovered source and
       traps on a misaligned length, so there is no effect left to assert. */
    func_80039890();

    func_8000AC90((u16)0x1234ABCD);
    assert(D_800A48D4 == 0xABCD);
    D_800A1D88 = 4;
    D_800D6940[2] = &object;
    func_80011EA4((s16)0x12340002);
    assert(D_800A1D8C == &object);
    func_80011EA4((s16)0x1234ABCD);
    D_800D6940[0] = &vec3_left;
    func_80011EA4(0);
    assert(D_800A1D8C == &vec3_left);
    func_80090634();
    func_80093864();
    assert(calls_8008C930 == 2);
    assert(argument_8008C930[0] == D_8014C3B8);
    assert(argument_8008C930[1] == D_8014C4D8);
    assert(second_8008C930 == 0 && third_8008C930 == 0);
    assert(func_80014D20(2.5f) == 5.0f);
    assert(argument_80014CC0 == 2.5f);
    /* func_8003F8FC is recovered source now. It builds a sixteen-word message
       and hands it to func_80018450, which is an empty stub in the original
       game, so the path has no observable effect left to assert on. The call
       is kept because it still exercises the message construction. */
    func_8003F974(17, &tail);

    D_8009A29C = 2;
    func_80005AFC();
    assert(D_8009A29C == 1);
    D_8009A29C = 0;
    func_80005AFC();
    assert(D_8009A29C == 0);
    D_8009A29C = -2;
    func_80005AFC();
    assert(D_8009A29C == -2);

    func_80008750(0x23);
    assert(D_8009A324 == 0x23);

    func_80008F58(1.5f, -2.0f);
    assert(D_8009AD08 == 1.5f);
    assert(D_8009AD0C == -2.0f);
    func_800117E4(7.0f);
    assert(D_8009B880 == 7.0f);

    D_8009B870 = 0;
    func_80011814();
    assert(D_8009B870 == 1);
    D_8009B810 = 0;
    func_80011918();
    assert(D_8009B810 == 1);

    func_80011ECC(-123, 456);
    assert(D_800A1CD0[0] == -123);
    assert(D_800A1CD0[1] == 456);
    first = 0;
    second = 0;
    func_80011EE8(&first, &second);
    assert(first == -123);
    assert(second == 456);

    func_8005D310(0x12345678, -9);
    assert(D_800A59FC == 0x12345678);
    assert(D_800A5A00 == -9);
    func_80065804(42);
    assert(D_8011C840 == 42);

    D_800A6700 = 3.25f;
    assert(func_8007EE40() == 3.25f);
    func_800811C0(-1.0);
    assert(D_800A6750 == -1.0);
    D_800A6758 = 0;
    func_800811CC();
    assert(D_800A6758 == 1);
    D_800A675C = 7;
    func_80081260();
    assert(D_800A675C == 0);

    func_80086CC8(-1, 2, 32767);
    assert(D_801488B8[0] == -1);
    assert(D_801488B8[1] == 2);
    assert(D_801488B8[2] == 32767);

    func_80006E50(object.bytes, 0x12);
    assert(*(u32 *)&object.bytes[0x100] == 0x12);
    func_80006E50(object.bytes, 0x41);
    assert(*(u32 *)&object.bytes[0x100] == 0x53);
    func_80006E60(object.bytes, 0x11);
    assert(*(u32 *)&object.bytes[0x100] == 0x42);
    func_80006EB4(object.bytes, 2.5f);
    assert(*(f32 *)&object.bytes[0x110] == 2.5f);
    func_80006F28(object.bytes, -4.0f);
    assert(*(f32 *)&object.bytes[0xDC] == -4.0f);

    D_800D2140[3] = 0x52;
    assert(func_80009524(3, 0x12) == 0x12);
    func_8000953C(3, 0x80);
    assert(D_800D2140[3] == 0xD2);
    func_8000955C(3, 0x50);
    assert(D_800D2140[3] == 0x82);

    func_80011764(6.0f, 9.0f);
    assert(D_8009B878 == 6.0f);
    assert(D_8009B87C == 9.0f);
    func_80011778((u8)0x123, (u8)0x234, (u8)0x345, (u8)0x456);
    assert(D_8009B874[0] == 0x23);
    assert(D_8009B874[1] == 0x34);
    assert(D_8009B874[2] == 0x45);
    assert(D_8009B874[3] == 0x56);
    func_80011824(4, -17);
    assert(D_800D6140[4] == -17);
    D_8009B810 = 3;
    func_80011928();
    assert(D_8009B810 == 0);
    D_8011AC8C = 1234;
    assert(func_8005EEFC() == 1234);

    func_80017D48(object.bytes, 0x12345678);
    assert(*(s32 *)&object.bytes[0x1C] == 0x12345678);
    func_80017D58(object.bytes, 2, 6.5f);
    assert(*(f32 *)&object.bytes[0x24] == 6.5f);
    func_80017D58(object.bytes, -1, 9.0f);
    assert(*(f32 *)&object.bytes[0x18] == 0.0f);

    *(u32 *)&object.bytes[0x00] = 0x89ABCDEF;
    *(s32 *)&object.bytes[0x14] = 3;
    *(s16 *)&object.bytes[0x20] = -12;
    *(s16 *)&object.bytes[0x22] = 34;
    assert(func_80017DA4(object.bytes) == 0x89ABCDEF);
    assert(func_80017DAC(object.bytes) == 3);
    assert(func_80017DDC(object.bytes) == -12);
    assert(func_80017DE4(object.bytes) == 34);
    assert(func_80017DEC(object.bytes) == *(u32 *)&object.bytes[0x24]);

    *(s32 *)&object.bytes[0x2C] = 11;
    *(s32 *)&object.bytes[0x28] = 22;
    func_80017DF4(object.bytes, 0, &first_word, &second_word);
    assert(first_word == 11);
    assert(second_word == 22);
    func_80017DF4(object.bytes, 1, &first_word, &second_word);
    assert(first_word == 0);
    assert(second_word == 0);

    *(f32 *)&object.bytes[0x08] = 1.0f;
    *(f32 *)&object.bytes[0x0C] = 2.0f;
    *(f32 *)&object.bytes[0x10] = 3.0f;
    *(f32 *)&object.bytes[0x14] = 4.0f;
    *(f32 *)&object.bytes[0x18] = 5.0f;
    *(f32 *)&object.bytes[0x1C] = 6.0f;
    func_80017E20(object.bytes, copied);
    assert(copied[0] == 1.0f && copied[5] == 6.0f);
    assert(func_80017E54(object.bytes) == *(s32 *)&object.bytes[0x14]);
    *(u32 **)&object.bytes[0x18] = items;
    assert(func_80017E5C(object.bytes, 1) == 20);
    func_80017E70(object.bytes, 1, 99);
    assert(*(s32 *)&object.bytes[0x08] != 99);
    func_80017E70(object.bytes, 2, 99);
    assert(*(s32 *)&object.bytes[0x08] == 99);

    assert(func_80017EDC(object.bytes) == *(u32 *)&object.bytes[0x00]);
    func_80017EEC(object.bytes, -7);
    assert(func_80017EE4(object.bytes) == -7);
    assert(func_80017EF4(object.bytes) == *(u32 *)&object.bytes[0x00]);
    assert(func_80017F20() == 4);

    *(u32 **)&object.bytes[0x18] = items;
    assert(func_80017DB4(object.bytes, 2) == 30);
    assert(func_80017DB4(0, 0) == 0);

    *(u32 *)&object.bytes[0x00] = 0;
    assert(func_80017E88(object.bytes, 1) == 0);
    *(u32 *)&object.bytes[0x00] = 0x08;
    assert(func_80017E88(object.bytes, 1) == 1);
    *(u32 *)&object.bytes[0x00] = 0x40;
    assert(func_80017E88(object.bytes, 1) == 2);
    *(u32 *)&object.bytes[0x00] = 0x48;
    assert(func_80017E88(object.bytes, 1) == 3);
    assert(func_80017E88(0, 1) == -1);
    assert(func_80017E88(object.bytes, 2) == -1);

    *(u32 *)&object.bytes[0x00] = 0x30;
    func_80017EFC(object.bytes, 0x05);
    assert(*(u32 *)&object.bytes[0x00] == 0x35);
    func_80017F0C(object.bytes, 0x14);
    assert(*(u32 *)&object.bytes[0x00] == 0x21);
    assert(func_80017F28(-1) == 0);
    assert(func_80017F28(0) == D_80120DF0[0]);
    assert(func_80017F28(3) == D_80120DF0[3]);
    assert(func_80017F28(4) == 0);

    *(f32 *)&object.bytes[0x148] = 0.0f;
    *(f32 *)&object.bytes[0x14C] = 0.0f;
    *(f32 *)&object.bytes[0x150] = 0.0f;
    func_80018084(object.bytes, 2, 2.5f);
    func_80018084(object.bytes, 3, 3.5f);
    func_80018084(object.bytes, 5, 5.5f);
    func_80018084(object.bytes, 1, 9.5f);
    assert(func_800180C8(object.bytes, 2) == 2.5f);
    assert(func_800180C8(object.bytes, 3) == 3.5f);
    assert(func_800180C8(object.bytes, 5) == 5.5f);
    assert(func_800180C8(object.bytes, 1) == -1.0f);

    func_80018114(object.bytes, -18);
    assert(*(s32 *)&object.bytes[0x168] == -18);
    *(s32 *)&object.bytes[0x158] = 0;
    *(s32 *)&object.bytes[0x15C] = 0;
    *(s32 *)&object.bytes[0x160] = 0;
    *(s32 *)&object.bytes[0x164] = 0;
    func_8001811C(object.bytes, 4, 14);
    func_8001811C(object.bytes, 3, 13);
    func_8001811C(object.bytes, 6, 16);
    func_8001811C(object.bytes, 5, 15);
    assert(*(s32 *)&object.bytes[0x15C] == 14);
    assert(*(s32 *)&object.bytes[0x164] == 13);
    assert(*(s32 *)&object.bytes[0x158] == 16);
    assert(*(s32 *)&object.bytes[0x160] == 15);
    assert(func_80018164(object.bytes, 4) == 14);
    assert(func_80018164(object.bytes, 3) == 13);
    assert(func_80018164(object.bytes, 6) == 16);
    assert(func_80018164(object.bytes, 5) == 15);
    assert(func_80018164(object.bytes, 0) == -1);

    *(u32 *)&object.bytes[0x04] = 41;
    *(u32 *)&object.bytes[0x08] = 82;
    assert(func_800182FC(object.bytes, 0) == 82);
    assert(func_800182FC(object.bytes, 2) == 41);
    assert(func_800182FC(object.bytes, 1) == 0);

    *(s32 *)&object.bytes[0x14] = 7;
    *(s32 *)&object.bytes[0x18] = 8;
    func_80018324(object.bytes, 0x10);
    assert(*(u32 *)&object.bytes[0x00] == 0x10);
    assert(*(s32 *)&object.bytes[0x04] == -1);
    assert(*(s32 *)&object.bytes[0x08] == -1);
    assert(*(s16 *)&object.bytes[0x0C] == 0);
    assert(*(s16 *)&object.bytes[0x0E] == 0);
    assert(*(s32 *)&object.bytes[0x10] == 0);
    assert(*(s32 *)&object.bytes[0x14] == 7);
    assert(*(s32 *)&object.bytes[0x18] == 8);

    func_80018324(object.bytes, 0xD065);
    assert(*(s32 *)&object.bytes[0x14] == 0);
    assert(*(s32 *)&object.bytes[0x18] == 0);
    assert(*(f32 *)&object.bytes[0x20] == 0.0f);
    assert(*(f32 *)&object.bytes[0x4C] == 0.0f);
    assert(*(f32 *)&object.bytes[0x1C] == 1.0f);
    assert(*(f32 *)&object.bytes[0x2C] == 1.0f);
    assert(*(f32 *)&object.bytes[0x3C] == 1.0f);

    func_800183B0(object.bytes, 0x1234);
    assert(func_800183A8(object.bytes) == 0x1234);
    *(u32 *)&D_800D6960.bytes[0x1C] = 0xFFFFFFFF;
    func_800183C0();
    assert(*(u32 *)&D_800D6960.bytes[0x1C] == 9);
    assert(*(s32 *)&D_800D6960.bytes[0x18] == 0);
    assert(*(s16 *)&D_800D6960.bytes[0x20] == 0);
    assert(*(s16 *)&D_800D6960.bytes[0x22] == 2);
    assert(*(f32 *)&D_800D6960.bytes[0x00] == 0.0f);
    assert(*(f32 *)&D_800D6960.bytes[0x14] == 0.0f);
    assert(*(f32 *)&D_800D6960.bytes[0x24] == 1.0f);
    assert(*(f32 *)&D_800D6960.bytes[0x28] == 1.0f);
    assert(*(s32 *)&D_800D6960.bytes[0x2C] == 0);
    assert(*(s32 *)&D_800D6960.bytes[0x30] == 1);
    assert(*(s16 *)&D_800D6960.bytes[0x34] == 30);
    assert(*(s16 *)&D_800D6960.bytes[0x36] == 0);
    assert(*(s32 *)&D_800D6960.bytes[0x38] == 0);
    func_80018440();
    func_80018448();
    func_80018450(0xEE06, 0x12345678);
    D_800A21AC = 0;
    func_80018470();
    assert(D_800A21AC == 5);

    func_80006FD4();
    func_80006FDC();
    func_80008540(object.bytes);
    func_80008530();
    func_8000C530();
    func_80033DC4();
    func_8002F1E4();
    func_800390A4();
    func_800827C0(object.bytes);

    func_8002DFB0(1, 2);
    D_800A268C = 4;
    D_800A2690 = 5;
    func_8002E028();
    func_8002E0A8();
    assert(D_800A268C == 0 && D_800A2690 == 0);
    D_800A26F4 = -12;
    D_800D7740 = 6.25f;
    assert(func_8002F054() == -12);
    assert(func_8002F060() == 6.25f);
    D_800A26F8 = 9;
    D_800A26FC = 0;
    func_8002F1CC();
    assert(D_800A26F8 == 0 && D_800A26FC == 1);
    D_800DB910[7] = 0;
    func_80031BEC(7);
    assert(D_800DB910[7] == 1);
    D_800A2DD4 = pointer_words;
    func_80031F94();
    assert(pointer_words[0] == 17 && pointer_words[1] == 0);
    func_8003D488(0xABCD);
    assert(D_800A48D4 == 0xABCD);
    assert(func_80073708(object.bytes) == 0);
    output = 99;
    assert(func_8007F22C(object.bytes, &output) == 0 && output == 0);
    output = 99;
    assert(func_8007F23C(object.bytes, &output) == 0 && output == 0);
    assert(func_80080350(object.bytes) == 0.0f);
    func_800834DC(1, 2, 3, 4);
    assert(func_8008D274(&head) == &tail);
    assert(head == 0);

    return 0;
}
