/*
gfg link - https://practice.geeksforgeeks.org/problems/fact-digit-sum4125/1
*/

	vector<int> FactDigit(int N)
	{
	    int arr[10];
	    arr[0]=1;
	    for(int i=1;i<10;i++){
	        arr[i]=i*arr[i-1];
	    }
	    vector<int>ans;
	    for(int i=9;i>=1;i--){
	        while(N>=arr[i]){
	            N=N-arr[i];
	            ans.push_back(i);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
