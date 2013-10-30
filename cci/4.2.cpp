/*
Given a directed graph, design an algorithm to find out whether there is a route be-
tween two nodes.
*/

#include <iostream>
#include "graph.h"

int has_route(Node* n1, Node* n2){
	if(n1==NULL) return 0;
	if(n2==NULL) return 0;
	if(n1==n2) return 0;//How to deal with this corner case?

	n1->component=1;
	if(n1->edges.size()==0) return 0;
	for(int edge_idx=0;edge_idx<n1->edges.size();edge_idx++){
		if(n1->edges[edge_idx]->id==n2->id) return 1;
		if(n1->edges[edge_idx]->component!=1){
			if(has_route(n1->edges[edge_idx],n2)) return 1;
		}
	}
	return 0;
	}


int main(){
	Graph* g=new Graph();
	
	//insert two nodes
	for(int i=0;i<2;i++){
		g->nodes.push_back(new Node(i));
		}
	
	g->nodes[0]->edges.push_back(g->nodes[1]);

	cout<<"Test result "<<has_route(g->nodes[0],g->nodes[1])<<endl;
}
