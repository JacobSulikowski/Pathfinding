#include <list>
#include "ipathfindspace.h"
#ifndef BOARD_H
#define BOARD_H
class Board : public IPathfindSpace{

    private:
        int height;
        int width;
        Unit* board; 
        Unit* startingNode;
        Unit* endingNode;
        Unit* currentNode;

    public:
        Board(int height,int width); 
        ~Board();
        

        //Derived methods
        void setPlane(int _height,int _width) override;
        Unit *getUnit(int x,int y) override; 
        void setUnits() override;
        void setStartingUnit(Unit *_unit) override;
        void setEndingUnit(Unit *_unit) override;
        void setCurrentUnit(Unit *_unit) override;
        Unit* getSartingUnit() override;
        Unit* getEndingUnit() override;
        Unit* getCurrentUnit() override;
        int getHeight() override;
        int getWidth() override;
};


#endif