class GraphNode;

class GraphConnection {

public:
	GraphConnection();

private:
	GraphNode* left_node;
	GraphNode* right_node;
	float transDelay;

};