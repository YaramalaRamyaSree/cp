/*
leetcode link - https://leetcode.com/problems/word-ladder/
*/

//T.C=O(N*26*N) S.C=O(N) USING LEVEL ORDER BFS 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        bool present=false;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord) 
                present=true;
                s.insert(wordList[i]);
        }
        if(present==false) return 0;
        queue<string>q;
        int n=beginWord.size();
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
            depth++;
            int level=q.size();
            while(level--){
                string st=q.front();
                q.pop();
                for(int i=0;i<n;i++){
                    string temp =st;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(st.compare(temp)==0) continue; // it should not be same as st
                        if(temp.compare(endWord)==0) { //if we found endword 
                            return depth+1;
                        }
                        if(s.find(temp)!=s.end()){ //if we found temp in set 
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }  
        }
        return 0;
    }
