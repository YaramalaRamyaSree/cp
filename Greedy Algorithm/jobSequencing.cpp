/*
gfg link - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
*/

//T.C=O(NlogN)+O(N*M) M is maximum deadline 
    static bool comparator(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
            sort(arr,arr+n,comparator);
            int maxi=arr[0].dead;
            for(int i=1;i<n;i++){
                maxi=max(arr[i].dead,maxi);
            }
            int slot[maxi+1];
            for(int i=0;i<=maxi;i++)
                slot[i]=-1;
            int countjobs=0,totalProfit=0;
            for(int i=0;i<n;i++){
                        for(int j=arr[i].dead;j>0;j--){
                            if(slot[j]==-1){
                                countjobs++;
                                totalProfit+=arr[i].profit;
                                slot[j]=i;
                                break;
                            }
                        }
                    }
                    return {countjobs,totalProfit};
    } 
