/*
gfg link - https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1
*/

    //T.C=O(3N)~O(N) S.C=O(H) -AUXILARY  ->Using upper bound 
    Node* f(int pre[],int size,int &i,int bound){
        if(i==size|| pre[i]>bound)
            return NULL;
        Node *root=newNode(pre[i++]);
        root->left=f(pre,size,i,root->data);
        root->right=f(pre,size,i,bound);
        return root;
    }
    Node* post_order(int pre[], int size)
    {
       int i=0;
       return f(pre,size,i,INT_MAX);
    }
   
