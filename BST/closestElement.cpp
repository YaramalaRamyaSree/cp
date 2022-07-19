/*
gfg link - https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
*/

//T.C=O(H),S.C=O(1)
    int minDiff(Node *root, int K)
    {
        int ceil_no=-1,floor_no=-1;
        while(root){
            if(root->data==K){
                return 0;
            }
            if(root->data>K){
                ceil_no=root->data;
                root=root->left;
            }
            else{
                floor_no=root->data;
                root=root->right;
            }
        }
       
        return min(abs(K-ceil_no),abs(K-floor_no));
    }
