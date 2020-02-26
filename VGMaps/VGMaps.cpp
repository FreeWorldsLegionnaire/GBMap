//
// Created by Tess on 2020-02-01.
//

#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <iostream>
#include "VGMaps.h"

using namespace std;

node::node() {
    value=0;
    string c="none";
    colour=&c;
    bool f=false;
    facingUp=&f;
}

node::node(int n) {
    value=new int;
    colour=new string;
    facingUp=new bool;
    if (n<5)
        *value=1;
    if (n>4 && n<10)
        *value=2;
    if (n>9 && n<15)
        *value=3;
    if (n>14 && n<20)
        *value=4;
    if (n>19 && n<25)
        *value=5;
    if (n>24)
        *value=6;
    *colour="none";
    *facingUp=false;
    if(n>4){
        adjacent.push_back(n-5);
    }
    if (n%5!=4) {
        adjacent.push_back(n + 1);
    }
    if(n%5!=0){
        adjacent.push_back(n-1);
    }
    if(n<25){
        adjacent.push_back(n+5);
    }
}


void node::printAdjacency() {
    for (std::list<int>::iterator it=adjacent.begin(); it != adjacent.end(); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';
}

int node::getValue() {
    return *value;
}

void node::setColour(std::string c) {
    colour=&c;
}

std::string node::getColour() {
    return *colour;
}

void node::setFacingUp(bool f) {
    facingUp=&f;
}

bool node::getFacingUp() {
    return *facingUp;
}

VGMaps::VGMaps() {
    name="unnamed";
    map=vector<node>(30);
    for(int i=0; i<30; i++){
        map[i]=node(i);
    }
}

VGMaps::VGMaps(std::string n) {
    name=n;
    map=vector<node>(30);
    for(int i=0; i<30; i++){
        map[i]=node(i);

    }
    cout<<"8 "<<map[8].getValue()<<endl;
}

std::string VGMaps::getName() {
    return name;
}

void VGMaps::setName(std::string n) {
    name=n;
}

void VGMaps::printMapAdjacency() {
    for (int i=0; i<30; i++){
        std::cout <<i << " -->";
        map[i].printAdjacency();
    }
}

void VGMaps::placeBuilding(string buildingColour, int buildingVal, bool facingUp) {
    //in game place building params will be buildingTile and facing up
    //check if colour already has been placed in map
    //check if have enough resources to place tile


    //map[i].colour = &buildingColour;
    //map[i].facingUp =&facingUp;
    //decrease resource tracker by buildingVal
}

void VGMaps::BFS(int x) {
// Mark all the vertices as not visited
//bool isColour;
    bool *visited = new bool[30];
    for (int i = 0; i < 30; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;
    // Mark the current node as visited and enqueue it
    visited[x] = true;
    queue.push_back(x);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        x = queue.front();
        cout << x << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = map[x].adjacent.begin(); i != map[x].adjacent.end();++i) {
            if (!visited[*i]) {

                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
void VGMaps::checkColourInMap(string c) {
    int x=29;
    list<int> placeAt;
    bool *visited = new bool[30];
    for (int i = 0; i < 30; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;
    // Mark the current node as visited and enqueue it
    visited[x] = true;
    queue.push_back(x);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        x = queue.front();
        if (map[x].colour->compare("green")==0) {
            for (std::list<int>::iterator it=map[x].adjacent.begin(); it != map[x].adjacent.end(); ++it) {
                //pushes filled values
                if(map[*it].colour->compare("none")==0)
                    placeAt.push_back(*it);
            }
        }
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = map[x].adjacent.begin(); i != map[x].adjacent.end();++i) {
            if (!visited[*i]) {

                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    placeAt.sort();
    placeAt.unique();
    if (placeAt.empty())
        cout << "\nThere are no green buildings.";
    else {
        cout << "Place at: ";
        for (std::list<int>::iterator it = placeAt.begin(); it != placeAt.end(); ++it)
            std::cout << ' ' << *it ;
    }
    queue.clear();
    placeAt.clear();
}


