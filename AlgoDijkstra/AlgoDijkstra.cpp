// AlgoDijkstra.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

using std::vector;

int main()
{
    PathfindingList openList;
    PathfindingList closedList;

    Node startNode = Node();
    startNode.node = 'A';
    startNode.connectedNodes;
    startNode.cost = 0;

    Node goalNode = Node();


    openList = PathfindingList();
    openList.nodeList.push_back( startNode);

    while (openList.nodeList.size() > 0)
    {
        Node current = *openList.FindSmallestValue();

        if (current.node == goalNode.node) break;
        
        
        for (Node* connection : current.connectedNodes)
        {
            

        }

    }

}



//
// Trouve dans la liste le node avec le nom qu'on veut et on le set en node de départ
// 
//
// Find: operator qui va comparer deux nodes avec leurs paralètres


struct Node
{
    char node;
    vector<Node*> connectedNodes;
    int cost;

};

class PathfindingList
{
public:
    vector<Node> nodeList;

    Node* FindSmallestValue();
    bool Contains();
    Node* Find();


    //Créer un override pour = et == qui va retourner la nodeList
    //Créer un override pour += et pour -=
};

