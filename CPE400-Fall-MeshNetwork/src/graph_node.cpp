#include "graph_node.h"
#include <cstdlib>
#include <iostream>
#include "graph_connection.h"


using namespace std;

GraphNode::GraphNode() {


	procDelay = rand() % 100;
	procDelay *= .01;


	transDelay = rand() % 100;
	qSize = rand() % 100;

	// a* data values for the node
	shortDis = 1000000;
	totalDis = 1000000;

	heur = 0;


}

void GraphNode::outPutNodalDelays() {

	cout << procDelay << endl;


}

void GraphNode::createConnection(GraphNode* connectingNode, float propDelay) {

	GraphConnection* temp = new GraphConnection(this ,connectingNode, propDelay);

	connections.push_back(temp);
}

GraphConnection* GraphNode::findConnection(int num) {

	std::vector<GraphConnection*>::iterator it;
	for (it = connections.begin(); it != connections.end(); it++) {
		if ((*it)->getEnd()->getID() == num) {
			return (*it);
		}
	}
}