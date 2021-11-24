// CPE400-Fall-MeshNetwork.cpp : Defines the entry point for the application.
//

#include "CPE400-Fall-MeshNetwork.h"
#include "graph.h"
#include "graph_connection.h"
#include "graph_node.h"
#include "command_utilities.h"

#include <cstdlib>
#include <time.h>
#include <vector>
#include <map>

using namespace std;

	enum nodesNames { a, b, c, d, e, f, z };

void astar(Graph* graph) {

	map<int, GraphNode*> unvisitedNodes;
	for (int i = 0; i < graph->getNumNodes(); i++) {

		unvisitedNodes.insert(pair<int, GraphNode*>(i,graph->getNodes()[i]));

	}

	// set short and total for starting node
	GraphNode* currNode = unvisitedNodes[a];
	currNode->setShort(0);
	currNode->setTotal(currNode->getHeur());

	while (currNode->getID() != z) { //while the currNode is not the final node

		cout << "curr node is:" << currNode->getID() << endl;

		std::vector<GraphConnection*> currConns = currNode->getConnections();

		//update shortest distance from a, and total distance for all connections
		for (int i = 0; i < currConns.size(); i++) { //for all connections
			if (unvisitedNodes[currConns[i]->getEnd()->getID()] != NULL) { //if the end node is not visited

				int connNodeID = currConns[i]->getEnd()->getID(); //the end node of the current connection

				float delay = currConns[i]->getDelay();			  //get the propagation delay of current connection

				float testTotal = currNode->getShort() + delay + currConns[i]->getEnd()->getHeur();

				//set shortest distance from start to be connection delay + currNode's shortest distance from starting node
				unvisitedNodes[connNodeID]->setShort(delay + currNode->getShort());
				
				
				if (testTotal < unvisitedNodes[connNodeID]->getTotal() ){
					//set total distance from start to be connection delay + heuristic distance 
					unvisitedNodes[connNodeID]->setTotal(testTotal);
				}
				//set previous node to be currNode
				unvisitedNodes[connNodeID]->setPrev(currNode);
			}

		}

		unvisitedNodes[currNode->getID()] = NULL; //remove the currNode from unvisited nodes

		//find node in unvisited with smallest 
		GraphNode* smallest = NULL;
		map<int, GraphNode*>::iterator itr;
		for (itr = unvisitedNodes.begin(); itr != unvisitedNodes.end(); ++itr) {
			if (itr->second != NULL) { //if the end node is not visited
				if (smallest == NULL || itr->second->getTotal() < smallest->getTotal()) {
					smallest = itr->second;
				}
			}
		}

		currNode = smallest;
		cout << "new curr node is:"  << currNode->getID() << " total distance from a is:" << currNode->getTotal() << endl;
	}


}

int main()
{
	srand(time(NULL));
	Graph* test = new Graph();

	map<int, GraphNode*>* unvisitedNodes = new map<int, GraphNode*>();
	map<int, GraphNode*>* visitedNodes = new map<int, GraphNode*>();

	for (int i = 0; i < test->getNumNodes(); i++) {

		unvisitedNodes->insert(pair<int, GraphNode*>(i, test->getNodes()[i]));

	}



	UI* ui = new UI(unvisitedNodes, visitedNodes);

	ui->aStar_Fast();

	ui->outputGraph(test);


	return 0;
}
