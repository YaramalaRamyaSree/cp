/*
coding ninjas link - https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
*/

//Recursive T.C=O(3^n*m),S.C=O(n)-stack space auxilary
int f(int day ,int last, vector<vector<int>>&points ){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi=max(maxi,points[0][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            maxi=max(maxi,points[day][i]+f(day-1,i,points));
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int last =3;
    return f(n-1,last,points);
}

//Memoization T.C=O(N*M*3)=o(n*4*3) m=4 states -0,1,2,3  S.C=O(N*4)+O(N)
int f(int day ,int last, vector<vector<int>>&points, vector<vector<int>>&dp ){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi=max(maxi,points[0][i]);
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            maxi=max(maxi,points[day][i]+f(day-1,i,points,dp));
        }
    }
    return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int last =3;
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,last,points,dp);
}

//Tabulation -T.C=O(N*M*3) S.C=O(N*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            for(int i=0;i<3;i++){
                if(i!=last){
                    int activity =points[day][i] + dp[day-1][i];
                    dp[day][last]=max(dp[day][last],activity);
                }
            }
        }
    }
    return dp[n-1][3];
}

//Space Otiimization T.C=O(N*M*3) ,S.C=O(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int>curr(4,0);
        for(int last=0;last<4;last++){
            for(int i=0;i<3;i++){
                if(i!=last){
                    int activity =points[day][i] + prev[i];
                    curr[last]=max(curr[last],activity);
                }
            }
        }
        prev=curr;
    }
    return prev[3];
}
