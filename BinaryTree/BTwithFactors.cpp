/*
leetcode link - https://leetcode.com/problems/binary-trees-with-factors/
*/

    //worst case T.C=O(N^2),S.C=O(N)
    int mod=1000000007;
    int helper(int rootindex,vector<int>&arr,unordered_map<int,long>&m,int n,int &count){
        if(rootindex==n) return 0;
        long int c=1;
        for(auto it=m.begin();it!=m.end();it++){
            if((arr[rootindex]%it->first)==0 && m.find(arr[rootindex]/it->first)!=m.end())
                c=(c%mod+ (it->second%mod*(m[arr[rootindex]/it->first]%mod)%mod))%mod;
        }
        
        m[arr[rootindex]]=c;
        count=(c%mod+helper(rootindex+1,arr,m,n,count)%mod)%mod;
        return count;
            
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long>m;
        int count=0;
        return helper(0,arr,m,arr.size(),count);
    }
