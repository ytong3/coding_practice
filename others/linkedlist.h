#include <cstdio>
using namespace std;
struct LLNode{
	int val;
	LLNode* next;
	LLNode(int x): val(x), next(NULL){}
	
	void traverse_from(){
		LLNode *p=this;
		while (p){
			printf("%d->",p->val);
			p=p->next;
		}
		printf("\n");
	}
};

typedef LLNode ListNode;
