/*
gfg link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/

    void merge(long long A[],long long int start,long long int mid,long long int end,long long int &count){
            long long int n1 = mid-start+1,n2 = end-mid;
            long long int l[n1+1],r[n2+1];
            for(long long int i=0;i<n1;i++)
                l[i]=A[start+i];
            for(long long int i=0;i<n2;i++)
                r[i]=A[mid+i+1];
            l[n1]=LLONG_MAX;
            r[n2]=LLONG_MAX;
            long long int i=0,j=0;
            for(long long int k=start;k<=end;k++){
                if(l[i]>r[j]){
                    count = ((count)+(n1-i));
                    A[k]=r[j++];
                }else
                    A[k]=l[i++];
            }
    }
 
    void merge_sort(long long A[],long long int start,long long int end,long long &count){
        if(start>=end) return;
        long long int mid = (start+end)>>1;
        merge_sort(A,start,mid,count);
        merge_sort(A,mid+1,end,count);
        merge(A,start,mid,end,count);
    }
        
    long long int inversionCount(long long arr[], long long N)
    {
    long long int count = 0;
    merge_sort(arr,0,N-1,count);
    return count;
    }
