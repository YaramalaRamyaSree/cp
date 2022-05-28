/*
leetcode link - https://leetcode.com/problems/linked-list-cycle-ii/
*/

    //T.C=O(N),s.c=O(1)
    
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode*slow=head,*fast=head;
        // First we detect is cycle exit i.e fast==slow ,then we move fast to head and move fast and slow simultaneously one step the point they collide is where cycle begins
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow!=head){
                    slow=slow->next;
                    head=head->next;
                }
                return slow;
            }
        }
        return NULL;
    }
