#include "node.h"

int Node::getX(){
    return x;
}

int Node::getY(){
    return y;
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
void Node::setPreviousNode(int _valX,int _valY){
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