#include "unit.h"
#include "ipathfindplane2D.h"
#ifndef PATHFINDPLANE_H
#define PATHFINDPLANE_H
class IPathfindSpace: public IPathFindPlane2D{ 

    public:

        virtual void setPlane(int _width,int _height)=0;
        virtual Unit *getUnit(int x,int y)=0; 
        virtual void setUnits()=0;
        virtual void setStartingUnit(Unit *_unit)=0;
        virtual void setEndingUnit(Unit *_unit)=0;
        virtual void setCurrentUnit(Unit *_unit)=0;
        
        virtual Unit* getSartingUnit()=0;
        virtual Unit* getEndingUnit()=0;
        virtual Unit* getCurrentUnit()=0;
        virtual int getHeight() override =0;
        virtual int getWidth() override =0;
};

#endif