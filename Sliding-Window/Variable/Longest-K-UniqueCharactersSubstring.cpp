/*
gfg link - https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
*/

//T.C=O(N) S.C=O(N)

    int longestKSubstr(string s, int k) {
    int i=0,j=0;
    int n=s.length();
    unordered_map<char,int>mpp;
    int ans=-1;
    while(j<n){
        mpp[s[j]]++;
        if(mpp.size()<k)
            j++;
        else if(mpp.size()>k){
            while(mpp.size()>k && i<j){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)
                    mpp.erase(s[i]);
                i++;
            }
        }
        if(mpp.size()==k){
            ans=max(ans,j-i+1);
            j++;
        }
    }
    return ans;
    }
