/*
gfg link - https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1
*/

    //Just insert one by one fro preorder to bst  -T.C=O(N*H) H in worst case N ,S.C=O(1) or O(H) depending on recursive insertion or iterative;
    Node* insert(Node *root, int x){
       if (root==NULL){
           root=newNode(x);
           return root;
       }
       if (root->data>x){
           root->left= insert(root->left, x);
       }
       else if (root->data<x){
           root->right=insert(root->right, x);;
       }
   }
   Node* post_order(int pre[], int size)
   {
       Node *root=newNode(pre[0]);
       for (int i=1; i<size; i++){
           insert(root, pre[i]);
       }
       return root;
   }
    
    //Second method - find inorder from preorder nlogn and using preorder and inorder construct unique bt which will be bst automatically -second method 
    //T.C=O(nlogn+n) S.C=O(n)+O(n)

     
    //  Third method 
    //T.C=O(3N)~O(N) S.C=O(H) -AUXILARY  ->Using upper bound  -OPTIMAL
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
   
