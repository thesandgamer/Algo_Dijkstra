#include "Connection.h"

/*
Connection::Connection(int costP, Node* fromNodeP, Node* toNodeP) : cost(costP),fromNode(fromNodeP),toNode(toNodeP)
{
}
*/

Connection::Connection(int costP, int fromNodeP, int toNodeP) : cost(costP), fromNode(fromNodeP), toNode(toNodeP)

{
}

Connection::Connection(): cost(0),fromNode(-1),toNode(-1)
{
}

Connection::~Connection()
{
}
