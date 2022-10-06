/*
gfg link - https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1
*/

//T.C=O(n)  S.C=O(1)
class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
        if(ispow(S.size())) k=k/2;
        else k=k*2;
        if(S.size()<=k) return "-1";
        stack<int>pq;
        string st="";
        int removed=0;
        for(int i=0;i<S.size();i++){
            while(!pq.empty() && removed<k && S[pq.top()]>S[i]){
                pq.pop();
                removed++;
            }
            pq.push(i);
        }
        while(removed<k)
        {
            pq.pop();
            removed++;
        }
        string ans="";
        while(!pq.empty()){
            ans+=S[pq.top()];
            pq.pop();
        }
        int i=0,j=ans.size()-1;
        while(i<j){
            swap(ans[i++],ans[j--]);
        }
        
        return ans;
    }
    bool ispow(int n)
    {
        if (n == 0)
            return false;
     
        return (ceil(log2(n)) == floor(log2(n)));
    }
};
