/*
gfg link - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/
//T.C=O(NlogN)+O(N)
    static bool comparator(Item a,Item b){
        double a1=(double)a.value/(double)a.weight;
        double a2=(double)b.value/(double)b.weight;
        return a1>a2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comparator);
        int currWeight=0; double totalValue=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight+currWeight<=W){
                currWeight+=arr[i].weight;
                totalValue+=arr[i].value;
            }
            else{
                int remWeight=W-currWeight;
                totalValue+=(arr[i].value/(double)arr[i].weight)*remWeight;
                break;
            }
        }
        return totalValue;
    }
