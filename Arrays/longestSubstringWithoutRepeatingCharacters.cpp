/*
leetcode link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,vector<int>> m;
        
        int maxi=0,cnt=0;
        
        for(int i=0;i<s.length();i++){
            
            if(m.find(s[i])!=m.end()){
                if(i-m[s[i]].back()<=cnt)
                cnt=i-m[s[i]].back();
                else
                    cnt=cnt+1;
                m[s[i]].push_back(i);
            }
            
            else{
                m[s[i]].push_back(i);
                cnt+=1;
            }
            
            maxi=max(maxi,cnt);
        }
        return maxi;
        
    }

//with constant space

    int longestUniqueSubsttr(string S){
       int mpp[26];
       memset(mpp,-1,sizeof(mpp));
       int maxi=0,cnt=0;
       for(int i=0;i<S.length();i++){
           if(mpp[S[i]-'a']!=-1)
           {
               if(i-mpp[S[i]-'a']<=cnt)
                    cnt=i-mpp[S[i]-'a'];
               else
                    cnt++;
                mpp[S[i]-'a']=i;
           }
           else
           {
               cnt++;
               mpp[S[i]-'a']=i;
           }
           
           if(cnt>maxi) maxi=cnt;
       }
        return maxi;
    }
