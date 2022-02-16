#pragma once
#include <vector>

using std::vector;

class Node;

class Connection
{
public:

//	Connection(int costP, Node* fromNodeP, Node* toNodeP);
	Connection(int costP, int fromNodeP, int toNodeP);
	Connection();
	~Connection();

	int GetCost() { return cost; }
	/*
	Node* GetFromNode() { return fromNode; }
	Node* GetToNode() { return toNode; }
	*/
	int GetFromNode() { return fromNode; }
	int GetToNode() { return toNode; }
	



private:
	int cost;
	/*
	Node* fromNode;
	Node* toNode;	
	*/

	int fromNode;
	int toNode;
	


};

