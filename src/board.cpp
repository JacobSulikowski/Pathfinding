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
            
            board[y * getWidth() + x].initializeUnit2D(x,y);
 
        }
    }
}


int Board::getHeight(){
    return height;
}



int Board::getWidth(){
    return width;
}


IUnit* Board::getSartingUnit(){
    return startingNode; 
}

IUnit* Board::getCurrentUnit(){
    return currentNode; 
}


IUnit* Board::getEndingUnit(){
    return endingNode; 
}