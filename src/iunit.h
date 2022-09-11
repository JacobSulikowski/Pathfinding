#include "icomparable.h"
#ifndef UNIT_H
#define UNIT_H

    
class IUnit : public IComparable<IUnit>{ 

    public:
        virtual void resetstate();

        virtual void setGValue(int _val);
        virtual void setHValue(int _val);
        virtual void setFValue(int _val);

        //Indication that setPreviousUnit() (Node) should be implemented
        virtual void initializeUnit();
        virtual void initializeUnit(int _valX,int _valY);
        virtual void setPreviousUnit();
        virtual void setUnitCoordinates();
        virtual void setUnitCoordinates(int _valX, int _valY);
        virtual void setChecked();
        virtual void setAdded();
        virtual void setWalkable();
        virtual bool compare(IUnit _toCompare) override;
        virtual void getCoordinates();
        virtual void getPreviousNodeCoordinates();
        virtual void printUnit();
        
        virtual int getGValue();
        virtual int getHValue();
        virtual int getFValue();
        virtual bool isChecked();
        virtual bool isWalkable();
        virtual bool isAdded();
};

#endif