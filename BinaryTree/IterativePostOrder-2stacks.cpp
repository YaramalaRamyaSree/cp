/*
gfg link - https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1
*/

//T.C=O(N) S.C=O(N)
    vector<int> postOrder(Node* node) {
       stack<Node*>st1,st2;
       st1.push(node);
       vector<int>ans;
       while(!st1.empty()){
           Node*temp=st1.top();
           st2.push(temp);
           st1.pop();
           if(temp->left)
                st1.push(temp->left);
           if(temp->right)
                st1.push(temp->right);  
       }
       while(!st2.empty()){
           ans.push_back(st2.top()->data);
           st2.pop();
       }
       return ans;
    }
