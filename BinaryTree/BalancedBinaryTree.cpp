/*
leetcode link - https://leetcode.com/problems/balanced-binary-tree/
*/

  //T.C=O(N),S.C=auxilary
    int maxheight (TreeNode* root) {
        if(!root) return 0;
        int lh =maxheight(root->left);
        int rh =maxheight(root->right);
        if(lh==-1 ||rh== -1) return -1;
        if(abs(lh-rh)>1)
            return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return maxheight(root)!=-1;
    }
