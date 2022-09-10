#include "iunit.h"
#include <utility>
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
        int getX();
        int getY();
        int getXOfPreviousNode();
        int getYOfPreviousNode();
        
        //setters
        void setPreviousNodeX(int _val);
        void setPreviousNodeY(int _val);
        void setPreviousUnit(int _valX,int _valY);
        void setX(int _val);
        void setY(int _val);

        //derived methods
        void resetstate() override;

        void initializeUnit(int _valX, int _valY) override;

        void getCoordinates() override;


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