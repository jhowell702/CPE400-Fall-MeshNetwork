#include <vector>

class GraphConnection;

class GraphNode {

public:
	GraphNode();

	void outPutNodalDelays();


	void setID(int in) { id = in; };

	void setShort(int in) { shortDis = in; };
	void setHeur(int in) { heur = in; };
	void setTotal(int in) { totalDis = in; };
	void setCurrent(bool in) { isCurrent = in; };

	void setPrev(GraphNode* in) { prevNode = in; };

	int getID() { return id; };
	int getShort() { return shortDis; };
	int getHeur() { return heur; };
	int getTotal() { return totalDis; };
	bool getCurrent() { return isCurrent; };

	void calcHeur(int, int, int);

	GraphNode* getPrev() { return prevNode; };

	void createConnection(GraphNode*, float);

	void genNewConnections();

	std::vector<GraphConnection*> getConnections() { return connections; };

	GraphConnection* findConnection(int num);

private:

	int id;

	int m_processingDelay;
	int m_transmissionDelay;
	int m_remainingBufferSize;

	// a* data values for the node
	int shortDis;
	int heur;
	int totalDis;

	GraphNode* prevNode;

	bool isCurrent;

	std::vector<GraphConnection*> connections;
};