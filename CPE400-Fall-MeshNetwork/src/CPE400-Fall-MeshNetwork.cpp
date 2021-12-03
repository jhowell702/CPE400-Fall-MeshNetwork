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


int main()
{
	//init for rand function using time as seed
	srand(time(NULL));

	//create the default graph
	Graph* default_graph = new Graph();

	//create unvisited, visited, and reset maps for A* usage
	map<int, GraphNode*>* unvisitedNodes = new map<int, GraphNode*>();
	map<int, GraphNode*>* visitedNodes = new map<int, GraphNode*>();
	map<int, GraphNode*>* reset = new map<int, GraphNode*>();

	//insert all nodes fromthe graph into the unvisited nodes map
	for (int i = 0; i < default_graph->getNumNodes(); i++) {

		unvisitedNodes->insert(pair<int, GraphNode*>(i, default_graph->getNodes()[i]));

	}

	//initialize the UI class using the maps and graph defined above
	UI* ui = new UI(unvisitedNodes, visitedNodes, reset, default_graph);

	//start the UI menu for command line interface
	ui->menu();

	return 0;
}
