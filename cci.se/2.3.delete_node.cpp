#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

bool delete_node(LLNode *p) {
	if (p==NULL||p->next==NULL)//not gonna work if p is NULL or the tail of the node.
		return false;

	p->val = p->next->val;
	p->next = p->next->next;
	return true;
}