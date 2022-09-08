/*
gfg link - https://practice.geeksforgeeks.org/problems/check-if-subtree/0
*/

//T.C=O(N) S.C=O(N)
   void search(Node* root,int key,vector<Node*>&nodes){
        if(!root) return ;
        if(root->data==key) nodes.push_back(root);
        search(root->left,key,nodes);
        search(root->right,key,nodes);
    }
    void inorder(Node* root,vector<string>&ans){
        if(!root) {ans.push_back("null"); return ;}
        ans.push_back(to_string(root->data));
        inorder(root->left,ans);
        inorder(root->right,ans);
    }
    bool isSubTree(Node* T, Node* S) 
    {
        vector<Node*>nodes;
        search(T,S->data,nodes);
        vector<string>ans1,ans2;
        inorder(S,ans1);
        for(int i=0;i<nodes.size();i++){
        inorder(nodes[i],ans2);
        if(ans1==ans2) return 1;
        ans2.clear();
        }
       return 0; 
    }
