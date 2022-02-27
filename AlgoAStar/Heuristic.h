#pragma once
#include "Node.h"

class Heuristic
{
public:
	Heuristic(int goalNodeP);

	int Estimate(Node node);

	int goalNode;



};

