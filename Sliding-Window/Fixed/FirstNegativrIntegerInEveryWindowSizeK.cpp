/*
gfg link - https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/
T.C=O(N) S.C=O(K)
typedef long long int ll;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    queue<ll>q;vector<ll>ans;
    int i=0,j=0;
    while(j<N){
        if(A[j]<0) q.push(A[j]);
        if(j-i+1<K){j++; continue;}
        auto element=q.empty()?0:q.front();
        ans.push_back(element);
        if(element==A[i])
                q.pop();
        i++;j++;
    }
    return ans;
 }
