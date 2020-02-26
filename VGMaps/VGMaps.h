//
// Created by Tess on 2020-02-01.
//
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <iostream>
#ifndef COMP345_ASSIGNMENT1_VGMAPS_H
#define COMP345_ASSIGNMENT1_VGMAPS_H
#pragma once
using namespace std;
class node{
public:
    list <int> adjacent;
    int *value;
    string *colour;
    bool *facingUp;

    node();
    explicit node(int n);
    void printAdjacency();
    void printInfo();
    int getValue();
    void setColour(std::string c);
    std::string getColour();
    void setFacingUp(bool fu);
    bool getFacingUp();
    std::list<int> getAdjacent();
};
class VGMaps {

public:
    std::vector<node> map;
    std::string name;
    VGMaps();
    VGMaps(std::string n);
    std::string getName();
    void setName(std::string n);
    std::vector<node> getMap();
    void printMapAdjacency();
    void BFS(int x);
    void checkColourInMap(string c);
    void placeBuilding(string buildingColour, int buildingVal, bool facingUp);
    void calculatePoints();
};


#endif //COMP345_ASSIGNMENT1_VGMAPS_H
