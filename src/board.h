#include <list>
#include "ipathfindplane.h"
#include "iunit.h"
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
        
        int getHeight();
        int getWidth();

        //Derived methods
        virtual void setPlane(int _height,int _width) override;
        virtual IUnit *getUnit(int x,int y) override; 
        virtual void setUnits() override;
        virtual void setStartingUnit(IUnit *_unit) override;
        virtual void setEndingUnit(IUnit *_unit) override;
        virtual void setCurrentUnit(IUnit *_unit) override;
};


#endif