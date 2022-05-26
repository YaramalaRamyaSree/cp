/*
leetcode link - https://leetcode.com/problems/add-two-numbers/
*/

//T.C=O(large linked list),S.C=O(n+m), given not to change linked list .
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* dummy=new ListNode();
        struct ListNode* temp=dummy;
        int sum,carry=0;
        while(l1!=NULL ||l2!=NULL ||carry!=0){
            sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next=node;
            temp=node;
        }
        return dummy->next;
    
    }
