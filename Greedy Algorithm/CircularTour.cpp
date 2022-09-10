/*
gfg link - https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
*/

//T.C=O(N) S.C=O(1)
    int tour(petrolPump p[],int n)
    {
       int total=0,totp=0;
       int start=0;
       for(int i=0;i<n;i++){
                totp+=p[i].petrol-p[i].distance;
                if(totp<0){
                    totp=0;
                    start=i+1;
                }
                total+=p[i].petrol-p[i].distance;
       }
       return (total<0?-1:start);
    }
