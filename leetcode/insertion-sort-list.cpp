/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(!head)
            return NULL;
        
        ListNode dummy1(-1);
        ListNode *p1(&dummy1),*pre1(&dummy1);
        ListNode dummy2(-1);
        dummy2.next=head;
        ListNode *pre(&dummy2);
        while (head){
            pre1=&dummy1;
            p1 = dummy1.next;
            
            while(true)
            {
                if (p1==NULL||p1->val>head->val){
                    pre->next=head->next;
                    head->next=p1;
                    pre1->next=head;
                    head=pre->next;
                    break;
                }
                
                pre1=p1;
                p1=p1->next;
            }
        }
        return dummy1.next;
    }
};