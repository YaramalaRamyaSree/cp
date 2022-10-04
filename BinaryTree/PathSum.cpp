/*
leetcode link - https://leetcode.com/problems/path-sum/
*/

    bool helper(TreeNode* root, int sum){
        if(!root) return false;
        sum-=root->val;
        if(!root->left&&!root->right){
            return (sum==0);
        }
        return helper(root->left,sum)||helper(root->right,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);  
    }
