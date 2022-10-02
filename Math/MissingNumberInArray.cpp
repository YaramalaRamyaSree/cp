/*
gfg link - https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1
*/

//T.C=O(N) S.C=O(1)
    int MissingNumber(vector<int>& array, int n) {
        int x=0;
        int j=1;
        for(int i=0;i<n-1;i++){
            x^=(array[i]^j);
            j++;
        }
        x^=j;
        return x;
    }
