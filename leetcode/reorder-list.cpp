void listReorder(ListNode *head){
	if (!head) return;
    
	//get the mid node first
	ListNode *slow(head), *fast(head);
	while (fast&&fast->next) {
		slow=slow->next;
		fast=fast->next->next;
	}
    
	//slow belongs to the first half;
	ListNode *secHead = slow->next;
    
	//reverse the second half;
	slow->next =NULL;
	ListNode *pre = NULL;
	if (secHead) {
		ListNode *p=secHead;
		while (p){
			ListNode *temp =p->next;
			p->next=pre;
			pre = p;
			p = temp;
		}
		secHead = pre;
	}else return;
    
	//interleave the first and second half
	while (secHead){
		ListNode *p=secHead;
		secHead=secHead->next;
		p->next=head->next;
		head->next=p;
		head=p->next;
	}
	return;
}