/* Implements the specification in specs/func_8007BDF4.md */
#include "podcruise/types.h"

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    f32 unk10;
} Entity8007BDF4;

typedef struct {
    u32 tag;
    f32 x;
    f32 y;
} Request8007BDF4;

typedef struct {
    u32 head0;
    u32 head1;
    Request8007BDF4 body;
    u32 tail;
} Packet8007BDF4;

extern void func_8003FA24(u32, Request8007BDF4 *, Entity8007BDF4 *);
extern void func_8003FD7C(Entity8007BDF4 *);

void func_8007BDF4(Entity8007BDF4 *entity) {
    Packet8007BDF4 packet;

    if (entity->unk10 > 4.0f) {
        packet.body.tag = 0x5368616B;
        packet.body.x = 0.0f;
        packet.body.y = 0.0f;
        func_8003FA24(0x634D616E, &packet.body, entity);
        entity->unk0C &= ~1;
        func_8003FD7C(entity);
    }
}
