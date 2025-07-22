#include "ityoshieggthrow.h"

#include "ef/efasync.h"
#include "it/inlines.h"
#include "it/it_266F.h"
#include "it/it_26B1.h"
#include "it/it_2725.h"
#include "it/item.h"

// Forward declaration required. (if sorting by address).
// Definition provided in this .c file, and only called in this .c file.
// TODO: Ask if it should go here or in .h file.
void it_802B2C38(Item_GObj* item_gobj);

// TODO: These constants are kind of silly?
const f32 ZERO = 0.0f;
const f32 ONE = 1.0f;

void it_802B2890(Item_GObj* item_gobj)
{
    Item* item = GET_ITEM((HSD_GObj*) item_gobj);
    item->owner = NULL;
    item->xDC8_word.flags.x13 = false;
    Item_8026A8EC(item_gobj);
}

Item_GObj* it_802B2A10(Item_GObj* parent, Point3d* pos, enum Fighter_Part arg2,
                       f32 dir)
{
    f32 _padding_1;
    SpawnItem spawn_item;
    f32 _padding_2;
    f32 _padding_3;
    Item_GObj* temp_r3;

    spawn_item.kind = It_Kind_Yoshi_EggThrow;
    spawn_item.prev_pos = *pos;
    it_8026BB68(parent, &spawn_item.pos);
    spawn_item.facing_dir = dir;
    spawn_item.x3C_damage = 0;
    spawn_item.vel.x = spawn_item.vel.y = spawn_item.vel.z = 0;
    spawn_item.x0_parent_gobj = (HSD_GObj*) parent;
    spawn_item.x4_parent_gobj2 = spawn_item.x0_parent_gobj;
    spawn_item.x44_flag.b0 = true;
    spawn_item.x40 = 0;

    temp_r3 = Item_80268B18(&spawn_item);
    if (temp_r3 != NULL) {
        Item_8026AB54((HSD_GObj*) temp_r3, (HSD_GObj*) parent, arg2);
    }
    return temp_r3;
}

void it_802B2AE0(Item_GObj* item_gobj)
{
    Item_80268E5C((HSD_GObj*) item_gobj, 0, ITEM_ANIM_UPDATE);
}

void it_802B2B08(Item_GObj* item_gobj)
{
    Item* item = GET_ITEM((HSD_GObj*) item_gobj);
    f32* unkc4_unk4 = item->xC4_article_data->x4_specialAttributes;
    Item_80268E5C((HSD_GObj*) item_gobj, 1, ITEM_ANIM_UPDATE);
    it_80275158(item_gobj, *unkc4_unk4);
}

s32 it_802B2B5C(void* arg0)
{
    // HACK: Commented out compile erroring code.
    // So pretty much the whole thing.

    // f32 temp_f1;
    // void* temp_r4;

    // temp_r4 = arg0->unk2C;
    // temp_f1 = temp_r4->unkD44;
    // M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    // if (temp_f1 == ZERO) {
    //     it_802B2C38(arg0);
    // } else {
    //     temp_r4->unkD44 = (f32) (temp_f1 - it_804DCFC4);
    // }
    return 0;
}

void it_802B2BA8(Item_GObj* item_gobj)
{
    Item* item = GET_ITEM((HSD_GObj*) item_gobj);
    ItemAttr* temp_r4 = item->xCC_item_attr;
    it_80272860(item_gobj, temp_r4->x10_fall_speed,
                temp_r4->x14_fall_speed_max);
}

bool it_802B2C04(Item_GObj* item_gobj)
{
    Item* item = GET_ITEM((HSD_GObj*) item_gobj);
    if ((enum_t) item->msid != 2) {
        it_802B2C38(item_gobj);
    }
    return 0;
}

