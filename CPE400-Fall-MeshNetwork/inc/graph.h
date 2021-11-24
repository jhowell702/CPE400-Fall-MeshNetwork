#include <vector>

class GraphNode;

class Graph {

public:
	Graph();

	void outputDelays();
	void defaultInit();

	int getNumNodes() { return numNodes; };

	std::vector<GraphNode*> getNodes() { return nodes; };

private:
	std::vector<GraphNode * > nodes;

	int numNodes;
};