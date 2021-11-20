// CPE400-Fall-MeshNetwork.cpp : Defines the entry point for the application.
//

#include "CPE400-Fall-MeshNetwork.h"
#include "graph.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	Graph* test = new Graph();

	test->outputDelays();
	return 0;
}
