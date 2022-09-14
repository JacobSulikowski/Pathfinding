#include "icomparable.h"
#include "i2dunits.h"
#ifndef UNIT_H
#define UNIT_H

    
class IUnit : public IComparable<IUnit>,public I2DUnits{ 

    public:
        virtual void resetstate()=0;

        virtual void setGValue(int _val)=0;
        virtual void setHValue(int _val)=0;
        virtual void setFValue(int _val)=0;

        //Indication that setPreviousUnit() (Node) should be implemented
        virtual void initializeUnit() =0;
        virtual void initializeUnit2D(int _valX,int _valY) override =0;
        virtual void setPreviousUnit() =0;
        virtual void setPreviousUnit2D(int _valX,int _valY) override =0;
        virtual void setUnitCoordinates()=0;
        virtual void setUnitCoordinates2D(int _valX, int _valY) override=0;
        virtual void setChecked()=0;
        virtual void setAdded()=0;
        virtual void setWalkable()=0;
        virtual bool compare(IUnit& _toCompare) override=0;
        virtual void getCoordinates()=0;
        virtual std::pair<int,int> getCoordinates2D() override=0;
        virtual void getPreviousNodeCoordinates()=0;
        virtual std::pair<int,int> getPreviousNodeCoordinates2D() override=0;
        virtual void printUnit()=0;
        
        virtual int getGValue()=0;
        virtual int getHValue()=0;
        virtual int getFValue()=0;
        virtual bool isChecked()=0;
        virtual bool isWalkable()=0;
        virtual bool isAdded()=0;
};

#endif