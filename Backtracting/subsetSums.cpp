/*
gfg link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1#
*/

//T.C=O(2^N) 
//S.c=O(2^N +N) =storing sums + recursive call stack space

void findSums(int i,int sum,vector<int>&arr,int N,vector<int>&ans){
        if(i==N){
            ans.push_back(sum);
            return ;
        }
        findSums(i+1,sum+arr[i],arr,N,ans);
        findSums(i+1,sum,arr,N,ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int>ans;
       findSums(0,0,arr,N,ans);
       return ans;
    }

// If asked to return sums in sorted order then we must sort ans before we return so extra time complexity of 2^nlog(2^n) will add
