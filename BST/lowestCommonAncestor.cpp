/*
leetcode link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/
    //T.C=O(H)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val>p->val && root->val>q->val) 
            return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val && root->val<q->val) 
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
