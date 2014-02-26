#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node {
  public:
    int id;
    vector <Node*> edges;
    int component;
    
    Node(int nodeid){
    		id=nodeid;
    		component=0;
    		edges.clear();
    	}
    		
};

class Graph {
  public:
    vector <Node *> nodes;
   // void Print();
};


/*
void Graph::Print()
{
  int i, j;
  Node *n;

  for (i = 0; i < nodes.size(); i++) {
    n = nodes[i];
    cout << "Node " << i << ": " << n->component << ":";
    for (j = 0; j < n->edges.size(); j++) {
      //cout << " " << n->edges[j]->id;
    }
    cout << endl;
  }
}
*/

