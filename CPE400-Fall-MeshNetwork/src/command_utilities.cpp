#include "command_utilities.h"
#include "graph_node.h"
#include "graph.h"
#include "graph_connection.h"
#include <iostream>

using namespace std;

enum nodesNames { a, b, c, d, e, f, g, h, i, j, k, z };

UI::UI(map<int, GraphNode*> * in, map<int, GraphNode*>* in2, map<int, GraphNode*>* inReset, Graph* in3) {

	visitedNodes = in2;
	unvisitedNodes = in;
	graph = in3;
	reset_unvisitedNodes = inReset;


}


void UI::menu() {

	bool running = true;
	int state = -1;

	while (running) {
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "|Menu:                                                                       |" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "|Display current graph:         | 1                                          |" << endl;
		cout << "|Generate new graph:            | 2                                          |" << endl;
		cout << "|Display full data for nodes:   | 3                                          |" << endl;
		cout << "|Step-by-step A*:               | 4                                          |" << endl;
		cout << "|Find A* path of current graph: | 5                                          |" << endl;
		cout << "|Exit:                          | 0                                          |" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "|Enter 0-5 to run command: ";
		cin >> state;

		switch (state) {
			case 1:
				currNode = (*graph).getNodes()[a];
				currNode->setShort(0);
				currNode->setTotal(currNode->getHeur());
				currNode->setCurrent(true);
				outputGraph();
				break;

			case 2:
				currNode = (*graph).getNodes()[a];
				currNode->setShort(0);
				currNode->setTotal(currNode->getHeur());
				currNode->setCurrent(true);
				(*graph).generateNewValues();
				outputGraph();
				outputFullData();
				break;

			case 3:
				outputFullData();
				break;

			case 4:
				aStar_Slow();
				break;

			case 5:
				aStar_Fast();
				break;

			case 0:
				cout << endl << "Exiting program." << endl;
				return;

			default:
				cout << endl << "Unrecognized input." << endl;
				break;
		}
	}

}

void UI::outputGraph() {
	cout << endl << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Current Graph" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	
	cout << "                  /--"; outputConnection(a, b); cout << "--";	outputNode(b);
	cout << "---"; outputConnection(b, e); cout << "---";	outputNode(e);
	cout << "---"; outputConnection(e, i); cout << "---";	outputNode(i);
	cout << "---"; outputConnection(i, z); cout << "---\\";

	// diagnol connectors

	cout << endl;	cout << "                 /             \\                /                  \\";

	cout << endl;
	cout << "                /";
	cout << "               "; outputConnection(b, f);
	cout << "              "; outputConnection(g, i);
	cout << "                  \\";

	cout << endl;	cout << "               /                 \\            /                      \\";

	/// Middle nodes

	cout << endl;	cout << "Start Node:";	outputNode(a);
	cout << "--"; outputConnection(a, c); cout << "--";	outputNode(c);
	cout << "--"; outputConnection(c, f); cout << "--";	outputNode(f);
	cout << "--"; outputConnection(f, g); cout << "--";	outputNode(g);
	cout << "--"; outputConnection(g, j); cout << "--";	outputNode(j);
	cout << "--"; outputConnection(j, z); cout << "--";	outputNode(z);

	// second set of diagnol connectors
	 
	cout << endl;	cout << "               \\                 /            \\                   /";
	cout << endl;
	cout << "                \\";
	cout << "               "; outputConnection(d, f);
	cout << "              "; outputConnection(g, k);
	cout << "               /";
	cout << endl;	cout << "                 \\             /                \\               /";

	cout << endl;
	cout << "                  \\--"; outputConnection(a, d); cout << "--";	outputNode(d);
	cout << "--"; outputConnection(d, h); cout << "--";						outputNode(h);
	cout << "--"; outputConnection(h, k); cout << "--";						outputNode(k);
	cout << "----"; outputConnection(k, z); cout << "-----/";
	cout << endl;

}

void UI::outputNode(int num) {
	if (currNode->getID() == num) {
		cout << "\033[30;47m";
	}
		cout << "|" << (char)(65 + graph->getNodes()[num]->getID()) << ":" << graph->getNodes()[num]->getHeur() << "|";
		cout << "\033[0m";

}

void UI::outputConnection(int node, int num) {
	cout << graph->getNodes()[node]->findConnection(num)->getDelay();
}

