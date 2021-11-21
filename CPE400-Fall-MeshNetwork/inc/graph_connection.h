class GraphNode;

class GraphConnection {

public:
	GraphConnection(GraphNode*, GraphNode*, float);

	GraphNode* getEnd() { return end_node; };
	float getDelay() { return propDelay; };

private:
	GraphNode* start_node;
	GraphNode* end_node;
	float propDelay;

};