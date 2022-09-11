#include <iostream>
#include "pathfinder.h"

Pathfinder::Pathfinder(IPathfindPlane _pathfindPlane){
    setPathfindPlane(_pathfindPlane);
}

void Pathfinder::setPathfindPlane(IPathfindPlane _pathfindPlane){
    this->pathfindPlane = _pathfindPlane;
}


void Pathfinder::printPath(){
    for(IUnit n : path){
        std::cout<<"Node: X "<<n.getCoordinates().first<<" Y "<<n.getCoordinates2D().second<<std::endl;
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

        addNodeToAnalyze(*currentNode); 

        for(Node *n : nodesToAnalyze){
            analyzeNode(*n,*startingNode,*endingNode);
            if((tempNode == nullptr || (tempNode->getFValue() > n->getFValue())||
            (tempNode->getFValue() == n->getFValue() && tempNode->getHValue() < n->getHValue())) && n->isChecked()!= true){
                
                tempNode = n;
            }
            currentNode = tempNode;
        } 
        tempNode = nullptr;
        currentNode -> setChecked(true);
        std::cout<<currentNode -> getX()<<currentNode -> getY()<<std::endl;
    }
    setPath();
}



std::list<IUnit*> Pathfinder::getNodesToAnalyze(){
    return nodesToAnalyze;
}



void Pathfinder::addNodeToAnalyze(IUnit _currentNode){

    int x = pathfindPlane.getCurrentUnit()->getCoordinates2D().first;
    int y = pathfindPlane.getCurrentUnit()->getCoordinates2D().second;  
    for(int i = -1;  i<2; i++){
        for(int z = -1; z<2;z++){
            if(!(i==0&&z==0) && (y+i)>=0 && (y+i)<=getHeight() && (x+z)>=0 && (x+z)<=getWidth()){
               if(!(getNode(x+z,y+i)->isChecked()) && (getNode(x+z,y+i)->isWalkable()) 
               && !(getNode(x+z,y+i)->isAdded()) && getNode(x+z,y+i)->equalNode(*startingNode) == false){ 

                    getNode(x+z,y+i)->setAdded(true);
                    getNode(x+z,y+i)->setPreviousNode(x,y);
                    nodesToAnalyze.push_back(getNode(x+z,y+i));
               }
            }
        }
    }
}



void Pathfinder::setPath(){
    path.push_front(*currentNode);
    while(!currentNode->equalNode(*startingNode)){
        currentNode = getNode(currentNode->getPreviousX(),currentNode->getPreviousY());
        path.push_front(*currentNode);
    }
    std::cout<<"Path set"<<std::endl;
}



void Pathfinder::analyzeNode(Node &_currentNode,Node _startingNode,Node _endingNode){
    
    int dX = _startingNode.getX() - _currentNode.getX();
    int dY = _startingNode.getY() - _currentNode.getY();
    _currentNode.setGValue(abs((sqrt(dX*dX + dY*dY))*10));

    dX = _endingNode.getX() - _currentNode.getX();
    dY = _endingNode.getY() - _currentNode.getY();
    _currentNode.setHValue(abs((sqrt(dX*dX + dY*dY))*10));
    _currentNode.setFValue(_currentNode.getHValue() + _currentNode.getGValue()); 
}