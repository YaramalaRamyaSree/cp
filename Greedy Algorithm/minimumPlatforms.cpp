/*
gfg link -https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
*/

//T.C=O(NlogN)

    int findPlatform(int arr[], int dep[], int n)
    {
      ///sort arriaval and departure times
    	sort(arr,arr+n);
    	sort(dep,dep+n);
      
    	int platform=1,result=1;
    	int i=1,j=0;
    	while( i<n && j<n){
    	    // if there are any arraivals before departure we need extra platform 
            if(arr[i]<=dep[j]){
                platform++;
                i++;
            }
        //if train goes departs platform we can reduce the platform no usage 
            else if(arr[i]>dep[j]){
                platform--;
                j++;
            }
       // when ever platform is more than result it gets updated 
            result=max(result,platform);
    	}
    	return result;
    }
