/*
gfg link - https://practice.geeksforgeeks.org/problems/complete-binary-tree/1
*/
    
    //T.C=O(N),S.C=O(N)
    //IDEA -traverse level order store nullvalue also -if its complete bt then while poping we can never find not null element after you encounter null element  -its the catch here!!
    bool isCompleteBT(Node* root){
        queue<Node*>q;
        q.push(root);
        bool nullNode=false;
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            if(!node) nullNode=1;
            else{
                if(nullNode) return 0;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return 1;
    }
