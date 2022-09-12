#include <list>
#include "ipathfindplane.h"
#ifndef PATHFINDER_H
#define PATHFINDER_H
class Pathfinder{
    private:
        Pathfinder(IPathfindPlane _pathfindPlane);
        IPathfindPlane pathfindPlane;
        IUnit *startingUnit;
        IUnit *endingUnit;
        IUnit *currentUnit;
        std::list<IUnit> path;
        std::list<IUnit*> nodesToAnalyze;
    
    public:
        void setPathfindPlane(IPathfindPlane _pathfindPlane);
        void findPath(IUnit _startingUnit,IUnit _endingUnit);
        void addUnitToAnalyze(IUnit _currentUnit);
        void clearUnitToAnalyze();
        void analyzeUnit(IUnit &_nodesToAnalyze, IUnit _startingNode,IUnit _endingNode);
        void printPath();
        void setPath();
        void setCurrentUnit(IUnit *_node);

        void addNodeToAnalyze(IUnit _currentNode);

        std::list<IUnit*> getUnitsToAnalyze();

};
    

#endif