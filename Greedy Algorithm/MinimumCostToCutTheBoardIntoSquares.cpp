/*
GFG LINK - https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1
*/
//T.C=O(MLOGM+NLOGN) S.C=O(1)
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        int cost=0;
        int i=M-2,j=N-2;
        int hcuts=1,vcuts=1;
        while(i>=0 || j>=0){
            if(X[i]>=Y[j])
                {
                    cost+=(X[i]*vcuts);
                    hcuts++;
                    i--;
                }
            else{
                cost+=( Y[j]*hcuts);
                    vcuts++;
                    j--;
            }
        }
        
        return cost;
    }
