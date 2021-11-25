#include <map>

using namespace std;

class Graph;
class GraphNode;

class UI {

public:

	UI(map<int, GraphNode*> * in, map<int, GraphNode*>* in2, Graph* graph);

	void aStar_Slow();
	void aStar_Fast();

	void outputNodeData();
	void outputGraph();
	void outputNode(int);
	void outputFinal(GraphNode* prev);
	void UI::outputConnection(int, int);

private:

	GraphNode* currNode;
	map<int, GraphNode*> * unvisitedNodes;
	map<int, GraphNode*> * visitedNodes;

	Graph* graph;

};