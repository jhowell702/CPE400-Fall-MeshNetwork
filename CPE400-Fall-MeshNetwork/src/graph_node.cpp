#include "graph_node.h"
#include <cstdlib>
#include <iostream>
#include "graph_connection.h"


using namespace std;

GraphNode::GraphNode() {


	id = 0;
	prevNode = NULL;

	m_processingDelay = 1;

	m_transmissionDelay = 1;

	m_remainingBufferSize = 1;

	heur = (1000 / m_remainingBufferSize) * (.01 * (m_processingDelay + m_transmissionDelay));

	// a* data values for the node
	shortDis = 300;
	totalDis = 300;


	isCurrent = false;


}

void GraphNode::outPutNodalDelays() {

	cout << m_processingDelay << endl;

}

void GraphNode::createConnection(GraphNode* connectingNode, float propDelay) {

	GraphConnection* temp = new GraphConnection(this ,connectingNode, propDelay);

	connections.push_back(temp);
}

void GraphNode::genNewConnections() {
	std::vector<GraphConnection*>::iterator it;
	for (it = connections.begin(); it != connections.end(); it++) {
		(*it)->genNewDelay();
	}
}

GraphConnection* GraphNode::findConnection(int num) {

	std::vector<GraphConnection*>::iterator it;
	for (it = connections.begin(); it != connections.end(); it++) {
		if ((*it)->getEnd()->getID() == num) {
			return (*it);
		}
	}
}

void GraphNode::calcHeurAndSet(int proc, int trans, int buffer) {

	m_processingDelay = proc;
	m_transmissionDelay = trans;
	m_remainingBufferSize = buffer;
	heur = (1000 / buffer) * (.01 * (proc + trans));

}

void GraphNode::genNewValues() {
	m_processingDelay = rand() % 10 + 10;

	m_transmissionDelay = rand() % 40 + 20;

	m_remainingBufferSize = rand() % 48 + 12;

	heur = (1000 / m_remainingBufferSize) * (.01 * (m_processingDelay + m_transmissionDelay));

	std::vector<GraphConnection*>::iterator it;
	for (it = connections.begin(); it != connections.end(); it++) {
		(*it)->genNewDelay();
	}
}