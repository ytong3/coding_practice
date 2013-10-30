/*
Given a directed graph, design an algorithm to find out whether there is a route be-
tween two nodes.
*/

#include "graph.h"
#include <iostream>

int has_route_bfs(Node* n1, Node* n2){
	if(n1==NULL) return 0;
	if(n2==NULL) return 0;
	if(n1==n2) return 0;

	vector<Node*> queue;//used as the queue in the BFS.
	queue.clear();

	n1->component=1;//assuming the nodes have been initialized such that all of them are marked as unvisited
	queue.push_back(n1);
	while(queue.size()){
		//get the first element and then deque
		Node* qhead=queue[0];
		queue.erase(queue.begin());
		
		//if(tmp_node==n2) return 1;
		if(qhead->edges.size()>0){
			for(int node_idx=0;node_idx<qhead->edges.size();node_idx++){
				Node* tmp_node=qhead->edges[node_idx];
				if(tmp_node->component==0){
					if(tmp_node==n2) return 1;
					else queue.push_back(tmp_node);
				}
			}
		}
		qhead->component=1;
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

	cout<<"Test result "<<has_route_bfs(g->nodes[0],g->nodes[1])<<endl;
}
