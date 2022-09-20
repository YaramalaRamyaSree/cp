/*
gfg link - https://practice.geeksforgeeks.org/problems/print-nodes-having-k-leaves/0
*/

// T.C=O(N) S.C=O(H)
    vector<int>a;
    int helper(Node* root,int k){
        if(!root) return 0;
        if(!root->left&&!root->right){
            return 1;
        }
        int l= helper(root->left,k);
        int r=helper(root->right,k);
        if(l+r==k) { a.push_back(root->data);}
        return l+r;
    }
    
    vector<int> btWithKleaves(Node *ptr, int k)
    { 
        int ans;
        helper(ptr,k);
        if(a.size()==0) return {-1};
        return a;
    }
