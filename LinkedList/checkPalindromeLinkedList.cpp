/*
leetcode link - https://leetcode.com/problems/palindrome-linked-list/
*/

    ListNode*reverse(ListNode *head){
        ListNode*newhead=NULL;
        while(head!=NULL){
            ListNode*nex=head->next;
            head->next=newhead;
            newhead=head;
            head=nex;
        }
        return newhead;
    }
    //T.C=O(N/2)+O(N/2)+O(N/2)=find middle+reverse(middle,end)+check values
    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next==NULL) return true;
        ListNode*slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            else
            {
                head=head->next;
                slow=slow->next;
            }
        }
        return true;
    }
