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

	nodes[a]->setHeur(5);
	nodes[a]->createConnection(nodes[b], 6);
	nodes[a]->createConnection(nodes[c], 3);
	nodes[a]->createConnection(nodes[d], 4);

	nodes[b]->setHeur(2);
	nodes[b]->createConnection(nodes[a], 6);
	nodes[b]->createConnection(nodes[e], 7);
	nodes[b]->createConnection(nodes[f], 9);

	nodes[c]->setHeur(5);
	nodes[c]->createConnection(nodes[a], 1);
	nodes[c]->createConnection(nodes[f], 3);

	nodes[d]->setHeur(3);
	nodes[d]->createConnection(nodes[a], 4);
	nodes[d]->createConnection(nodes[f], 1);
	nodes[d]->createConnection(nodes[h], 8);

	nodes[e]->setHeur(2);
	nodes[e]->createConnection(nodes[b], 7);
	nodes[e]->createConnection(nodes[i], 11);

	nodes[f]->setHeur(9);
	nodes[f]->createConnection(nodes[c], 3);
	nodes[f]->createConnection(nodes[b], 9);
	nodes[f]->createConnection(nodes[d], 1);
	nodes[f]->createConnection(nodes[g], 4);

	nodes[g]->setHeur(6);
	nodes[g]->createConnection(nodes[f], 4);
	nodes[g]->createConnection(nodes[i], 12);
	nodes[g]->createConnection(nodes[j], 13);
	nodes[g]->createConnection(nodes[k], 9);

	nodes[h]->setHeur(2);
	nodes[h]->createConnection(nodes[d], 8);
	nodes[h]->createConnection(nodes[k], 6);

	nodes[i]->setHeur(7);
	nodes[i]->createConnection(nodes[e], 1);
	nodes[i]->createConnection(nodes[g], 12);
	nodes[i]->createConnection(nodes[z], 5);

	nodes[j]->setHeur(1);
	nodes[j]->createConnection(nodes[e], 1);
	nodes[j]->createConnection(nodes[g], 13);
	nodes[j]->createConnection(nodes[z], 3);

	nodes[k]->setHeur(k);
	nodes[k]->createConnection(nodes[h], 6);
	nodes[k]->createConnection(nodes[z], 7);
	nodes[k]->createConnection(nodes[g], 9);

	nodes[z]->setHeur(z);
	nodes[z]->createConnection(nodes[z], 6);

}

void Graph::outputDelays() {

	for (auto & i : nodes) {
		i->outPutNodalDelays();
	}

}
