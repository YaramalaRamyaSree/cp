/*
leetcode link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

//T.C=O(2N)
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
     
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
     
        if(count-n==0){
            ListNode* temp1=head;
            head=head->next;
            delete(temp1);
            return head;  
        }
        temp=head;
        int k=1;
        while(k!=count-n){
            temp=temp->next;
            k++;
        }
        ListNode* temp1=temp->next;
        temp->next=temp1->next;
        delete(temp1);
        return head;
        
    }

//OPTIMISED - O(N)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=new ListNode();temp->next=head;
        ListNode *slow=temp,*fast=temp;
        //Move fast pointers n hops
        for(int i=1;i<=n;++i){
            fast=fast->next;
        }
        //Move both slow and fast one step in each time till end of list
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
    }
        slow->next=slow->next->next;
        return temp->next;
    }
