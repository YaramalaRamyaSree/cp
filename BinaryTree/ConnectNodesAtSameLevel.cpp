/*
gfg link - https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/0
*/

//T.C=O(N) S.C=O(N)
    void connect(Node *root)
    {
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int size=q.size();
           Node* prev=q.front();
           q.pop();
           if(prev->left)q.push(prev->left);
           if(prev->right)q.push(prev->right);
           for(int i=1;i<size;i++){
                Node* root=q.front();
                q.pop();
                prev->nextRight=root;
                prev=root;
                if(prev->left)q.push(root->left);
                if(prev->right)q.push(root->right);
           }
       }
    } 
