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

	nodes[a]->setHeur(0);
	nodes[a]->createConnection(nodes[b], 30);
	nodes[a]->createConnection(nodes[c], 20);
	nodes[a]->createConnection(nodes[d], 90);

	nodes[b]->calcHeur(12, 27, 52);
	nodes[b]->createConnection(nodes[a], 30);
	nodes[b]->createConnection(nodes[e], 37);
	nodes[b]->createConnection(nodes[f], 40);

	nodes[c]->calcHeur(20, 60, 30);
	nodes[c]->createConnection(nodes[a], 20);
	nodes[c]->createConnection(nodes[f], 50);

	nodes[d]->calcHeur(14, 26, 57);
	nodes[d]->createConnection(nodes[a], 90);
	nodes[d]->createConnection(nodes[f], 10);
	nodes[d]->createConnection(nodes[h], 26);

	nodes[e]->calcHeur(12, 53, 12);
	nodes[e]->createConnection(nodes[b], 37);
	nodes[e]->createConnection(nodes[i], 45);

	nodes[f]->calcHeur(11, 31, 48);
	nodes[f]->createConnection(nodes[c], 50);
	nodes[f]->createConnection(nodes[b], 40);
	nodes[f]->createConnection(nodes[d], 10);
	nodes[f]->createConnection(nodes[g], 67);

	nodes[g]->calcHeur(17, 48, 22);
	nodes[g]->createConnection(nodes[f], 67);
	nodes[g]->createConnection(nodes[i], 26);
	nodes[g]->createConnection(nodes[j], 48);
	nodes[g]->createConnection(nodes[k], 24);

	nodes[h]->calcHeur(12, 23, 59);
	nodes[h]->createConnection(nodes[d], 26);
	nodes[h]->createConnection(nodes[k], 32);

	nodes[i]->calcHeur(20, 60, 12);
	nodes[i]->createConnection(nodes[e], 45);
	nodes[i]->createConnection(nodes[g], 26);
	nodes[i]->createConnection(nodes[z], 51);

	nodes[j]->calcHeur(15, 37, 18);
	nodes[j]->createConnection(nodes[g], 48);
	nodes[j]->createConnection(nodes[z], 82);

	nodes[k]->calcHeur(13, 20, 56);
	nodes[k]->createConnection(nodes[h], 32);
	nodes[k]->createConnection(nodes[z], 24);
	nodes[k]->createConnection(nodes[g], 42);

	nodes[z]->setHeur(0);
	nodes[z]->createConnection(nodes[i], 51);
	nodes[z]->createConnection(nodes[j], 82);
	nodes[z]->createConnection(nodes[k], 42);

}

/*void Graph::defaultInit() {

	enum nodesNames { a, b, c, d, e, f, g, h, i, j, k, z };

	nodes[a]->setHeur(0);
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

}*/

void Graph::outputDelays() {

	for (auto & i : nodes) {
		i->outPutNodalDelays();
	}

}
