#include "node.h"

int Node::getX(){
    return x;
}

int Node::getY(){
    return y;
}

void Node::setUnit(int _valX,int _valY){
    this -> setX(_valX);
    this -> setY(_valY);
    this -> resetstate();

}

void Node::resetstate(){
    this->setPreviousUnit(0,0);
    this->setWalkable();
    this->setAdded();
    this->setChecked();
}

int Node::getXOfPreviousNode(){
    return previousNodeX;
}

int Node::getYOfPreviousNode(){
    return previousNodeY;
}

void Node::setPreviousNodeX(int _val){
    previousNodeX = _val;
}

void Node::setPreviousNodeY(int _val){
    previousNodeY = _val;
}
void Node::setPreviousUnit(int _valX,int _valY){
   setPreviousNodeX(_valX); 
   setPreviousNodeY(_valY);
}

void Node::setX(int _val){
    x = _val;
}

void Node::setY(int _val){
    y = _val;
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
   if(this -> x == _toCompare.getX() && this -> y == _toCompare.getY()){
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