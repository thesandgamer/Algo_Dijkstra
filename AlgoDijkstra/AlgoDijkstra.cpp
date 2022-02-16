// AlgoDijkstra.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Node.h"
#include "PathFindingList.h"






int main()
{
    float noCO = 100000.0f;
    float graph[7][7] =
    {
        //A     B       C       D       E       F       G
        {noCO,  noCO,   noCO,   noCO,   noCO,   noCO,   noCO}, //A
        {noCO,  noCO,   noCO,   noCO,   noCO,   noCO,   noCO}, //B
        {noCO,  noCO,   noCO,   noCO,   noCO,   noCO,   noCO}, //C
        {noCO,  noCO,   noCO,   noCO,   noCO,   noCO,   noCO}, //D
        {noCO,  noCO,   noCO,   noCO,   noCO,   noCO,   noCO}, //E
        {noCO,  noCO,   noCO,   noCO,   noCO,   noCO,   noCO}, //F
        {noCO,  noCO,   noCO,   noCO,   noCO,   noCO,   noCO}, //G

    };

    PathFindingList openList = PathFindingList();
    PathFindingList closedList = PathFindingList();

    Node startNode = Node();
    startNode.node = 'A';
    startNode.connectedNodes;
    startNode.cost = 0;

    Node goalNode = Node();


    openList.nodeList.push_back( startNode);

    while (openList.nodeList.size() > 0)
    {
        Node current = *openList.FindSmallestValue();

        if (current.node == goalNode.node) break;
        
        
        for (Node* connection : current.connectedNodes)
        {
            Node endNode = *connection;
            Node* endNodeRecord;
            int endNodeCost = current.cost + connection->cost;

            if (closedList.Contains(endNode))
            {
                continue;
            }
            else if (openList.Contains(endNode))
            {                             
                endNodeRecord = new Node();
                endNodeRecord = openList.Find(endNode);
                if (endNodeRecord->cost <= endNodeCost) continue;
            }
            else
            {
                endNodeRecord = new Node();
                endNodeRecord->node = endNode.node;
                
            }
            endNodeRecord->cost = endNodeCost;
            endNodeRecord->connectedNodes.push_back(connection);

            if (!openList.Contains(endNode))
            {
                openList.nodeList.push_back(*endNodeRecord);
            }

            //REMOVE LE current de open
            closedList.nodeList.push_back(current);

        }


        //Créer le path
        if (current.node != goalNode.node)
        {

        }




    }



}



//
// Trouve dans la liste le node avec le nom qu'on veut et on le set en node de départ
// 
//
// Find: operator qui va comparer deux nodes avec leurs paralètres


