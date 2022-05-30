/*
coding ninjas link - https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
*/
    
    /* Functions 
    
          1.Insert
          2.CountWordsEqualsTo
          3.CountWordsStartingWith 
          4.Erase
          
          ALL of them take T.C=O(N) N is len of given word
    
    */

    struct Node {

        Node *links[26];
        int cntendwith=0;
        int cntprefix=0;

        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }

        void put(char ch , Node *node){
            links[ch-'a']=node;
        }

        Node* get(char ch){
            return links[ch-'a']; 
        }

        void increasePrefix(){
            cntprefix++;
        }

        void increaseEnd(){
            cntendwith++;
        }

        int getPrefix(){
            return cntprefix;
        }

        int getEndWith(){
            return cntendwith;
        }

        void decreasePrefix(){
            cntprefix--;
        }

        void decreaseEnd(){
            cntendwith--;
        }
    } ;

    class Trie{
        private:
        Node *root;
        public:

        Trie(){
            root = new Node();
        }

        void insert(string &word){
            Node *node =root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node =node->get(word[i]);
                node->increasePrefix();
            }
            node->increaseEnd();
        }

        int countWordsEqualTo(string &word){
           Node *node =root;
           for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }
                node =node->get(word[i]);
           }
           return node->getEndWith();
        }

        int countWordsStartingWith(string &word){
            Node *node =root;
           for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }
                node =node->get(word[i]);
           }
           return node->getPrefix();
        }

        void erase(string &word){
            Node *node =root;
           for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return;
                }
                node =node->get(word[i]);
                node->decreasePrefix();
           }
           node->decreaseEnd();
        }
    };
