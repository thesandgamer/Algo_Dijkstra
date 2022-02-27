// AlgoDijkstra.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Node.h"
#include "PathFindingList.h"
#include "Heuristic.h"

#include <string>

using std::string;


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
        {15.0,  0.0f,   noCO,   20.0,   18.0,   noCO,   noCO}, //B
        {22.0,  noCO,   0.0f,   16.0,   noCO,   42.0,   noCO}, //C
        {noCO,  20.0,   16.0,   0.0f,   noCO,   noCO,   noCO}, //D
        {noCO,  18.0,   5.0f,   noCO,   0.0f,   15.0,   25.0}, //E
        {noCO,  noCO,   42.0,   noCO,   15.0,   0.0f,   10.0}, //F
        {noCO,  noCO,   noCO,   noCO,   25.0,   10.0,   0.0f}, //G

    };
    char letterTab[7] = { 'A','B','C','D','E','F','G' };

    //[=========================================================================]

    //Créer les listes des node ouvert et fermé
    PathFindingList openList = PathFindingList(); //Nodes visités
    PathFindingList closedList = PathFindingList(); //Node plus calculable car on à tout calculé

    //
    Node goalNode = Node();
    goalNode.node = 5;
    goalNode.connectedNodes = {};
    goalNode.cost = 0;

    //
    Heuristic heuristique = Heuristic(goalNode.node);


    //Créer le record du node de départ
    Node startNode = Node();
    startNode.node = 0;
    startNode.connectedNodes.push_back( Connection(graph[0][0], 0, 0) );
    startNode.cost = 0;
    startNode.estimedTotalCost = heuristique.Estimate(startNode);




    //Ajoute à la liste des nodes à lire le node de départ
    openList.nodeList.push_back(startNode);

    Node current =  Node();



    //tant qu'il y a des nodes à essayer les connections
    while (openList.nodeList.size() > 0)
    {

        //Le node actuel est le node record de la la liste avec le plus petit côut
        current = *openList.FindSmallestValue(); ////utiliser le total cost pour le find smallest value

        //Si le plus petit calcul(node record) est celui de fin on arrète
        if (current.node == goalNode.node) break;


        //------------Connections---------------
        //Choper la valeur de taille du Graph
        int rows = sizeof(graph) / sizeof(graph[0]);
        int cols = sizeof(graph[0]) / sizeof(graph[0][0]);

        //Cheche le node actuel, et regarde quels sont ces connections
        //Lire chaque Ligne ou colonne
        //Si y'a un connection(pas de 0 ou de noCo on rajoute)
        
        int cnode = current.node;
        vector<Connection> currentConnections; 
        for (int i = 0; i < rows; i++)
        {
            if ((graph[cnode][i] != noCO) and (graph[cnode][i] != 0.0f))
            {
                Connection connect = Connection(graph[cnode][i], cnode, i);
                currentConnections.push_back(connect);
            }
        }
        //-------------------------------
        
        //Pour chaque connection du node actuel
        for (Connection connection : currentConnections)
        {
            //On va faire des test avec le node connecté
            Node* nextNodeRecord;
            Node nextNode = Node(); //Stoque le node auquel il est relié

            //Set le node suivant
            int nextNodeValue = connection.GetToNode();
            int nextNodeCost = current.cost + connection.GetCost(); //Stoquer le cout du node auquel le actuel est va
            int nextNodeHeuristic;

            nextNode.node = nextNodeValue;
            nextNode.cost = nextNodeCost;


            //Print la connection
            char nodeStart = letterTab[connection.GetFromNode()];
            char nodeEnd = letterTab[connection.GetToNode()];
            //std::cout << "From node: " << nodeStart << " to node: " << nodeEnd << " cost: " << connection.GetCost() << std::endl;
            //std::cout << "From node: " << connection.GetFromNode() << " to node: " << connection.GetToNode() << " cost: " << connection.GetCost() << std::endl;

            if (nextNodeValue == 5)
            {
                bool k = false;
            }


            //Si il fait parti des nodes fermé on passe à la connection uivante
            if (closedList.Contains(nextNode))
            {
                nextNodeRecord = closedList.Find(nextNode);
                if (nextNodeRecord->cost <= nextNodeCost) continue;
                std::vector<Node>::iterator it = std::find(closedList.nodeList.begin(), closedList.nodeList.end(), nextNodeRecord);
                closedList.nodeList.erase(it);

                nextNodeHeuristic = nextNodeRecord->estimedTotalCost - nextNodeRecord->cost;

                continue;
            }
            //Si il fait parti de la liste ouverte
            else if (openList.Contains(nextNode))
            {
                nextNodeRecord = openList.Find(nextNode);
               
                if (nextNodeRecord->cost <= nextNodeCost)
                {
                    continue; //Si son coût 
                }

                nextNodeHeuristic = nextNodeRecord->estimedTotalCost - nextNodeRecord->cost;
            }
            //Sinon on va créer un record/un node 
            else
            {
                nextNodeRecord = new Node();
                nextNodeRecord->node = nextNode.node;

                nextNodeHeuristic = heuristique.Estimate(nextNode);

            }

            nextNodeRecord->cost = nextNodeCost;
            nextNodeRecord->connectedNodes.clear();
            nextNodeRecord->connectedNodes.push_back(connection);
            nextNodeRecord->estimedTotalCost = nextNodeCost + nextNodeHeuristic;

            //Si il ne fait pas parti de la liste des nodes visité, on l'ajoute
            if (!openList.Contains(nextNode))
            {
                openList.nodeList.push_back(*nextNodeRecord);
            }


        }
        //std::cout << "NODE " << current.node << " COST " << current.cost<< " from node: " << current.connectedNodes[0].GetFromNode() << std::endl;
        std::cout << "NODE " << letterTab[current.node] << " COST " << current.cost<< " Heurstique cost: "<< current.estimedTotalCost << " from node: " << letterTab[current.connectedNodes[0].GetFromNode()] << std::endl;

        
        //Quand on à finit de check toutes les connections du node
        //On enlève current de open
        std::vector<Node>::iterator it = std::find(openList.nodeList.begin(), openList.nodeList.end(), current);
        openList.nodeList.erase(it);
        //On le rajoute dnas closed
        closedList.nodeList.push_back(current);






    }
    //std::cout << "NODE " << current.node << " COST " << current.cost << " from node: " << current.connectedNodes[0].GetFromNode() << std::endl;
    std::cout << "NODE " << letterTab[current.node] << " COST " << current.cost << " from node: " << letterTab[current.connectedNodes[0].GetFromNode()] << std::endl;
    

    //Créer le path
     vector<int> path = {};
     int finalCost = current.cost;
     //---------
     std::cout << std::endl;
     std::cout << "Start node: " << letterTab[startNode.node] << " => " << "End node: " << letterTab[goalNode.node] << std::endl;;
    //Si à la fin le node current n'est pas le goal c'est qu'on ne l'a pas trouvé
    if (current.node != goalNode.node)
    {
        std::cout << std::endl << "Path not found"<< std::endl;
    }
    //Calcul du chemin final
    else
    {
        while (current.node != startNode.node)//Tant que le node actuel n'est pas le premier
        {
            path.push_back(current.node);
            current = *closedList.Find( current.connectedNodes[0].GetFromNode());
        }
        path.push_back(startNode.node);

        std::reverse(path.begin(), path.end());

        std::cout << "Path: ";
        for (int let : path)
        {
            std::cout << letterTab[let] << " ";

        }
        std::cout << std::endl;

        std::cout << "For a cost of: " << finalCost << std::endl;

    }




    return {};
}



