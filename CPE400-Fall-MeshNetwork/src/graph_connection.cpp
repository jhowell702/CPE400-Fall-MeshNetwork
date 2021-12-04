#include "graph_connection.h"
#include "graph_node.h"

GraphConnection::GraphConnection(GraphNode* begin, GraphNode* end, float in_propDelay) {

	//set starting node, end node, and propagation delay
	start_node = begin;
	end_node = end;
	propDelay = in_propDelay;

}

void GraphConnection::genNewDelay() {

	//randomly genearte new propagation delay
	propDelay = rand() % 80 + 20;

}