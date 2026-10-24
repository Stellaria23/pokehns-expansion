#ifndef GUARD_FISHING_ITEMS_H
#define GUARD_FISHING_ITEMS_H

#include "item.h"
#include "constants/items.h"

#define FOSSIL_COUNT 2
#define VITAMIN_COUNT 6

static const u16 sFishingItems_Old[] =
{
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_FULL_HEAL,
    ITEM_GREAT_BALL,
};



static const u16 sFishingItems_Good[] =
{
    ITEM_HYPER_POTION,
    ITEM_ULTRA_BALL,
    ITEM_REVIVE,
    ITEM_ETHER,
};


static const u16 sFishingItems_Super[] =
{
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_ELIXIR,
    ITEM_HP_UP,
    ITEM_PROTEIN,
    ITEM_IRON,
    ITEM_CALCIUM,
    ITEM_CARBOS,
    ITEM_ZINC,
    ITEM_COVER_FOSSIL,
    ITEM_PLUME_FOSSIL,
};




#endif // GUARD_FISHING_ITEMS_H