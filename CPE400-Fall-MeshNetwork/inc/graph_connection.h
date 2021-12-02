class GraphNode;

class GraphConnection {

public:
	GraphConnection(GraphNode*, GraphNode*, float);

	GraphNode* getEnd() { return end_node; };
	int getDelay() { return propDelay; };

	void genNewDelay();

private:
	GraphNode* start_node;
	GraphNode* end_node;
	int propDelay;

};