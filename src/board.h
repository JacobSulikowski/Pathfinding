#include <list>
#include "ipathfindplane.h"
#ifndef BOARD_H
#define BOARD_H
class Board : public IPathfindPlane{

    private:
        int height;
        int width;
        IUnit* board; 
        IUnit* startingNode;
        IUnit* endingNode;
        IUnit* currentNode;

    public:
        Board(int height,int width); 
        ~Board();
        

        //Derived methods
        void setPlane(int _height,int _width) override;
        IUnit *getUnit(int x,int y) override; 
        void setUnits() override;
        void setStartingUnit(IUnit *_unit) override;
        void setEndingUnit(IUnit *_unit) override;
        void setCurrentUnit(IUnit *_unit) override;
        IUnit* getSartingUnit() override;
        IUnit* getEndingUnit() override;
        IUnit* getCurrentUnit() override;
        int getHeight() override;
        int getWidth() override;
};


#endif