void UI::outputFinal(GraphNode* prev) {

	if (prev->getID() == z) {
		outputFinal(prev->getPrev());
		cout << (char)(prev->getID() + 65);

	}else if (prev->getID() != a) {
		outputFinal(prev->getPrev());
		cout << (char)(prev->getID() + 65) << "->";
	}
	else  {
		cout << (char)(prev->getID() + 65) << "->";
		return;
	}
}

void UI::outputNodeData() {

	map<int, GraphNode*>::iterator it;

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Heuristic Node Data" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Unvisited Nodes" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	if ((*unvisitedNodes).size() != 0) {
		for (it = (*unvisitedNodes).begin(); it != (*unvisitedNodes).end(); it++) {
			if (it->second != NULL) {
				cout << "| Node: " << (char)(it->second->getID() + 65) << " | Shortest Distance From A: " << it->second->getShort() << " | Heuristic: ";
				cout << it->second->getHeur() << " | Total Distance: " << it->second->getTotal() << endl;
			}
		}
	}
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Visited Nodes" << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	if ((*visitedNodes).size() != 0) {
		for (it = (*visitedNodes).begin(); it != (*visitedNodes).end(); it++) {
			if (currNode->getID() == it->second->getID()) {
				cout << "\033[30;47m";
			}
			cout << "| Node: " << (char)(it->second->getID() + 65) << " |\033[0m Shortest Distance From A: " << it->second->getShort() << " | Heuristic: " << it->second->getHeur();
			cout << " | Total Distance: " << it->second->getTotal()  << endl;
		}
	}

	cout << "------------------------------------------------------------------------------" << endl;

}

void UI::outputFullData() {

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|Full Data                                                                    |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	for (auto& i : (*graph).getNodes()) {
		cout << "|" << (char)((*i).getID() + 65) << " |Processing Delay: " << (*i).getProcDelay() << " |Transmission Delay: " << (*i).getTransDelay() 
						<< "|Buffer Size: " << (*i).getBuffer() << " |Heuristic: " << (*i).getHeur() << "|" << endl;
	}

}

void UI::aStar_Slow() {
	visitedNodes->clear();
	(*reset_unvisitedNodes).clear();
	(*reset_unvisitedNodes) = (*unvisitedNodes);

	currNode = (*unvisitedNodes)[a];
	currNode->setShort(0);
	currNode->setTotal(currNode->getHeur());
	currNode->setCurrent(true);

	GraphNode* pastNode = currNode;

	int slowState = 1;

	while (slowState != 0) {


		cout << "Input and enter: 1 to continue, 0 to return to main menu" << endl << "Input: ";
		cin >> slowState;

		if (currNode->getID() == z) {
			slowState = 0;
		}



		if (slowState == 1) {
			//pastNode = currNode;
			//if the currNode exists
			if (currNode != NULL) {

				//get all current connections
				std::vector<GraphConnection*> currConns = currNode->getConnections();

				for (int i = 0; i < currConns.size(); i++) { //for all connections

					//if curr connection has a destination node
					if (currConns[i]->getEnd() != NULL) {

						//get the propagation delay of current connection
						int delay = currConns[i]->getDelay() + (.25 * currConns[i]->getEnd()->getHeur());

						//calculate shortest distance using this connection to compare
						int testShort = currNode->getShort() + delay;

						//if the new shortest distance is less than the current shortest distance of destination node
						if (testShort < currConns[i]->getEnd()->getShort()) {
							//set shortest distance from start to be connection delay + currNode's shortest distance from starting node
							currConns[i]->getEnd()->setShort(testShort);

							//sum a total using current shortest path to start node, length of connection, and heuristic
							currConns[i]->getEnd()->setTotal(testShort + currConns[i]->getEnd()->getHeur());

							//set previous node to be currNode
							currConns[i]->getEnd()->setPrev(currNode);

							if ((*unvisitedNodes)[currConns[i]->getEnd()->getID()] == NULL) {
								(*unvisitedNodes)[currConns[i]->getEnd()->getID()] = (*visitedNodes)[currConns[i]->getEnd()->getID()];
								(*visitedNodes).erase(currConns[i]->getEnd()->getID());
							}
						}

						//if the new shortest distance is greater than, ignore this connection
						else {

						}
					}

					//no destination node for current connection, output error
					else {
						cout << "------------------------------------------------------------------------------" << endl;
						cout << "|No destination node for current connection";
						cout << "------------------------------------------------------------------------------" << endl;
						return;
					}

				}

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
				outputGraph();
				outputNodeData();

				//mark current node as been visited
				(*visitedNodes).insert(pair<int, GraphNode*>(currNode->getID(), currNode));
				(*unvisitedNodes)[currNode->getID()] = NULL;

				currNode = smallest;
			}
			//if the currNode does not exists
			else {
				cout << "------------------------------------------------------------------------------" << endl;
				cout << "|Current node does not exist";
				cout << "------------------------------------------------------------------------------" << endl;
				return;
			}
	}
}
	if(slowState != 0){
		(*visitedNodes).insert(pair<int, GraphNode*>(currNode->getID(), currNode));
		(*unvisitedNodes)[currNode->getID()] = NULL; //remove the currNode from unvisited nodes
		outputGraph();
		outputNodeData();

		cout << "Final A* Path: "; outputFinal(graph->getNodes()[z]); cout << endl;
		cout << "------------------------------------------------------------------------------" << endl;
	}
	else {
		(*unvisitedNodes) = (*reset_unvisitedNodes);
		return;
	}
}

