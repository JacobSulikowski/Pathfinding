#include <list>
#include "ipathfindplane.h"
#include "iunit.h"
#ifndef BOARD_H
#define BOARD_H

class Board : IPathfindPlane{

    private:
        int height;
        int width;
        IUnit* board; 




        void setNodes();
    public:
        Board(int height,int width); 
        ~Board();
        void setBoard(int _height, int _width);
        IUnit getBoard(int i);
        IUnit *getUnit(int x,int y); 
        int getHeight();
        int getWidth();
};


#endif