/*
leetcode link - https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

//T.C=O(N)+O(N/K)*K
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode();
        ListNode*pre=dummy,*curr=dummy,*nex=dummy;
        dummy->next=head;
        int count=0;
        //find total count of nodes
        while(head!=NULL){
            count++;
            head=head->next;
        }
        //reverse untill nodes are multiples of k
        while(count>=k){
            curr=pre->next;
            nex=curr->next;
            //every time in a segment k reverse k-1 nodes 
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            count-=k;
        }
        return dummy->next;
    }
