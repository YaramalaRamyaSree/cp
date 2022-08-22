/*
interview bit - https://www.interviewbit.com/problems/maximum-sum-combinations/
*/

//first approch
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<int> helper;
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            helper.push(a[i]+b[j]);
        }}
    for(int i=0;i<k;i++){
        ans.push_back(helper.top());
        helper.pop();
    }
    return ans;
}

//second approch 
struct three{
    int val;int i;int j;
};
struct cmp{
    bool operator()(three a,three b){
    return a.val<b.val;}
};
bool rev(int a,int b){
    return a<b;
}
vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
	sort(a.begin(),a.end(),rev);
    sort(b.begin(),b.end(),rev);
    priority_queue<three,vector<three>,cmp>pq;
    int n=a.size();
    set<pair<int ,int>>s;
    s.insert({n-1,n-1});
    pq.push({a[n-1]+b[n-1],n-1,n-1});
    vector<int>ans;
    while(ans.size()!=c){
        three item=pq.top();
        pq.pop();
        int value=item.val;int indx=item.i;int jndx=item.j;
        if(indx>0 && s.count({indx-1,jndx})==0){
            pq.push({a[indx-1]+b[jndx],indx-1,jndx});
            s.insert({indx-1,jndx});}
        if(jndx>0 && s.count({indx,jndx-1})==0){
            pq.push({a[indx]+b[jndx-1],indx,jndx-1});
            s.insert({indx,jndx-1});}
    }
    return ans;
}
