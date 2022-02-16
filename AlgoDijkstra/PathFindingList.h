#pragma once
#include <iostream>
#include "Node.h"

class PathFindingList
{
public:
    PathFindingList();
    ~PathFindingList();

    vector<Node> nodeList;

    Node* FindSmallestValue();
    bool Contains(Node node);
    Node* Find(Node node);


    //Cr�er un override pour = et == qui va retourner la nodeList
    //Cr�er un override pour += et pour -=

    /*
    PathFindingList operator+=(PathFindingList const& obj)
    {
        PathFindingList result
    }
    */
};
