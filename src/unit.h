#include "icomparable.h"
#include "i2dunits.h"
#ifndef UNIT_H
#define UNIT_H

    
class Unit : public IComparable<Unit>,public I2DUnits{ 
    private:
        std::pair<int,int> coordinates;
        std::pair<int,int> previousNodeCoordinates;
        int GValue;
        int HValue;
        int FValue;
        bool checked;
        bool added;
        bool walkable;

    public:

        void resetstate();

        void setGValue(int _val);
        void setHValue(int _val);
        void setFValue(int _val);

        void initializeUnit();
        void initializeUnit2D(int _valX,int _valY) override;
        void setPreviousUnit() {};
        void setPreviousUnit2D(int _valX,int _valY) override;
        void setUnitCoordinates();
        void setUnitCoordinates2D(int _valX, int _valY) override;
        void setChecked();
        void setAdded();
        void setWalkable();
        bool compare(Unit _toCompare) override;
        void getCoordinates();
        virtual std::pair<int,int> getCoordinates2D() override;
        void getPreviousNodeCoordinates();
        std::pair<int,int> getPreviousNodeCoordinates2D() override;
        void printUnit();
        
        int getGValue();
        int getHValue();
        int getFValue();
        bool isChecked();
        bool isWalkable();
        bool isAdded();
};

#endif