void it_802B2C38(Item_GObj* item_gobj)
{
    // HACK: Commented out compile erroring code.
    f32 sp1C;
    HSD_JObj* temp_r29;
    void* temp_r30;
    Item* item = GET_ITEM((HSD_GObj*) item_gobj);

    temp_r29 = item_gobj->hsd_obj;
    // temp_r30 = temp_r31->unkC4->unk4;
    Item_80268E5C((HSD_GObj*) item_gobj, 2, 0x12);
    it_8026BB44(item_gobj);
    it_80273598(item_gobj, 0xC, 0xA);
    it_8026BD24(item_gobj);
    it_8027518C(item_gobj);
    it_80273454(item_gobj);
    // temp_r31->unkD44 = (f32) temp_r30->unk4;
    // efAsync_Spawn(arg0, arg0->user_data + 0xBC0, 1U, 0x4CEU, (HSD_GObj* )
    // temp_r29);
    sp1C = ONE;
    // efAsync_Spawn(arg0, arg0->user_data + 0xBC0, 4U, 0x4CFU, (HSD_GObj* )
    // temp_r29, &sp1C);
    Item_8026AE84((Item*) item, 0x44618, 0x7F, 0x40);
}

void it_802B2D30(Item_GObj* item_gobj)
{
    it_802751D8(item_gobj);
}

// TODO: Slightly incorrect. 75% matching
bool it_802B2D50(Item_GObj* item_gobj)
{
    f32 sp20;
    HSD_JObj* joint_obj;
    Item* item;
    itUnkAttributes* attr;
    u64 padding;
    u64 padding2;

    item = GET_ITEM((HSD_GObj*) item_gobj); // lwz _ 0x2c
    if (item->msid != 2) {
        joint_obj = GET_JOBJ((HSD_GObj*) item_gobj);
        attr = item->xC4_article_data->x4_specialAttributes;
        Item_80268E5C((HSD_GObj*) item_gobj, 2, 0x12);
        it_8026BB44(item_gobj);
        it_80273598(item_gobj, 0xC, 0xA);
        it_8026BD24(item_gobj);
        it_8027518C(item_gobj);
        it_80273454(item_gobj);
        item->xD44_lifeTimer = attr->x4_float;
        efAsync_Spawn((HSD_GObj*) item_gobj, &item->xBC0, 1U, 0x4CEU,
                      joint_obj);
        sp20 = 1.0f;
        efAsync_Spawn((HSD_GObj*) item_gobj, &item->xBC0, 4U, 0x4CFU,
                      joint_obj, &sp20);
        Item_8026AE84(item, 0x44618, 0x7F, 0x40);
    }
    return 0;
}

bool it_802B2E5C(Item_GObj* item_gobj)
{
    return it_80273030(item_gobj);
}

bool it_802B2E7C(Item_GObj* item_gobj)
{
    // HACK: Commented out compile erroring code.
    f32 sp20;
    HSD_JObj* temp_r30;
    void* temp_r31;
    Item* item = GET_ITEM((HSD_GObj*) item_gobj);

    if ((s32) item->msid != 2) {
        temp_r30 = item_gobj->hsd_obj;
        temp_r31 = item->xC4_article_data->x4_specialAttributes;
        Item_80268E5C((HSD_GObj*) item_gobj, 2, 0x12);
        it_8026BB44(item_gobj);
        it_80273598(item_gobj, 0xC, 0xA);
        it_8026BD24(item_gobj);
        it_8027518C(item_gobj);
        it_80273454(item_gobj);
        // temp_r29->xD44_lifeTimer = temp_r31->unk4;
        // efAsync_Spawn((HSD_GObj* ) arg0, &arg0->user_data->unkBC0, 1U,
        // 0x4CEU, temp_r30);
        sp20 = ONE;
        // efAsync_Spawn((HSD_GObj* ) arg0, &arg0->user_data->unkBC0, 4U,
        // 0x4CFU, temp_r30, &sp20);
        Item_8026AE84(item, 0x44618, 0x7F, 0x40);
    }
    return 0;
}

void it_802B2FA8(Item_GObj* gobj, Item_GObj* ref_gobj)
{
    it_8026B894(gobj, ref_gobj);
}

bool it_802B2F88(Item_GObj* item_gobj)
{
    return itColl_BounceOffShield(item_gobj);
}

bool it_802B2BD8(Item_GObj* item_gobj)
{
    it_8026E5A0(item_gobj, it_802B2C38);
    return 0;
}
