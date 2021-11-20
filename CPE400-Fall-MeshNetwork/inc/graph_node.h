#include <vector>
#include "graph_connection.h"

class GraphNode {

public:
	GraphNode();

	void outPutNodalDelays();

private:
	float procDelay;
	float transDelay;
	float qDelay;

	std::vector<GraphConnection> connections;
};