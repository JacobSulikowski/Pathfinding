#include "board.h"
#include <cmath>
#include <iostream>

void Board::setPlane(int _height, int _width){
    this -> board = new Unit[_height*_width];
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
Unit *Board::getUnit(int _width, int _height){
    return &board[_height * getWidth() + _width];
}


void Board::setStartingUnit(Unit *_unit){
    startingNode = _unit; 
    startingNode -> setAdded();
    startingNode -> setChecked();
}

void Board::setEndingUnit(Unit *_unit){
    endingNode = _unit;
}

void Board::setCurrentUnit(Unit *_unit){
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


Unit* Board::getSartingUnit(){
    return startingNode; 
}

Unit* Board::getCurrentUnit(){
    return currentNode; 
}


Unit* Board::getEndingUnit(){
    return endingNode; 
}