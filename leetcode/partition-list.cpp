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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(0);//dummy head;
        dummy.next = head;
        ListNode *pre(&dummy),*end(&dummy);
        while(head)
        {
            if (head->val<x)
            {
                if (pre!=end)
                {
                    //append head to end
                    pre->next=head->next;//take out the node
                    head->next = end->next;//insert. First back
                    end->next = head;//then front
                }
                end=end->next;
            }
            pre=head;
            head=head->next;
        }
        return dummy.next;
    }
};