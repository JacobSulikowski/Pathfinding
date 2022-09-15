#include <list>
#include "ipathfindspace.h"
#ifndef PATHFINDER_H
#define PATHFINDER_H
class Pathfinder{
    private:
        Pathfinder(IPathfindSpace& _pathfindSpace);
        IPathfindSpace* pathfindSpace;
        Unit *startingUnit;
        Unit *endingUnit;
        Unit *currentUnit;
        std::list<Unit> path;
        std::list<Unit*> unitsToAnalyze;
    
    public:
        void setPathfindSpace(IPathfindSpace& _pathfindPlane);
        void findPath(Unit _startingUnit,Unit _endingUnit);
        void addUnitToAnalyze(Unit _currentUnit);
        void clearUnitToAnalyze();
        void analyzeUnit(Unit &_nodesToAnalyze, Unit _startingNode,Unit _endingNode);
        void printPath();
        void setPath();
        void setCurrentUnit(Unit *_node);

        void addNodeToAnalyze(Unit _currentNode);

        std::list<Unit*> getUnitsToAnalyze();

};
    

#endif