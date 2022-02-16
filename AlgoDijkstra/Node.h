#pragma once
#include <vector>
#include "Connection.h"
using std::vector;


struct Node
{
    char node;
    vector<Connection> connectedNodes;
    int cost;


    bool operator == (Node const& obj)
    {
        if (this->node == obj.node)
        {
            return true;

        }
        else
        {
            return false;
        }
        
    }

    /*
    Node operator =(Node const& obj)
    {
        return 
    }*/

};
