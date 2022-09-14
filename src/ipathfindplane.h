
#include "iunit.h"
#include "ipathfindplane2D.h"
#ifndef PATHFINDPLANE_H
#define PATHFINDPLANE_H
class IPathfindPlane: public IPathFindPlane2D{ 

    public:

        virtual void setPlane(int _width,int _height)=0;
        virtual IUnit *getUnit(int x,int y)=0; 
        virtual void setUnits()=0;
        virtual void setStartingUnit(IUnit *_unit)=0;
        virtual void setEndingUnit(IUnit *_unit)=0;
        virtual void setCurrentUnit(IUnit *_unit)=0;
        
        virtual IUnit* getSartingUnit()=0;
        virtual IUnit* getEndingUnit()=0;
        virtual IUnit* getCurrentUnit()=0;
        virtual int getHeight() override =0;
        virtual int getWidth() override =0;
};

#endif