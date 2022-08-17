#include <list>
#include "ipathfindplane.h"
#ifndef PATHFINDER_H
#define PATHFINDER_H
namespace Pathfinding
{
    class Pathfinder{
        Pathfinder(IPathfindPlane _pathfindPlane);
        IUnit *startingUnit;
        IUnit *endingUnit;
        IUnit *currentUnit;

        void findPath(IUnit _startingUnit,IUnit _endingUnit);
        void addUnitToAnalyze(IUnit _currentUnit);
        void clearUnitToAnalyze();
        void analyzeUnit(IUnit &_nodesToAnalyze, IUnit _startingNode,IUnit _endingNode);
        void printPath();
        void setPath();
        void setCurrentUnit(IUnit *_node);

        std::list<IUnit*> getUnitsToAnalyze();

    };
    
} // namespace Pathfinding

#endif