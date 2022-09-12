#include "iunit.h"
#include <utility>
#include "i2dunits.h"
#ifndef NODE_H
#define NODE_H
class Node : public IUnit{
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
        //getters
        std::pair<int,int> getPreviousNodeCoordinates2D() override; 
        //setters
        void setPreviousUnit(int _valX,int _valY);
        void setUnitCoordinates2D(int _valX, int _valY) override;

        //derived methods
        void resetstate() override;

        void printUnit() override;

        void initializeUnit2D(int _valX, int _valY) override;

        void setPreviousUnit() override;
        void setPreviousUnit2D(int _valX, int _valY) override;

        void getCoordinates() override;
        std::pair<int,int> getCoordinates2D() override;


        void setGValue(int _val) override;
        void setHValue(int _val) override;
        void setFValue(int _val) override;

        bool compare(Node _toCompare);
        void setChecked() override;
        void setAdded() override;
        void setWalkable() override;
        
        int getGValue() override;
        int getHValue() override;
        int getFValue() override;
        bool isChecked() override;
        bool isWalkable() override;
        bool isAdded() override;


};

#endif