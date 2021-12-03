#include "graph_connection.h"
#include "graph_node.h"

GraphConnection::GraphConnection(GraphNode* begin, GraphNode* end, float in_propDelay) {

	start_node = begin;
	end_node = end;
	propDelay = in_propDelay;

}

void GraphConnection::genNewDelay() {

	propDelay = rand() % 80 + 20;

}