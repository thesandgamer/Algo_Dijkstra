// AlgoDijkstra.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Node.h"
#include "PathFindingList.h"




vector<float> FindPath();

int main()
{



    FindPath();


    return 0;
}


vector<float> FindPath()
{
    //[===============================]Graph[===================================]
    float noCO = 100000.0f;
    float graph[7][7] =
    {
        //A     B       C       D       E       F       G
        {0.0f,  15.0,   22.0,   noCO,   noCO,   noCO,   noCO}, //A
        {15.0,  noCO,   noCO,   20.0,   18.0,   noCO,   noCO}, //B
        {22.0,  noCO,   noCO,   16.0,   noCO,   42.0,   noCO}, //C
        {noCO,  20.0,   16.0,   noCO,   noCO,   noCO,   noCO}, //D
        {noCO,  noCO,   noCO,   noCO,   noCO,   15.0,   25.0}, //E
        {noCO,  noCO,   42.0,   noCO,   15.0,   noCO,   10.0}, //F
        {noCO,  noCO,   noCO,   noCO,   25.0,   10.0,   noCO}, //G

    };
    //[=========================================================================]

    //Créer les listes des node ouvert et fermé
    PathFindingList openList = PathFindingList(); //Nodes visités
    PathFindingList closedList = PathFindingList(); //Node plus calculable car on à tout calculé

    //
    vector<Connection> connections;

    //Créer le record du node de départ
    Node startNode = Node();
    startNode.node = 'A';
    startNode.connectedNodes = {};
    startNode.cost = 0;

    Node goalNode = Node();
    goalNode.node = 'F';
    goalNode.connectedNodes = {};
    goalNode.cost = 0;

    //Ajoute à la liste des nodes à lire le node de départ
    openList.nodeList.push_back(startNode);

    //tant qu'il y a des nodes à essayer les connections
    while (openList.nodeList.size() > 0)
    {
        //Le node actuel est le node record de la la liste avec le plus petit côut
        Node current = *openList.FindSmallestValue();

        //Si le plus petit calcul(node record) est celui de fin on arrète
        if (current.node == goalNode.node) break;


        //Choper la valeur du tableau du node current
        int rows = sizeof(graph) / sizeof(graph[0]);
        int cols = sizeof(graph[0]) / sizeof(graph[0][0]);

        connections.resize(rows * cols);

        //On va set les connections du node record
        for (int x = 0; x < rows; x++)
        {
            for (int x = 0; x < cols; x++)
            {

            }
        }
        
        //Pour chaque connection du node actuel
        for (Connection connection : current.connectedNodes)
        {
            //On va faire des test avec le node connecté
            Node* endNodeRecord;

            Node endNode = *connection.GetFromNode(); //Stoque le node auquel il est relié
            int endNodeCost = current.cost + connection.GetCost(); //Stoquer le cout du node auquel le actuel est va

            //Si il fait parti des nodes fermé on passe à la connection uivante
            if (closedList.Contains(endNode))
            {
                continue;
            }
            //Si il fait parti de la liste ouverte
            else if (openList.Contains(endNode))
            {
                endNodeRecord = openList.Find(endNode);
                if (endNodeRecord->cost <= endNodeCost) continue; //Si son coût 
            }
            //Sinon on va créer un record/un node 
            else
            {
                endNodeRecord = new Node();
                endNodeRecord->node = endNode.node;

            }

            endNodeRecord->cost = endNodeCost;
            endNodeRecord->connectedNodes.push_back(connection);

            //Si il ne fait pas parti de la liste des nodes visité, on l'ajoute
            if (!openList.Contains(endNode))
            {
                openList.nodeList.push_back(*endNodeRecord);
            }



        }
        //Quand on à finit de check toutes les connections du node
        //On enlève current de open
        std::vector<Node>::iterator it = std::find(openList.nodeList.begin(), openList.nodeList.end(), current);
        openList.nodeList.erase(it);
        //On le rajoute dnas closed
        closedList.nodeList.push_back(current);


        //Créer le path
        vector<Connection> path;
        if (current.node != goalNode.node)
        {
        }
        else
        {
            while (current.node != startNode.node)
            {
               // path.push_back(current.connectedNodes);
               // current = current.connectedNodes.get
            }
        }




    }

    return {};
}


//
// Trouve dans la liste le node avec le nom qu'on veut et on le set en node de départ
// 
//
// Find: operator qui va comparer deux nodes avec leurs paralètres


