#pragma once
#include "Node.h"

class Heuristic
{
public:
	Heuristic(int goalNodeP); //Constructeur qui va prendre le node d'arriv�e
	Heuristic(); //Constructeur qui va prendre le node d'arriv�e

	int Estimate(Node node);//Estimer l'Heuristique du node

	int goalNode; //Stoque quel va �tre le node d'arriv�e



};

