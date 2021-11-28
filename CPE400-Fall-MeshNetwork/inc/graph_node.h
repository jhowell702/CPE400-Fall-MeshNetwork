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
	void setCurrent(bool in) { isCurrent = in; };

	void setPrev(GraphNode* in) { prevNode = in; };

	int getID() { return id; };
	float getShort() { return shortDis; };
	float getHeur() { return heur; };
	float getTotal() { return totalDis; };
	bool getCurrent() { return isCurrent; };

	GraphNode* getPrev() { return prevNode; };

	void createConnection(GraphNode*, float);

	std::vector<GraphConnection*> getConnections() { return connections; };

	GraphConnection* findConnection(int num);

private:

	int id;

	float m_processingDelay;
	float m_transmissionDelay;
	float m_remainingBufferSize;

	// a* data values for the node
	float shortDis;
	float heur;
	float totalDis;

	GraphNode* prevNode;

	bool isCurrent;

	std::vector<GraphConnection*> connections;
};