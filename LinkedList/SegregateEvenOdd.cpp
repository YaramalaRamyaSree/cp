/*
gfg link - https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
*/

    Node* divide(int N, Node *head){
        Node* i=new Node(0);
        Node* j=new Node(0);
        Node *evenhead=i;
        Node *oddhead=j;
        while(head!=NULL){
            if(head->data%2==0){
                i->next=head;
                i=i->next;
            }
            else {
                j->next=head;
                j=j->next;
            }
            head=head->next;
        }
        j->next=NULL;
        i->next=oddhead->next;
        return evenhead->next;
    }
