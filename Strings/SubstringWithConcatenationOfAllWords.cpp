/*
leetcode link - https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/

    //T.C=O(M*N) S.C=O(N)
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        int wordlen = words[0].length();
        int total=n*wordlen;
        vector<int>res;
        if(s.size()<total)
            return res;
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[words[i]]++;
        }
        for(int i=0;i<=s.size()-total;i++){
            unordered_map<string,int>copy;
            copy=m;
            int k;
            for(k=0;k<n;k++){
                string str=s.substr(i+k*wordlen,wordlen);
                if(!copy.count(str)) break;
                if(copy[str]==1) copy.erase(str); 
                else  copy[str]--;
            }
            if(k==n) res.push_back(i);
        }
        return res;
    }
