#include <vector>

class GraphConnection;



class GraphNode {

public:
	GraphNode();

	void outPutNodalDelays();


	void setID(int in) { id = in; };

	void setShort(float in) { shortDis = in; };
	void setHeur(float in) { heur = in; };
	void setTotal(float in) { totalDis = in; };

	void setPrev(GraphNode* in) { prevNode = in; };

	int getID() { return id; };
	float getShort() { return shortDis; };
	float getHeur() { return heur; };
	float getTotal() { return totalDis; };

	void createConnection(GraphNode*, float);

	std::vector<GraphConnection*> getConnections() { return connections; };

private:

	int id;

	float procDelay;
	float transDelay;
	float qSize;

	// a* data values for the node
	float shortDis;
	float heur;
	float totalDis;

	GraphNode* prevNode;

	std::vector<GraphConnection*> connections;
};