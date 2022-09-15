#include <iostream>
#include "pathfinder.h"
#include "math.h"

Pathfinder::Pathfinder(IPathfindSpace& _pathfindSpace){
    setPathfindSpace(_pathfindSpace);
}

void Pathfinder::setPathfindSpace(IPathfindSpace& _pathfindSpace){
    pathfindSpace = &_pathfindSpace;
}


void Pathfinder::printPath(){
    for(Unit n : path){
        n.printUnit();
    }
}


void Pathfinder::findPath(Unit _startingUnit, Unit _endingUnit){
    if(path.empty()){
        pathfindSpace -> setStartingUnit(&_startingUnit);
        pathfindSpace -> setEndingUnit(&_endingUnit);
        pathfindSpace -> setCurrentUnit(&_startingUnit);
        pathfindSpace -> getCurrentUnit()->setChecked();
        pathfindSpace -> getCurrentUnit()->setAdded();
    }
    Unit *tempUnit = nullptr;
    while(!(pathfindSpace -> getCurrentUnit()->compare(*pathfindSpace -> getEndingUnit()))){

        addUnitToAnalyze(*pathfindSpace -> getCurrentUnit()); 

        for(Unit *n : getUnitsToAnalyze()){
            analyzeUnit(*n,*pathfindSpace -> getSartingUnit(),*pathfindSpace -> getEndingUnit());
            if((tempUnit == nullptr || (tempUnit->getFValue() > n->getFValue())||
            (tempUnit->getFValue() == n->getFValue() && tempUnit->getHValue() < n->getHValue())) && n->isChecked()!= true){
                
                tempUnit = n;
            }
            pathfindSpace -> setCurrentUnit(tempUnit);
        } 
        tempUnit = nullptr;
        pathfindSpace -> getCurrentUnit() -> setChecked();
        std::cout<<pathfindSpace -> getCurrentUnit() -> getCoordinates2D().first<<pathfindSpace -> getCurrentUnit() -> getCoordinates2D().second<<std::endl;
    }
    setPath();
}



std::list<Unit*> Pathfinder::getUnitsToAnalyze(){
    return unitsToAnalyze;
}



void Pathfinder::addUnitToAnalyze(Unit _currentUnit){

    int x = pathfindSpace -> getCurrentUnit()->getCoordinates2D().first;
    int y = pathfindSpace -> getCurrentUnit()->getCoordinates2D().second;  
    for(int i = -1;  i<2; i++){
        for(int z = -1; z<2;z++){
            if(!(i==0&&z==0) && (y+i)>=0 && (y+i)<=pathfindSpace -> getHeight() && (x+z)>=0 && (x+z)<=pathfindSpace -> getWidth()){
               if(!(pathfindSpace -> getUnit(x+z,y+i)->isChecked()) && (pathfindSpace -> getUnit(x+z,y+i)->isWalkable()) 
               && !(pathfindSpace -> getUnit(x+z,y+i)->isAdded()) && pathfindSpace -> getUnit(x+z,y+i)->compare(*pathfindSpace -> getSartingUnit()) == false){ 

                    pathfindSpace -> getUnit(x+z,y+i)->setAdded();
                    pathfindSpace -> getUnit(x+z,y+i)->setPreviousUnit2D(x,y);
                    unitsToAnalyze.push_back(pathfindSpace -> getUnit(x+z,y+i));
               }
            }
        }
    }
}



void Pathfinder::setPath(){
    path.push_front(*pathfindSpace -> getCurrentUnit());
    while(!pathfindSpace -> getCurrentUnit()->compare(*pathfindSpace -> getSartingUnit())){
        pathfindSpace -> setCurrentUnit(pathfindSpace -> getUnit(pathfindSpace -> getCurrentUnit()->getCoordinates2D().first,pathfindSpace -> getCurrentUnit()->getCoordinates2D().second));
        path.push_front(*pathfindSpace -> getCurrentUnit());
    }
    std::cout<<"Path set"<<std::endl;
}



void Pathfinder::analyzeUnit(Unit &_currentUnit,Unit _startingUnit,Unit _endingUnit){
    
    int dX = _startingUnit.getCoordinates2D().first - _currentUnit.getCoordinates2D().first;
    int dY = _startingUnit.getCoordinates2D().second - _currentUnit.getCoordinates2D().second;
    _currentUnit.setGValue(abs((sqrt(dX*dX + dY*dY))*10));

    dX = _endingUnit.getCoordinates2D().first - _currentUnit.getCoordinates2D().first;
    dY = _endingUnit.getCoordinates2D().second - _currentUnit.getCoordinates2D().second;
    _currentUnit.setHValue(abs((sqrt(dX*dX + dY*dY))*10));
    _currentUnit.setFValue(_currentUnit.getHValue() + _currentUnit.getGValue()); 
}