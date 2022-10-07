/*
gfg link - https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
*/
    vector <int> zigZagTraversal(Node* root)
    {
       vector<vector<int>>ans;
       
       queue<Node*>que;

        que.push(root);

        bool leftToRight = true;

        while(!que.empty()){

            int size = que.size();

            vector<int>row(size);

            for(int i=0;i<size;i++){

                Node* temp = que.front();

                int index;

                index=(leftToRight)? i:size-1-i;

                row[index] = temp->data;

                if(temp->left){

                    que.push(temp->left);

                }

                if(temp->right){

                    que.push(temp->right);

                }

                que.pop();

            }

            leftToRight = !leftToRight;

            ans.push_back(row);

        }

        vector<int>final;

        for(int i=0;i<ans.size();i++){

            for(int j=0;j<ans[i].size();j++){

                final.push_back(ans[i][j]);

            }

        }

        return final;
    }
