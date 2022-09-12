#include <iostream>
#include "pathfinder.h"
#include "math.h"

Pathfinder::Pathfinder(IPathfindPlane _pathfindPlane){
    setPathfindPlane(_pathfindPlane);
}

void Pathfinder::setPathfindPlane(IPathfindPlane _pathfindPlane){
    this->pathfindPlane = _pathfindPlane;
}


void Pathfinder::printPath(){
    for(IUnit n : path){
        n.printUnit();
    }
}


void Pathfinder::findPath(IUnit _startingNode, IUnit _endingNode){
    if(path.empty()){
        pathfindPlane.setStartingUnit(&_startingNode);
        pathfindPlane.setEndingUnit(&_endingNode);
        pathfindPlane.setCurrentUnit(&_startingNode);
        pathfindPlane.getCurrentUnit()->setChecked();
        pathfindPlane.getCurrentUnit()->setAdded();
    }
    IUnit *tempNode = nullptr;
    while(!(pathfindPlane.getCurrentUnit()->compare(*pathfindPlane.getEndingUnit()))){

        addNodeToAnalyze(*pathfindPlane.getCurrentUnit()); 

        for(IUnit *n : getUnitsToAnalyze()){
            analyzeUnit(*n,*pathfindPlane.getSartingUnit(),*pathfindPlane.getEndingUnit());
            if((tempNode == nullptr || (tempNode->getFValue() > n->getFValue())||
            (tempNode->getFValue() == n->getFValue() && tempNode->getHValue() < n->getHValue())) && n->isChecked()!= true){
                
                tempNode = n;
            }
            pathfindPlane.setCurrentUnit(tempNode);
        } 
        tempNode = nullptr;
        pathfindPlane.getCurrentUnit() -> setChecked();
        std::cout<<pathfindPlane.getCurrentUnit() -> getCoordinates2D().first<<pathfindPlane.getCurrentUnit() -> getCoordinates2D().second<<std::endl;
    }
    setPath();
}



std::list<IUnit*> Pathfinder::getUnitsToAnalyze(){
    return nodesToAnalyze;
}



void Pathfinder::addNodeToAnalyze(IUnit _currentNode){

    int x = pathfindPlane.getCurrentUnit()->getCoordinates2D().first;
    int y = pathfindPlane.getCurrentUnit()->getCoordinates2D().second;  
    for(int i = -1;  i<2; i++){
        for(int z = -1; z<2;z++){
            if(!(i==0&&z==0) && (y+i)>=0 && (y+i)<=pathfindPlane.getHeight() && (x+z)>=0 && (x+z)<=pathfindPlane.getWidth()){
               if(!(pathfindPlane.getUnit(x+z,y+i)->isChecked()) && (pathfindPlane.getUnit(x+z,y+i)->isWalkable()) 
               && !(pathfindPlane.getUnit(x+z,y+i)->isAdded()) && pathfindPlane.getUnit(x+z,y+i)->compare(*pathfindPlane.getSartingUnit()) == false){ 

                    pathfindPlane.getUnit(x+z,y+i)->setAdded();
                    pathfindPlane.getUnit(x+z,y+i)->setPreviousUnit2D(x,y);
                    nodesToAnalyze.push_back(pathfindPlane.getUnit(x+z,y+i));
               }
            }
        }
    }
}



void Pathfinder::setPath(){
    path.push_front(*pathfindPlane.getCurrentUnit());
    while(!pathfindPlane.getCurrentUnit()->compare(*pathfindPlane.getSartingUnit())){
        pathfindPlane.setCurrentUnit(pathfindPlane.getUnit(pathfindPlane.getCurrentUnit()->getCoordinates2D().first,pathfindPlane.getCurrentUnit()->getCoordinates2D().second));
        path.push_front(*pathfindPlane.getCurrentUnit());
    }
    std::cout<<"Path set"<<std::endl;
}



void Pathfinder::analyzeUnit(IUnit &_currentNode,IUnit _startingNode,IUnit _endingNode){
    
    int dX = _startingNode.getCoordinates2D().first - _currentNode.getCoordinates2D().first;
    int dY = _startingNode.getCoordinates2D().second - _currentNode.getCoordinates2D().second;
    _currentNode.setGValue(abs((sqrt(dX*dX + dY*dY))*10));

    dX = _endingNode.getCoordinates2D().first - _currentNode.getCoordinates2D().first;
    dY = _endingNode.getCoordinates2D().second - _currentNode.getCoordinates2D().second;
    _currentNode.setHValue(abs((sqrt(dX*dX + dY*dY))*10));
    _currentNode.setFValue(_currentNode.getHValue() + _currentNode.getGValue()); 
}