/*
leetcode link - https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

    //T.C=O(2M),S.C=O(1) 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode* dummy1=headA,*dummy2=headB;
        
        //if a and b LL are different length we do two iterations before return 
        
        //else a==b length then one iteration is enough to return intersection-beast case T.C=O(M)
       
        while(dummy1!=dummy2){
           
            // when any of dummy1 or dummy2 reaches null we eassign it to other linked list head 
            dummy1=(dummy1==NULL?headB:dummy1->next);
            dummy2=(dummy2==NULL?headA:dummy2->next);
        
        }
        return dummy1;
    }

    //Another approch of O(2M) is 
    //O(M)+O(M-N)+O(N)
    //=count lengths of two ll and find difference + 
    //move the greater ll pointer by m-n steps + 
    //now move l1,l2 pointers simultaneously and return when they both pointers reach same address.
