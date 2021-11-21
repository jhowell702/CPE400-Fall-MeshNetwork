#include <vector>
#include "graph_connection.h"

class GraphNode {

public:
	GraphNode();

	void outPutNodalDelays();

private:
	float procDelay;
	float transDelay;
	float qSize;

	// a* data values for the node
	float shortDis;
	float heur;
	float totalDis;

	GraphNode* prevNode;

	std::vector<GraphConnection> connections;
};