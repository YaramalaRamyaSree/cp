/*
gfg link - https://practice.geeksforgeeks.org/problems/minimum-swaps/1
*/

  typedef pair<int,int> pii;
	int minSwaps(vector<int>&nums)
	{
	   vector<pii>v;
	   for(int i=0;i<nums.size();i++){
	       v.push_back({nums[i],i});
	   }
	   sort(v.begin(),v.end());
	   int swaps=0;
	   for(int i=0;i<nums.size();i++){
	       pii temp=v[i];
	       int num=temp.first;
	       int index=temp.second;
	       if(i!=index)
            {
               swaps++; 
               swap(v[i],v[index]);
               i--;
            }	   
	   }
	   return swaps;
	}
