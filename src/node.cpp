#include "node.h"

void Node::setFValue(int _val){
  this -> fValue = _val;
}
void Node::setGValue(int _val){
  this -> gValue = _val;
}
void Node::setHValue(int _val){
  this -> hValue = _val;
}

void Node::setX(int _val){
  this -> x = _val;
}

void Node::setY(int _val){
  this -> y = _val;
}

void Node::setPreviousX(int _val){
  this -> previousX = _val;
}

void Node::setPreviousY(int _val){
  this -> previousY = _val;
}

bool Node::equalNode(Node _node){
  if(this -> getX() == _node.getX() && this -> getY() == _node.getY()){
    return true;
  } else {
    return false;
  }
}
void Node::setPreviousNode(int _valX,int _valY){
  setPreviousX(_valX);
  setPreviousY(_valY);
}

void Node::setChecked(bool _val){
  this -> checked = _val;
}

void Node::setAdded(bool _val){
  this -> added = _val;
}

void Node::resetState(){
    this ->setFValue(0);
    this ->setGValue(0);
    this ->setHValue(0);
}

void Node::setWalkable(bool _val){
  this -> walkable = _val; 
}

int Node::getFValue(){
  return fValue;
}
int Node::getGValue(){
  return gValue;
}
int Node::getHValue(){
  return hValue;
}

int Node::getX(){
  return x;
}
int Node::getY(){
  return y;
}
bool Node::isChecked(){
  return checked;
}
bool Node::isWalkable(){
  return walkable;
}
bool Node::isAdded(){
  return added;
}
int Node::getPreviousX(){
  return previousX;
}
int Node::getPreviousY(){
  return previousY;
}