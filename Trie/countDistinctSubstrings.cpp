/*
coding ninjas link - https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
*/
 
        //T.C=O(N^2)=logic we increment count when ever we insert char into trie datastructure
       //(eg:abcd: we insert (a -root,b,c,d),(b-root,c,d),(c-root,d),d-root)+{}) , and empty string is added at last
        struct Node{
                    Node *links[26];
                    bool containsKey(char ch){
                        return (links[ch-'a']!=NULL);
                    }
                    void put(char ch,Node *node){
                        links[ch-'a']=node;
                    }
                    Node* get(char ch){
                        return links[ch-'a'];
                    }
                };

         int countDistinctSubstrings(string &s){
                    int count=0;
                    Node *root= new Node();
                    for(int i=0;i<s.length();i++){
                        Node *node=root;
                        for(int j=i;j<s.length();j++){
                            if(!node->containsKey(s[j])){
                                count++;
                                node->put(s[j],new Node());
                            }
                            node=node->get(s[j]);
                        }
                    }
                    return count+1;
         }
