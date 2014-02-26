#include <iostream>
#include <string>
#include "linkedlis.h"
#include <unordered_set>
using namespace std;

LLNode* find_beginning_of_loop(LLNode *head) {
	if (!head) return NULL;
	
	LLNode *p1;
	LLNode *p2;
	//finding the meeting point;
	while (p2!=NULL&p1!=NULL) {
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
			break;
	}

	if (p2==NULL||p1==NULL) return NULL//there is not cycle in this linked list.

	//move p1 to the head of the list. Keep n2 at the meeting point. Each are k steps away from the loop start. If they move at the same pace, they must meet at the loop start;
	n1 = head;
	while (p1!=p2) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p2;
}

int main() {
	//testing omitted
}
	

	