void UI::aStar_Fast() {
	visitedNodes->clear();
	(*reset_unvisitedNodes).clear();
	(*reset_unvisitedNodes) = (*unvisitedNodes);
	// set short and total for starting node

	currNode = (*unvisitedNodes)[a];
	currNode->setShort(0);
	currNode->setTotal(currNode->getHeur());
	currNode->setCurrent(true);

	//while the currNode is not the final node
	while (currNode->getID() != z) { 

		if (currNode != NULL) {

			//get all current connections
			std::vector<GraphConnection*> currConns = currNode->getConnections();

			for (int i = 0; i < currConns.size(); i++) { //for all connections

				//if curr connection has a destination node
				if (currConns[i]->getEnd() != NULL) {

					//get the propagation delay of current connection
					int delay = currConns[i]->getDelay() + (1.1 * currConns[i]->getEnd()->getHeur());

					//calculate shortest distance using this connection to compare
					int testShort = currNode->getShort() + delay;

					//if the new shortest distance is less than the current shortest distance of destination node
					if (testShort <= currConns[i]->getEnd()->getShort()) {
						//set shortest distance from start to be connection delay + currNode's shortest distance from starting node
						currConns[i]->getEnd()->setShort(testShort);

						//sum a total using current shortest path to start node, length of connection, and heuristic
						currConns[i]->getEnd()->setTotal(testShort + currConns[i]->getEnd()->getHeur());

						//set previous node to be currNode
						currConns[i]->getEnd()->setPrev(currNode);

						if ((*unvisitedNodes)[currConns[i]->getEnd()->getID()] == NULL) {
							(*unvisitedNodes)[currConns[i]->getEnd()->getID()] = (*visitedNodes)[currConns[i]->getEnd()->getID()];
							(*visitedNodes).erase(currConns[i]->getEnd()->getID());
						}
					}

					//if the new shortest distance is greater than, ignore this connection
					else {
						
					}
				}

				//no destination node for current connection, output error
				else {
					cout << "------------------------------------------------------------------------------" << endl;
					cout << "|No destination node for current connection " << i << " of node " << currNode->getID();
					cout << "------------------------------------------------------------------------------" << endl;
					return;
				}

			}

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
			outputGraph();
			outputNodeData();

			//mark current node as been visited
			(*visitedNodes).insert(pair<int, GraphNode*>(currNode->getID(), currNode));
			(*unvisitedNodes)[currNode->getID()] = NULL;

			currNode = smallest;
		}
		//if the currNode does not exists
		else {
			cout << "------------------------------------------------------------------------------" << endl;
			cout << "|Current node does not exist";
			cout << "------------------------------------------------------------------------------" << endl;
			return;
		}
	}

	(*visitedNodes).insert(pair<int, GraphNode*>(currNode->getID(), currNode));
	(*unvisitedNodes)[currNode->getID()] = NULL; //remove the currNode from unvisited nodes
	outputGraph();
	outputNodeData();

	cout << "Final A* Path: "; outputFinal(graph->getNodes()[z]); cout << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	(*unvisitedNodes) = (*reset_unvisitedNodes);

}