#include "graph_node.h"
#include <cstdlib>
#include <iostream>
#include "graph_connection.h"


using namespace std;

GraphNode::GraphNode() {


	id = 0;
	prevNode = NULL;

	m_processingDelay = rand() % 100;
	m_processingDelay *= .01;


	m_transmissionDelay = rand() % 100;
	m_remainingBufferSize = rand() % 100;

	// a* data values for the node
	shortDis = 1000000;
	totalDis = 1000000;

	heur = 0;

	isCurrent = false;


}

void GraphNode::outPutNodalDelays() {

	cout << m_processingDelay << endl;


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