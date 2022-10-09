/*
gfg link - https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
*/
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
       queue<Node*>q;
       q.push(root);
       vector<int>v;
       while(!q.empty()){
           Node* temp=q.front();
           q.pop();
           if(!temp) {v.push_back(0);continue;}
           else {
               v.push_back(temp->data);}
            if(temp){
               q.push(temp->left);
               q.push(temp->right);
           }
       }
       return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &v)
    {
       int i=0;
       Node* root=new Node(v[i++]);
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           Node* node=q.front();
           q.pop();
           if(v[i]){
               node->left=new Node(v[i]);
               q.push(node->left);
           }else
           node->left=NULL;
           i++;
           if(v[i]){
               node->right=new Node(v[i]);
               q.push(node->right);
           }else
            node->right=NULL;
            i++;
       }
       return root;
    }

};
