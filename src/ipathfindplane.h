
#include "iunit.h"
#ifndef PATHFINDPLANE_H
#define PATHFINDPLANE_H

class IPathfindPlane{ 

    IUnit *plane = nullptr;
    virtual void setPlane();
    virtual IPathfindPlane getPlane();
    
};

#endif