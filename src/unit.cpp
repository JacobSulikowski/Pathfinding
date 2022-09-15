#include "unit.h"
#include <iostream>


void Unit::initializeUnit2D(int _valX,int _valY){
    this -> setUnitCoordinates2D(_valX,_valY);
    this -> resetstate();

}

void Unit::getCoordinates(){

}

void Unit::resetstate(){
    this->setPreviousUnit2D(0,0);
    this->setWalkable();
    this->setAdded();
    this->setChecked();
}

std::pair<int,int> Unit::getPreviousNodeCoordinates2D(){
    return previousNodeCoordinates;
}

std::pair<int,int> Unit::getCoordinates2D(){
    return coordinates;
}

void Unit::printUnit(){
    std::cout<<"Node: X: "<< getCoordinates2D().first<<" Y: "<< getCoordinates2D().second<<std::endl;
}



void Unit::setPreviousUnit2D(int _valX,int _valY){
    this->previousNodeCoordinates.first = _valX;
    this->previousNodeCoordinates.second = _valY;
}

void Unit::setUnitCoordinates2D(int _valX,int _valY){
    this->coordinates.first = _valX;
    this->coordinates.second = _valY; 
}

void Unit::setGValue(int _val){
    GValue = _val;
}

void Unit::setHValue(int _val){
    HValue = _val;
}

void Unit::setFValue(int _val){
    FValue = _val;
}

bool Unit::compare(Unit _toCompare){
   if(this -> coordinates.first == _toCompare.getCoordinates2D().first && this -> coordinates.second == _toCompare.getCoordinates2D().second){
    return true;
   } else {
    return false;
   } 
}

void Unit::setChecked(){
    checked = true;
}
    
void Unit::setAdded(){
    added = true;
}

void Unit::setWalkable(){
    walkable = true;
}

int Unit::getGValue(){
    return GValue;
}

int Unit::getHValue(){
    return HValue;
}

int Unit::getFValue(){
    return FValue;
}

bool Unit::isAdded(){
    return added;
}
bool Unit::isChecked(){
    return checked;
}
bool Unit::isWalkable(){
    return walkable;
}