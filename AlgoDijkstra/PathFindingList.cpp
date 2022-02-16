#include "PathFindingList.h"

PathFindingList::PathFindingList()
{
}

PathFindingList::~PathFindingList()
{
}

Node* PathFindingList::FindSmallestValue()
{
	return nullptr;
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
