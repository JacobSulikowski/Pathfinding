#include "node.h"
#include <iostream>


void Node::initializeUnit(int _valX,int _valY){
    this -> setUnitCoordinates(_valX,_valY);
    this -> resetstate();

}

void Node::getCoordinates(){

}

void Node::resetstate(){
    this->setPreviousUnit(0,0);
    this->setWalkable();
    this->setAdded();
    this->setChecked();
}

std::pair<int,int> Node::getPreviousNodeCoordinates2D(){
    return previousNodeCoordinates;
}

void Node::printUnit(){
    std::cout<<"Node: X: "<<getCoordinates()
}

void Node::setPreviousUnit(int _valX,int _valY){
    setPreviousUnit2D(_valX,_valY);
}
void Node::setPreviousUnit2D(int _valX,int _valY){
    this->previousNodeCoordinates.first = _valX;
    this->previousNodeCoordinates.second = _valY;
}

void Node::setUnitCoordinates(int _valX,int _valY){
    setUnitCoordinates2D(_valX,_valY);
}
void Node::setUnitCoordinates2D(int _valX,int _valY){
    this->coordinates.first = _valX;
    this->coordinates.second = _valY; 
}

void Node::setGValue(int _val){
    GValue = _val;
}

void Node::setHValue(int _val){
    HValue = _val;
}

void Node::setFValue(int _val){
    FValue = _val;
}

bool Node::compare(Node _toCompare){
   if(this -> coordinates.first == _toCompare.getCoordinates2D().first && this -> coordinates.second == _toCompare.getCoordinates2D().second){
    return true;
   } else {
    return false;
   } 
}

void Node::setChecked(){
    checked = true;
}
    
void Node::setAdded(){
    added = true;
}

void Node::setWalkable(){
    walkable = true;
}

int Node::getGValue(){
    return GValue;
}

int Node::getHValue(){
    return HValue;
}

int Node::getFValue(){
    return FValue;
}

bool Node::isAdded(){
    return added;
}
bool Node::isChecked(){
    return checked;
}
bool Node::isWalkable(){
    return walkable;
}