/*
leetcode link - https://leetcode.com/problems/trapping-rain-water/
*/

    //T.C=O(N),S.C=O(1)-OPTIMISED-uses two pointers efficiently to know leftmax and right max and water trapped

    int trap(vector<int>& height) {
        int maxleft=0,maxright=0;
        int trap=0;
        int l=0,r=height.size()-1;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=maxleft) maxleft=height[l];
                else trap+=maxleft-height[l];
                l++;
            }
            else{
                 if(height[r]>=maxright) maxright=height[r];
                 else trap+=maxright-height[r];
                 r--;
            }
        }
        return trap;
    }

  
    //better than brute approach uses prefix left and right arrays and find water traped at each index by min(left[i],right[i])-height[i];
    //T.C=O(3N)=find left prefixO(N),right perfix O(N),and finding water trapped O(N)=O(3N),S.C=O(2N) -
    int trap(vector<int>& height) {
        int h=height.size();
        if(h==0)
            return 0;
        int mx[h],mxr[h];
        int a=0,b=0;int sum=0;
        
        for(int i=0;i<h;i++){
            if(height[i]>a){
                mx[i]=height[i];
                a=height[i];
            }
            else
                mx[i]=a;
        }
        for(int i=h-1;i>=0;i--){
            if(height[i]>b){
                mxr[i]=height[i];
                b=height[i];
            }
            else
                mxr[i]=b;
        }
        
        for(int i=1;i<h-1;i++){
            if(mx[i-1]>height[i]&&mxr[i+1]>height[i])
               sum+=(min(mx[i-1],mxr[i+1])-height[i]);
        }
        return sum;       
    }
