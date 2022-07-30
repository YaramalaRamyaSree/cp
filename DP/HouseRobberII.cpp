/*
coding ninjas - https://www.codingninjas.com/codestudio/problems/house-robber_839733
*/
//This problem is slight change of maximum sum of non adjacent elements (i.e added n-1 is neighbour of 0) so idea if we take last we should not include first and viceversa .
//We do take two arrays 0 to n-2 and 1 to n-1 and find maximum sum of non adj ele and return max of both .
//T.C=O(N),S.C=O(1)
long long  maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    long long int prev2=0;
    long long int prev=nums[0];
    for(int i=1;i<n;i++){
        long long int take=nums[i]+prev2;
        long long int notTake=prev;
        long long int curr=max(take,notTake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}
