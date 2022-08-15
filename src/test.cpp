#include <iostream>
#include <list>
#include "board.h"

void TestClassInit();
void TestSetNodes();
void TestAddNodesToAnalyze();
void TestAnalyzeNodes();

enum MODE{
  TEST = 0,
  RUN = 1
};

//TODO: Diagonal pathfinding works well weird anomalys when setting sNode and eNode in 0,0 10,10;
// sNode 1,5 eNode 4,9 not working
// sNode 2,5 eNode 4,8 now working
//Repair it
 



int main()
{
  MODE mode;
  mode = RUN;
  if(mode == TEST){
    TestClassInit();
    TestSetNodes();
    TestAddNodesToAnalyze();
    TestAnalyzeNodes();
  } else if (mode == RUN){
    Board board(10,10);
    board.findPath(*board.getNode(0,0),*board.getNode(9,0));
    board.printPath();
  }
  return 0;
}




void TestClassInit(){
  Board board(10,10);
  if(board.getHeight() == 10,board.getWidth() == 10){
    std::cout<<"TestClassInit: Passed"<<std::endl;
    std::cout<<std::endl;
  } else {
    std::cout<<"TestClassInit: Failed"<<std::endl;
    std::cout<<std::endl;
  }
}




void TestSetNodes(){
  Board board(10,10);

  if(board.getNode(5,5)->getX() != 5){
    std::cout<<"TestSetNodes: Failed -> getX"<<std::endl;
    std::cout<<std::endl;
  }else if(board.getNode(5,5)->getY() != 5){
  
    std::cout<<"TestSetNodes: Failed -> getY"<<std::endl;
    std::cout<<board.getNode(5,5)->getY()<<std::endl;
    std::cout<<std::endl;

  }else if(board.getNode(5,5)->getPreviousX() != 0){
  
    std::cout<<"TestSetNodes: Failed -> getPreviousX"<<std::endl;
    std::cout<<std::endl;

  }else if(board.getNode(5,5)->getPreviousY() != 0){
  
    std::cout<<"TestSetNodes: Failed -> getPreviousY"<<std::endl;
    std::cout<<std::endl;

  }else if(board.getNode(5,5)->isAdded() != false){
  
    std::cout<<"TestSetNodes: Failed -> isAdded"<<std::endl;
    std::cout<<std::endl;

  }else if(board.getNode(5,5)->isChecked() != false){
  
    std::cout<<"TestSetNodes: Failed -> isChecked"<<std::endl;
    std::cout<<std::endl;

  }else if(board.getNode(5,5)->isWalkable() != true){
  
    std::cout<<"TestSetNodes: Failed -> isWalkable"<<std::endl;
    std::cout<<std::endl;

  }else {
    std::cout<<"TestSetNodes: Passed"<<std::endl;
    std::cout<<std::endl;
  }
}




void TestAddNodesToAnalyze(){
  Board board(10,10);

  board.addNodeToAnalyze(*board.getNode(5,5));

  if(board.getNodesToAnalyze().empty()){
    std::cout<<"TestAddNodesToAnalyze: Failed -> list is empty"<<std::endl;
    std::cout<<std::endl;
  }else if(board.getNodesToAnalyze().size() < 8){ 
    std::cout<<"TestAddNodesToAnalyze: Failed -> not every Node added"<<std::endl;
    std::cout<<board.getNodesToAnalyze().size()<<std::endl;
    std::cout<<std::endl;
  }else if(board.getNodesToAnalyze().front()->getPreviousX() == 0){
    std::cout<<"TestAddNodesToAnalyze: Failed -> PreviousNotSet"<<std::endl;
    std::cout<<std::endl;
  }else if(board.getNodesToAnalyze().front()->isAdded() != true){
    std::cout<<"TestAddNodesToAnalyze: Failed -> isAdded not set"<<std::endl;
    std::cout<<std::endl;
  } else {
    std::cout<<"TestAddNodesToAnalyze: Passed"<<std::endl;
    std::cout<<std::endl;
  }
}




void TestAnalyzeNodes(){
  Board board(10,10);
  board.analyzeNode(*board.getNode(5,5),*board.getNode(3,3),*board.getNode(6,6));
  if(board.getNode(5,5)->getGValue() != 28){
    std::cout<<"TestAnalyzeNodes: Failed -> GValue not valid "<<std::endl; 
    std::cout<<board.getNode(5,5)->getGValue()<<std::endl;
    std::cout<<std::endl;
  } else if (board.getNode(5,5)->getHValue() != 14){
    std::cout<<"TestAnalyzeNodes: Failed -> HValue not valid "<<std::endl; 
    std::cout<<board.getNode(5,5)->getHValue()<<std::endl;
    std::cout<<std::endl;
  } else if (board.getNode(5,5)->getFValue() != 42){
    std::cout<<"TestAnalyzeNodes: Failed -> FValue not valid"<<std::endl;
    std::cout<<board.getNode(5,5)->getFValue()<<std::endl; 
    std::cout<<std::endl;
  } else {
    std::cout<<"TestAnalyzeNodes: Passed"<<std::endl;
    std::cout<<std::endl;
  }
}




void TestFindPath(){
  Board board(10,10);
  board.findPath(*board.getNode(3,3),*board.getNode(6,6));
}