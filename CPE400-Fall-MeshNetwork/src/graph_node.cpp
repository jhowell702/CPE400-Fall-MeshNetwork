#include "graph_node.h"
#include <cstdlib>
#include <iostream>
#include "graph_connection.h"


using namespace std;

GraphNode::GraphNode() {

	//default initialization of values.
	id = 0;
	prevNode = NULL;

	m_processingDelay = 1;

	m_transmissionDelay = 1;

	m_remainingBufferSize = 1;

	heur = 1;

	isCurrent = false;

	// a* data values for the node. Set to be an arbitrary high number, such that any calculated shortest distance or total distance is always lower than default.
	shortDis = 500;
	totalDis = 500;

}


void GraphNode::createConnection(GraphNode* connectingNode, float propDelay) {

	//create a new connection with starting node, end node, and given propagation delay, and add to vector
	GraphConnection* temp = new GraphConnection(this ,connectingNode, propDelay);

	connections.push_back(temp);
}

void GraphNode::genNewConnections() {

	//for all connections this node has, generate a new propagation delay
	std::vector<GraphConnection*>::iterator it;
	for (it = connections.begin(); it != connections.end(); it++) {
		(*it)->genNewDelay();
	}
}

GraphConnection* GraphNode::findConnection(int num) {

	//find connection that leads to end node in vector
	std::vector<GraphConnection*>::iterator it;
	for (it = connections.begin(); it != connections.end(); it++) {
		if ((*it)->getEnd()->getID() == num) {
			return (*it);
		}
	}
}

void GraphNode::calcHeurAndSet(int proc, int trans, int buffer) {

	//given a processing, transmission delay and buffer size, calculate heuristic value for node
	m_processingDelay = proc;
	m_transmissionDelay = trans;
	m_remainingBufferSize = buffer;
	heur = (1000 / buffer) * (.01 * (proc + trans));

}

void GraphNode::genNewValues() {

	//randomly generate new delays, buffer size, and calculate new heuristic using those values, then generate new propagation delays for all connections
	m_processingDelay = rand() % 10 + 10;

	m_transmissionDelay = rand() % 40 + 20;

	m_remainingBufferSize = rand() % 48 + 12;

	heur = (1000 / m_remainingBufferSize) * (.01 * (m_processingDelay + m_transmissionDelay));

	std::vector<GraphConnection*>::iterator it;
	for (it = connections.begin(); it != connections.end(); it++) {
		(*it)->genNewDelay();
	}
}