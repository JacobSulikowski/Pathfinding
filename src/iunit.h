#include "icomparable.h"
#include "i2dunits.h"
#ifndef UNIT_H
#define UNIT_H

    
class IUnit : public IComparable<IUnit>,public I2DUnits{ 

    public:
        virtual void resetstate();

        virtual void setGValue(int _val);
        virtual void setHValue(int _val);
        virtual void setFValue(int _val);

        //Indication that setPreviousUnit() (Node) should be implemented
        virtual void initializeUnit();
        virtual void initializeUnit2D(int _valX,int _valY) override;
        virtual void setPreviousUnit();
        virtual void setUnitCoordinates();
        virtual void setUnitCoordinates2D(int _valX, int _valY) override;
        virtual void setChecked();
        virtual void setAdded();
        virtual void setWalkable();
        virtual bool compare(IUnit _toCompare) override;
        virtual void getCoordinates();
        virtual void getPreviousNodeCoordinates();
        virtual void printUnit();
        virtual void getUnit(int _valX, int _valY);
        
        virtual int getGValue();
        virtual int getHValue();
        virtual int getFValue();
        virtual bool isChecked();
        virtual bool isWalkable();
        virtual bool isAdded();
};

#endif