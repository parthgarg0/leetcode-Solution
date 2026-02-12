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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=fast;
        int temp=0;

        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) {
                temp=1;
                slow=head;
                break;
            }
        }
        if (temp){
            while(slow!=fast){
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }
            return slow;
        }
        //prev->next=NULL;
        return NULL;
    }
};