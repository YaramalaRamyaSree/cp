/*
gfg link - https://practice.geeksforgeeks.org/problems/form-coils-in-a-matrix4726/1
*/
  
    //T.C=O(N^2),S.C=O(N^2)
    vector<vector<int>> formCoils(int n) {
        //Each coil is of size 8*n*n
        int m=8*n*n;
        vector<int>c1(m);
        //first element formula by trail and error
        c1[0]= 8*n*n + 2*n;
        //to find next index value we need previous so we maintain curr
        int curr=c1[0];
        //every time step increases by 2
        int step=2;
        //we either add / subtract 4n or add/subtarct 1 so for add/subtarct we use flag 1/-1
        int flag=1;
        int index=1;
        // we go up right down left and continue till m index for first coil.
        //for up we need to subtarct 4n, right add 1, down add 4n, left subtract 1 
        while(index<m){
            for(int i=0;i<step;i++){
                curr=c1[index++]=(curr-4*n*flag);
                if(index>=m)
                 break;
            }
            if(index>=m) break;
            for(int i=0;i<step;i++){
                curr=c1[index++]=(curr+flag);
                if(index>=m)
                 break;
            }
            step+=2;
            flag=flag*-1;
        }
        //for finding coil two we just use this formula based on coil 1.
        vector<int>c2(m);
        for(int i=0;i<m;i++){
            c2[i]=(16*n*n + 1- c1[i]);
        }
        return {c1,c2};
    }
