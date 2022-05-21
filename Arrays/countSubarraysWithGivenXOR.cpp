/*
interviewbit link - https://www.interviewbit.com/problems/subarray-with-given-xor/
*/

//T.C=O(N),S.C=O(N)
//LOGIC: maintain prefix xorr's and check if xoorr^B is present in map or xorr==B accordingly increment count 
//Map stores frequency of particular xorr value .

int Solution::solve(vector<int> &A, int B) {

    unordered_map<int,int> hashMap;
  
    if(A.size()==1) {
    if(A[0]==B) return 1;
    else return 0;}
  
    int count=0,xor_value=0,temp;
  
    for(auto it:A){
        xor_value^=it;
      
        if(xor_value==B)
        count+=1;
      
        temp=B^xor_value;
      
        if(hashMap.find(temp)!=hashMap.end()){
            count+=hashMap[temp];
        }
      
        hashMap[xor_value]++;
    }
    return count;
}
