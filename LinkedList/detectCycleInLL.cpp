/*
leetcode link - https://leetcode.com/problems/linked-list-cycle/
*/

    //definetely fast pointer will catch up slow is intution T.C=O(N),S.C=O(1)
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode*slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
    
    /*Another approch  2 in datastructure of Node add flag also every time u traverse make flag 1 and 
      traverse when ever u see alredy node's flag as 1 return true else false
      */

//Approch 3 -without changing datastructure of Node also we can make use  flag concept how??
// by pointing traversed nodes to some temp value ,when ever u see a node pointing to temp we return true 
    bool detectLoop(Node* head)
    {
        Node* point=new Node(-1);
        Node* temp=head;
        if(!head || !head->next)
            return false;
        while(temp){
            if(temp->next==point) return true;
            Node* temp2 =temp->next;
            temp->next=point;
            temp=temp2;
        }
        return false;
    }
