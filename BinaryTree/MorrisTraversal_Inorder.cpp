/*
leetcode link - https://leetcode.com/problems/binary-tree-inorder-traversal/
*/
    //T.C=O(N)+O(N)=O(N),S.C=O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr=root;
        while(curr!=NULL){
                if(curr->left==NULL){
                        inorder.push_back(curr->val);
                        curr=curr->right;
                }
                else{
                        TreeNode* prev=curr->left;
                        while(prev->right&&prev->right!=curr){
                            prev=prev->right; 
                        }
                        if(prev->right==NULL){
                            prev->right=curr;
                            curr=curr->left;
                        }
                        else{
                            prev->right=NULL;
                            inorder.push_back(curr->val);
                            curr=curr->right;
                        }
                }
        }
        return inorder;
    }
