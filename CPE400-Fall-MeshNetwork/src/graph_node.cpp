#include "graph_node.h"
#include <cstdlib>
#include <iostream>


using namespace std;

GraphNode::GraphNode() {


	procDelay = rand() % 100;
	procDelay *= .01;

}

void GraphNode::outPutNodalDelays() {

	cout << procDelay << endl;


}
