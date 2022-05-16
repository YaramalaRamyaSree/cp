/*

gfg link - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

Time Complexity=O(N)
Space Complexity=O(1)
*/

int *findTwoElement(int *arr, int n) {
        int xor1=0,i,set_bit;
        int a[2]={0};
        for( i=0;i<n;i++){
            xor1=xor1^arr[i];
        }
        for(i=1;i<=n;i++){
            xor1=xor1^i;
        }
  //finding right most set bit 
        set_bit=xor1&~(xor1-1);
        for(i=0;i<n;i++){
            if(arr[i]&set_bit){
                a[0]=a[0]^arr[i];
            }
            else
            a[1]=a[1]^arr[i];
        }
        for(i=1;i<=n;i++){
            if(i&set_bit){
                a[0]=a[0]^i;
            }
            else
            a[1]=a[1]^i;
        }
        /*checking for which is missing and which is repeated*/
        bool f=0;
        for(int i=0;i<n;i++){
            if(a[0]==arr[i])
            f=1;
        }
        if(f==0){
            arr[0]=a[1];
            arr[1]=a[0];
        }
    return arr;
    }
