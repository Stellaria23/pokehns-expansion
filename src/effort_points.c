#include "global.h"
#include "main.h"
#include "effort_points.h"

#define EP_MAX 255

u16 GetEffort_Points(void)
{
    return gSaveBlock1Ptr->effortPoints;
}

void AddEffort_Points(u16 amount)
{
    gSaveBlock1Ptr->effortPoints += amount;
    if(EP_MAX < gSaveBlock1Ptr->effortPoints) gSaveBlock1Ptr->effortPoints = EP_MAX;
}

void TakeEffort_Points(u16 amount)
{
    if (gSaveBlock1Ptr->effortPoints >= amount)
        gSaveBlock1Ptr->effortPoints -= amount;
    else
        gSaveBlock1Ptr->effortPoints = 0;
}