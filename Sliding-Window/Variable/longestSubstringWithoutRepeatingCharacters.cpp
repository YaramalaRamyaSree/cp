
    int longestUniqueSubsttr(string S){
       unordered_map<char,int>mpp;
       int i=0,j=0,maxi=0;
       int n=S.size();
       while(j<n){
           mpp[S[j]]++;
           if(mpp.size()==j-i+1)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(mpp.size()<j-i+1){
                while(mpp.size()<j-i+1){
                    mpp[S[i]]--;
                    if(mpp[S[i]]==0)
                        mpp.erase(S[i]);
                    i++;
                }
                j++;
            }
       }
       return maxi;
    }
