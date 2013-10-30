#include <iostream>
#include "LLNode.h"

void del_node(LLNode *n){
	if(n==NULL||n->next==NULL)
		return;

	LLNode *next=n->next;

	n->val=next->val;
	n->next=next->next;
}

/*
	Note that by linked list is identified by its value;
	Do not contrain yourself to the assumption that a node with the same value but different pointer (memory addr.) are not the same.
*/
