/*
code studio - https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
*/


//This greedy algo only works for indian currency  T.C=O(N)
int findMinimumCoins(int V) 
{
    int coins[9]={1,2,5,10,20,50,100,500,1000};
        int i=8,count=0;
        while(V!=0){
            if(coins[i]<=V){
                count++;
                V-=coins[i];
            }
            else{
                i--;
            }
        }
        return count;
}
