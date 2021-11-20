#include "graph_node.h"
#include <vector>

class Graph {

public:
	Graph();

	void outputDelays();

private:
	std::vector<GraphNode * > nodes;

	int numNodes;
};