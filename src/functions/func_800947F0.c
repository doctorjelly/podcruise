/* Recovered from specs/func_800947F0.md (renderer service loop). */
#include "podcruise/types.h"

typedef struct Unk800947F0_Entry {
    u8 unk00[36];
} Unk800947F0_Entry;

typedef struct Unk800947F0_Command {
    s32 unk00;
    s32 unk04;
    u8 unk08[4];
    s32 unk0C;
} Unk800947F0_Command;

typedef struct Unk800947F0_Task {
    s32 unk00;
    u16 unk04;
    u16 unk06;
    s32 unk08;
    u8 unk0C[4];
    u32 unk10;
    u8 unk14[4];
    Unk800947F0_Entry unk18[1];
} Unk800947F0_Task;

typedef struct Unk800947F0_Payload {
    u8 unk00[4];
    u8 unk04;
    u8 unk05[0xF];
    s32 unk14;
    u8 unk18[2];
    u16 unk1A;
    u8 unk1C[0x10];
    s32 unk2C;
} Unk800947F0_Payload;

typedef struct Unk800947F0_Message {
    u16 unk00;
    u8 unk02[2];
    void *unk04;
    void *unk08;
    void *unk0C;
    void *unk10;
    Unk800947F0_Payload *unk14;
} Unk800947F0_Message;

typedef struct Unk800947F0_Context {
    u8 unk00[8];
    void *unk08;
    void *unk0C;
    void *unk10;
    s32 (*unk14)(s32, void *, void *, void *);
    s32 (*unk18)(void *, s32, void *, void *, void *);
} Unk800947F0_Context;

extern void func_80087E80(void *queue, void *output, s32 mode);
extern void func_80097990(u32 arg0);
extern s32 func_800979F0(void *handle, u32 offset, u32 value);
extern s32 func_80097B80(void *handle, u32 offset, u32 *output);
extern void func_80097D20(u32 arg0);
extern void func_80097D70(void);
extern s32 func_8008C930(void *queue, void *value, s32 mode);

void func_800947F0(Unk800947F0_Context *arg0) {
    Unk800947F0_Message *message;
    void *spare40;
    void *spare3C;
    s32 status;
    Unk800947F0_Context *context;
    s32 pending;
    Unk800947F0_Command *command;
    Unk800947F0_Task *task;
    u32 probe;

    pending = 0;
    message = 0;
    status = 0;
    context = arg0;

    while (1) {
        func_80087E80(context->unk08, &message, 1);
        if ((message->unk14 != 0) && (message->unk14->unk04 == 2) &&
            ((message->unk14->unk14 == 0) || (message->unk14->unk14 == 1))) {
            task = (Unk800947F0_Task *)&message->unk14->unk14;
            command = (Unk800947F0_Command *)&task->unk18[task->unk06];
            task->unk08 = -1;
            if (task->unk04 != 3) {
                command->unk04 = command->unk04 - command->unk0C;
            }
            if ((task->unk04 == 2) && (message->unk14->unk14 == 0)) {
                pending = 1;
            } else {
                pending = 0;
            }
            func_80087E80(context->unk10, &spare3C, 1);
            func_80097990(0x100401);
            func_800979F0(message->unk14, 0x5000510, task->unk10 | 0x80000000);
            do {
                func_80087E80(context->unk0C, &spare40, 1);
                task = (Unk800947F0_Task *)&message->unk14->unk14;
                command = (Unk800947F0_Command *)&task->unk18[task->unk06];
                if (command->unk00 == 0x1D) {
                    func_800979F0(message->unk14, 0x5000510, task->unk10 | 0x10000000);
                    func_800979F0(message->unk14, 0x5000510, task->unk10);
                    func_80097B80(message->unk14, 0x5000508, &probe);
                    if ((probe & 0x02000000) != 0) {
                        func_800979F0(message->unk14, 0x5000510, task->unk10 | 0x01000000);
                    }
                    command->unk00 = 4;
                    *(u32 *)0xA4600010 = 2;
                    func_80097D20(0x100C01);
                }
                func_8008C930(message->unk04, message, 0);
                if ((pending == 1) && (message->unk14->unk2C == 0)) {
                    pending = 0;
                } else {
                    break;
                }
            } while (1);
            func_8008C930(context->unk10, 0, 0);
            if (message->unk14->unk1A == 1) {
                func_80097D70();
            }
        } else {
            switch (message->unk00) {
            case 11:
                func_80087E80(context->unk10, &spare3C, 1);
                status = context->unk14(0, message->unk0C, message->unk08, message->unk10);
                break;
            case 12:
                func_80087E80(context->unk10, &spare3C, 1);
                status = context->unk14(1, message->unk0C, message->unk08, message->unk10);
                break;
            case 15:
                func_80087E80(context->unk10, &spare3C, 1);
                status = context->unk18(message->unk14, 0, message->unk0C, message->unk08,
                                        message->unk10);
                break;
            case 16:
                func_80087E80(context->unk10, &spare3C, 1);
                status = context->unk18(message->unk14, 1, message->unk0C, message->unk08,
                                        message->unk10);
                break;
            case 10:
                func_8008C930(message->unk04, message, 0);
                status = -1;
                break;
            default:
                status = -1;
                break;
            }
            if (status == 0) {
                func_80087E80(context->unk0C, &spare40, 1);
                func_8008C930(message->unk04, message, 0);
                func_8008C930(context->unk10, 0, 0);
            }
        }
    }
}
