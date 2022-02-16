#pragma once
#include <vector>

using std::vector;

class Node;

class Connection
{
public:

	int GetCost() { return cost; }
	Node* GetFromNode() { return fromNode; }
	Node* GetToNode() { return toNode; }



private:
	int cost;
	Node* fromNode;
	Node* toNode;

};

