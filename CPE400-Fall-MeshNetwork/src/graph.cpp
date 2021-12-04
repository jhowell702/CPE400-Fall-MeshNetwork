#include <graph.h>
#include "graph_node.h"

Graph::Graph() {
	

	//default initialization for 12 node graph
	numNodes = 12;

	//create 12 nodes and pushback onto node list
	for (int x = 0; x < numNodes; x++) {

		GraphNode* temp = new GraphNode();
		temp->setID(x);
		nodes.push_back(temp);

	}

	//default initialization for all nodes
	defaultInit();

}

void Graph::defaultInit() {

	//default graph intialization using prepicked values

	enum nodesNames { a, b, c, d, e, f, g, h, i, j, k, z };

	nodes[a]->calcHeurAndSet(15, 40, 60);
	nodes[a]->createConnection(nodes[b], 30);
	nodes[a]->createConnection(nodes[c], 20);
	nodes[a]->createConnection(nodes[d], 100);

	nodes[b]->calcHeurAndSet(12, 27, 52);
	nodes[b]->createConnection(nodes[a], 30);
	nodes[b]->createConnection(nodes[e], 20);
	nodes[b]->createConnection(nodes[f], 34);

	nodes[c]->calcHeurAndSet(20, 60, 30);
	nodes[c]->createConnection(nodes[a], 20);
	nodes[c]->createConnection(nodes[f], 50);

	nodes[d]->calcHeurAndSet(14, 26, 57);
	nodes[d]->createConnection(nodes[a], 100);
	nodes[d]->createConnection(nodes[f], 20);
	nodes[d]->createConnection(nodes[h], 37);

	nodes[e]->calcHeurAndSet(12, 53, 12);
	nodes[e]->createConnection(nodes[b], 20);
	nodes[e]->createConnection(nodes[i], 24);

	nodes[f]->calcHeurAndSet(11, 31, 48);
	nodes[f]->createConnection(nodes[c], 50);
	nodes[f]->createConnection(nodes[b], 34);
	nodes[f]->createConnection(nodes[d], 20);
	nodes[f]->createConnection(nodes[g], 67);

	nodes[g]->calcHeurAndSet(17, 48, 22);
	nodes[g]->createConnection(nodes[f], 67);
	nodes[g]->createConnection(nodes[i], 26);
	nodes[g]->createConnection(nodes[j], 48);
	nodes[g]->createConnection(nodes[k], 24);

	nodes[h]->calcHeurAndSet(12, 23, 59);
	nodes[h]->createConnection(nodes[d], 37);
	nodes[h]->createConnection(nodes[k], 32);

	nodes[i]->calcHeurAndSet(20, 60, 15);
	nodes[i]->createConnection(nodes[e], 24);
	nodes[i]->createConnection(nodes[g], 26);
	nodes[i]->createConnection(nodes[z], 25);

	nodes[j]->calcHeurAndSet(15, 37, 18);
	nodes[j]->createConnection(nodes[g], 48);
	nodes[j]->createConnection(nodes[z], 82);

	nodes[k]->calcHeurAndSet(13, 24, 56);
	nodes[k]->createConnection(nodes[h], 32);
	nodes[k]->createConnection(nodes[z], 43);
	nodes[k]->createConnection(nodes[g], 42);

	nodes[z]->setHeur(0);
	nodes[z]->createConnection(nodes[i], 25);
	nodes[z]->createConnection(nodes[j], 82);
	nodes[z]->createConnection(nodes[k], 53);

}

void Graph::generateNewValues() {

	//for all nodes, generate new delays, buffer sizes, and connection delays

	enum nodesNames { a, b, c, d, e, f, g, h, i, j, k, z };

	for (auto& i : nodes) {
		i->genNewValues();
	}
	nodes[a]->setHeur(0);
	nodes[z]->setHeur(0);

}

