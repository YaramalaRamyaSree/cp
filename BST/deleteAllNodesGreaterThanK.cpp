/*
gfg link - https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1
*/

  //T.C=O(N) S.C=O(N)-auxilary
    Node* deleteNode(Node* root, int k)
    {
        if(!root) return NULL;
        if(root->data>=k)
           return deleteNode(root->left,k); //writing return here is v.v.v important other wise doing recursion will go in vain as it doesnot return crt value.
        else
            root->right=deleteNode(root->right,k);
        return root;
    }
