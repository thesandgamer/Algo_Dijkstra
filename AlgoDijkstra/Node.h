#pragma once
#include <vector>

using std::vector;


struct Node
{
    char node;
    vector<Node*> connectedNodes;
    int cost;

};
