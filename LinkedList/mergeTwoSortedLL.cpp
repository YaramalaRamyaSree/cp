/*
leetcode link - https://leetcode.com/problems/merge-two-sorted-lists/
*/

    //In-place merged with T.C=O(N+M)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        //Always making list1 to be smaller 
        if(list1->val>list2->val) swap(list1,list2);
        ListNode* head=list1;
        while(list1!=NULL && list2!=NULL){
            ListNode* temp=NULL;
            while(list1!=NULL && list1->val<=list2->val){
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            swap(list1,list2);
        }
        return head;
    }

    // with recursion
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
      {
        if(l1 == NULL)   {	return l2;	}

        if(l2 == NULL) {   return l1;   } 

        if(l1 -> val <= l2 -> val){
          l1 -> next = mergeTwoLists(l1 -> next, l2);
          return l1;
        }
        else {
          l2 -> next = mergeTwoLists(l1, l2 -> next);
          return l2;            
        }
      }
