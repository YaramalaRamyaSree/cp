/*
leetcode link - https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/

//T.C=O(N) S.C=O(H) recursion stack space 
    void order(TreeNode* root,int maxi,int &count){
        if(!root) return ;
        if(root->val>=maxi){
            count++;
            maxi=root->val;
        }
        order(root->left,maxi,count);
        order(root->right,maxi,count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        order(root,root->val,count);
        return count;
    }
