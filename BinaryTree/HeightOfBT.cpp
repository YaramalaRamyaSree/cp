/*
gfg link - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/0
*/

//T.C=O(N) S.C=O(N)
    int height(struct Node* node){
       if(!node) return 0;
       int lh=height(node->left);
       int rh=height(node->right);
       return 1+max(lh,rh);
    }
