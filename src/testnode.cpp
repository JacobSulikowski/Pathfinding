#include <iostream>
#include "../utils/test.h"
#include "unit.h"


//TODO: Diagonal pathfinding works well weird anomalys when setting sNode and eNode in 0,0 10,10;
// sNode 1,5 eNode 4,9 not working
// sNode 2,5 eNode 4,8 now working
//Repair it
 
void TestGetCoordinates2D();

int main()
{
  //TestGetCoordinates2D();
  return 0;
}


void TestGetCooridnates2D(){
  Unit testNode;
  Test::TEST_EQ("TestGetCoordinates2DX",testNode.getCoordinates2D().first,0);
}




