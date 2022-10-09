/*
gfg link - https://practice.geeksforgeeks.org/problems/burning-tree/1
*/

class Solution
{
private:
    unordered_map<Node*,Node*>parent;
    Node* node;
public:

    void makeParents(Node* root,int target){
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            if(temp->data==target) node=temp;
            q.pop();
            if(temp->left)
                {
                    parent[temp->left]=temp;
                    q.push(temp->left);
                }
            if(temp->right)
                {
                    parent[temp->right]=temp;
                    q.push(temp->right);
                }
        }
    }
    
    int minTime(Node* root, int target)
    {
        makeParents(root,target);
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        q.push(node);
        vis[node]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left&&!vis[temp->left]){
                    vis[temp->left]=true;
                    q.push(temp->left);
                    flag=1;
                }
                if(temp->right&&!vis[temp->right]){
                    vis[temp->right]=true;
                    q.push(temp->right);
                    flag=1;
                }
                if(parent[temp]&&!vis[parent[temp]]){
                    vis[parent[temp]]=true;
                    q.push(parent[temp]);
                    flag=1;
                }
            }
            if(flag) level++;
        }
        return level;
    }
};
