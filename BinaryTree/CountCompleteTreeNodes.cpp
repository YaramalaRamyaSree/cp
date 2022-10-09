/*
leetcode link - https://leetcode.com/problems/count-complete-tree-nodes/
*/

class Solution {
public:
    int leftheight(TreeNode* root){
        int lh=0;
        while(root){
            lh++;
            root=root->left;
        }
        return lh;
    }
    int rightheight(TreeNode* root){
        int rh=0;
        while(root){
            rh++;
            root=root->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(!root)  return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh) return (1<<lh)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};
