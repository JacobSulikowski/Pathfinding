#include "board.h"
#include <cmath>
#include <iostream>

void Board::setPlane(int _height, int _width){
    this -> board = new IUnit[_height*_width];
    this -> height = _height; 
    this -> width = _width;
}

Board::Board(int height,int width){
    setPlane(height,width);
    setUnits();
}



Board::~Board(){
    delete[] board;
}
IUnit *Board::getUnit(int _width, int _height){
    return &board[_height * getWidth() + _width];
}


void Board::setStartingUnit(IUnit *_unit){
    startingNode = _unit; 
    startingNode -> setAdded();
    startingNode -> setChecked();
}

void Board::setEndingUnit(IUnit *_unit){
    endingNode = _unit;
}

void Board::setCurrentUnit(IUnit *_unit){
    currentNode = _unit;
}

void Board::setUnits(){
    for(int y=0; y < getHeight();y++)
    { 
        for(int x=0; x < getWidth();x++){
            
            board[y * getWidth() + x].setX(x);
            board[y * getWidth() + x].setY(y);
            board[y * getWidth() + x].setPreviousNode(0,0);
            board[y * getWidth() + x].setWalkable(true);
            board[y * getWidth() + x].setAdded(false);
            board[y * getWidth() + x].setChecked(false);
            
        }
    }
}

void Board::printPath(){
    for(Node n : path){
        std::cout<<"Node X:"<<n.getX()<<" Y:"<<n.getY()<<std::endl;
    }
}

void Board::findPath(Node _startingNode, Node _endingNode){
    if(path.empty()){
        setStartingNode(&_startingNode);
        setEndingNode(&_endingNode);
        setCurrentNode(&_startingNode);
        currentNode->setChecked(true);
        currentNode->setAdded(true);
    }
    Node *tempNode = nullptr;
    while(!(currentNode->equalNode(*endingNode))){
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
int Board::getHeight(){
    return height;
}


std::list<Node*> Board::getNodesToAnalyze(){
    return nodesToAnalyze;
}

int Board::getWidth(){
    return width;
}
void Board::addNodeToAnalyze(Node _currentNode){

    int x = _currentNode.getX();
    int y = _currentNode.getY();  
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

void Board::setPath(){
    path.push_front(*currentNode);
    while(!currentNode->equalNode(*startingNode)){
        currentNode = getNode(currentNode->getPreviousX(),currentNode->getPreviousY());
        path.push_front(*currentNode);
    }
    std::cout<<"Path set"<<std::endl;
}

void Board::analyzeNode(Node &_currentNode,Node _startingNode,Node _endingNode){
    
    int dX = _startingNode.getX() - _currentNode.getX();
    int dY = _startingNode.getY() - _currentNode.getY();
    _currentNode.setGValue(abs((sqrt(dX*dX + dY*dY))*10));

    dX = _endingNode.getX() - _currentNode.getX();
    dY = _endingNode.getY() - _currentNode.getY();
    _currentNode.setHValue(abs((sqrt(dX*dX + dY*dY))*10));
    _currentNode.setFValue(_currentNode.getHValue() + _currentNode.getGValue()); 
}