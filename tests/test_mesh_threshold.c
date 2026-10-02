#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "../src/functions/func_800834F0.c"

s32 D_800A6890 = 1;
Vertex D_800A6808[6];
Command D_800A6868[6];
f32 D_800ADD10 = 0.1f;
f64 D_800ADD18 = 0.8;
f64 D_800ADD20 = 0.7;
f64 D_800ADD28 = 0.3;
f64 D_800ADD30 = 0.2;
f32 D_80120C40[64];

static s32 mockNodeFlags;
static s32 nodeQueryCount;

void func_80014CC0(f32 angle, f32 *sine, f32 *cosine) {
    (void)angle;
    *sine = 0.0f;
    *cosine = 1.0f;
}

s32 func_80017DA4(Node *node) {
    (void)node;
    nodeQueryCount++;
    return mockNodeFlags;
}

s32 func_80017DAC(Node *node) {
    (void)node;
    return 0;
}

static void init_templates(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_800A6808[i].unk00 = (s16)(10 + i);
        D_800A6808[i].unk02 = (s16)(20 + i);
        D_800A6808[i].unk04 = (s16)(30 + i);
        D_800A6808[i].unk06 = (s16)(40 + i);
        D_800A6808[i].unk08 = (s16)(50 + i);
        D_800A6808[i].unk0A = (s16)(60 + i);
        D_800A6808[i].color = ((u32)(70 + i) << 24) |
                              ((u32)(80 + i) << 16) |
                              ((u32)(90 + i) << 8) | (u32)(100 + i);

        D_800A6868[i].w0 = 0xA0000000u + (u32)i;
        D_800A6868[i].w1 = 0xB0000000u + (u32)i;
    }
}

static void run_mesh(f32 arg5, Vertex *vertices, Command *commands) {
    void *children[1];
    Mesh mesh;
    Node node;

    memset(vertices, 0xCD, sizeof(Vertex) * 27);
    memset(commands, 0xCD, sizeof(Command) * 26);
    memset(&mesh, 0, sizeof(mesh));
    memset(&node, 0, sizeof(node));
    mesh.commands = commands;
    mesh.vertices = vertices;
    children[0] = &mesh;
    node.children = children;

    mockNodeFlags = 0x3064;
    nodeQueryCount = 0;
    func_800834F0(&node, 0, 0, 0.0f, 1.0f, arg5, 1.0f, 0);
    assert(nodeQueryCount == 1);
}

static void test_below_threshold(void) {
    struct {
        u32 before;
        Vertex items[27];
        u32 after;
    } vertexStorage;
    struct {
        u32 before;
        Command items[26];
        u32 after;
    } commandStorage;
    s32 i;

    vertexStorage.before = 0x12345678;
    vertexStorage.after = 0x87654321;
    commandStorage.before = 0x23456789;
    commandStorage.after = 0x98765432;

    /* factor = 1 - (0.98 / 1.0)^2 = 0.0396, below 0.1. */
    run_mesh(0.98f, vertexStorage.items, commandStorage.items);

    assert(memcmp(vertexStorage.items, D_800A6808,
                  sizeof(D_800A6808)) == 0);
    assert(commandStorage.items[0].w0 == 0x0100600Cu);
    assert(commandStorage.items[0].w1 ==
           (u32)(unsigned long)vertexStorage.items);
    for (i = 1; i < 6; i++) {
        assert(commandStorage.items[i].w0 == D_800A6868[i].w0);
        assert(commandStorage.items[i].w1 == D_800A6868[i].w1);
    }
    assert(vertexStorage.before == 0x12345678);
    assert(vertexStorage.after == 0x87654321);
    assert(commandStorage.before == 0x23456789);
    assert(commandStorage.after == 0x98765432);
}

static void test_above_threshold(void) {
    struct {
        u32 before;
        Vertex items[27];
        u32 after;
    } vertexStorage;
    struct {
        u32 before;
        Command items[26];
        u32 after;
    } commandStorage;

    vertexStorage.before = 0x3456789A;
    vertexStorage.after = 0xA9876543;
    commandStorage.before = 0x456789AB;
    commandStorage.after = 0xBA987654;

    /* factor = 1 - (0.9 / 1.0)^2 = 0.19, above 0.1. */
    run_mesh(0.9f, vertexStorage.items, commandStorage.items);

    assert(commandStorage.items[0].w0 == 0x0101B036u);
    assert(commandStorage.items[0].w1 ==
           (u32)(unsigned long)vertexStorage.items);
    assert(vertexStorage.items[0].unk00 == D_800A6808[0].unk00);
    assert(vertexStorage.items[1].unk00 == D_800A6808[1].unk00);
    assert(vertexStorage.items[2].unk00 == D_800A6808[2].unk00);
    assert(vertexStorage.items[24].unk00 == D_800A6808[3].unk00);
    assert(vertexStorage.items[25].unk00 == D_800A6808[4].unk00);
    assert(vertexStorage.items[26].unk00 == D_800A6808[5].unk00);
    assert(commandStorage.items[25].w0 == 0xDF000000u);
    assert(commandStorage.items[25].w1 == 0);
    assert(vertexStorage.before == 0x3456789A);
    assert(vertexStorage.after == 0xA9876543);
    assert(commandStorage.before == 0x456789AB);
    assert(commandStorage.after == 0xBA987654);
}

int main(void) {
    D_800A6890 = 1;
    D_800ADD10 = 0.1f;
    D_800ADD18 = 0.8;
    D_800ADD20 = 0.7;
    D_800ADD28 = 0.3;
    D_800ADD30 = 0.2;
    memset(D_80120C40, 0, sizeof(D_80120C40));
    init_templates();
    test_below_threshold();
    test_above_threshold();
    return 0;
}
