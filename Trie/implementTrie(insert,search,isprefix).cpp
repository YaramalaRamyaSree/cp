/*
leetcode link - https://leetcode.com/problems/implement-trie-prefix-tree/
*/

    //datastructure Node
    struct Node{
            Node *links[26];
            bool flag=false;

            bool containsKey(char ch){
                return (links[ch-'a']!=NULL);
            }

            void put(char ch,Node* node){
                links[ch-'a']=node;
            } 

            Node* get(char ch){
                return links[ch-'a'];
            }

            void setEnd(){
                flag=true;
            }

            bool isEnd(){
                return flag;
            }
    };

    class Trie {
    private: 
        Node *root; // a variable of type of Node
    public:

        //Constructor -intialising its variables .
        Trie() {
            root=new Node();
        }

        //T.C=O(N) N is length of word 
        void insert(string word) {
            Node *node =root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }

        //T.C=O(N) N is length of word
        bool search(string word) {
            Node *node =root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])) 
                    return false;
                node=node->get(word[i]);
            }
            return node->isEnd();
        }

        //T.C=O(N) N is length of prefix word
        bool startsWith(string prefix) {
            Node *node =root;
            for(int i=0;i<prefix.length();i++){
                if(!node->containsKey(prefix[i]))
                    return false;
                node=node->get(prefix[i]);
            }
            return true;
        }
    };
