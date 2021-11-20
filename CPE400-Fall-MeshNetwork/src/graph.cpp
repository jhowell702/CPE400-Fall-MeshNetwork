#include <graph.h>


Graph::Graph() {
	
	numNodes = 10;

	for (int x = 0; x < numNodes; x++) {

		GraphNode* temp = new GraphNode();
		nodes.push_back(temp);

	}

}

void Graph::outputDelays() {

	for (auto & i : nodes) {
		i->outPutNodalDelays();
	}

}
