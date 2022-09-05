/*
gfg link - https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

    //T.C=O(NlogK) S.C=O(K)
    int kthSmallest(int arr[], int l, int r, int k) {
       priority_queue<int>q;
       //kth smallest so created max heap 
       //my heap will have maximum of k ele
       //it is optimised than sorting which takes o(nlogn)
       for(int i=l;i<=r;i++){
           q.push(arr[i]);
           if(q.size()>k) q.pop();
       }
       return q.top();
    }
