#include "global.h"
#include "main.h"
#include "effort_points.h"

u16 GetEffort_Points(void)
{
    return gSaveBlock1Ptr->effortPoints;
}

void AddEffort_Points(u16 amount)
{
    gSaveBlock1Ptr->effortPoints += amount;
}

void TakeEffort_Points(u16 amount)
{
    if (gSaveBlock1Ptr->effortPoints >= amount)
        gSaveBlock1Ptr->effortPoints -= amount;
    else
        gSaveBlock1Ptr->effortPoints = 0;
}