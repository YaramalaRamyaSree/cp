/*
gfg link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/

//T.C=O(H)+O(N)+O(H) S.C=O(N)
    bool isleaf(Node* root){
        if(!root->left&&!root->right)
            return 1;
        return 0;
    }
    void leftboundary(Node* root,vector<int>&ans){
        root=root->left;
        while(root){
            if(!isleaf(root)) ans.push_back(root->data);
            if(root->left)root=root->left;
            else root=root->right;
        }
    }
    
    void leaves(Node* root,vector<int>&ans){
        if(!root) return;
        leaves(root->left,ans);
        if(isleaf(root)) ans.push_back(root->data);
        leaves(root->right,ans);
    }
    
    void rightboundary(Node* root,vector<int>&ans){
        root=root->right;
        stack<int>s;
        while(root){
             if(!isleaf(root)) s.push(root->data);
            if(root->right)root=root->right;
            else root=root->left;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(!root) return ans;
        if(!isleaf(root)) ans.push_back(root->data);
        leftboundary(root,ans);
        leaves(root,ans);
        rightboundary(root,ans);
        return ans;
    }
