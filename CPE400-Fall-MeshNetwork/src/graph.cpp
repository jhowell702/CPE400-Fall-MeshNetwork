#include <graph.h>
#include "graph_node.h"

Graph::Graph() {
	
	numNodes = 12;

	for (int x = 0; x < numNodes; x++) {

		GraphNode* temp = new GraphNode();
		temp->setID(x);
		nodes.push_back(temp);

	}

	defaultInit();

}

void Graph::defaultInit() {

	enum nodesNames { a, b, c, d, e, f, g, h, i, j, k, z };

	nodes[a]->setHeur(14);
	nodes[a]->createConnection(nodes[b], 4);
	nodes[a]->createConnection(nodes[c], 3);

	nodes[b]->setHeur(12);
	nodes[b]->createConnection(nodes[a], 4);
	nodes[b]->createConnection(nodes[f], 5);
	nodes[b]->createConnection(nodes[e], 12);

	nodes[c]->setHeur(11);
	nodes[c]->createConnection(nodes[a], 3);
	nodes[c]->createConnection(nodes[e], 10);
	nodes[c]->createConnection(nodes[d], 7);

	nodes[d]->setHeur(6);
	nodes[d]->createConnection(nodes[c], 7);
	nodes[d]->createConnection(nodes[e], 2);

	nodes[e]->setHeur(4);
	nodes[e]->createConnection(nodes[c], 10);
	nodes[e]->createConnection(nodes[d], 2);
	nodes[e]->createConnection(nodes[b], 12);
	nodes[e]->createConnection(nodes[z], 5);

	nodes[f]->setHeur(11);
	nodes[f]->createConnection(nodes[b], 5);
	nodes[f]->createConnection(nodes[z], 16);

	nodes[z]->setHeur(0);
	nodes[z]->createConnection(nodes[f], 16);
	nodes[z]->createConnection(nodes[e], 5);


}

void Graph::outputDelays() {

	for (auto & i : nodes) {
		i->outPutNodalDelays();
	}

}
