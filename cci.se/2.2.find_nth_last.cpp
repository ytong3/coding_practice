#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

LLNode *find_nth_to_last(LLNode *head, int n){
	if (!head||n<1) return NULL;

	LLNode *front(head), *back(head);

	for(int i=0;back&&i<n;i++)
		back=back->next;
	
	if(!back) return NULL;
	
	while (back){
		front=front->next;
		back=back->next;
	}

	return front;
}

int find_nth_last_recur(LLNode *head, int n, LLNode *&ans) {
	if (!head) return 0;

	if (ans==NULL){
		int cnt=1+find_nth_last_recur(head->next,n,ans);
		if (cnt==n){
			ans = head;
			cout<<"ans set"<<endl;
		}
		return cnt;
	}
	return -1;
}

int main() {
	LLNode node(1);
	LLNode *p(&node);

	for (int i=0;i<10;i++) {
		p->next = new LLNode (i+2);
		p=p->next;
	}

	node.traverse_from();

	p=find_nth_to_last(&node, 5);
	cout<<p->val<<endl;

	p=NULL;
	find_nth_last_recur(&node, 1, p);
	cout<<p->val<<endl;
}