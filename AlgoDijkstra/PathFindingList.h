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


    //Créer un override pour = et == qui va retourner la nodeList
    //Créer un override pour += et pour -=

    bool operator == (PathFindingList const& obj)
    {
        if (this->nodeList == obj.nodeList)
        {
            return true;

        }
        else
        {
            return false;
        }

    }

    /*
    PathFindingList operator+=(PathFindingList const& obj)
    {
        PathFindingList result
    }
    */
};
