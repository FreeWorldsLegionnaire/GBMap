
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <iostream>
#include "VGMaps.h"

using namespace std;


int main()
{
    VGMaps gilford =  VGMaps("gilford");
    cout<< "Village Board Adjacency \n";
    gilford.printMapAdjacency();
    cout<<"Print value of space 6: " <<gilford.map[6].getValue() << "\n";
    cout <<"Breadth First Search: Starting at 6 \n";
    gilford.BFS(6);
    gilford.checkColourInMap("green");
    cout <<"\nSet node 8, 12 and 13 to green. ";
    gilford.map[8].setColour("green");
    gilford.map[13].setColour("green");
    gilford.map[12].setColour("green");
    cout<<"\n Print Info of space 8: Value: " <<gilford.map[8].getValue()<< " Colour: "<<gilford.map[8].getColour()<<" Facing Up: "<<gilford.map[8].getFacingUp()<<"\n";
    gilford.checkColourInMap("green");
    return 0;
}