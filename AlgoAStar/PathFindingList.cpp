#include "PathFindingList.h"

PathFindingList::PathFindingList()
{
}

PathFindingList::~PathFindingList()
{
}

Node* PathFindingList::FindSmallestValue()
{
	/*
	Node oldNode= nodeList[0];
	for (Node node : nodeList)
	{
		if (node.cost < oldNode.cost )
		{
			oldNode = node;
		}
	}
	return &oldNode;*/

	int min = nodeList[0].cost;
	int storedNode = 0;

	// Iterate through list of nodes, skipping the first one because it already is the reference
	for (int i = 1; i < nodeList.size(); i++)
	{
		if (nodeList[i].cost < min) {
			min = nodeList[i].cost;
			storedNode = i;
		}
	}

	return &nodeList[storedNode];
}

bool PathFindingList::Contains(Node node)
{
	std::vector<Node>::iterator it = std::find(nodeList.begin(), nodeList.end(), node);
	if (it != nodeList.end())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Node* PathFindingList::Find(Node node)
{
	
	std::vector<Node>::iterator it = std::find(nodeList.begin(), nodeList.end(), node);
	return &nodeList.at(it - nodeList.begin());
}

Node* PathFindingList::Find(int node)
{
	int storedNode = 0;

	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList[i].node == node)
		{
			storedNode = i;
			break;
		}
	}
	return &nodeList[storedNode];
}
