/*
gfg link - https://practice.geeksforgeeks.org/problems/preorder-traversal-iterative/1
*/

//T.C=O(N) S.C=O(N)
    vector<int> preOrder(Node* root)
    {
        stack<Node*>st;
        st.push(root);
        vector<int>ans;
        while(!st.empty()){
            Node *temp=st.top();
            ans.push_back(temp->data);
            st.pop();
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return ans;
    }
