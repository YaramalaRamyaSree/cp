/*
leetcode link - https://leetcode.com/problems/copy-list-with-random-pointer/
*/

    //T.C=O(N)+O(N)+O(N)=O(N),S.C=O(1)
    Node* copyRandomList(Node* head) {
        if(!head){
            Node*copy=NULL;return copy;
        }
       Node *iter=head,*front;
        //creating deep copy nodes 
        while(iter!=NULL){
            front=iter->next;
            Node* copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter=head;
        //marking deep copy nodes random pointer correctly
        while(iter!=NULL){
            if(iter->random!=NULL)
                iter->next->random=iter->random->next;
            iter=iter->next->next;
        }
        Node* dummy=new Node(0);
        Node*temp=dummy;
        iter=head;
        //making deep copy and original linked list next pointer correctly
        while(iter!=NULL){
            front=iter->next->next;
            temp->next=iter->next;
            temp=temp->next;
            iter->next=front;
            iter=front;
        }
        return dummy->next;
    }
