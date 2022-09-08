/*
leetcode link - https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        stack<TreeNode*>s;
        TreeNode* curr=root;
        while(true){
                if(curr!=NULL){
                    s.push(curr);
                    curr=curr->left;
                }
                else {
                    if(s.empty()){
                        break;}
                    curr=s.top();
                    inorder.push_back(curr->val);
                    s.pop();
                    curr=curr->right;
                }   
        }
        return inorder;
    }
