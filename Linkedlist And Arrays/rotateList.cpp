/*
leetcode link - https://leetcode.com/problems/rotate-list/
*/
    //T.C=O(N)
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next) return head;
        int count =0;
        ListNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        count++;
        k=k%count;
        temp->next=head;
        k=count-k;
        while(k--) temp=temp->next;
        head=temp->next;
        temp->next=NULL;
        return head;
        
    }

    //Approach-2 T.C=O(N)
    // you may also use fast and slow pointers and find where to cut the link and attach at front of linkedlist .
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next) return head;
        int count =0;
        ListNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        count++;
        k=k%count;
        if(k==0) return head;
        ListNode *slow=head,*fast=head;
        for(int i=1;i<=k;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        fast=slow->next;
        temp->next=head;
        head=fast;
        slow->next=NULL;
        return head;
        
    }
