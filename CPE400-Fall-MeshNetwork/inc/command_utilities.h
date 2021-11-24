#include <map>

using namespace std;

class Graph;
class GraphNode;

class UI {

public:

	UI(map<int, GraphNode*> * in, map<int, GraphNode*>* in2);

	void aStar_Slow();
	void aStar_Fast();

	void outputNodes();
	void outputGraph(Graph* graph);
	void outputNode(Graph* graph, int);
	void UI::outputConnection(Graph* graph, int, int);

private:

	GraphNode* currNode;
	map<int, GraphNode*> * unvisitedNodes;
	map<int, GraphNode*> * visitedNodes;

};