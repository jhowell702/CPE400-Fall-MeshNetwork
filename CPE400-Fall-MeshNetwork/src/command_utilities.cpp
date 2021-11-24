#include "command_utilities.h"
#include "graph_node.h"
#include "graph.h"
#include "graph_connection.h"
#include <iostream>

using namespace std;

enum nodesNames { a, b, c, d, e, f, g, h, i, j, k, z };

UI::UI(map<int, GraphNode*> * in, map<int, GraphNode*>* in2) {

	visitedNodes = in2;
	unvisitedNodes = in;

}

void UI::outputGraph(Graph* graph) {
;
	
	cout << "                  /--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, b);
	cout << "---"; outputConnection(graph, a, c); cout << "---";	outputNode(graph, e);
	cout << "---"; outputConnection(graph, a, c); cout << "---";	outputNode(graph, i);
	cout << "---"; outputConnection(graph, a, c); cout << "---\\";

	// diagnol connectors

	cout << endl;	cout << "                 /             \\                /             \\";

	cout << endl;
	cout << "                "; outputConnection(graph, a, b);
	cout << "               "; outputConnection(graph, a, b);
	cout << "              "; outputConnection(graph, a, c);
	cout << "               "; outputConnection(graph, a, c);

	cout << endl;	cout << "               /                 \\            /                 \\";

	/// Middle nodes

	cout << endl;	cout << "Start Node:";	outputNode(graph, a);
	cout << "--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, c);
	cout << "--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, f);
	cout << "--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, g);
	cout << "--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, j);
	cout << "--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, z);

	// second set of diagnol connectors

	cout << endl;	cout << "               \\                 /            \\                /";
	cout << endl;
	cout << "                ";outputConnection(graph, a, b);
	cout << "               "; outputConnection(graph, a, b);
	cout << "              "; outputConnection(graph, a, b);
	cout << "              "; outputConnection(graph, a, b);
	cout << endl;	cout << "                 \\             /                \\            /";

	cout << endl;
	cout << "                  \\--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, b);
	cout << "--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, e);
	cout << "--"; outputConnection(graph, a, c); cout << "--";	outputNode(graph, i);
	cout << "----"; outputConnection(graph, a, c); cout << "-----/";

}

void UI::outputNode(Graph* graph, int num) {
	cout << "\033[30;47m";
	cout << "|" << (char)(65 + graph->getNodes()[num]->getID()) << ":" << graph->getNodes()[num]->getHeur() << "|";
	cout << "\033[0m";
}

void UI::outputConnection(Graph* graph, int node, int num) {
	cout << graph->getNodes()[node]->findConnection(num)->getDelay();
}

void UI::outputNodes() {

	map<int, GraphNode*>::iterator it;
	if ((*visitedNodes).size() != 0) {
		for (it = (*visitedNodes).begin(); it != (*visitedNodes).end(); it++) {
			cout << "|Node: " << it->second->getID() << "|" << it->second->getHeur() << endl;
		}
	}
	cout << "-------------------" << endl;
}

void UI::aStar_Slow() {

}

void UI::aStar_Fast() {
	// set short and total for starting node

	currNode = (*unvisitedNodes)[a];
	currNode->setShort(0);
	currNode->setTotal(currNode->getHeur());

	while (currNode->getID() != z) { //while the currNode is not the final node

		outputNodes();

		std::vector<GraphConnection*> currConns = currNode->getConnections();

		//update shortest distance from a, and total distance for all connections
		for (int i = 0; i < currConns.size(); i++) { //for all connections
			if ((*unvisitedNodes)[currConns[i]->getEnd()->getID()] != NULL) { //if the end node is not visited

				int connNodeID = currConns[i]->getEnd()->getID(); //the end node of the current connection

				float delay = currConns[i]->getDelay();			  //get the propagation delay of current connection

				float testTotal = currNode->getShort() + delay + currConns[i]->getEnd()->getHeur();

				//set shortest distance from start to be connection delay + currNode's shortest distance from starting node
				(*unvisitedNodes)[connNodeID]->setShort(delay + currNode->getShort());


				if (testTotal < (*unvisitedNodes)[connNodeID]->getTotal()) {
					//set total distance from start to be connection delay + heuristic distance 
					(*unvisitedNodes)[connNodeID]->setTotal(testTotal);
				}
				//set previous node to be currNode
				(*unvisitedNodes)[connNodeID]->setPrev(currNode);
			}

		}

		(*visitedNodes).insert(pair<int, GraphNode*>(currNode->getID(), currNode));
		(*unvisitedNodes)[currNode->getID()] = NULL; //remove the currNode from unvisited nodes


		//find node in unvisited with smallest 
		GraphNode* smallest = NULL;
		map<int, GraphNode*>::iterator itr;
		for (itr = (*unvisitedNodes).begin(); itr != (*unvisitedNodes).end(); ++itr) {
			if (itr->second != NULL) { //if the end node is not visited
				if (smallest == NULL || itr->second->getTotal() < smallest->getTotal()) {
					smallest = itr->second;
				}
			}
		}

		currNode = smallest;
	}
}