#pragma once
#include "Node.h"

class Heuristic
{
public:
	Heuristic(int goalNodeP); //Constructeur qui va prendre le node d'arrivée
	Heuristic(); //Constructeur qui va prendre le node d'arrivée

	int Estimate(Node node);//Estimer l'Heuristique du node

	int goalNode; //Stoque quel va être le node d'arrivée



};

