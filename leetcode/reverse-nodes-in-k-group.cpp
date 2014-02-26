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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k<=1||head==NULL||head->next==NULL) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        //use dummy node
        ListNode *cur = head;
        while (cur) {
            int counter = k;
            while (cur!=NULL&&counter>1){
                cur=cur->next;
                counter--;
            }
            
            if (cur!=NULL) {//we got a complete group
                cur = pre->next;//cur has not changed all the  time. it always points to the tail node of reversed group linked list.
                counter=k;
                while (counter>1) {
                    ListNode *next = cur->next;
                    cur->next = next->next;
                    next->next = pre->next;
                    pre->next = next;
                    counter--;
                }
                pre = cur;
                cur = pre->next;
            }
        }
        return dummy.next;
    }
};