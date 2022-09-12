
#include "iunit.h"
#include "ipathfindplane2D.h"
#ifndef PATHFINDPLANE_H
#define PATHFINDPLANE_H

class IPathfindPlane: public IPathFindPlane2D{ 

    public:
        virtual void setPlane(int _width,int _height);
        virtual IUnit *getUnit(int x,int y); 
        virtual void setUnits();
        virtual void setStartingUnit(IUnit *_unit);
        virtual void setEndingUnit(IUnit *_unit);
        virtual void setCurrentUnit(IUnit *_unit);
        
        virtual IUnit* getSartingUnit();
        virtual IUnit* getEndingUnit();
        virtual IUnit* getCurrentUnit();
        virtual int getHeight() override;
        virtual int getWidth() override;
};

#endif