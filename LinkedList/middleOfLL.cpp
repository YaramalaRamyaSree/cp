/*
Leetcode link - https://leetcode.com/problems/middle-of-the-linked-list/
*/
   
    //Brute force approach is in one iteration find number of elements in ll and second n/2 iteration return middle node .T.C=O(N)+O(N/2)

    // Optimised -with two pointers (slow and fast tortoise)
    //T.C=O(N/2),S.C=O(1)

    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

