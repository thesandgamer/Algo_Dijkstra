#pragma once
#include <vector>
#include "Connection.h"
using std::vector;


struct Node
{
    //char node;
    int node;
    vector<Connection> connectedNodes;
    int cost;
    int estimedTotalCost;

    Node() {};

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
    bool operator == (Node* const& obj)
    {
        
        if (this->node == obj->node)
        {
            return true;

        }
        else
        {
            return false;
        }
        
    }


 

    Node& operator= (const Node& ref)
    {
        node = ref.node;
        connectedNodes = ref.connectedNodes;
        cost = ref.cost;
        estimedTotalCost = ref.estimedTotalCost;    
        return *this;
    };

    Node(const Node& ref)
    {
        *this = ref;
    };


};
