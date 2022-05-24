/*
leetcode link - https://leetcode.com/problems/reverse-linked-list/
*/

// with just pointers 
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead=NULL;
        while(head!=NULL){
            ListNode* next=head->next;
            head->next=newhead;
            newhead=head;
            head=next;
        }
        return newhead;
    }

//with recursion
    ListNode* newhead=NULL;

    void reverse(ListNode* p){
      
        if(p==NULL) return ;
      
        if(p->next==NULL){
            newhead=p;
            return;
        }
      
        reverse(p->next);
      
        p->next->next=p;
      
        p->next=NULL;
    }

    ListNode* reverseList(ListNode* head) {
      reverse(head);
      return newhead;
    }
