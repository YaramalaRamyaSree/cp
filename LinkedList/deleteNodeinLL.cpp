    /*
    leetcode link - https://leetcode.com/problems/delete-node-in-a-linked-list/
    */
    
//T.C=O(1)
//we are just copying next node val and deleting it , because we do not have prev pointer access as it is singly linked list and also we are not given head of LL
    void deleteNode(ListNode* node) {
        //copy the next nodes value to present node and change next address of given node 
        node->val=node->next->val;
        node->next=node->next->next;
    }
